#ifndef SRC_DB_STRUCTS_H_
#define SRC_DB_STRUCTS_H_

typedef struct ai_module {
  int id;
  char name[30];
  int module_level;
  int cell;
  int deletion_flag;
} ai_module;

typedef struct level {
  int id;
  int cells_amount;
  int protection_flag;
} level;

typedef struct status_event {
  int id;
  int module_id;
  int new_status;
  char date[11];
  char time[8];
} status_event;

#endif  // SRC_DB_STRUCTS_H_
