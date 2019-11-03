#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char *argv[]) {
    pid_t pid;
    /* fork a child process */
    pid = fork();
    if (pid == 0) {
        int argv0size = strlen(argv[0]);  //Take note of how many chars have been allocated
        strncpy(argv[0], "main-thread-name", argv0size);
        printf("name: %s\n", argv[0]);
    }

    return 0;
}