#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *f1(void *);
void *f2(void *);

int main() {
    pthread_t tid1, tid2;

    // Creating threads
    pthread_create(&tid1, NULL, f1, NULL);
    pthread_create(&tid2, NULL, f2, NULL);

    // Joining two threads
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    printf("\nBYE BYE FROM MAIN THREAD\n");
    return 0;
}

void *f1(void * arg) {
    for (int i = 0; i < 1000; i++) {
        fprintf(stderr, "%c", 'X');
        fflush(stdout);
    }

    pthread_exit(NULL);
}

void *f2(void *arg) {
    for (int j = 0; j < 800; j++) {
        fprintf(stderr, "%c", 'O');
        fflush(stdout);
    }

    pthread_exit(NULL);
}
