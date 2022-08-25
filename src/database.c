#include "database.h"

void *select(FILE *db, FILE *indices, int id, size_t struct_size) {
  void *result = malloc(struct_size);
  int shift = 0; id_index select_index = index_binary_search(id, &shift, indices);
  if (-1 == select_index.db_pos) {
    free(result);
    result = NULL;
  } else {
    fseek(db, shift * struct_size, SEEK_SET);
    fread(result, struct_size, 1, db);
  }
  return result;
}

int delete(FILE *db, FILE *indices, int id, size_t struct_size) {
  fseek(db, 0, SEEK_END);
  int size = ftell(db) / struct_size;
  void *cur_entity = malloc(struct_size);
  int found_target = 0;
  FILE *temp = fopen("tempusfrempus.tmp", "w+b");
  for (int i = 0; i < size; i++) {
    fseek(db, i * struct_size, SEEK_SET);
    fseek(temp, (i - found_target) * struct_size, SEEK_SET);
    fread(cur_entity, struct_size, 1, db);
    if (*(int*)(cur_entity) == id) {
      found_target = 1;
    } else {
      fwrite(cur_entity, struct_size, 1, temp);
    }
  }
  if (found_target) {
    db = freopen(NULL, "wb", db);
    rewind(db);
    rewind(temp);
    for (int i = 0; i < size - 1; i++) {
      fseek(db, i * struct_size, SEEK_SET);
      fseek(temp, i * struct_size, SEEK_SET);
      fread(cur_entity, struct_size, 1, temp);
      fwrite(cur_entity, struct_size, 1, db);
    }
    db = freopen(NULL, "r+b", db);
    rewind(db);
    delete_from_index(id, indices);
  }
  fclose(temp);
  free(cur_entity);
  remove("tempusfrempus.tmp");
  return found_target;
}

int insert(FILE *db, FILE *indices, void *entity, size_t struct_size) {
  int desired_id = *(int*)entity;
  id_index found_index = index_binary_search(desired_id, NULL, indices);
  if (-1 == found_index.db_pos) {
    fseek(db, 0, SEEK_END);
    fwrite(entity, struct_size, 1, db);
    insert_into_index(desired_id, ftell(db) / struct_size - 1, indices);
  }
  return -1 == found_index.db_pos;
}

int update(FILE *db, FILE *indices, int id, void *entity, size_t struct_size) {
  int new_id = *(int*)entity;
  int shift = 0;
  id_index new_id_index = index_binary_search(new_id, NULL, indices);
  id_index updated_index = index_binary_search(id, &shift, indices);
  if (-1 == new_id_index.db_pos || (new_id == id && -1 != updated_index.db_pos)) {
    fseek(db, shift * struct_size, SEEK_SET);
    fwrite(entity, struct_size, 1, db);
    update_index(updated_index.id, updated_index.db_pos, indices);
  }
  return (2 * (-1 == updated_index.id)) |\
       (-1 != new_id_index.id && new_id_index.id != updated_index.id);
}
