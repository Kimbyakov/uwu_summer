#ifndef SRC_SHARED_H_
#define SRC_SHARED_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "db_master_modules.h"
#include "db_master_levels.h"
#include "db_master_status_events.h"
#include "definitions.h"
#include "input_functions.h"

void non_aggregative_query(int *state, void (*ai_modules_query)(int*),
                    void (*levels_query)(int*), void (*status_events_query)(int*));
void active_modules_query(int *state);
void memlevel_modules_query(int *state);
void set_protected_module_query(int *state);
void move_module_query(int *state);
void set_protected_level_query(int *state);
void to_protected_mode_events(int module_id, FILE *status_db);
int find_module_status(ai_module cur_module, FILE *status_db);
int find_max_status_id(int size, FILE *status_db);
void save_the_world(int *state);
void turn_off_additional_modules(FILE *module_db, FILE *status_db);
void set_deletion_flags(FILE *module_db);
int move_main_module(FILE *module_db, FILE *level_db);

#endif  // SRC_SHARED_H_
