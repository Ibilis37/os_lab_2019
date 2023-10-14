#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv) {

    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process

        execl("./sequential_min_max", "./sequential_min_max", argv[1], argv[2], NULL);

        // execl fails
        perror("Exec failed");
        exit(1);
        
    } else {
    // Parent process
        int status;
        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            int exit_status = WEXITSTATUS(status);
            if (exit_status == 0) {
                printf("Child process exited successfully\n");
            } else {
                printf("Child process exited with an error\n");
            }
        }
    }

    return 0;
}