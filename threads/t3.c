// Multi threaded program that take more than one argument
// Using structure to pass multiple argument

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

struct myStruct {
    char character;
    int count;
};

void *f1(void *);

int main(int argc, char *argv[]) {

    pthread_t tid1, tid2;

    struct myStruct t1_args;
    t1_args.character = 'X';
    t1_args.count = 10;
    pthread_create(&tid1, NULL, f1, (struct myStruct *)&t1_args);


    struct myStruct t2_args;
    t2_args.character = 'O';
    t2_args.count = 10;
    pthread_create(&tid2, NULL, f1, (struct myStruct *)&t2_args);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    printf("\nBye Bye from main\n");
    return 0;
}

void *f1(void * args) {
    struct myStruct p = *(struct myStruct*)args;

    for (int i = 0; i < p.count; i++) {
        putc(p.character, stderr);
    }
    
    pthread_exit(NULL);
}
