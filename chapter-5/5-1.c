#include <stdio.h>
#include <unistd.h>

/*
 * The parent a child process both respect x before the fork and the value of x when it is changed after
 * the fork. The parent has no access to the child and vice versa
 */
int main(int argc, char **argv) {
    int x = 100;

    int pid = fork();
    if (pid == 0) {
        // Child process
        printf("Child inital x: %d\n", x);
        x = 50;
        printf("Child changes x: %d\n", x);
    } else {
        // Parent process
        printf("Parent process x: %d\n", x);
        x = 25;
        printf("Parent changes x: %d\n", x);
    }

    return 0;
}