//
// Created by Jonah Rueb on 1/28/26.
//

// There is no good way to ensure the child process completes before the parent does without using "wait()"
// We can use "sleep()" to try to make sure the child prints first.

#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
    int fd = open("test.log", O_RDWR|O_CREAT, 0644);
    int pid = fork();
    if (pid == 0) {
        // Child
        write(fd, "hello", 5);
    } else {
        sleep(3);
        write(fd, "goodbye", 7);
    }
}
