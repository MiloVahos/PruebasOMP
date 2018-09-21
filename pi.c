#include <stdio.h>
#include <omp.h>

static long num_steps = 100000;
double step;

void main ( ) {

    double pi, sum = 0.0;
    double auxs1 = 0.0;
    double auxs2 = 0.0;
    double auxs3 = 0.0;
    double auxs4 = 0.0;
    step = 1.0/(double) num_steps;

    #pragma omp parallel num_threads(4) 
    {
        int ID  =   omp_get_thread_num();
        double x;
        switch ( ID ) {
            case 0:
                for ( int i = 0; i < (num_steps/4)*1 ; i++ ) {
                    x = (i+0.5)*step;
                    auxs1 = auxs1 + 4.0/(1.0+x*x);
                }
                printf("AUX1: %f\n",auxs1);
            break;
            case 1:
                for ( int i = ((num_steps/4)*1)+1; i < (num_steps/4)*2 ; i++ ) {
                    x = (i+0.5)*step;
                    auxs2 = auxs2 + 4.0/(1.0+x*x);
                }
                printf("AUX2: %f\n",auxs2);
            break;
            case 2:
                for ( int i = ((num_steps/4)*2)+1; i < (num_steps/4)*3 ; i++ ) {
                    x = (i+0.5)*step;
                    auxs3 = auxs3 + 4.0/(1.0+x*x);
                }
                printf("AUX3: %f\n",auxs3);
            break;
            case 3:
                for ( int i = ((num_steps/4)*3)+1; i < num_steps ; i++ ) {
                    x = (i+0.5)*step;
                    auxs4 = auxs4 + 4.0/(1.0+x*x);
                }
                printf("AUX4: %f\n",auxs4);
            break;
        }
    }

    sum =  auxs1 + auxs2 + auxs3 + auxs4;
    pi = step * sum;

    printf("PI = %f\n",pi);

}


/*
 * 
 * SECUENCIAL
 * 
 * static long num_steps = 100000;
    double step;
    void main ()
    {
    int i; double x, pi, sum = 0.0;
    step = 1.0/(double) num_steps;
    for (i=0;i< num_steps; i++){
    x = (i+0.5)*step;
    sum = sum + 4.0/(1.0+x*x);
    }
    pi = step * sum;
    }
 * 
 */