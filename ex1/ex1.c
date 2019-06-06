// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
   int x = 10;
    printf("Before Fork - x: %d\n", x);
    int rc = fork();
    printf("After Fork - x: %d\n", x);
    x += x;
    printf("After Fork - x + x: %d\n", x);
   if (rc == 0) {
        printf("Child (pid: %d) - x: ", (int) getpid());
        printf("%d\n", x);
        x *= 2;
        printf("Child (pid: %d) - x * 2: ", (int) getpid());
        printf("%d\n", x);
    } else {
        printf("Parent (pid: %d) - x: ", (int) getpid());
        printf("%d\n", x);
        x /= 2;
        printf("Parent (pid: %d) - x / 2: ", (int) getpid());
        printf("%d\n", x);
    }


    return 0;
}
