#include "deck.h"

/**
 * sort_deck - It's a sorts a deck of card
 * @deck: It's only doubly linked list to sort
 */
void sort_deck(deck_node_t **deck)
{
deck_node_t *c;
size_t ln;
deck_node_t *o, *t, *th, *f;

ln = listLenDeck(*deck);

if (!deck || !*deck || ln < 2)
return;

c = *deck;
while (c)
{
if (c->prev && cardValue(c) < cardValue(c->prev))
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
*deck = th;
t->prev = th;
c = *deck;
continue;
}
else
c = c->next;
}
}

/**
 * cardValue - It's returns the value of a card
 * @nd: It's a card in a deck
 *
 * Return: It's a value between 1 and 52 interval
 */
int cardValue(deck_node_t *nd)
{
char *v[13] = {"Ace", "2", "3", "4", "5", "6",
"7", "8", "9", "10", "Jack", "Queen", "King"};
char *k[4] = {"SPADE", "HEART", "CLUB", "DIAMOND"};
int z, kv = 0;

for (z = 1; z <= 13; z++)
{
if (!_itstrcmp(nd->card->value, v[z - 1]))
kv = z;
}

for (z = 1; z <= 4; z++)
{
if (!_itstrcmp(k[nd->card->kind], k[z - 1]))
kv = kv + (13 * z);
}
return (kv);
}

/**
 * _itstrcmp - It's to compares two strings
 * @c1: It's a first string to compare
 * @c2: It's a second string to compare
 *
 * Return: It's a less than 0 if s1 is less than s2, 0 if they're equal,
 * more than 0 if s1 is greater than s2
 */
int _itstrcmp(const char *c1, const char *c2)
{
while (*c1 == *c2)
{
if (*c1 == '\0')
{
return (0);
}
c1++;
c2++;
}
return (*c1 - *c2);
}

/**
 * listLenDeck - It's a function returns length of list
 * @lst: It's only head of list
 *
 * Return: It's length fir this function
 */
size_t listLenDeck(deck_node_t *lst)
{
size_t ln = 0;

while (lst)
{
ln++;
lst = lst->next;
}
return (ln);
}
