/*
 * vec.c
 */
#include <stdlib.h>
#include "./vec.h"

/* Create vector of specific length */
vec_ptr new_vec(long length) {
    vec_ptr vec = (vec_ptr)malloc(sizeof(vec_rec));

    // srand((unsigned int)time(NULL));
    vec->data = malloc(length * sizeof(data_t));
    
    if (!vec->data)
        return 0;

    for (unsigned long i = 0; i < length; i++)
    {
      (vec->data)[i] = (data_t) i;
      // (vec->data)[i] = (data_t) rand() / (data_t)(RAND_MAX/ 100);
    }
        

    vec->length = length;
    
    return vec;
}

/*
 * Retrieve vector element and store at dest
 * return 0 (out of bounds) or 1 (successful)
 */
int get_vec_element(vec_ptr v, long index, data_t *dest) {
  if (index < 0 || index >= v->length) {
    return 0;
  }
  *dest = v->data[index];
  return 1;
}

/* return length of vector */
long vec_length(vec_ptr v) {
  return v->length;
}

/* expose data */
data_t* get_vec_start(vec_ptr v) {
  return v->data;
}

/* set data */
void set_vec_start(vec_ptr v, data_t *data) {
  v->data = data;
}
