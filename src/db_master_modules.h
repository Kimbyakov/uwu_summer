#ifndef SRC_DB_MASTER_MODULES_H_
#define SRC_DB_MASTER_MODULES_H_
#include "db_structs.h"
#include <string.h>
#include "database.h"
#include "definitions.h"
#include "input_functions.h"
#include "indices.h"

ai_module *ai_modules_select(int id, int *state);
int ai_modules_delete(int id, int *state);
int ai_modules_update(int id, ai_module *updated_ai_module, int *state);
int ai_modules_insert(ai_module *new_ai_module, int *state);
void ai_modules_select_query(int *state);
void ai_modules_insert_query(int *state);
void ai_modules_update_query(int *state);
void ai_modules_delete_query(int *state);
void ai_modules_all_query(int *state);
void print_ai_module(ai_module printed_module);
ai_module input_ai_module(int *state);



#endif  // SRC_DB_MASTER_MODULES_H_

