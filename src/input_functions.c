#include "input_functions.h"

int clean_stdin(void) {
  while (getchar() != '\n') {}
  return 1;
}

int get_option(int limit, int *state) {
  int option = -1;
  if (RUNNING == *state) {
    if (1 != scanf("%d", &option) || option <= 0 || option > limit) {
      *state = ERROR;
    }
  }
  clean_stdin();
  return option;
}

int choose_table(int *state) {
  printf(TABLE_CHOOSE_MESSAGE);
  int table_number = get_option(3, state);
  return table_number;
}

int input(int *option) {
  int state = RUNNING;
  printf(INSTRUCTION_MESSAGE);
  *option = get_option(11, &state);
  if (0 == *option) {
    state = OFF;
  }
  return state;
}

void all_files_initialization(int *state) {
  FILE *modules_db = NULL;
  FILE *levels_db = NULL;
  FILE *status_db = NULL;
  FILE *modules_indices = NULL;
  FILE *levels_indices = NULL;
  FILE *status_indices = NULL;
  if (NULL == (modules_db = fopen("../materials/master_modules.db", "r+b"))) {
    *state = OFF;
  } else if (NULL == (levels_db = fopen("../materials/master_levels.db", "r+b"))) {
    *state = OFF;
  } else if (NULL == (status_db = fopen("../materials/master_status_events.db", "r+b"))) {
    *state = OFF;
  } else if (NULL == (modules_indices = fopen("../materials/modules_indices.db", "w+b"))) {
    *state = OFF;
  } else if (NULL == (levels_indices = fopen("../materials/levels_indices.db", "w+b"))) {
    *state = OFF;
  } else if (NULL == (status_indices = fopen("../materials/status_events_indices.db", "w+b"))) {
    *state = OFF;
  } else {
    init_indices(modules_db, sizeof(ai_module), modules_indices);
    init_indices(levels_db, sizeof(level), levels_indices);
    init_indices(status_db, sizeof(status_event), status_indices);
  }
  if (RUNNING != *state) {
    printf("CRITICAL ERROR! CANNOT OPEN DATABASE FILE! CLOSING!!!\n");
  }
  close_files(modules_db, levels_db, status_db, modules_indices, levels_indices, status_indices);
}

void close_files(FILE *modules_db, FILE *levels_db, FILE *status_db,
                 FILE *modules_indices, FILE *levels_indices, FILE *status_indices) {
  if (NULL != modules_db) {
    fclose(modules_db);
  }
  if (NULL != levels_db) {
    fclose(levels_db);
  }
  if (NULL != status_db) {
    fclose(status_db);
  }
  if (NULL != modules_indices) {
    fclose(modules_indices);
  }
  if (NULL != levels_indices) {
    fclose(levels_indices);
  }
  if (NULL != status_indices) {
    fclose(status_indices);
  }
}





