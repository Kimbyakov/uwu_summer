#ifndef SRC_DATABASE_H_
#define SRC_DATABASE_H_
#include <stdio.h>
#include <stdlib.h>
#include "indices.h"


//////////////////////////////////////////////////////
void *select(FILE *db, FILE *indices, int id, size_t struct_size);
int delete(FILE *db, FILE *indices, int id, size_t struct_size);
int insert(FILE *db, FILE *indices, void *entity, size_t struct_size);
int update(FILE *db, FILE *indices, int id, void *entity, size_t struct_size);
//////////////////////////////////////////////////////

#endif  // SRC_DATABASE_H_
