#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#include <inttypes.h>

#define N 50
#define SUP 100

void main ( ) {

    uint16_t A[N];
    uint16_t B[N];
    uint16_t C[N];
    uint16_t D[N];

    srand(time(NULL));

    // Inicialización de matrices
    for ( int j = 0; j < N; j++ ) {
        A[j] = rand() %(SUP + 1 - 0) + 0;
        B[j] = rand() %(SUP + 1 - 0) + 0;
    }

    #pragma omp parallel
    {
        int id, i, Nthreads, istart, iend;
        id = omp_get_thread_num();
        Nthreads    =   omp_get_num_threads();
        istart  =   id*N/Nthreads;
        iend    =   (id+1)*N/Nthreads;
        if ( id == Nthreads-1 ) iend    =   N;
        printf("Thread = %d\n", id);
        for ( i = istart; i < iend; i++ ) {
            C[i]    =   A[i]    +   B[i];
            printf("C[%d] = %d  ",i,C[i]);
        }
        printf("\n");
 
    }

    for( int j = 0; j < N; j++ ) {
        printf("%"PRIu16" ", A[j]);
    }
    printf("\n");
     for( int j = 0; j < N; j++ ) {
        printf("%"PRIu16" ", B[j]);
    }
    printf("\n");
     for( int j = 0; j < N; j++ ) {
        printf("%"PRIu16" ", C[j]);
    }


    // AHORA CON EL PARALLEL FOR
    printf("\n\n Resultado con el parallel for \n\n");
    #pragma omp parallel
    {
        #pragma omp for
            for ( int i = 0; i < N; i++ ) {
                D[i]    =   A[i]    +   B[i];
            }
            printf("Id = %d ",omp_get_team_num());
    }

    printf("\n");
     for( int j = 0; j < N; j++ ) {
        printf("%"PRIu16" ", D[j]);
    }
    printf("\n");

}