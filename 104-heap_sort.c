#include "sort.h"

/**
 * heap_sort - It's a sorts an array following the Heap sort algorithm
 * @array: It's a array of ints to sort
 * @size: It's a size of the array to sort
 */
void heap_sort(int *array, size_t size)
{
int q;
int tp;

if (size < 2)
return;

for (q = size / 2 - 1; q >= 0; q--)
heapIfeey(array, size, (size_t)q, size);

for (q = size - 1; q >= 0; q--)
{
tp = array[q];
array[q] = array[0];
array[0] = tp;
if (q != 0)
print_array(array, size);
heapIfeey(array, (size_t)q, 0, size);
}
}

/**
 * heapIfeey - It's a turns an array in a heap tree
 * @arr: It's a array to turn into heap
 * @siz: Its' a size of the subtree
 * @r: index of the subtree in the heap
 * @sz: size of the whole array
 */
void heapIfeey(int *arr, size_t siz, size_t r, size_t sz)
{
size_t mx, l, rg;
int tp;

mx = r;
l = (r * 2) + 1;
rg = (r * 2) + 2;

if (l < siz && arr[l] > arr[mx])
mx = l;

if (rg < siz && arr[rg] > arr[mx])
mx = rg;

if (mx != r)
{
tp = arr[r];
arr[r] = arr[mx];
arr[mx] = tp;
print_array(arr, sz);
heapIfeey(arr, siz, mx, sz);
}
}
