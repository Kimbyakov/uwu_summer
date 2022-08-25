#ifndef SRC_DB_MASTER_LEVELS_H_
#define SRC_DB_MASTER_LEVELS_H_
#include "db_structs.h"
#include "database.h"
#include "definitions.h"
#include "input_functions.h"
#include "indices.h"

level *levels_select(int id, int *state);
int levels_delete(int id, int *state);
int levels_insert(level *new_level, int *state);
int levels_update(int id, level *updated_level, int *state);
void levels_select_query(int *state);
void levels_insert_query(int *state);
void levels_update_query(int *state);
void levels_delete_query(int *state);
void levels_all_query(int *state);
void print_level(level printed_level);
level input_level(int *state);

#endif  // SRC_DB_MASTER_LEVELS_H_

