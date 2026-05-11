#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define NUM_PROC 3

void hijoHasAlgo(int numero);

int main ()
{
    int i, pid;
    for (i=1; i<=NUM_PROC; i++)
    {
        pid = fork();
        switch(pid)
        {
            case -1:
                fprintf(stderr, "Error al crear el proceso\n");
                break;
            case 0:
                // Proceso hijo
                hijoHasAlgo(i);
                exit(0);
            default:
                // Proceso padre
                printf("Ejecutando el padre\n");
                wait(0);
                printf("Mi hijo %d ha terminado.\n\n", i);
                break;
        }
    }
    return 0;
}

void hijoHasAlgo (int numero)
{
    int i, MAX=10;
    printf("Ejecutando el hijo %d (PID: %d):\n", numero, getpid());
    
    if (numero == 1) {
        printf("-> Tarea: Contar del 1 al 10\n");
        for (i=1; i<=MAX; i++) {
            printf("%d\t", i);
        }
        printf("\n");
    } 
    else if (numero == 2) {
        printf("-> Tarea: Cuenta regresiva del 10 al 1\n");
        for (i=MAX; i>=1; i--) {
            printf("%d\t", i);
        }
        printf("\n");
    } 
    else if (numero == 3) {
        int suma = 0;
        printf("-> Tarea: Sumar los numeros del 1 al 10\n");
        for (i=1; i<=MAX; i++) {
            suma += i;
        }
        printf("La suma total es: %d\n", suma);
    }
}
