// #include <stdio.h>
// #include <unistd.h>
// #include <fcntl.h>
// #include <wait.h>
// int main(int argc, char *argv[])
// {
//     printf("I am Parent\n");
//     int cp = fork();
//     if (!cp)
//     {
//         printf("%d", cp);
//         execl("/usr/bin/echo","echo", "I am the child", NULL);
//     }
//     else
//     {
//         printf("%d", cp);
//         wait(NULL);
//         execlp("echo", "echo", "I am Parent child is terminated", NULL);
//     }
//     return 0;
// }

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <wait.h>
int main(void)
{
    printf("I am Parent\n");
    int cp = fork();
    if (!cp)
    {
        printf("%d", cp);
        execl("/usr/bin/echo", "I am the child", NULL);
    }
    else
    {
        printf("%d", cp);
        wait(NULL);
        execlp("/usr/bin/echo", "I am Parent child is terminated", NULL);
    }
    return 0;
}

