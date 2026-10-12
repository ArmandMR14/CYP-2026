#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
int main()
{
	int32_t C = 2;
	int32_t B = 1;
	int32_t A = 10;
	int32_t suma = A+ B+ C;
	char msg[100];
	snprintf(msg, sizeof(msg), "El resultado de la suma es: %d", suma);
	write (1, msg, sizeof (msg) -1);
	return 0;
}
