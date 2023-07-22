#include "sort.h"

void swapy_intsy(int *x, int *z);
void maxy_heapify(int *arr, size_t sz, size_t bs, size_t rt);
void heap_sort(int *array, size_t size);
/**
 * swapy_intsy - It's a Swap two integers in an array.
 * @x: It's a The first integer to swap.
 * @z: It's a The second integer to swap.
 */
void swapy_intsy(int *x, int *z)
{
int tp;

tp = *x;
*x = *z;
*z = tp;
}
/**
 * maxy_heapify - It's a Turn a binary tree into a complete binary heap.
 * @arr: It's a An array of integers representing a binary tree.
 * @sz: It's a The size of the array/tree.
 * @bs: It's a The index of the base row of the tree.
 * @rt: It's a The root node of the binary tree.
 */
void maxy_heapify(int *arr, size_t sz, size_t bs, size_t rt)
{
size_t l, r, g;

l = 2 * rt + 1;
r = 2 * rt + 2;
g = rt;

if (l < bs && arr[l] > arr[g])
g = l;
if (r < bs && arr[r] > arr[g])
g = r;

if (g != rt)
{
swapy_intsy(arr + rt, arr + g);
print_array(arr, sz);
maxy_heapify(arr, sz, bs, g);
}
}

/**
 * heap_sort - It's a Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: It's a An array of integers.
 * @sz: It's The size of the array.
 *
 * Description: It's a For Implements the sift-down heap sort
 * algorithme. So Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
int p;

if (array == NULL || size < 2)
return;

for (p = (size / 2) - 1; p >= 0; p--)
maxy_heapify(array, size, size, p);

for (p = size - 1; p > 0; p--)
{
swapy_intsy(array, array + p);
print_array(array, size);
maxy_heapify(array, size, p, 0);
}
}
