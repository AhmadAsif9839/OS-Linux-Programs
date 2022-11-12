#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("We are in exec2.c\n");
    printf("process id of exec2 is %d\n", getpid());

    return 0;
}
