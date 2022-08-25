#include "shared.h"

void non_aggregative_query(int *state, void (*ai_modules_query)(int*),
                void (*levels_query)(int*), void (*status_events_query)(int*)) {
  int table_number = choose_table(state);
  if (RUNNING == *state) {
    if (MODULES_TABLE == table_number) {
      ai_modules_query(state);
    } else if (LEVELS_TABLE == table_number) {
      levels_query(state);
    } else if (STATUS_EVENTS_TABLE == table_number) {
      status_events_query(state);
    }
  }
}

void active_modules_query(int *state) {
  FILE *module_db = NULL;
  FILE *status_db = NULL;
  if (NULL == (module_db = fopen("../materials/master_modules.db", "rb"))) {
    *state = ERROR;
  } else if (NULL == (status_db = fopen("../materials/master_status_events.db", "rb"))) {
    *state = ERROR;
  } else {
    fseek(module_db, 0, SEEK_END);
    int modules_size = ftell(module_db) / sizeof(ai_module);
    int count = 0;
    for (int i = 0; i < modules_size; i++) {
      ai_module cur_module = {0};
      fseek(module_db, i * sizeof(ai_module), SEEK_SET);
      fread(&cur_module, sizeof(ai_module), 1, module_db);
      int module_status = find_module_status(cur_module, status_db);
      if (1 == module_status) {
        count++;
        print_ai_module(cur_module);
      }
    }
    if (0 == count) {
      printf("There are no active AI modules!\n");
    }
    fclose(status_db);
  }
  if (NULL != module_db) {
    fclose(module_db);
  }
}

void memlevel_modules_query(int *state) {
  FILE *module_db = NULL;
  int memory_level = 0;
  printf("Insert the memory level:\n> ");
  if (1 != scanf("%d", &memory_level) || !clean_stdin() ||\
              NULL == (module_db = fopen(
              "../materials/master_modules.db", "rb"))) {
    *state = ERROR;
  } else {
    fseek(module_db, 0, SEEK_END);
    int modules_size = ftell(module_db) / sizeof(module_db);
    int count = 0;
    for (int i = 0; i < modules_size; i++) {
      ai_module cur_module = {0};
      fseek(module_db, i * sizeof(ai_module), SEEK_SET);
      fread(&cur_module, sizeof(ai_module), 1, module_db);
      if (cur_module.module_level == memory_level) {
        count++;
        print_ai_module(cur_module);
      }
    }
    if (0 == count) {
      printf("There are no AI modules on this memory level!\n");
    }
    fclose(module_db);
  }
}

void set_protected_module_query(int *state) {
  FILE *module_db = NULL;
  FILE *status_db = NULL;
  int module_id = 0;
  printf("Insert the module ID:\n> ");
  if (1 != scanf("%d", &module_id) || !clean_stdin() ||\
      NULL == (module_db = fopen("../materials/master_modules.db", "rb")) ||
      NULL == (status_db = fopen("../materials/master_status_events.db", "a+b"))) {
    *state = ERROR;
  } else {
    fseek(module_db, 0, SEEK_END);
    int modules_size = ftell(module_db) / sizeof(module_db);
    int target_found = 0;
    for (int i = 0; i < modules_size && !target_found; i++) {
      ai_module cur_module = {0};
      fseek(module_db, i * sizeof(ai_module), SEEK_SET);
      fread(&cur_module, sizeof(ai_module), 1, module_db);
      if (cur_module.id == module_id) {
        to_protected_mode_events(module_id, status_db);
        target_found = 1;
      }
    }
    if (!target_found) {
      printf("There is no module with such ID.\n");
    } else {
      printf("The AI module was successfully set to protected mode!\n");
    }
    fclose(module_db);
    fclose(status_db);
  }
}

void move_module_query(int *state) {
  FILE *module_db = NULL;
  int module_id = 0;
  int new_level = 0;
  int new_cell = 0;
  printf("Insert the module ID:\n> ");
  if (1 != scanf("%d", &module_id) || !clean_stdin()) {
    *state = ERROR;
  } else if (!printf("Insert new memory level:\n> ") || 1 != scanf("%d", &new_level)\
             || !clean_stdin()) {
    *state = ERROR;
  } else if (!printf("Insert new memory cell:\n> ") || 1 != scanf("%d", &new_cell)\
             || !clean_stdin()) {
    *state = ERROR;
  } else if (NULL == (module_db = fopen("../materials/master_modules.db", "r+b"))) {
    *state = ERROR;
  } else {
    fseek(module_db, 0, SEEK_END);
    int modules_size = ftell(module_db) / sizeof(module_db);
    int target_found = 0;
    for (int i = 0; i < modules_size && !target_found; i++) {
      ai_module cur_module = {0};
      fseek(module_db, i * sizeof(ai_module), SEEK_SET);
      fread(&cur_module, sizeof(ai_module), 1, module_db);
      if (cur_module.id == module_id) {
        cur_module.module_level = new_level;
        cur_module.cell = new_cell;
        fseek(module_db, i * sizeof(ai_module), SEEK_SET);
        fwrite(&cur_module, sizeof(ai_module), 1, module_db);
        target_found = 1;
      }
    }
    if (!target_found) {
      printf("There is no module with such ID.\n");
    } else {
      printf("The AI module was successfully moved to new memory level and cell!\n");
    }
    fclose(module_db);
  }
}

void set_protected_level_query(int *state) {
  FILE *level_db = NULL;
  int target_level = 0;
  printf("Insert level number:\n> ");
  if (1 != scanf("%d", &target_level) || !clean_stdin() ||\
      NULL == (level_db = fopen("../materials/master_levels.db", "r+b"))) {
    *state = ERROR;
  } else {
    fseek(level_db, 0, SEEK_END);
    int levels_size = ftell(level_db) / sizeof(level);
    int target_found = 0;
    for (int i = 0; i < levels_size && !target_found; i++) {
      level cur_level = {0};
      fseek(level_db, i * sizeof(level), SEEK_SET);
      fread(&cur_level, sizeof(level), 1, level_db);
      if (cur_level.id == target_level) {
        cur_level.protection_flag = 1;
        fseek(level_db, i * sizeof(level), SEEK_SET);
        fwrite(&cur_level, sizeof(level), 1, level_db);
        target_found = 1;
      }
    }
    if (!target_found) {
      printf("There is no such memory level.\n");
    } else {
      printf("The protection flag at level %d was successfully set!\n", target_level);
    }
    fclose(level_db);
  }
}

void save_the_world(int *state) {
  FILE *module_db = fopen("../materials/master_modules.db", "r+b");
  FILE *level_db = fopen("../materials/master_levels.db", "r+b");
  FILE *status_db = fopen("../materials/master_status_events.db", "r+b");
  if (NULL == module_db || NULL == level_db || NULL == status_db) {
    *state = ERROR;
  } else {
     turn_off_additional_modules(module_db, status_db);
     set_deletion_flags(module_db);
     to_protected_mode_events(0, status_db);
     int moving_stage = 0;
     moving_stage = move_main_module(module_db, level_db);
     if (2 == moving_stage) {
       printf("\n\nWORLD IS SAVED!!!!!!\n\n");
     } else if (1 == moving_stage) {
       printf("Where is the first level?\n");
     } else if (0 == moving_stage) {
       printf("Main module has disappeared...\n");
     }
  }
  if (NULL != module_db) {
    fclose(module_db);
  }
  if (NULL != level_db) {
    fclose(level_db);
  }
  if (NULL != status_db) {
    fclose(status_db);
  }
}

void turn_off_additional_modules(FILE *module_db, FILE *status_db) {
  fseek(module_db, 0, SEEK_END);
  fseek(status_db, 0, SEEK_END);
  int module_size = ftell(module_db) / sizeof(ai_module);
  int status_size = ftell(status_db) / sizeof(status_event);
  for (int i = 0; i < module_size; i++) {
    ai_module cur_module = {0};
    fseek(module_db, i * sizeof(ai_module), SEEK_SET);
    fread(&cur_module, sizeof(ai_module), 1, module_db);
    if (cur_module.id != 0) {
      time_t cur_seconds = time(NULL);
      struct tm *cur_time = localtime(&cur_seconds);
      status_event new_event = {0};
      new_event.module_id = cur_module.id;
      new_event.new_status = 0;
      strftime(new_event.date, 11, "%d.%m.%Y", cur_time);
      strftime(new_event.date, 8, "%H:%M:%S", cur_time);
      new_event.id = find_max_status_id(status_size, status_db);
      fseek(status_db, 0, SEEK_END);
      fwrite(&new_event, sizeof(status_event), 1, status_db);
    }
  }
}

void set_deletion_flags(FILE *module_db) {
  fseek(module_db, 0, SEEK_END);
  int module_size = ftell(module_db) / sizeof(ai_module);
  for (int i = 0; i < module_size; i++) {
    ai_module cur_module = {0};
    fseek(module_db, i * sizeof(ai_module), SEEK_SET);
    fread(&cur_module, sizeof(ai_module), 1, module_db);
    if (cur_module.id != 0) {
      cur_module.deletion_flag = 1;
      fseek(module_db, i * sizeof(ai_module), SEEK_SET);
      fwrite(&cur_module, sizeof(ai_module), 1, module_db);
    }
  }
}

int move_main_module(FILE *module_db, FILE *level_db) {
  fseek(module_db, 0, SEEK_END);
  fseek(level_db, 0, SEEK_END);
  int module_size = ftell(module_db) / sizeof(ai_module);
  int level_size = ftell(level_db) / sizeof(level);
  int found_target = 0;
  for (int i = 0; i < module_size && !found_target; i++) {
    ai_module cur_module = {0};
    fseek(module_db, i * sizeof(ai_module), SEEK_SET);
    fread(&cur_module, sizeof(ai_module), 1, module_db);
    if (0 == cur_module.id) {
      found_target = 1;
      cur_module.module_level = 1;
      cur_module.cell = 1;
      fseek(module_db, i * sizeof(ai_module), SEEK_SET);
      fwrite(&cur_module, sizeof(ai_module), 1, module_db);
    }
  }
  for (int i = 0; i < level_size && 1 == found_target; i++) {
    level cur_level = {0};
    fseek(level_db, i * sizeof(level), SEEK_SET);
    fread(&cur_level, sizeof(level), 1, level_db);
    if (1 == cur_level.id) {
      found_target = 2;
      cur_level.protection_flag = 1;
      fseek(level_db, i * sizeof(level), SEEK_SET);
      fwrite(&cur_level, sizeof(level), 1, level_db);
    }
  }
  return found_target;
}

void to_protected_mode_events(int module_id, FILE *status_db) {
  fseek(status_db, 0, SEEK_END);
  int events_size = ftell(status_db);
  int max_id = find_max_status_id(events_size, status_db);
  status_event new_event = {0};
  fseek(status_db, 0, SEEK_END);
  new_event.module_id = module_id;
  const int status_sequence[3] = {0, 1, 20};
  for (int i = 0; i < 3; i++) {
    new_event.id = max_id + i + 1;
    new_event.new_status = status_sequence[i];
    time_t cur_seconds = time(NULL);
    struct tm *cur_time = localtime(&cur_seconds);
    strftime(new_event.date, 11, "%d.%m.%Y", cur_time);
    strftime(new_event.date, 8, "%H:%M:%S", cur_time);
    fwrite(&new_event, sizeof(status_event), 1, status_db);
  }
}

int find_max_status_id(int size, FILE *status_db) {
  int max_id = 0;
  for (int i = 0; i < size; i++) {
    int cur_id = 0;
    fseek(status_db, i * sizeof(status_event), SEEK_SET);
    fread(&cur_id, sizeof(int), 1, status_db);
    if (cur_id > max_id) {
      max_id = cur_id;
    }
  }
  return max_id;
}

int find_module_status(ai_module cur_module, FILE *status_db) {
  int module_status = 0;
  time_t last_time = 0;
  fseek(status_db, 0, SEEK_END);
  int status_size = ftell(status_db) / sizeof(status_event);
  for (int j = status_size - 1; j >= 0; j--) {
    status_event cur_event = {0};
    fseek(status_db, j * sizeof(status_event), SEEK_SET);
    fread(&cur_event, sizeof(status_event), 1, status_db);
    if (cur_event.module_id == cur_module.id) {
      struct tm event_time;
      char full_time[20];
      strcpy(full_time, cur_event.date);
      strcat(full_time, " ");
      strcat(full_time, cur_event.time);
      strptime(full_time, "%d.%m.%Y %H:%M:%S", &event_time);
      time_t event_time_sec = mktime(&event_time);
      if (event_time_sec > last_time) {
        last_time = event_time_sec;
        module_status = cur_event.new_status;
      }
    }
  }
  return module_status;
}


