#ifndef SRC_INDICES_H_
#define SRC_INDICES_H_
#include <stdio.h>
#include "db_structs.h"
#include "input_functions.h"


typedef struct id_index {
  int id;
  int db_pos;
} id_index;

void init_indices(FILE *db, size_t struct_size, FILE *index_file);
void index_initial_sort(int begin, int end, FILE *index_file);
void swap_indices(int left, int right, id_index *left_index, id_index *right_index, FILE *index_file);
id_index index_binary_search(int id, int *shift, FILE *index_file);
void insert_into_index(int id, int pos, FILE *index_file);
void delete_from_index(int id, FILE *index_file);
void update_index(int id, int pos, FILE *index);


#endif  // SRC_INDICES_H_
