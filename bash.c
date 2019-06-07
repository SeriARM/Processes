include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(void)
{
    char line[8192];

    while (1) {
        printf(">>$ "); fflush(stdout);

        fgets(line, sizeof line, stdin);

        // Strip newline off the end
        line[strlen(line)-1] = '\0';

        // Check for exit built-in command to exit the shell
        if (strcmp(line, "exit") == 0) {
            break;
        }

        pid_t pid = fork();

        if (pid == 0) {
            execlp(line, line, NULL);
            // This line gets hit if you try to run a non-existent command:
            perror("exec");
            exit(1);
        } else {
            wait(NULL);
        }
    }

    return 0;
}