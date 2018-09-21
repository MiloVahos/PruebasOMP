#include <stdio.h>
#include <omp.h>

static long num_steps = 100000;
double step;
    
void main () {
    
    int i; double x, pi, sum = 0.0;
    step = 1.0/(double) num_steps;

    #pragma omp parallel num_threads(4)
    {
        int ID = omp_get_thread_num();
        switch(ID) {
            case 0:
                for ( int i = 0; i < (num_steps/4)*1 ; i++ ) {
                    x = (i+0.5)*step;
                    #pragma omp atomic
                        sum = sum + 4.0/(1.0+x*x);
                }
            break;
            case 1:
                for ( int i = ((num_steps/4)*1)+1; i < (num_steps/4)*2 ; i++ ) {
                    x = (i+0.5)*step;
                    #pragma omp atomic
                        sum = sum + 4.0/(1.0+x*x);       
                }
            break;
            case 2:
                for ( int i = ((num_steps/4)*2)+1; i < (num_steps/4)*3 ; i++ ) {
                    x = (i+0.5)*step;
                    #pragma omp atomic
                        sum = sum + 4.0/(1.0+x*x);     
                }
            break;
            case 3:
                for ( int i = ((num_steps/4)*3)+1; i < num_steps ; i++ ) {
                    x = (i+0.5)*step;
                    #pragma omp atomic                    
                        sum = sum + 4.0/(1.0+x*x);    
                }
            break;
        }
    }
    
    pi = step * sum;
    printf("pi = %f\n",pi);

}