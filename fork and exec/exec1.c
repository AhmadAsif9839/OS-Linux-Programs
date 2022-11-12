#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("process id of exec1 %d\n", getpid());
    char *args[] ={"Hello", "Ahmad", "Asif", NULL};

    execv("./exec2", args);
    printf("Back to exec1\n");
}
