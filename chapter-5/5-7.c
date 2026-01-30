//
// Created by Jonah Rueb on 1/28/26.
//
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
    int pid = fork();
    if (pid == 0) {
        close(STDOUT_FILENO);
        printf("Child process\n");
    } else {
        wait(NULL);
        printf("Parent process\n");
    }
}

/*
 * The child process's print does not go to standard output.
 */

