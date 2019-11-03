#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// *************************
const int n = 2;
const int m = 3;

int A[2][3] = {{1, 2, 3},
               {4, 5, 6}};

int B[3][2] = {{7, 8},
               {9, 10},
               {11, 12}};

int C[2][2];
// *************************

typedef struct {
    // calc location
    int n; // 0
    int m; // 1

    // size of matrix a
    int aM;
} CalcInfo;

void *MatMul(void *args) {
    CalcInfo *temp = args;

    // calculations
    int sum = 0;
    for(int i = 0; i < temp->aM; i++) {
        sum += A[temp->n][i] * B[i][temp->m];
    }
    C[temp->n][temp->m] = sum;
    // printf("%d\n", C[temp->n][temp->m]);


    free(temp);
    return 0;
}


int main() {
    pthread_t Matrix[n * m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            CalcInfo *args = malloc(sizeof *args);
            args->n = i;
            args->m = j;
            args->aM = m;
            if (pthread_create(&Matrix[i + j], NULL, MatMul, args)) {
                free(args);
            }
            pthread_join(Matrix[i], NULL);
        }
    }

    // print Matrix C to check
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    pthread_exit(NULL);
    return 0;
}
