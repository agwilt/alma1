#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc<3) return 1;

	int n = atoi(argv[2]);
	int i, a, b;
	char *filename = argv[1];
	FILE *fp = fopen(filename, "w");
	if (fp == NULL) return 1;

	fprintf(fp, "%d\n", n);
	for (i=0; i<4*n; ++i) {
		a = rand()%n;
		b = rand()%n;
		if (a!=b)
			fprintf(fp, "%d %d\n", a, b);
	}
	fclose(fp);

	return 0;
}
