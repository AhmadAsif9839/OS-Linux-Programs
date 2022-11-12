#include <stdio.h>
#include <unistd.h>

int main(void)
{
    // pid_t pid = fork(); 

    // if (pid == 0) {
    //     printf("Child process executes with pid %d\n", getpid());
    // } else {
    //     printf("Parent process executes with pid %d\n", getpid());
    // }

    fork();
    fork();
    fork();

    // print 8 times 2^n processes will be created
    // where n is the number of fork calls
    printf("Processes with pid %d\n", getpid());
    
    return 0;
}

