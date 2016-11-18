#include <stdio.h>
#include <stdlib.h>

double inverse(int b)
{
	double old_x=0, x=1;
	while (old_x != x) {
		old_x = x;
		x = x + x*(1-(b*x));
		printf("%f\n", x);
	}
	return x;
}

int main(int argc, char *argv[])
{
	if (argc<3) return 1;
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	printf("%d,%d\n", a, b);

	double inverse_b = inverse(b);

	printf("%f\n", a * inverse_b);

	return 0;
}

