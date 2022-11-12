#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    write(1, "I am learning OS", 17);
    write(1, "I know what is sys call", 24);
    write(1, "I am going to run echo command", 31);

    char *args[] = {"I am here", NULL};
    
    // excel ("file path", process name, what does process do, a null pointer to terminate the execl)
    // Once the exec command called it only runs the process and when the process terminates it does not go the
    // furthur instructions and program finishes
    // execl("/usr/bin/echo", "echo", "i am here", NULL);


    execl("echo", "echo", "i am here", NULL);
    
    // Alternative way
    execlp("echo", "echo", *args, NULL); // specifying the process

    // the further statements does not execute
    write(1, "Should i be printed on the screen or not", 41);
    return 0;
}


