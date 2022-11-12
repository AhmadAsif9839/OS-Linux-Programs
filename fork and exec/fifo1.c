#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char *argv[])
{
    // Opening file descriptor
    int fd = open("transporter", O_WRONLY);

    int arr[5];
    srand(time(NULL));


    if (fd == -1) {
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        arr[i] = rand() % 100;
    } 


    for (int i = 0; i < 5; i++) {
        if (write(fd, &arr[i], sizeof(int)) == -1) {
            return 2;
        }
        
        printf("Writing %d\n", arr[i]);
    }


    close(fd);

    return 0;
}