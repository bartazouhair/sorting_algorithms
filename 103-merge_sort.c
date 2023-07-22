#include "sort.h"

void mergey_subarry(int *subrr, int *bff, size_t frt, size_t md, size_t bk);
void merge_sorty_recursivey(int *subrr, int *bff, size_t frt, size_t bk);
void merge_sort(int *array, size_t size);
/**
 * mergey_subarry - It's a Sort a subarray of integers.
 * @subrr: It's A subarray of an array of integers to sort.
 * @bff: It's  a buffer to store the sorted subarray.
 * @frt: It's a The front index of the array.
 * @md: It's a The middle index of the array.
 * @bk: It's a The back index of the array.
 */
void mergey_subarry(int *subrr, int *bff, size_t frt, size_t md, size_t bk)
{
size_t a, b, c = 0;

printf("Merging...\n[left]: ");
print_array(subrr + frt, md - frt);

printf("[right]: ");
print_array(subrr + md, bk - md);

for (a = frt, b = md; a < md && b < bk; c++)
bff[c] = (subrr[a] < subrr[b]) ? subrr[a++] : subrr[b++];
for (; a < md; a++)
bff[c++] = subrr[a];
for (; b < bk; b++)
bff[c++] = subrr[b];
for (a = frt, c = 0; a < bk; a++)
subrr[a] = bff[c++];

printf("[Done]: ");
print_array(subrr + frt, bk - frt);
}
/**
 * merge_sorty_recursivey - It's a Implement the merge sort algorithm through recursion.
 * @subrr: It's A subarray of an array of integers to sort.
 * @bff: It's A buffer to store the sorted result.
 * @frt: It's a The front index of the subarray.
 * @bk: It's a The back index of the subarray.
 */
void merge_sorty_recursivey(int *subrr, int *bff, size_t frt, size_t bk)
{
size_t md;

if (bk - frt > 1)
{
md = frt + (bk - frt) / 2;
merge_sorty_recursivey(subrr, bff, frt, md);
merge_sorty_recursivey(subrr, bff, md, bk);
mergey_subarry(subrr, bff, frt, md, bk);
}
}
/**
 * merge_sort - It's a Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: It's a An array of integers.
 * @size: It's a The size of the array.
 *
 * Description: It's only For Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
int *bff;

if (array == NULL || size < 2)
return;

bff = malloc(sizeof(int) * size);
if (bff == NULL)
return;

merge_sorty_recursivey(array, bff, 0, size);

free(bff);
}
