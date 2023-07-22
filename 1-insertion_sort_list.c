#include "sort.h"
/**
 * swapy_two - It's a swap to doubly linked list elements
 * @aa: It's the left element
 * @bb: It's the right element
 * @lt: It's a all doubly linked list
 * Return: pointer to a element (actual)
 */
listint_t *swapy_tow(listint_t *aa, listint_t *bb, listint_t **lt)
{
if (aa->prev)
(aa->prev)->next = bb;
else
*lt = bb, bb->prev = NULL;
if ((bb->next))
(bb->next)->prev = aa;
bb->prev = aa->prev;
aa->prev = bb;
aa->next = bb->next;
bb->next = aa;
return (aa);
}
/**
 * insertion_sort_list - It's a bsorts list in ascending order
 * @list: It's only a doubly linked list of integers to be sorted
 */
void insertion_sort_list(listint_t **list)
{
listint_t *actl;
listint_t *prev, *back;

if (!list || !(*list) || !(*list)->next)
return;

actl = (*list)->next;
while (actl)
{
prev = actl->prev;
back = actl;
while (back->prev && back->n < prev->n)
{
actl = swapy_tow(prev, back, list);
print_list(*list);
if (!back->prev)
break;
prev = back->prev;
}
actl = actl->next;
prev = prev->next;
}
}
