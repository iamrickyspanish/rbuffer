#ifndef __R_BUFFER_H
#define __R_BUFFER_H

#include <stddef.h>
#include <stdbool.h>

typedef struct {
    size_t start;
    size_t end;
    size_t size;
    size_t capacity;
    size_t typesize;
    unsigned char buffer[];
} cbuffer_t;

typedef cbuffer_t* cbuffer;

cbuffer_t* cbuffer_create(size_t capacity, size_t typesize);

bool cbuffer_available(const cbuffer_t*);

int cbuffer_shift(cbuffer_t*, void*);

void cbuffer_push(cbuffer_t*, const void*);

void cbuffer_reset(cbuffer_t*);

//int cbuffer_at(const cbuffer_t*, size_t, void*);

size_t cbuffer_size(const cbuffer_t*);

#endif
