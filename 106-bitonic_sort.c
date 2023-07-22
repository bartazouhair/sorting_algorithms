#include "sort.h"
#include <stdio.h>

/**
 * printchecky - It's only to print a range
 * @arr: It's a the array to print
 * @rg1: It's a Less range
 * @rg2: It's a Final range
 * Return: Nothing bacause it's void
 */
void printchecky(int *arr, int rg1, int rg2)
{
int y;

for (y = rg1; y <= rg2; y++)
{
if (y > rg1)
printf(", ");
printf("%d", arr[y]);
}
printf("\n");
}
/**
 * _swapy - It's a swap two elements in an array
 * @arr: It's only THe array to change the values
 * @idx: It's A index
 * @jdx: It's Another index
 * @d: It's only Direction of the array
 * Return: Nothing bacause it's void
 */
void _swapy(int *arr, int idx, int jdx, int d)
{
int t;

if (d == (arr[idx] > arr[jdx]))
{
t = arr[idx];
arr[idx] = arr[jdx];
arr[jdx] = t;
}
}
/**
 * bitonic_mergey - It's only to swap the elements to sort
 * @arr: It's the Array to sort
 * @l: It's a The low element in the range to sort
 * @sz: It's only The size of the range to sort
 * @d: It's is Indicate which half are manage
 * @r_sz: It's a The size of the all array
 * Return: Nothing bacause it's void
 */
void bitonic_mergey(int *arr, int l, int sz, int d, const int r_sz)
{
int m = sz, y = l;

if (sz > 1)
{
m = sz / 2;

for (y = l; y < l + m; y++)
_swapy(arr, y, y + m, d);

bitonic_mergey(arr, l, m, d, r_sz);
bitonic_mergey(arr, l + m, m, d, r_sz);
}
}
/**
 * _sorty - It's only segmentate the array
 * @arr: It's a The array to sort
 * @l: It's a The lowest element in each range
 * @sz: IOt's only Size of the range to sort
 * @d: It's Indicate which half are manage
 * @r_sz: It's The size of the all array
 * Return: Nothing because it's void
 */
void _sorty(int *arr, int l, int sz, int d, const int r_sz)
{
int m = sz;

if (sz > 1)
{
if (d == 1)
printf("Merging [%d/%d] (UP):\n", sz, r_sz);
if (d == 0)
printf("Merging [%d/%d] (DOWN):\n", sz, r_sz);
printchecky(arr, l, l + m - 1);

m = sz / 2;
_sorty(arr, l, m, 1, r_sz);

_sorty(arr, l + m, m, 0, r_sz);

bitonic_mergey(arr, l, sz, d, r_sz);
if (d == 1)
{
printf("Result [%d/%d] (UP):\n", sz, r_sz);
printchecky(arr, l, l + 2 * m - 1);
}
if (d == 0)
{
printf("Result [%d/%d] (DOWN):\n", sz, r_sz);
printchecky(arr, l, l + 2 * m - 1);
}
}
}
/**
 * bitonic_sort - It's only to call the sort function
 * @array: It's The array to sort
 * @size: It's only Size of the array
 * Return: Nothing because iit's void
 */
void bitonic_sort(int *array, size_t size)
{
int ux = 1;
const int r_sz = (int)size;

if (size < 2 || !array)
return;

_sorty(array, 0, (int)size, ux, r_sz);
}
