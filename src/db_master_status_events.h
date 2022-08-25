#ifndef SRC_DB_MASTER_STATUS_EVENTS_H_
#define SRC_DB_MASTER_STATUS_EVENTS_H_
#include "db_structs.h"
#include <time.h>
#include "database.h"
#include "definitions.h"
#include "input_functions.h"
#include "indices.h"

status_event *status_events_select(int id, int *state);
int status_events_delete(int id, int *state);
int status_events_insert(status_event *new_status_event, int *state);
int status_events_update(int id, status_event *updated_status_event, int *state);
void status_events_select_query(int *state);
void status_events_insert_query(int *state);
void status_events_update_query(int *state);
void status_events_delete_query(int *state);
void status_events_all_query(int *state);
void print_status_event(status_event printed_event);
status_event input_status_event(int *state);

#endif  // SRC_DB_MASTER_STATUS_EVENTS_H_

