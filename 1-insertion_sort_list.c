#include "sort.h"

/**
 * lnList - It's a returns the length of a linked list
 * @z: It's pointer to the list
 *
 * Return: Returrn a length of list
 */
int lnList(listint_t *z)
{
int ln = 0;

while (z)
{
ln++;
z = z->next;
}
return (ln);
}

/**
 * insertion_sort_list - sorts a linked list with the Insert Sort algorithm
 * @list: double pointer to the list to sort
 */
void insertion_sort_list(listint_t **list)
{
listint_t *c = NULL, *o = NULL;
listint_t *t = NULL, *th = NULL, *f = NULL;

if (!list || !(*list) || lnList(*list) < 2)
return;

c = *list;

while (c)
{
if (c->prev && c->n < c->prev->n)
{
o = c->prev->prev;
t = c->prev;
th = c;
f = c->next;

t->next = f;
if (f)
f->prev = t;
th->next = t;
th->prev = o;
if (o)
o->next = th;
else
*list = th;
t->prev = th;
c = *list;
print_list(*list);
continue;
}
else
c = c->next;
}
}
