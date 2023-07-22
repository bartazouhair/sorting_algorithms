#include "sort.h"
/**
 * swapy - It's a sorts an array of integers in ascending order
 * @arr: It's the elements to be sorted
 * @a: It's the left element
 * @b: It's the right element
 * @sz: It's the size of array
 */
void swapy(int *arr, int a, int b, int sz)
{
int tp;

if (arr[a] == arr[b])
return;
tp = arr[a];
arr[a] = arr[b];
arr[b] = tp;
print_array(arr, sz);
}
/**
 * partitiony - It's a sort array partition
 * @arr: It's the elements to be sorted
 * @s: It's the left side
 * @e: It's the right side
 * @sz: It's the size of array
 * Return: It's a pt sorted
 */
int partitiony(int *arr, int s, int e, int sz)
{
int pt = arr[e];
int dx = s;
int k;

for (k = s; k < e; k++)
if (arr[k] < pt)
swapy(arr, dx++, k, sz);
swapy(arr, dx, e, sz);
return (dx);
}
/**
 * recursivey - It's a quick_sort core
 * @arr: It's the elements to be sorted
 * @s: It's the left side
 * @e: It's the right side
 * @sz: It's the size of array
 */
void recursivey(int *arr, int s, int e, int sz)
{
if (s < e)
{
int pos = partitiony(arr, s, e, sz);

recursivey(arr, s, pos - 1, sz);
recursivey(arr, pos + 1, e, sz);
}
}
/**
 * quick_sort - It's the sorts an array of integers in ascending order
 * @array: It's the elements to be sorted
 * @size: It's the size of array
 */
void quick_sort(int *array, size_t size)
{
recursivey(array, 0, size - 1, size);
}
