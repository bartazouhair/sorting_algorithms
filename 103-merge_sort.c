#include "sort.h"

void mg(size_t il, size_t md, size_t mh, int *d, int *c);
void mp(size_t ml, size_t mh, int *ay, int *cp);
/**
 * merge_sort - It's A function that sorts an array using merge
 * @array: It's a The array
 * @size: It's a size of the array
 * Return: Rien because is void
 */
void merge_sort(int *array, size_t size)
{
size_t w;
int *p = NULL;

if (!array || size < 2)
return;
p = malloc(sizeof(int) * size);
if (!p)
return;
for (w = 0; w < size; w++)
p[w] = array[w];
mp(0, size, array, p);
free(p);
}

/**
 * mg - It's A function that prints subarrays.
 * @il: It's a index lower
 * @md: It's a index midlle
 * @mh: It'a index higher
 * @d: It's a Data destination
 * @c: It's a input data
 * Return: rien because its void
 */
void mg(size_t il, size_t md, size_t mh, int *d, int *c)
{
size_t z = 0, q = 0, w = 0;

printf("Merging...\n");
printf("[left]: ");
print_array(c + il, md - il);
printf("[right]: ");
print_array(c + md, mh - md);
z = il;
q = md;
w = il;
for (; w < mh; w++)
{
if (z < md && (q >= mh || c[z] <= c[q]))
{
d[w] = c[z];
z++;
}
else
{
d[w] = c[q];
q++;
}
}
printf("[Done]: ");
print_array(d + il, mh - il);
}
/**
 * mp - It's A funtion that separet array
 * @ml: index loweer
 * @mh: index higher
 * @ay: The array
 * @cp: The copy of arry
 * Return: Rien parceque it's void
 */
void mp(size_t ml, size_t mh, int *ay, int *cp)
{
size_t r = 0;

if (mh - ml < 2)
return;
r = (ml + mh) / 2;
mp(ml, r, ay, cp);
mp(r, mh, ay, cp);
mg(ml, r, mh, ay, cp);
for (r = ml; r < mh; r++)
cp[r] = ay[r];
}
