#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main()
{
	int pid;
	int i;
	int variable = 0;

	pid = fork();

	switch(pid){

		case -1:
			perror("Error al crear el proceso");
			return 1;

		case 0: //Proeso hijo

			{
				printf("Soy el hijo con el PID: %d\n", getpid());

				FILE *archivo = fopen("log.txt", "w");
				if(archivo == NULL) exit(1);

				for(i = 0; i < 10; i++){
					fprintf(archivo, "Hijo lee valor de variable: %d\n", variable);
				}

				fclose(archivo);
				exit(0);
			}
			break;

		default: //Proceso padre

			printf("Soy el padre con el PID: %d\n", getpid());
			for(i = 0; i < 10; i++){
				variable += 10;
				printf("Padre incrementa variable a: %d\n", variable);
			}

			wait(NULL);
			break;

	}

	return 0;
}
