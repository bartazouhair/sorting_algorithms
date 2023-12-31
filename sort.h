#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void cntSortLSD(int *arr, size_t sz, size_t ld);
void heapIfeey(int *arr, size_t siz, size_t r, size_t sz);
void MSubarray(int *ar, int *arr, size_t l, size_t m, size_t r);
void MRecursion(int *ar, int *arr, size_t l, size_t r);
int lnList(listint_t *z);
void mg(int *arr, int *l, size_t lz, int *r, size_t rz);
void my_p(int *arr, size_t lb, size_t ub, int *cp);
void my_jp(int *arr, size_t ml, size_t mht, size_t md, int *cp);
void mppe(int *arr, const char *mt, size_t ml, size_t mht);
#endif /*SORT_H*/
