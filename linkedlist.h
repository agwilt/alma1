#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node {
	struct Node *next;
	int value;
} Node;

typedef struct {
	struct Node *first;
	struct Node *last;
	int num;
} List;

List *list_create();
void list_free(List *list);

void list_print(List *list);
void list_det_print(List *list);

Node *list_append(List *list, int element);
Node *list_walk(List *list, int n);

List *list_merge_sort(List *list);

void list_fill_random(List *list, int n);
int list_fill_file(List *list, const char *filename);

#endif
