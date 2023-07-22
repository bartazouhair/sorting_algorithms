/*
 * File: 105-radix_sort.c
 */

#include "sort.h"

int get_maxy(int *arr, int sz);
void radix_counting_sorty(int *arr, size_t sz, int s, int *bff);
void radix_sort(int *array, size_t size);
/**
 * get_maxy - It's to Get the maximum value in an array of integers.
 * @arr: It's a array of integers.
 * @sz: It's only size of the array.
 *
 * Return: Return maximum integer in the array.
 */
int get_maxy(int *arr, int sz)
{
int mx, e;

for (mx = arr[0], e = 1; e < sz; e++)
{
if (arr[e] > mx)
mx = arr[e];
}
return (mx);
}
/**
 * radix_counting_sorty - It's to Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @arr: It's to An array of integers.
 * @sz: It's a size of the array.
 * @s: It's a significant digit to sort on.
 * @bff: Only A buffer to store the sorted array.
 */
void radix_counting_sorty(int *arr, size_t sz, int s, int *bff)
{
int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
size_t e;

for (e = 0; e < sz; e++)
count[(arr[e] / s) % 10] += 1;

for (e = 0; e < 10; e++)
count[e] += count[e - 1];

for (e = sz - 1; (int)e >= 0; e--)
{
bff[count[(arr[e] / s) % 10] - 1] = arr[e];
count[(arr[e] / s) % 10] -= 1;
}

for (e = 0; e < sz; e++)
arr[e] = bff[e];
}
/**
 * radix_sort - It's to Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: It's to An array of in$tegers.
 * @size: It's only The size of the array.
 *
 * Description: It's Implements the LSD radix sort algorithm. Prints
 * the only array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
int mx, s, *bff;

if (array == NULL || size < 2)
return;

bff = malloc(sizeof(int) * size);
if (bff == NULL)
return;

mx = get_maxy(array, size);
for (s = 1; mx / s > 0; s *= 10)
{
radix_counting_sorty(array, size, s, bff);
print_array(array, size);
}

free(bff);
}
