//
// Created by shambala on 25.03.15.
//
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include "helpers.h"

int spawn(const char *file, char *const argv[]) {
    pid_t child_pid = fork();
    if (child_pid == -1) {
        return -1;
    } else if (child_pid == 0) {
        execvp(file, argv);
        return -1;
    }
    int status;
    pid_t wr = waitpid(child_pid, &status, 0);
    if (wr == -1 || !WIFEXITED(status)) {
        return -1;
    }
    return WEXITSTATUS(status);
}
