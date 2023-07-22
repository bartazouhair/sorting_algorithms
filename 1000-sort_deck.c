#include <stdlib.h>
#include <string.h>
#include "deck.h"

/**
 * _strcmpy - It's to Compares two strings.
 * @c1: It's a The first string to be compared.
 * @c2: It's a The second string to be compared.
 *
 * Return: It's a Positive byte difference if s1 > s2
 *         And 0 if s1 == s2
 *         And Negative byte difference if s1 < s2
 */
int _strcmpy(const void *c1, const void *c2)
{
const card_t *cd1 = *(const card_t **)c1;
const card_t *cd2 = *(const card_t **)c2;

if (cd1->kind != cd2->kind)
return (cd1->kind - cd2->kind);
else
return (strcmp(cd1->value, cd2->value));
}
/**
 * sort_deck - It's a Sort a deck of cards from ace to king and
 *             from spades to diamonds.
 * @deck: It's only A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck(deck_node_t **deck)
{
size_t y;
card_t *crd[52];
deck_node_t *nd;

if (deck == NULL || *deck == NULL)
return;

nd = *deck;
for (y = 0; y < 52; y++)
{
crd[y] = (card_t *)nd->card;
nd = nd->next;
}

qsort(crd, 52, sizeof(card_t *), _strcmpy);

nd = *deck;
for (y = 0; y < 52; y++)
{
nd->card = crd[y];
nd = nd->next;
}
}
