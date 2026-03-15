#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("usage: %s <size in MB>\n", argv[0]);
    }

    int bytes = 1000000 * atoi(argv[1]);
    char *array = (char *) malloc(sizeof(char) * bytes);
    while (1) {
        for (int i = 0; i < bytes; i++) {
            array[i] += array[i];
        }
    }
}