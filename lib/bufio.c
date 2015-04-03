//
// Created by shambala on 03.04.15.
//
#include <stdlib.h>
#include "bufio.h"

#ifdef DEBUG
#define abort(condition) if (condition) {abort();}
#else
#define abort(condition)
#endif

struct buf {
    size_t capacity;
    size_t size;

    void* data;
};

struct buf *buf_new(size_t cap) {
    struct buf* new_buf = (struct buf*) malloc(sizeof(struct buf) + capacity);
    if (new_buf==NULL) {
        return new_buf;
    }
    new_buf->data = (void*) sizeof(new_buf) + cap;
    new_buf->capacity = cap;
    new_buf->size = 0;
    return new_buf;
}

void buf_free(struct buf *b) {
    abort(b==NULL);
    free(b);
}

size_t buf_capacity(struct buf *b) {
    abort(b==NULL);
    return b->capacity;
}

size_t buf_size(struct buf *b) {
    abort(b==NULL);
    return b->size;
}

