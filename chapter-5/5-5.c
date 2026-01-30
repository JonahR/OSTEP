//
// Created by Jonah Rueb on 1/28/26.
//
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
    int pid = fork();
    if (pid == 0) {
        wait(NULL);
        printf("Child process\n");
    } else {
        printf("Parent process\n");
    }
}

/*
 * The wait system call returns contains information about the terminated proccess.
 * If you use wait in the child proccess, it will wait until the parent process is terminated before
 * continuing.
 */

