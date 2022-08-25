#include "indices.h"



void init_indices(FILE *db, size_t struct_size, FILE *index_file) {
  fseek(db, 0, SEEK_END);
  int size = ftell(db) / struct_size;
  for (int i = 0; i < size; i++) {
    id_index cur_id = {.id = 0, .db_pos = i};
    fseek(db, i * struct_size, SEEK_SET);
    fread(&(cur_id.id), sizeof(int), 1, db);
    fseek(index_file, i * sizeof(id_index), SEEK_SET);
    fwrite(&cur_id, sizeof(id_index), 1, index_file);
  }
  index_initial_sort(0, size - 1, index_file);
}

void index_initial_sort(int begin, int end, FILE *index_file) {
  int left = begin;
  id_index left_index = {0};
  fseek(index_file, left * sizeof(id_index), SEEK_SET);
  fread(&left_index, sizeof(id_index), 1, index_file);
  int right = end;
  id_index right_index = {0};
  fseek(index_file, right * sizeof(id_index), SEEK_SET);
  fread(&right_index, sizeof(id_index), 1, index_file);
  id_index pivot_index = {0};
  fseek(index_file, sizeof(id_index) * (left + right) / 2, SEEK_SET);
  fread(&pivot_index, sizeof(id_index), 1, index_file);
  while (left <= right) {
    while (left_index.id < pivot_index.id && left < end) {
      left++;
      fseek(index_file, left * sizeof(id_index), SEEK_SET);
      fread(&left_index, sizeof(id_index), 1, index_file);
    }
    while (right_index.id > pivot_index.id && right > begin) {
      right--;
      fseek(index_file, right * sizeof(id_index), SEEK_SET);
      fread(&right_index, sizeof(id_index), 1, index_file);
    }
    if (left <= right) {
      swap_indices(left, right, &left_index, &right_index, index_file);
      left++;
      right--;
    }
  }
  if (begin < right) {
    index_initial_sort(begin, right, index_file);
  }
  if (end > left) {
    index_initial_sort(left, end, index_file);
  }
}

void swap_indices(int left, int right, id_index *left_index, id_index *right_index, FILE *index_file) {
  id_index temp = *left_index;
  fseek(index_file, left * sizeof(id_index), SEEK_SET);
  fwrite(right_index, sizeof(id_index), 1, index_file);
  *left_index = *right_index;
  fseek(index_file, right * sizeof(id_index), SEEK_SET);
  fwrite(&temp, sizeof(id_index), 1, index_file);
  *right_index = temp;
}

id_index index_binary_search(int id, int *shift, FILE *index_file) {
  fseek(index_file, 0, SEEK_END);
  int left = 0;
  int right = ftell(index_file) / sizeof(id_index);
  id_index found_index = {.db_pos = -1};
  while (left <= right && -1 == found_index.db_pos) {
    int middle = (left + right) / 2;
    id_index middle_index;
    fseek(index_file, middle * sizeof(id_index), SEEK_SET);
    fread(&middle_index, sizeof(id_index), 1, index_file);
    if (middle_index.id == id) {
      found_index = middle_index;
      if (NULL != shift) {
        *shift = middle;
      }
    } else if (middle_index.id < id) {
      left = middle + 1;
    } else {
      right = middle - 1;
    }
  }
  return found_index;
}

void insert_into_index(int id, int pos, FILE *index_file) {
  fseek(index_file, 0, SEEK_END);
  int i = ftell(index_file) / sizeof(id_index);
  id_index new_index = {.id = id, .db_pos = pos};
  fwrite(&new_index, sizeof(id_index), 1, index_file);
  id_index prev_index;
  if (i > 0) {
    fseek(index_file, (i - 1) * sizeof(id_index), SEEK_SET);
    fread(&prev_index, sizeof(id_index), 1, index_file);
    while (i > 0 && prev_index.id > new_index.id) {
      swap_indices(i - 1, i, &prev_index, &new_index, index_file);
      new_index = prev_index;
      fseek(index_file, -1, SEEK_CUR);
      fread(&prev_index, sizeof(id_index), 1, index_file);
      i--;
    }
  }
}

void delete_from_index(int id, FILE *index_file) {
  FILE *tmpfile = fopen("tempotempoindekususamadesu.tmp", "w+b");
  fseek(index_file, 0, SEEK_END);
  int size = ftell(index_file) / sizeof(id_index);
  int found_target = 0;
  for (int i = 0; i < size; i++) {
    id_index cur_index = {0};
    fseek(index_file, i * sizeof(id_index), SEEK_SET);
    fread(&cur_index, sizeof(id_index), 1, index_file);
    if (cur_index.id != id) {
      fwrite(&cur_index, sizeof(id_index), 1, tmpfile);
    } else {
      found_target = 1;
    }
  }
  if (found_target) {
    index_file = freopen(NULL, "wb", index_file);
    rewind(tmpfile);
    for (int i = 0; i < size - 1; i++) {
      id_index cur_index = {0};
      fread(&cur_index, sizeof(id_index), 1, tmpfile);
      fwrite(&cur_index, sizeof(id_index), 1, index_file);
    }
    index_file = freopen(NULL, "r+b", index_file);
    rewind(index_file);
  }
  fclose(tmpfile);
  remove("tempotempoindekususamadesu.tmp");
}

void update_index(int id, int pos, FILE *index_file) {
  int shift = 0;
  id_index updated_index = index_binary_search(id, &shift, index_file);
  updated_index.db_pos = pos;
  fseek(index_file, shift * sizeof(id_index), SEEK_SET);
  fwrite(&updated_index, sizeof(id_index), 1, index_file);
}

