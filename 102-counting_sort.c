#include "sort.h"

/**
 * get_maxy - It's a Get the maximum value in an array of integers.
 * @arr: It's a An array of integers.
 * @sz: It's a The size of the array.
 *
 * Return: Return The maximum integer in the array.
 */
int get_maxy(int *arr, int sz)
{
int mx, c;

for (mx = arr[0], c = 1; c < sz; c++)
{
if (arr[c] > mx)
mx = arr[c];
}

return (mx);
}

/**
 * counting_sort - It's a Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: It's a An array of integers.
 * @size: It's a The size of the array.
 *
 * Description: It's So, Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
int *cnt, *s, mx, x;

if (array == NULL || size < 2)
return;

s = malloc(sizeof(int) * size);
if (s == NULL)
return;
mx = get_maxy(array, size);
cnt = malloc(sizeof(int) * (mx + 1));
if (cnt == NULL)
{
free(s);
return;
}

for (x = 0; x < (mx + 1); x++)
cnt[x] = 0;
for (x = 0; x < (int)size; x++)
cnt[array[x]] += 1;
for (x = 0; x < (mx + 1); x++)
cnt[x] += cnt[x - 1];
print_array(cnt, mx + 1);

for (x = 0; x < (int)size; x++)
{
s[cnt[array[x]] - 1] = array[x];
cnt[array[x]] -= 1;
}

for (x = 0; x < (int)size; x++)
array[x] = s[x];

free(s);
free(cnt);
}
