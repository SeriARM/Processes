#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    pid_t pid = fork();

    if (pid == 0) {
        // Child process exits immediately
        printf("Child!\n");
        exit(3);
    } else {
        // Parent process needs to hit RETURN to wait
        // for child.
        printf("Parent!\n");

        // Run `ps al` in anohter bash shell to see the
        // child with `Z`ombie status.

        printf("Press RETURN to wait\n");
        getchar();

        wait(NULL); // This reaps the zombie

        printf("Press RETURN to exit\n");
        getchar();
    }

    return 0;
}