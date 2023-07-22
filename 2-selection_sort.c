#include "sort.h"

/**
 * selection_sort - It's to sorts an array for the selection sort algorithm
 * @array: Ir's array sorting
 * @size: It's obly size for the array;
 */
void selection_sort(int *array, size_t size)
{
unsigned int y, z, m;

register int tp;

if (size < 2)
return;

for (y = 0; y < size; y++)
{
m = y;
for (z = y + 1; z < size; z++)
{
if (array[z] < array[m])
m = z;
}
tp = array[y];
array[y] = array[m];
array[m] = tp;
if (y != m)
print_array(array, size);
}
}
