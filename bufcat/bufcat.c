//
// Created by shambala on 03.04.15.
//

#include <unistd.h>
#include "../lib/bufio.h"


int main(int argc, char *argv[]) {
    struct buf *buffer = buf_new(1024);
    size_t capacity = buf_capacity(buffer);
    for(;;) {
        ssize_t res_r = buf_fill(STDIN_FILENO,buffer, capacity);
        ssize_t res_w = buf_flush(STDIN_FILENO, buffer, buf_size(buffer));
        if(res_r==-1 || res_w == -1 || res_r < capacity) {
            break;
        }

    }
    buf_free(buffer);
    return 0;

}

