#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define num_threads 100

typedef struct {
    int number;
} num;

// Let us create a global variable to change it in threads
int g = 0;

// The function to be executed by all threads
void *primeNumberPrinter(void *args) {
    num *temp = args;

    if(temp->number == 0) {
        return 0;
    }
    
    for(int i = 2; i <= temp->number / 2; i++) {
        if(temp->number % i == 0) {
            return 0;
        }
    }
    
    printf("%d\n", temp->number);

    free(temp);
    return 0;
}

int main() {
    int primeArray[num_threads];
    pthread_t primes[num_threads];
    for (int i = 0; i < num_threads; i++) {
        num *args = malloc(sizeof *args);
        args->number = i;

        if(pthread_create(&primes[i], NULL, primeNumberPrinter, args)) {
            free(args);
        }
        pthread_join(primes[i], NULL);
    }

    pthread_exit(NULL);
    return 0;
}
