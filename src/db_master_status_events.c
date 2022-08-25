#include "db_master_status_events.h"

status_event *status_events_select(int id, int *state) {
  FILE *db = NULL;
  status_event *selected = NULL;
  if (NULL == (db = fopen("../materials/master_status_events.db", "r+b"))) {
    *state = ERROR;
  } else {
    FILE *indices = NULL;
    if (NULL == (indices = fopen("../materials/status_events_indices.db", "r+b"))) {
      *state = ERROR;
    } else {
      selected = select(db, indices, id, sizeof(status_event));
      fclose(indices);
    }
    fclose(db);
  }
  return selected;
}

int status_events_delete(int id, int *state) {
  FILE *db = NULL;
  int result = 0;
  if (NULL == (db = fopen("../materials/master_status_events.db", "r+b"))) {
    *state = ERROR;
  } else {
    FILE *indices = NULL;
    if (NULL == (indices = fopen("../materials/status_events_indices.db", "r+b"))) {
      *state = ERROR;
    } else {
      result = delete(db, indices, id, sizeof(status_event));
      fclose(indices);
    }
    fclose(db);
  }
  return result;
}

int status_events_insert(status_event *new_status_event, int *state) {
  FILE *db = NULL;
  int result = 0;
  if (NULL == (db = fopen("../materials/master_status_events.db", "r+b"))) {
    *state = ERROR;
  } else {
    FILE *indices = NULL;
    if (NULL == (indices = fopen("../materials/status_events_indices.db", "r+b"))) {
      *state = ERROR;
    } else {
      result = insert(db, indices, new_status_event, sizeof(status_event));
      fclose(indices);
    }
    fclose(db);
  }
  return result;
}

int status_events_update(int id, status_event *updated_status_event, int *state) {
  FILE *db = NULL;
  int result = 0;
  if (NULL == (db = fopen("../materials/master_status_events.db", "r+b"))) {
    *state = ERROR;
  } else {
    FILE *indices = NULL;
    if (NULL == (indices = fopen("../materials/status_events_indices.db", "r+b"))) {
      *state = ERROR;
    } else {
      result = update(db, indices, id, updated_status_event, sizeof(status_event));
      fclose(indices);
    }
    fclose(db);
  }
  return result;
}

void status_events_select_query(int *state) {
  int target_id = 0;
  printf("Insert ID of the selected event:\n> ");
  if (1 != scanf("%d", &target_id)) {
    *state = ERROR;
  } else {
    status_event *result = status_events_select(target_id, state);
    if (RUNNING == *state) {
      if (NULL == result) {
        printf("Event with inserted ID doesn't appear in the database.\n");
      } else {
        print_status_event(*result);
      }
    }
    free(result);
  }
}

void status_events_insert_query(int *state) {
  status_event new_event = input_status_event(state);
  int result = status_events_insert(&new_event, state);
  if (RUNNING == *state) {
    if (0 == result) {
      printf("Database already has an status event with that ID.\n");
    } else {
      printf("New status event was successfully inserted into database!\n");
    }
  }
}

void status_events_update_query(int *state) {
  int target_id = 0;
  status_event updated_event = input_status_event(state);
  if (RUNNING != *state || !printf("Insert ID of the updated event:\n> ") ||  1 != scanf("%d", &target_id)) {
    *state = ERROR;
  } else {
    int result = status_events_update(target_id, &updated_event, state);
    if (RUNNING == *state) {
      if (1 == result) {
        printf("Event with inserted ID doesn't appear in the database.\n");
      } else if (2 == result) {
        printf("Event with inserted ID is already in the database and doesn't"
               " match with the old one.\n");
      } else {
        printf("The memory level was successfully updated!\n");
      }
    }
  }
}

void status_events_delete_query(int *state) {
  int target_id = 0;
  printf("Insert ID of the deleted event:\n> ");
  if (1 != scanf("%d", &target_id)) {
    *state = ERROR;
  } else {
    int result = status_events_delete(target_id, state);
    if (RUNNING == *state) {
      if (0 == result) {
        printf("Event with inserted ID doesn't appear in the database.\n");
      } else {
        printf("The status event was successfully deleted!\n");
      }
    }
  }
}

void status_events_all_query(int *state) {
  FILE *db = NULL;
  if (NULL == (db = fopen("../materials/master_status_events.db", "rb"))) {
    *state = ERROR;
  } else {
    rewind(db);
    while (!feof(db)) {
      status_event cur_event = {0};
      fread(&cur_event, sizeof(status_event), 1, db);
      if (!feof(db)) {
        print_status_event(cur_event);
      }
    }
    fclose(db);
  }
}

void print_status_event(status_event printed_event) {
  printf("  %d %d %d %s %s\n", printed_event.id, printed_event.module_id,
                     printed_event.new_status, printed_event.date, printed_event.time);
}

status_event input_status_event(int *state) {
  status_event new_event = {0};
  printf("Insert new event ID:\n> ");
  if (1 != scanf("%d", &(new_event.id))) {
    *state = ERROR;
  } else if (!printf("Insert new event module ID:\n> ") ||  !clean_stdin()\
             || 1 != scanf("%d", &(new_event.module_id))) {
    *state = ERROR;
  } else if (!printf("Insert new event module status:\n> ") || !clean_stdin()\
             || 1 != scanf("%d", &(new_event.new_status)) || !clean_stdin()) {
    *state = ERROR;
  }
  time_t cur_seconds = time(NULL);
  struct tm *cur_time = localtime(&cur_seconds);
  strftime(new_event.date, 11, "%d.%m.%Y", cur_time);
  strftime(new_event.time, 8, "%H:%M:%S", cur_time);
  return new_event;
}
