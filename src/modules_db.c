#include "db_master_modules.h"
#include "db_master_levels.h"
#include "db_master_status_events.h"
#include "shared.h"
#include "definitions.h"

void execute_query(int option, int *state);

int main(void) {
  int state = RUNNING;
  int option = 0;
  all_files_initialization(&state);
  while (OFF != state) {
    if (RUNNING == state) {
      state = input(&option);
      execute_query(option, &state);
    }
    if (ERROR == state) {
      printf("An error occured! Continuing...\n");
      state = RUNNING;
    }
  }
  return 0;
}

void execute_query(int option, int *state) {
  if (1 == option) {
    non_aggregative_query(state, ai_modules_select_query, levels_select_query, status_events_select_query);
  } else if (2 == option) {
    non_aggregative_query(state, ai_modules_insert_query, levels_insert_query, status_events_insert_query);
  } else if (3 == option) {
    non_aggregative_query(state, ai_modules_update_query, levels_update_query, status_events_update_query);
  } else if (4 == option) {
    non_aggregative_query(state, ai_modules_delete_query, levels_delete_query, status_events_delete_query);
  } else if (5 == option) {
    non_aggregative_query(state, ai_modules_all_query, levels_all_query, status_events_all_query);
  } else if (6 == option) {
    active_modules_query(state);
  } else if (7 == option) {
    memlevel_modules_query(state);
  } else if (8 == option) {
    set_protected_module_query(state);
  } else if (9 == option) {
    move_module_query(state);
  } else if (10 == option) {
    set_protected_level_query(state);
  } else if (11 == option) {
    save_the_world(state);
  }
}

