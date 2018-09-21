/*
 *@Developer: Juan Camilo Peña Vahos
 *@Description: Prueba de algoritmo paralelizado y profiling con scalasca
*/ 

// LIBRERÍAS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>

#define N 99
#define SUP 100

int main () {

    uint64_t A[N][N];
    uint64_t B[N][N];
    uint64_t C[N][N];
    int temporal;

    srand(time(NULL));

    // Inicialización de matrices
    for ( int i = 0; i < N; i++ ) { 
        for ( int j = 0; j < N; j++ ) {
            A[i][j] = rand() %(SUP + 1 - 0) + 0;
            B[i][j] = rand() %(SUP + 1 - 0) + 0;
        }
    }

    // Multiplicación de matrices
    for ( int i = 0; i < N; i++ ) {
        for( int j = 0;j < N; j++ ){
            C[i][j]=0;
            for( int k = 0; k < N; k++ ) {
                C[i][j] =   (C[i][j]+(A[i][k]*B[k][j]));
            }
        }
    }

    /*Rutina para imprimir
    printf("\n\n\t\t\t Matriz A");
    printf("\n");
    for( int i = 0; i < N; i++ ) {
        printf("\n\t\t");
        for( int j = 0; j < N; j++ ) {
            printf("  %6d  ", A[i][j]);
        }
    }
    printf("\n\n\t\t\t Matriz B");
    printf("\n");
    for( int i = 0; i < N; i++ ) {
        printf("\n\t\t");
        for( int j = 0; j < N; j++ ) {
            printf("  %6d  ", B[i][j]);
        }
    }
    
    printf("\n\n\t\t\t Matriz B");
    printf("\n");
    for( int i = 0; i < N; i++ ) {
        printf("\n\t\t");
        for( int j = 0; j < N; j++ ) {
            printf("  %"PRIu64"  ", C[i][j]);
        }
    }
    printf("\n");*/

    return 0;

}