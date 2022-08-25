#include "db_master_modules.h"

ai_module *ai_modules_select(int id, int *state) {
  FILE *db = NULL;
  ai_module *selected = NULL;
  if (NULL == (db = fopen("../materials/master_modules.db", "r+b"))) {
    *state = ERROR;
  } else {
    FILE *indices = NULL;
    if (NULL == (indices = fopen("../materials/modules_indices.db", "r+b"))) {
      *state = ERROR;
    } else {
      selected = select(db, indices, id, sizeof(ai_module));
      fclose(indices);
    }
    fclose(db);
  }
  return selected;
}

int ai_modules_delete(int id, int *state) {
  FILE *db = NULL;
  int result = 0;
  if (NULL == (db = fopen("../materials/master_modules.db", "r+b"))) {
    *state = ERROR;
  } else {
    FILE *indices = NULL;
    if (NULL == (indices = fopen("../materials/modules_indices.db", "r+b"))) {
      *state = ERROR;
    } else {
      result = delete(db, indices, id, sizeof(ai_module));
      fclose(indices);
    }
    fclose(db);
  }
  return result;
}

int ai_modules_insert(ai_module *new_ai_module, int *state) {
  FILE *db = NULL;
  int result = 0;
  if (NULL == (db = fopen("../materials/master_modules.db", "r+b"))) {
    *state = ERROR;
  } else {
    FILE *indices = NULL;
    if (NULL == (indices = fopen("../materials/modules_indices.db", "r+b"))) {
      *state = ERROR;
    } else {
      result = insert(db, indices, new_ai_module, sizeof(ai_module));
      fclose(indices);
    }
    fclose(db);
  }
  return result;
}

int ai_modules_update(int id, ai_module *updated_ai_module, int *state) {
  FILE *db = NULL;
  int result = 0;
  if (NULL == (db = fopen("../materials/master_modules.db", "r+b"))) {
    *state = ERROR;
  } else {
    FILE *indices = NULL;
    if (NULL == (indices = fopen("../materials/modules_indices.db", "r+b"))) {
      *state = ERROR;
    } else {
      result = update(db, indices, id, updated_ai_module, sizeof(ai_module));
      fclose(indices);
    }
    fclose(db);
  }
  return result;
}

void ai_modules_select_query(int *state) {
  int target_id = 0;
  printf("Insert ID of the selected AI module:\n> ");
  if (1 != scanf("%d", &target_id)) {
    *state = ERROR;
  } else {
    ai_module *result = ai_modules_select(target_id, state);
    if (RUNNING == *state) {
      if (NULL == result) {
        printf("Module with inserted ID doesn't appear in the database.\n");
      } else {
        print_ai_module(*result);
      }
    }
    free(result);
  }
}

void ai_modules_insert_query(int *state) {
  ai_module new_module = input_ai_module(state);
  int result = ai_modules_insert(&new_module, state);
  if (RUNNING == *state) {
    if (0 == result) {
      printf("Database already has an AI module with that ID.\n");
    } else {
      printf("New AI module was successfully inserted into database!\n");
    }
  }
}

void ai_modules_update_query(int *state) {
  int target_id = 0;
  ai_module updated_module = input_ai_module(state);
  if (RUNNING != *state || !printf("Insert ID of the updated module:\n> ") ||  1 != scanf("%d", &target_id)) {
    *state = ERROR;
  } else {
    int result = ai_modules_update(target_id, &updated_module, state);
    if (RUNNING == *state) {
      if (2 == result) {
        printf("Module with inserted old ID doesn't appear in the database.\n");
      } else if (1 == result) {
        printf("Module with inserted new ID is already in the database and doesn't"
               " match with the old one.\n");
      } else {
        printf("The memory level was successfully updated!\n");
      }
    }
  }
}

void ai_modules_delete_query(int *state) {
  int target_id = 0;
  printf("Insert ID of the deleted module:\n> ");
  if (1 != scanf("%d", &target_id)) {
    *state = ERROR;
  } else {
    int result = ai_modules_delete(target_id, state);
    if (RUNNING == *state) {
      if (0 == result) {
        printf("Module with inserted ID doesn't appear in the database.\n");
      } else {
        printf("The module was successfully deleted!\n");
      }
    }
  }
}

void ai_modules_all_query(int *state) {
  FILE *db = NULL;
  if (NULL == (db = fopen("../materials/master_modules.db", "rb"))) {
    *state = ERROR;
  } else {
    rewind(db);
    while (!feof(db)) {
      ai_module cur_module = {0};
      fread(&cur_module, sizeof(ai_module), 1, db);
      if (!feof(db)) {
        print_ai_module(cur_module);
      }
    }
    fclose(db);
  }
}

void print_ai_module(ai_module printed_module) {
  printf("  %d %s %d %d %d\n", printed_module.id, printed_module.name,
      printed_module.module_level, printed_module.cell, printed_module.deletion_flag);
}

ai_module input_ai_module(int *state) {
  ai_module new_module = {0};
  printf("Insert new module ID:\n> ");
  if (1 != scanf("%d", &(new_module.id))) {
    *state = ERROR;
  } else if (!printf("Insert new module name:\n> ") ||  !clean_stdin()\
              || NULL == fgets(new_module.name, 30, stdin)) {
    *state = ERROR;
  } else if (!printf("Insert new module memory level:\n> ") \
              || 1 != scanf("%d", &(new_module.module_level))) {
    *state = ERROR;
  } else if (!printf("Insert new module memory cell:\n> ") || !clean_stdin()\
              || 1 != scanf("%d", &(new_module.cell)) || !clean_stdin()) {
    *state = ERROR;
  }
  new_module.name[strcspn(new_module.name, "\n")] = 0;
  new_module.deletion_flag = 0;
  return new_module;
}
