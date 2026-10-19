#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 64

int
main ()
{
	float Masa;
	float MM;
	float Litros;
	scanf("%f", &Masa);
	scanf("%f", &MM);
	scanf("%f", &Litros);
	double F = (Masa/MM)/Litros;
	printf("Molaridad:\t%.2fM", F);
	return 0;
}
