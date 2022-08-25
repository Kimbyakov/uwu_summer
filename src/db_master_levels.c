#include "db_master_levels.h"

level *levels_select(int id, int *state) {
  FILE *db = NULL;
  level *selected = NULL;
  if (NULL == (db = fopen("../materials/master_levels.db", "r+b"))) {
    *state = ERROR;
  } else {
    FILE *indices = NULL;
    if (NULL == (indices = fopen("../materials/levels_indices.db", "r+b"))) {
      *state = ERROR;
    } else {
      selected = select(db, indices, id, sizeof(level));
      fclose(indices);
    }
    fclose(db);
  }
  return selected;
}

int levels_delete(int id, int *state) {
  FILE *db = NULL;
  int result = 0;
  if (NULL == (db = fopen("../materials/master_levels.db", "r+b"))) {
    *state = ERROR;
  } else {
    FILE *indices = NULL;
    if (NULL == (indices = fopen("../materials/levels_indices.db", "r+b"))) {
      *state = ERROR;
    } else {
      result = delete(db, indices, id, sizeof(level));
      fclose(indices);
    }
    fclose(db);
  }
  return result;
}

int levels_insert(level *new_level, int *state) {
  FILE *db = NULL;
  int result = 0;
  if (NULL == (db = fopen("../materials/master_levels.db", "r+b"))) {
    *state = ERROR;
  } else {
    FILE *indices = NULL;
    if (NULL == (indices = fopen("../materials/levels_indices.db", "r+b"))) {
      *state = ERROR;
    } else {
      result = insert(db, indices, new_level, sizeof(level));
      fclose(indices);
    }
    fclose(db);
  }
  return result;
}

int levels_update(int id, level *updated_level, int *state) {
  FILE *db = NULL;
  int result = 0;
  if (NULL == (db = fopen("../materials/master_levels.db", "r+b"))) {
    *state = ERROR;
  } else {
    FILE *indices = NULL;
    if (NULL == (indices = fopen("../materials/levels_indices.db", "r+b"))) {
      *state = ERROR;
    } else {
      result = update(db, indices, id, updated_level, sizeof(level));
      fclose(indices);
    }
    fclose(db);
  }
  return result;
}

void levels_select_query(int *state) {
  int target_id = 0;
  printf("Insert number of the selected memory level:\n> ");
  if (1 != scanf("%d", &target_id)) {
    *state = ERROR;
  } else {
    level *result = levels_select(target_id, state);
    if (RUNNING == *state) {
      if (NULL == result) {
        printf("Level with inserted number doesn't appear in the database.\n");
      } else {
        print_level(*result);
      }
    }
    free(result);
  }
}

void levels_insert_query(int *state) {
  level new_level = input_level(state);
  int result = levels_insert(&new_level, state);
  if (RUNNING == *state) {
    if (0 == result) {
      printf("Database already has a memory level with that number.\n");
    } else {
      printf("New memory level was successfully inserted into database!\n");
    }
  }
}

void levels_update_query(int *state) {
  int target_id = 0;
  level updated_level = input_level(state);
  if (RUNNING != *state || !printf("Insert number of the updated memory level:\n> ")\
        ||  1 != scanf("%d", &target_id)) {
    *state = ERROR;
  } else {
    int result = levels_update(target_id, &updated_level, state);
    if (RUNNING == *state) {
      if (1 == result) {
        printf("Memory level with inserted number doesn't appear in the database.\n");
      } else if (2 == result) {
        printf("Memory level with inserted number is already in the database and doesn't"
               " match with the old one.\n");
      } else {
        printf("The memory level was successfully updated!\n");
      }
    }
  }
}

void levels_delete_query(int *state) {
  int target_id = 0;
  printf("Insert number of the deleted memory level:\n> ");
  if (1 != scanf("%d", &target_id)) {
    *state = ERROR;
  } else {
    int result = levels_delete(target_id, state);
    if (RUNNING == *state) {
      if (0 == result) {
        printf("Memory level with inserted ID doesn't appear in the database.\n");
      } else {
        printf("The memory level was successfully deleted!\n");
      }
    }
  }
}

void levels_all_query(int *state) {
  FILE *db = NULL;
  if (NULL == (db = fopen("../materials/master_levels.db", "rb"))) {
    *state = ERROR;
  } else {
    rewind(db);
    while (!feof(db)) {
      level cur_level = {0};
      fread(&cur_level, sizeof(level), 1, db);
      if (!feof(db)) {
        print_level(cur_level);
      }
    }
    fclose(db);
  }
}

void print_level(level printed_level) {
  printf("  %d %d %d\n", printed_level.id, printed_level.cells_amount, printed_level.protection_flag);
}

level input_level(int *state) {
  level new_level = {0};
  printf("Insert new memory level number:\n> ");
  if (1 != scanf("%d", &(new_level.id))) {
    *state = ERROR;
  } else if (!printf("Insert new memory level cells amount:\n> ") || !clean_stdin()\
                  || 1 != scanf("%d", &(new_level.cells_amount))) {
    *state = ERROR;
  } else if (!printf("Insert new memory level protection flag:\n> ") || !clean_stdin()\
                  || 1 != scanf("%d", &(new_level.protection_flag)) || !clean_stdin()) {
    *state = ERROR;
  }
  return new_level;
}

