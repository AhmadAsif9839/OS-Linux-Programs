#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    //execlp(command name, command name, parameters.., NULL pointer)
    execlp("ls", "ls", "-l", NULL);

    return 0;
}



