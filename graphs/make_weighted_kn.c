#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc<3) return 1;

	int n = atoi(argv[2]);
	int i, j;
	char *filename = argv[1];
	FILE *fp = fopen(filename, "w");
	if (fp == NULL) return 1;

	fprintf(fp, "%d\n", n);
	for (i=0; i<n; ++i) {
		for (j=0; j<n; ++j) {
			if (j != i) {
				fprintf(fp, "%d %d %f\n", i, j, (double) rand());
			}
		}
	}
	fclose(fp);

	return 0;
}
