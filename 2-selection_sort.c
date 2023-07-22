#include "sort.h"
/**
 * selection_sort - It's a sorts an array of integers in ascending order
 * @array: It's the element to be sorted
 * @size: It's only the size of array
 */
void selection_sort(int *array, size_t size)
{
unsigned int y, w;

if (size < 2)
return;

for (y = 0; y < size; y++)
{
unsigned int z = y;
int tem = array[y];

for (w = y + 1; w < size; w++)
{
if (array[y] < tem)
tem = array[w], z = w;
}
if (z != y)
{
array[z] = array[y];
array[y] = tem;
print_array(array, size);
}
}
}
