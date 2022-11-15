// // Basic Program that takes 10 sec to execute (single threaded)
// #include <stdio.h>
// #include <unistd.h>
// #include <time.h>

// void f1()
// {
//     for (int i = 0; i < 5; i++) 
//     {
//         printf("%s", "PUCIT");
//         fflush(stdout);
//         sleep(1);
//     }
// }

// void f2()
// {
//     for (int i = 0; i < 5; i++)
//     {
//         printf("%s", "AHMAD");
//         fflush(stdout);
//         sleep(1);
//     }
// }

// int main()
// {
//     f1();
//     f2();
//     printf("\nBye Bye from main\n");

//     return 0;
// }


// Multi_Threaded program
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>

void * f1(void *);
void * f2(void *);


int main()
{
    pthread_t tid1, tid2;

    // Create two child threads and wait for their termination
    pthread_create(&tid1, NULL, f1, NULL);
    pthread_create(&tid2, NULL, f2, NULL);


    // Both threads are executing concurrently

    // Join the two threads
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);


    printf("\nBye Bye from main thread\n");
}
 
void *f1(void * arg) {
    for (int i = 0; i < 5; i++) {
        printf("%s", "AHMAD");
        fflush(stdout);
        sleep(1);
    }
    // return NULL;
    pthread_exit(NULL);
}

void *f2(void * arg) {
    for (int j = 0; j < 5; j++) {
        printf("%s", "PUCIT");
        fflush(stdout);
        sleep(1);
    }

    pthread_exit(NULL);
}

