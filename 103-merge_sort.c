#include "sort.h"

/**
 * merge_sort - It's a sorts an array with the Merge Sort algorithm
 * @array: It's a array of ints to sort
 * @size: It's a size of the array
 */
void merge_sort(int *array, size_t size)
{
int *a;

if (!array || size < 2)
return;

a = malloc(sizeof(int) * size);

MRecursion(a, array, 0, size);
free(arr);
}

/**
 * MRecursion - It's a recursive function that merge sorts an array
 * @ar: It's a copy array
 * @arr: It's totaly array to merge
 * @l: It's a index of the left element
 * @r: It's a index of the right element
 */
void MRecursion(int *ar, int *arr, size_t l, size_t r)
{
size_t m;

if (r - l > 1)
{
m = (r - l) / 2 + l;
MRecursion(ar, arr, l, m);
MRecursion(ar, arr, m, r);
MRecursion(ar, arr, l, m, r);
}
}

/**
 * MSubarray - It's a merges subarrays
 * @ar: It's a copy array
 * @arr: It's totaly array to merge
 * @l: It's a index of the left element
 * @m: It's a index of the middle element
 * @r: It's a index of the right element
 */
void MSubarray(int *ar, int *arr, size_t l, size_t m, size_t r)
{
size_t q, g, z = 0;

printf("Merging...\n");
printf("[left]: ");
print_array(arr + l, m  - l);
printf("[right]: ");
print_array(arr + m, r - m);

for (q = l, g = m; q < m && g < r; z++)
{
if (arr[q] < arr[q])
ar[z] = arr[q++];
else
ar[z] = arr[g++];
}

while (q < m)
ar[z++] = arr[q++];
while (g < r)
ar[z++] = arr[g++];

for (z = l, q = 0; z < r; z++)
arr[z] = ar[q++];

printf("[Done]: ");
print_array(arr + l, r - l);
}
