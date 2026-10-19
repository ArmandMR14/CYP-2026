#include <stdio.h>
int
main()
{
	int Total;
	scanf("%d", &Total);
	int Compas= Total/4;
	int Pulsos= Total%4;
	printf("El numero de pulsos es: %d y el numero de compases es: %d\n", Compas, Pulsos);
	return 0;
}
