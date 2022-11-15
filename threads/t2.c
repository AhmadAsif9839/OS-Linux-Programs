// Multi threaded program that takes command line arguments
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>


void *f1(void *);
void *f2(void *);

int main(int argc, char *argv[]) {

    pthread_t tid1, tid2;

    int count_of_X = atoi(argv[1]);
    int count_of_O = atoi(argv[2]);

    // Creating threads
    pthread_create(&tid1, NULL, f1, (void *)&count_of_O);
    pthread_create(&tid2, NULL, f2, (void *)&count_of_X);

    // Joining threads
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);


    printf("\nBye Bye from Main\n");
    return 0;
}

void *f1(void * arg) {
    int ctr_thread = *((int *)arg);
    for (int i = 0; i < ctr_thread; i++) {
        fprintf(stderr, "%c", 'X');
        fflush(stdout);
    }

    pthread_exit(NULL);
}

void *f2(void * arg) {
    int ctr_thread = *((int *)arg);
    for (int i = 0; i  < ctr_thread; i++) {
        fprintf(stderr, "%c", 'O');
        fflush(stdout);
    }

    pthread_exit(NULL);
}

