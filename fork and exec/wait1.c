#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    int id = fork();
    int status = 0;
    int n;

    if (id == 0)
        n = 1;
    else
        n = 6;

    // wait for child process to terminate
    if (id != 0)
        wait(&status);
    
    for (int i = n; i < n + 5; i++) {
        printf("%d ", i);
        fflush(stdout); // flushing the buffer
    }
    
    if (id != 0)
        printf("\n");
        
    return 0;
}

