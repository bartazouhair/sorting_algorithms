#include "sort.h"
/**
 * shell_sorty - It's a Sort an array using shell_sort algorithm
 * @array: It's only array
 * @size: It's the size of the array
 * Return: It's NULL because it's void
 **/
void shell_sort(int *array, size_t size)
{
unsigned int gp = 1, a, b;
int tp;

if (array == NULL)
return;
if (size < 2)
return;
while (gp < size / 3)
gp = gp * 3 + 1;

while (gp > 0)
{
for (a = gp; a < size; a++)
{
tp = array[a];
b = a;
while (b >= gp && array[b - gp] > tp)
{
array[b] = array[b - gp];
b -= gp;
}
array[b] = tp;
}
print_array(array, size);
gp /= 3;
}
}
