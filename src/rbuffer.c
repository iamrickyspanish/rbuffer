#include "rbuffer.h"
#include <stdlib.h>
#include <string.h>

cbuffer_t* cbuffer_create(size_t capacity, size_t typesize)
{
    cbuffer_t *cb = malloc(sizeof(*cb)+capacity*typesize);
 
    if (cb) {
        	cb -> start = 0;
        	cb -> end = 0;
	        cb -> size = 0;
        	cb -> capacity = capacity;
		cb -> typesize = typesize;
    }
   
    return cb;
};

static size_t cbuffer_get_next_buffer_position(cbuffer_t* cb, size_t position)
{
    return ((position + 1) >= cb->capacity) ? 0 : position + 1;
};

void cbuffer_push(cbuffer_t* cb, const void* elm)
{
    if (cb->size == cb->capacity) {
        cb->start = cbuffer_get_next_buffer_position(cb, cb->start);
    } else   
	cb->size++;
    memcpy(cb->buffer + cb->end*cb->typesize, elm, cb->typesize);
    cb->end = cbuffer_get_next_buffer_position(cb, cb->end); 
};

int cbuffer_shift(cbuffer_t* cb, void* elm)
{
    memcpy(elm, cb->buffer + cb->start*cb->typesize, cb->typesize);
    if (cb->size > 0)
    {
        cb->start = cbuffer_get_next_buffer_position(cb, cb->start);
        cb->size--;
    }
    return 0;
};

bool cbuffer_available(const cbuffer_t* cb)
{
    return cb->size > 0;
};


size_t cbuffer_size(const cbuffer_t* cb)
{
    return cb->size;
};

void cbuffer_reset(cbuffer_t* cb) {
    cb->start = cb->end;
}

//int cbuffer_at(const cbuffer_t* cb, size_t position, void* elm) {
//    memcpy(elm, cb->buffer + cb->start*cb->typesize, cb->typesize);
//    return 0;
//}
