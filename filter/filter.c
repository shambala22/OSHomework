//
// Created by shambala on 25.03.15.
//

#include <unistd.h>
#include <string.h>
#include "../lib/helpers.h"

const size_t BUFSIZE = 1024;

int main(int argc, char *argv[]) {
    if (argc<2) {
        char const* error = "MORE ARGUMENTS, PLS\n";
        write(STDOUT_FILENO, error, strlen(error));
        return 1;
    }
    int i;

    char buf[BUFSIZE];

    char* spawn_command = argv[1];

    for (i = 0; i<argc-1; i++) {
        argv[i] = argv[i+1];
    }

    ssize_t r;
    size_t arg_length = 0;
    char last[256];
    argv[argc-1] = last;
    while ((r = read(STDIN_FILENO, buf, BUFSIZE))) {
        for (i = 0; i<r; i++) {
            if (buf[i]=='\n') {
                last[arg_length] = 0;
                if (spawn(spawn_command, argv) == 0) {
                    last[arg_length] = '\n';
                    write(STDOUT_FILENO, last, arg_length+1);
                }
                arg_length = 0;
            } else {
                last[arg_length] = buf[i];
                arg_length++;
            }
        }
    }

    return 0;
}
