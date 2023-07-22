/*
 * File: 107-quick_sort_hoare.c
 */

#include "sort.h"

void swapy_ints(int *x, int *z);
int hoarePartitiony(int *arr, size_t sz, int l, int r);
void hoareSorty(int *arr, size_t sz, int l, int r);
void quick_sort_hoare(int *array, size_t size);
/**
 * swapy_ints - It's only to Swap two integers in an array.
 * @x: It's a The first integer to swap.
 * @z: It's a The second integer to swap.
 */
void swapy_ints(int *x, int *z)
{
int tp;

tp = *x;
*x = *z;
*z = tp;
}
/**
 * hoarePartitiony - It's a Order a subset of an array of integers
 *                   according to the hoare partition scheme.
 * @arr: It's a The array of integers.
 * @sz: It's a The size of the array.
 * @l: It's a The starting index of the subset to order.
 * @r: It's a The ending index of the subset to order.
 *
 * Return: It's a The final partition index.
 *
 * Description: It's a Uses the last element of the partition as the pivot.
 * Prints only the array after each swap of two elements.
 */
int hoarePartitiony(int *arr, size_t sz, int l, int r)
{
int pv, av, bw;

pv = arr[r];
for (av = l - 1, bw = r + 1; av < bw;)
{
do {
av++;
} while (arr[av] < pv);
do {
bw--;
} while (arr[bw] > pv);

if (av < bw)
{
swapy_ints(arr + av, arr + bw);
print_array(arr, sz);
}
}
return (av);
}

/**
 * hoareSorty - It's a Implement the quicksort algorithm through recursion.
 * @arr: It's a An array of integers to sort.
 * @sz: It's a The size of the array.
 * @l: It's a The starting index of the array partition to order.
 * @r: It's a The ending index of the array partition to order.
 *
 * Description: It's a Uses the Hoare partition scheme.
 */
void hoareSorty(int *arr, size_t sz, int l, int r)
{
int p;

if (r - l > 0)
{
p = hoarePartitiony(arr, sz, l, r);
hoareSorty(arr, sz, l, p - 1);
hoareSorty(arr, sz, p, r);
}
}
/**
 * quick_sort_hoare - It's only to Sort an array of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: It's a An array of integers.
 * @size: It's a The size of the array.
 *
 * Description: It's a Uses the Hoare partition scheme. Prints
 * the only array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

hoareSorty(array, size, 0, size - 1);
}
