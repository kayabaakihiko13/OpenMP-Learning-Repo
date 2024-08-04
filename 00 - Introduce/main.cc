#include <stdio.h>
#include <omp.h>
int main(void){
    #pragma omp parallel
    {
        printf("Selamat");
        printf("Datang\n");
    }
    return 0;
}