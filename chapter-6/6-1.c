//
// Created by Jonah Rueb on 1/30/26.
//
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/errno.h>
#include <sys/time.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    // struct timeval tp;
    // char *buf[1];
    //
    // gettimeofday(&tp, NULL);
    // printf("Seconds: %ld\n", tp.tv_sec);
    // printf("Microseconds: %d\n", tp.tv_usec);
    //
    // for (int i = 0; i < 100000; ++i) {
    //     read(0, &buf, 0);
    // }
    //
    //
    // gettimeofday(&tp, NULL);
    // printf("This is seconds: %ld\n", tp.tv_sec);
    // printf("Microseconds: %d\n", tp.tv_usec);

    int pipe_fds[2];
    pid_t pid;

    if (pipe(pipe_fds) < 0) {
        printf("pipe() error: %s\n", strerror(errno));
    }

    if ((pid = fork()) < 0) {
        printf("fork() error: %s\n", strerror(errno));
    }

    struct timeval tp;
    gettimeofday(&tp, NULL);
    printf("Seconds: %ld\n", tp.tv_sec);
    printf("Microseconds: %d\n", tp.tv_usec);

    if (pid == 0) {
        char buf[1];
        // Child
        for (int i = 0; i < 100000; ++i) {
            read(pipe_fds[0], buf, 1);
        }
        return 0;
    } else {
        // Parent
        for (int i = 0; i < 100000; ++i) {
            write(pipe_fds[1], "b", 1);
        }
    }
    wait(NULL);

    gettimeofday(&tp, NULL);
    printf("This is seconds: %ld\n", tp.tv_sec);
    printf("Microseconds: %d\n", tp.tv_usec);
}

/*
 * I ran 100,000 read system calls in 30,721 microseconds. This averages out to be ~0.31 microseconds
 * per system call.
 */

/*
 * I ran 100,000 context switches in 349 microseconds using a single performance core with `taskpolicy -b`. This
 * averages out to be 0.00349ms per context switch. This seems extremely fast. I may not have been able to
 * isolate my 2 processes out on a single CPU.
 */