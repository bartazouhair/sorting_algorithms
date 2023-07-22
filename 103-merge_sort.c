#include <stdlib.h>
#include <stdio.h>

void print_array(const int *array, size_t size);  /* Forward declaration */

/**
 * mg - It's a Merges two subarrays into one sorted array
 * @arr: It's a Pointer to the original array
 * @l: It's a Pointer to the left subarray
 * @lz: It's a Size of the left subarray
 * @r: It's a Pointer to the right subarray
 * @rz: It's a Size of the right subarray
 */
void mg(int *arr, int *l, size_t lz, int *r, size_t rz)
{
size_t q = 0, y = 0, z = 0;
size_t s = lz + rz;
int *tp = malloc(sizeof(int) * s);

printf("Merging...\n[left]: ");
print_array(l, lz);
printf("[right]: ");
print_array(r, rz);

printf("[Done]: ");
while (q < lz && y < rz)
{
if (l[q] <= r[y])
tp[z++] = l[q++];
else
tp[z++] = r[y++];
}

while (q < lz)
tp[z++] = l[q++];

while (y < rz)
tp[z++] = r[y++];

for (q = 0; q < s; q++)
{
arr[q] = tp[q];
if (q < s - 1)
printf("%d, ", array[q]);
else
printf("%d\n", array[q]);
}

free(tp);
}

/**
 * merge_sort - It's a Sorts an array of integers in ascending order using
 *              the merge sort algorithm
 * @array: It's a Pointer to the array to be sorted
 * @size: It's a Size of the array
 *
 * * Description: It's So, Merge and sort
 */
void merge_sort(int *array, size_t size)
{
size_t m;
int *l, *r;

if (size < 2 || array == NULL)
return;

m = size / 2;
l = array;
r = array + m;

merge_sort(l, m);
merge_sort(r, size - m);

mg(array, l, m, r, size - m);

printf("\n");
}
