#include "sort.h"

/**
 * bubble_sort - It's sorts an array of integers in ascending order using the
 * Bubble sort algorithme
 * @array: It's the array to be sorted
 * @size: It's the size of the array (arr)
 *
 * Return: It's void
 */

void bubble_sort(int *array, size_t size)
{
size_t j, m, new_m;
int sp;

if (array == NULL || size < 2)
return;

m = size;
while (m > 0)
{
new_m = 0;
for (j = 0; j < m - 1; j++)
{
if (array[j] > array[j + 1])
{
sp = array[j];
array[j] = array[j + 1];
array[j + 1] = sp;
new_m = j + 1;
print_array(array, size);
}
}
m = new_m;
}
}
