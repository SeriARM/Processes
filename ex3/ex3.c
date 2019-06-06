// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
   int rc = fork();
    if (rc < 0) {
        printf(stderr, "fork() error\n");
        exit(1);
    } else if (rc == 0) {
        printf("hello\n");
    } else {
        wait(&rc);
        printf("goodbye\n");
    }


    return 0;
}
