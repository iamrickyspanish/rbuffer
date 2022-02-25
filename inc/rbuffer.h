#ifndef __R_BUFFER_H
#define __R_BUFFER_H

#include <stddef.h>
#include <stdbool.h>

typedef struct {
    void* buffer;
    void* start;
    void* end;
    size_t count;
    size_t size;
} cbuffer_t;

cbuffer_t cbuffer_create(void*, int, size_t);

bool cbuffer_available(const cbuffer_t*);

void* cbuffer_shift(cbuffer_t*);

size_t cbuffer_length(const cbuffer_t*);

void cbuffer_push(cbuffer_t*, void*);

void cbuffer_reset(cbuffer_t*);

void* cbuffer_at(const cbuffer_t*, size_t);

#endif