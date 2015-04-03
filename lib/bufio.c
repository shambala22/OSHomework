//
// Created by shambala on 03.04.15.
//
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
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
    struct buf* new_buf = (struct buf*) malloc(sizeof(struct buf) + cap);
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

ssize_t buf_fill(int fd, struct buf *b, size_t req) {
    abort(buf == NULL || req > b->capacity);
    int res = 0;
    int count = req - b->size;
    while(1) {
        res = read(fd, b->data + b->size, b->capacity - b->size);
        if (res >= count) {
            return b->size += res;
        }
        if (res == 0) {
            return b->size;
        }
        b->size += res;
        count -= res;
    }
}

ssize_t buf_flush(int fd, struct buf *b, size_t req) {
    abort(b==NULL || req > b->capacity);
    int res = 0;
    int count = (int) req;
    int wr = 0;
    for(;;) {
        res = (int) write(fd, b->data + wr, b->size - wr);
        if (res==-1) break;
        wr += res;
        if (res>=count) break;
        if (wr==b->size) break;
        count -= res;
    }
    if ((b->size-=wr)>0) {
        memmove(b, b+wr, b->size);
    }
    return wr;
}