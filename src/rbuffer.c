#include "rbuffer.h"

cbuffer_t cbuffer_create(void* buffer, int buffersize, size_t typesize)
{
    const void* arena = malloc(buffersize*typesize);
    cbuffer_t cbuffer = {
        .buffer = buffer,
        .start = arena,
        .end = arena,
        .count = 0,
        .size = buffersize
    };
    return cbuffer;
};

static size_t cbuffer_get_next_buffer_position(cbuffer_t* cbuffer, size_t position)
{
    bool overflow = (position + 1) >= cbuffer->size;
    return (overflow) ? 0 : position + 1;
};

void cbuffer_push(cbuffer_t* cbuffer, void* elm)
{
    if (cbuffer->count == cbuffer->size) {
        size_t pos = cbuffer_get_next_buffer_position(cbuffer, cbuffer->start);
        // memcpy(S->top, data, S->typesize);
        // S->top = (void*)( (int)S->top + S->typesize );
        cbuffer->start = cbuffer_get_next_buffer_position(cbuffer, cbuffer->start);
    } else
        cbuffer->count++;
    cbuffer->buffer[cbuffer->end] = elm;
    cbuffer->end = cbuffer_get_next_buffer_position(cbuffer, cbuffer->end);
};

void* cbuffer_shift(cbuffer_t* cbuffer)
{
    void* elm = &cbuffer->buffer[cbuffer->start];
    if (cbuffer->count > 0)
    {
        cbuffer->start = cbuffer_get_next_buffer_position(cbuffer->start);
        cbuffer->count--;
    }
    return elm;
};

bool cbuffer_t_available(const cbuffer_t* cbuffer)
{
    return cbuffer->count > 0;
};


size_t cbuffer_size(const cbuffer_t* cbuffer)
{
    return cbuffer->count;
};

void cbuffer_reset(cbuffer_t* cbuffer) {
    cbuffer->start = cbuffer->end;
}

void* cbuffer_at(const cbuffer_t* cbuffer, size_t position) {
    void* elm = &cbuffer->buffer[position];
    return elm;
}
