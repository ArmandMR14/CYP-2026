#include <stdio.h>
#include <math.h>
#define GRAVEDAD 9.8	
#define Division 0.5
int
main()
{
	float t;
	float m;

	scanf("%d", &t);
	scanf("%d", &m);
	double h = Division*GRAVEDAD*(t*t);
	printf("%f", h);
	return 0;
}

	
