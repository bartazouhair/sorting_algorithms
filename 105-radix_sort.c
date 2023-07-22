#include "sort.h"

/**
 * radix_sort - It's a sorts an array the Radix sort algorithm
 * @array: It's a array of ints to sort
 * @size: It's a size of the array
 */
void radix_sort(int *array, size_t size)
{
int mx;
size_t q, ld;

if (!array || size < 2)
return;

mx = 0;
for (q = 0; q < size; q++)
if (array[q] > mx)
mx = array[q];

for (ld = 1; mx / ld > 0; ld *= 10)
{
cntSortLSD(array, size, ld);
print_array(array, size);
}
}

/**
 * cntSortLSD - It's a count sort with LSD
 * @arr: It's a array to sort
 * @sz: It's a size of the array
 * @ld: It's a least significant digit
 */
void cntSortLSD(int *arr, size_t sz, size_t ld)
{
int cr[10] = {0}, *or, t, r;
size_t q, d;

or = malloc(sizeof(int) * sz);

for (q = 0; q < sz; q++)
cr[(arr[q] / ld) % 10]++;
for (t = 1; t < 10; t++)
cr[t] += cr[t - 1];

for (r = sz - 1; r >= 0; r--)
{
or[cr[(arr[r] / ld) % 10] - 1] = arr[r];
cr[(arr[r] / ld) % 10]--;
}

for (d = 0; d < sz; d++)
arr[d] = or[d];

free(or);
}
