//
// Created by Jonah Rueb on 1/28/26.
//
#include <unistd.h>

int main(int argc, char **argv) {
    char *vec[3];
    vec[0] = "ls";
    vec[1] = "-a";
    vec[2] = NULL;

    char *envs[2];
    envs[0] = "TEST:hi";
    envs[1] = NULL;

    // execl("/bin/ls", "ls", NULL);
    //execle("/bin/ls", "ls", "-a", NULL, envs);
    // execlp("ls", "ls", NULL);
    // execv("/bin/ls", vec);
    execvp("ls", vec);
}

// There is multiple methods to preform exec to help pass in different types of values.
// By using the 'e' version, the programmer can pass in custom ENV variables for the new program to run
// instead of using the ones from the original process. By using the 'p' version, the programming can reference
// the new program by name, and it will try to find it using the process's PATH environment variable.
// It also gives you options to pass in an array of arguemnts or to list them out one by one. This is good
// for passing in dynamic arguemnts to the exec function you may not know at compile time.