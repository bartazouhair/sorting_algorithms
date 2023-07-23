#include "sort.h"

/**
 * mppe - It's a prints array value
 *
 * @arr: It's a array printed
 * @mt: my_text printed values
 * @ml: low boun
 * @mht: up boun
 */
void mppe(int *arr, const char *mt,
		size_t ml, size_t mht)
{
	size_t q;
	char *sp = "";

	printf("[%s]: ", mt);
	for (q = ml; q <= mht; q++)
	{
		printf("%s%d", sp, arr[q]);
		sp = ", ";
	}
	printf("\n");
}
/**
 * my_jp - It's a join value sort in the array
 * parsed
 *
 * @arr: It's a array sorted
 * @ml: It's a start index array passe
 * @mht: It's a end index array passed
 * @md: It's a mid split array
 * @cp: It's a array sorte values
 */
void my_jp(int *arr, size_t ml, size_t mht,
		size_t md, int *cp)
{
	size_t mh = md + 1, mdex, ms = ml, q;

	printf("Merging...\n");
	mppe(arr, "left", ml, md);
	mppe(arr, "right", md + 1, mht);

	for (mdex = ml; mdex <= mht; mdex++)
	{
		if ((ms <= md && arr[ms] <= arr[mh]) ||
				mh > mht)
			cp[mdex] = arr[ms++];
		else
			cp[mdex] = arr[mh++];
	}

	for (q = ml; q <= mht; q++)
		arr[q] = cp[q];

	mppe(arr, "Done", ml, mht);
}

/**
 * my_p - recur merge sort et sort the
 * giv array
 *
 * @arr: It's a array sorted
 * @lb: It's a low boun
 * @ub: Its' a up boun
 * @cp: Its' a array store values
 */
void my_p(int *arr, size_t lb, size_t ub, int *cp)
{
	size_t md;

	if (lb < ub)
	{
		md = (ub + lb - 1) / 2;

		my_p(array, lb, md, cp);
		my_p(array, md + 1, ub, cp);

		my_jp(array, lb, ub, md, cp);
	}
}

/**
 * merge_sort - It's a appli the merge sort
 * algorithm sort an array integers
 *
 * @array: It's a array sorted
 * @size: It's a size array
 */
void merge_sort(int *array, size_t size)
{
	int *mc;

	if (!array || size < 2)
		return;

	mc = malloc(sizeof(int) * size);
	if (!mc)
		return;

	my_p(array, 0, size - 1, mc);
	free(mc);
}
