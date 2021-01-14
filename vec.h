/*
 * vec.h
 */
#include <time.h>
typedef long data_t;

/* Create abstract date type for vector */
typedef struct {
  long length;
  data_t *data;
} vec_rec, *vec_ptr;

vec_ptr new_vec(long length);
int get_vec_element(vec_ptr v, long index, data_t *dest);
data_t* get_vec_start(vec_ptr v);
long vec_length(vec_ptr v);
void set_vec_start(vec_ptr v, data_t *data);

