#ifndef SRC_INPUT_FUNCTIONS_H_
#define SRC_INPUT_FUNCTIONS_H_
#include <stdio.h>
#include "definitions.h"
#include "indices.h"

int clean_stdin(void);
int get_option(int limit, int *state);
int choose_table(int *state);
int input(int *option);
void all_files_initialization(int *state);
void close_files(FILE *modules_db, FILE *levels_db, FILE *status_db,
                   FILE *modules_indices, FILE *levels_indices, FILE *status_indices);

#endif  // SRC_INPUT_FUNCTIONS_H_
