#include "sort.h"
/**
*swapy - Its' a swaps 2 nodes in a doubly-linked list
*@aa: It's a address of first node
*@bb: It's a address of second node
*
*Return: void
*/
void swapy(listint_t *aa, listint_t *bb)
{
if (aa->prev)
aa->prev->next = bb;
if (bb->next)
bb->next->prev = aa;
aa->next = bb->next;
bb->prev = aa->prev;
aa->prev = bb;
bb->next = aa;
}
/**
*tail_traversey- It's a function that sorts from the tail back
*
*@h: It's a head of list
*@t: It's a tail of the list
*@lst: It's a original head of the list
*
*Return: retun a new head of the list (lst)
*/
listint_t *tail_traversey(listint_t *h, listint_t *t, listint_t *lst)
{
while (t && t->prev)
{
if (t->n < t->prev->n)
{
swapy(t->prev, t);
if (t->prev == NULL)
lst = t;
print_list(lst);
}
else
t = t->prev;
if (t->prev == NULL)
h = t;
}
return (h);
}

/**
*cocktail_sort_list - It's a sorts linked list using cocktail shaker sort
*
*@list: It's a doubly linked list to be sorted (lst)
*/
void cocktail_sort_list(listint_t **list)
{
listint_t *t, *h, *lnn;
int a = 0, b = 0, swpd = 1;

if (!list || !*list)
return;
lnn = *list;
for (a = 0; lnn; a++)
{
lnn = lnn->next;
}
if (a < 2)
return;
h = *list;
while (b < a)
{
swpd = 0;
while (h && h->next)
{
if (h->n > h->next->n)
{
swapy(h, h->next);
swpd++;
if (h->prev->prev == NULL)
*list = h->prev;
print_list(*list);
}
else
h = h->next;
if (h->next == NULL)
t = h;
}
h = tail_traversey(h, t, *list);
*list = h;
b++;
}
}
