//
// Created by shambala on 03.04.15.
//

#ifndef _OSHW3_BUFIO_H_
#define _OSHW3_BUFIO_H_


#include <stddef.h>
#include <stdio.h>

struct buf;

struct buf *buf_new(size_t capacity);
void buf_free(struct buf*);
size_t buf_capacity(struct buf*);
size_t buf_size(struct buf *);
ssize_t buf_fill(int fd, struct buf *b, size_t required);
ssize_t buf_flush(int fd, struct buf *b, size_t);

#endif //_OSHW3_BUFIO_H_
