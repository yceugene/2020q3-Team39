/*
 * 5.13.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "vec.h"

#define OP *

void inner1(vec_ptr u, vec_ptr v, data_t *dest) {
    long i;

    for (i = 0; i < vec_length(u); i++) {
        data_t udata;
        get_vec_element(u, i, &udata);
        data_t vdata;
        get_vec_element(u, i, &vdata);
        *dest += udata OP vdata;
    }
}

void inner2(vec_ptr u, vec_ptr v, data_t *dest) {
    data_t i;
    data_t length = vec_length(u);

    for (i = 0; i < length; i++) {
        data_t udata;
        get_vec_element(u, i, &udata);
        data_t vdata;
        get_vec_element(u, i, &vdata);
        *dest += udata OP vdata;
    }
}

void inner3(vec_ptr u, vec_ptr v, data_t *dest) {
    data_t i;
    data_t length = vec_length(u);
    data_t *udata = get_vec_start(u);
    data_t *vdata = get_vec_start(v);

    for (i = 0; i < length; i++) {
        *dest += udata[i] OP vdata[i];
    }
}

void inner4(vec_ptr u, vec_ptr v, data_t *dest) {
    data_t i;
    data_t length = vec_length(u);
    data_t *udata = get_vec_start(u);
    data_t *vdata = get_vec_start(v);
    data_t sum = 0;

    for (i = 0; i < length; i++) {
        sum += udata[i] OP vdata[i];
    }
    *dest = sum;
}


/* inner product. accumulate in temporary */
void inner4_t15(vec_ptr u, vec_ptr v, data_t *dest) {
  long i;
  long length = vec_length(u);
  data_t *udata = get_vec_start(u);
  data_t *vdata = get_vec_start(v);
  data_t sum = (data_t) 0;

  for (i = 0; i < length; i++) {
    sum = sum + udata[i] * vdata[i];
  }
  *dest = sum;
}

int main(int argc, char* argv[]) {
    data_t length = 4;
    vec_ptr u = new_vec(length);
    vec_ptr v = new_vec(length);
    data_t *dest = malloc(sizeof(data_t));
    
    *dest = 0;
    inner1( u, v, dest);
    printf("Result of inner1 is: %ld\n", *dest);

    *dest = 0; 
    inner2( u, v, dest);
    printf("Result of inner2 is: %ld\n", *dest);

    *dest = 0; 
    inner3( u, v, dest);
    printf("Result of inner3 is: %ld\n", *dest);

    *dest = 0; 
    inner4( u, v, dest);
    printf("Result of inner4 is: %ld\n", *dest);            

    free(u->data);
    free(v->data);
    free(u);
    free(v);
    free(dest);
    return 0;
}