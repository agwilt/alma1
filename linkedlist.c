#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "linkedlist.h"

List *list_create()
{
	List *list = malloc(sizeof(List));
	list->first = NULL;
	list->num = 0;
	return list;
}

void free_string(Node *node)
{
	if (node != NULL) {
		free_string(node->next);
		free(node);
	}
}

void list_free(List *list)
{
	free_string(list->first);
	free(list);
}

Node *list_append(List *list, int element)
{
	Node *node = malloc(sizeof(Node));

	node->value = element;
	node->next = NULL;

	if (list->last != NULL) {
		list->last->next = node;
	} else {
		list->first = node;
	}
	list->last = node;

	++(list->num);

	return node;
}

Node *list_walk(List *list, int n)
{
	int i;
	Node *node = list->first;
	for (i=0; i<n && node != NULL; ++i) {
		node = node->next;
	}
	return node;
}

void list_print(List *list)
{
	Node *node = list->first;

	if (node == NULL) {
		puts("[]");
		return;
	}

	putchar('[');
	while (node->next != NULL) {
		printf("%d, ", node->value);
		node = node->next;
	}
	printf("%d", node->value);
	puts("]");
}

void list_fill_random(List *list, int n)
{
	int i;
	srand(time(NULL));
	for (i=0; i<n; ++i) {
		list_append(list, rand());
	}
}

void list_det_print(List *list)
{
	int i;
	Node *node = list->first;
	printf("+------------------+\n");
	printf("|list->first = %p\n", (void *) list->first);
	printf("|list->last = %p\n", (void *) list->last);
	printf("|list->num = %d\n", list->num);
	for (i=0; i<(list->num); ++i) {
		printf("+------------------+\n");
		printf("| Node:  %p\n", (void *) node);
		printf("| Value: %d\n", node->value);
		printf("| Next:  %p\n", (void *) node->next);
		printf("+------------------+\n");
		node = node->next;
	}
}

List *list_merge_sort(List *list)
{
	if (list->first == list->last) return list;
	// >=2 Elements guaranteed
	// Declarations
	int l = list->num/2;
	Node *middle = list_walk(list, l-1);

	List *head = list_create();
	List *tail = list_create();

	// Split
	head->first = list->first;
	head->last = middle;

	tail->first = middle->next;
	tail->last = list->last;
	middle->next = NULL;

	head->num = l;
	tail->num = list->num - l;

	// Sort
	list_merge_sort(head);
	list_merge_sort(tail);

	// Merge
	// First value (set first)
	if (head->first->value < tail->first->value) {
		list->last = list->first = head->first;
		head->first = head->first->next;
		if (head->first == NULL) head->last = NULL;
		--(head->num);
	} else {
		list->last = list->first = tail->first;
		tail->first = tail->first->next;
		if (tail->first == NULL) tail->last = NULL;
		--(tail->num);
	}
	list->num = 1;

	// Merge all the other elements
	while ((head->first != NULL) && (tail->first != NULL)) {
		++(list->num);
		if (head->first->value < tail->first->value) {
			list->last->next = head->first;
			list->last = head->first;
			head->first = head->first->next;
			--(head->num);
		} else {
			list->last->next = tail->first;
			list->last = tail->first;
			tail->first = tail->first->next;
			--(tail->num);
		}
	}
	if (head->first != NULL) {
		list->last->next = head->first;
		list->num += head->num;
		list->last = head->last;
	}
	if (tail->first != NULL) {
		list->last->next = tail->first;
		list->num += tail->num;
		list->last = tail->last;
	}

	free(head);
	free(tail);

	return list;
}
