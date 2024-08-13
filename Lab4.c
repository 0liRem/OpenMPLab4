/*
* -------------------------------------------------------------
* UNIVERSIDAD DEL VALLE DE GUATEMALA
* Programación de Microprocesadores
*
* Introducción OpenMP
* Descripción: Resolver una ecuación con paralelización
* Autor:	   Olivier Viau
* Fecha:	   Agosto 13, 2024.
* -------------------------------------------------------------
*/

#include <stdlib.h>
#include <omp.h>
#include <stdio.h>

// Modificar para N = 1024 y MIN_SIZE = 64
#define N 1024
#define MIN_SIZE 64

int main() {
    // Inicialización de los vectores A y B
    printf("Ingresa el número de hilos con el que quieres trabajar, 8,16,32 \n");
    int valor;
    scanf("%d",&valor);
    int cont=2;
    if(valor==16 || valor==32 || valor==8){
        int x[valor];
        int y[valor];
        for (int i=0;i<valor;i++){
            x[i]=cont;
            cont+=2;
    }
    omp_set_num_threads(valor);
    #pragma omp parallel for num_threads(valor)
        for(int i=0; i<valor;i++){
            y[i]=((5/2)+(x[i]*x[i]));
            printf("El hilo %d ejecuto la tarea %d y dio de resultado %d \n",omp_get_thread_num(),i,y[i]);
        }
    }
    else{
        printf("El valor ingresado no es un número de hilos trabajable");
    }

    return 0;
}
