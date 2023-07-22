#include "sort.h"

/**
* shell_sort - It's a function sorts an array of integers using
* the shell sort algorithm with Knuth sequence
* @array: It's a the array of integers
* @size: It's a size of the array
*
* Return: none because void
*/
void shell_sort(int *array, size_t size)
{
size_t g = 0, y, z;
int tp;

if (size < 2)
return;

while ((g = g * 3 + 1) < size)
;

g = (g - 1) / 3;

for (; g > 0; g = (g - 1) / 3)
{
for (z = g; z < size; i++)
{
tp = array[z];
for (y = z; y >= g && tp <= array[y - g]; y -= g)
array[y] = array[y - g];
array[y] = tp;
}
print_array(array, size);
}
}
