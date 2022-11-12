#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <fcntl.h>

int main()
{
    // Opening file descriptor in read only mode
    int fd = open("transporter", O_RDONLY);

    int arr[5];

    if (fd == -1) {
        return 1;
    }


    // Reading from fifo1
    for (int i = 0; i < 5; i++) {
        if (read(fd, &arr[i], sizeof(int)) == -1) {
            return 2;
        }

        printf("Reading %d\n", arr[i]);
    }

    // closing the descriptor
    close(fd);
    return 0;
}
