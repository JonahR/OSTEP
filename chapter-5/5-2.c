#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/errno.h>

int main(int argc, char **argv) {
    int n;
    int fd = open("test.log", O_RDWR|O_CREAT, 0644);
    if (fd == -1) {
        perror(NULL);
    }
    int pid = fork();
    if (pid == 0) {
        n = write(fd, "Writing from child\n", 19);
    } else {
        n = write(fd, "Writing from parent\n", 20);
    }
    if (n == -1) {
        perror(NULL);
    }
    close(fd);
}

// The parent and child can use the same file description
// Dependeing on if the child or parent writes second, it appends
// on to after the first process's write
