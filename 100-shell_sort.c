#include "sort.h"

/**
 * shell_sort - It's a Sorts an array of integers in ascending order using Shell sort algorithm with Knuth sequence
 * @array: It's a Array to be sorted
 * @size: It's a Size of the array
 */
void shell_sort(int *array, size_t size)
{
size_t g = 1, z, y;
int tp;

if (array == NULL || size < 2)
return;

while (g < size / 3)
g = g * 3 + 1;

while (g > 0)
{
for (z = g; z < size; z++)
{
tp = array[z];
y = z;

while (y >= g && array[y - g] > tp)
{
array[y] = array[y - g];
y -= g;
}

array[y] = tp;
}

print_array(array, size);
g /= 3;
}
}
