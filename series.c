#include <stdio.h>
#include <stdlib.h>

int C(int n)
{
	if (n==0) return 1;
	int k, sum=0;
	for (k=0; k<n; ++k)
		sum += C(k)*C(n-1-k);
	return sum;
}

int main(int argc, char *argv[])
{
	int n;
	if (argc>1) {
		n = atoi(argv[1]);
		printf("%d\n", C(n));
	}
	return 0;
}
