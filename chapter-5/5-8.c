//
// Created by Jonah Rueb on 1/28/26.
//
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
    int p[2];
    int pids[2];
    int pid = 0;

    pipe(p);

    for (int i = 0; i < 2; i++) {
        pid = fork();
        if (pid != 0) {
            pids[i] = pid;
            break;
        }
    }

    if (pid == pids[0]) {
        printf("I am in child 1\n");
        dup2(p[1], STDOUT_FILENO);
        printf("Printing after dup2\n");
    } else if (pid == pids[1]) {
        printf("I am in child 2\n");
        dup2(p[0], STDIN_FILENO);
        printf("First char from child 1: %c\n", getc(stdin));
    } else {
        waitpid(pids[0], NULL, 0);
        waitpid(pids[1], NULL, 0);
        fflush(stdout);
    }


}

/*
 * The child process's print does not go to standard output.
 */

//
// Created by Jonah Rueb on 1/29/26.
//