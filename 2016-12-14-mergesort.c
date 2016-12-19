#include <stdlib.h>
#include <stdio.h>

#include "linkedlist.h"

int main(int argc, char *argv[])
{
	if (argc<2) return 1;
	int n = atoi(argv[1]);

	List list = {NULL, NULL, 0};

	list_fill_random(&list, n);

	printf("Unsorted:\n");
	list_print(&list);

	printf("---------------------------\nSorted:\n");
	list_merge_sort(&list);
	list_print(&list);

	free_string(list.first);

	return 0;
}
