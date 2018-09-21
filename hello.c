#include <stdio.h>
#include <omp.h>

void main ( ) {

    //omp_set_num_threads(4);
    #pragma omp parallel num_threads(4)
    {

        int ID = omp_get_thread_num();
        printf("Hello(%d)",ID);
        printf("World(%d)\n",ID);

    }

    //CONCLUSIONES:
        // -> num_threads y set_num_threads determinan cuantos hilos va a usar la región de paralela

}