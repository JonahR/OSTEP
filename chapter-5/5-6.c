//
// Created by Jonah Rueb on 1/28/26.
//
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
    int pid = fork();
    if (pid == 0) {
        printf("Child process\n");
    } else {
        waitpid(pid, NULL, 0);
        printf("Parent process\n");
    }
}

/*
 * The waitpid system call waits until a specific pid is terminated vs wait which looks for any terminated process.
 * This is useful for only conitnuing when a specific process is complete.
 */

