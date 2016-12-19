#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>

#include "linkedlist.h"

_Bool is_number(const char *s)
{
	while (*s != '\0') {
		if (! isdigit(*s)) return 0;
		++s;
	}
	return 1;
}

int main(int argc, char *argv[])
{
	clock_t start_time;
	List list = {NULL, NULL, 0};
	int n;

	if (argc<2) return 1;

	if (is_number(argv[1])) {
		n = atoi(argv[1]);
		list_fill_random(&list, n);
	} else {
		n = list_fill_file(&list, argv[1]);
	}

	if (n <= 100) {
		printf("Unsorted:\n");
		list_print(&list);
		printf("---------------------------\nSorted:\n");
	}

	printf("Mergesort with list:\n");
	start_time = clock();
	list_merge_sort(&list);
	printf("Time: %ld\n", (clock() - start_time)/CLOCKS_PER_SEC);

	if (n <= 100) {
		list_print(&list);
	}

	list_free(&list);

	return 0;
}
