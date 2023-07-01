#include "deck.h"

int strcmp_(const char *string1, const char *string2);
char get_value(deck_node_t *card);
void sort_deck_kind(deck_node_t **deck);
void sort_deck_value(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
  * strcmp_ - compares two strings
  * @string1: first string to compare
  * @string2: second string to compare
  *
  * Return: 0 always success
  */
int strcmp_(const char *string1, const char *string2)
{
    while (*string1 && *string2 && *string1 == *string2)
    {
        string1++;
        string2++;
    }

    if (*string1 != *string2)
        return (*string1 - *string2);
    return (0);
}

/**
 * get_value - gets the numerical value of a card
 * @card: pointer to a node of a card
 *
 * Return: numerical card value
 */
char get_value(deck_node_t *card)
{
    if (strcmp_(card->card->value, "Ace") == 0)
		return (0);
    if (strcmp_(card->card->value, "1") == 0)
        return (1);
    if (strcmp_(card->card->value, "2") == 0)
        return (2);
    if (strcmp_(card->card->value, "3") == 0)
        return (3);
    if (strcmp_(card->card->value, "4") == 0)
        return (4);
    if (strcmp_(card->card->value, "5") == 0)
        return (5);
    if (strcmp_(card->card->value, "6") == 0)
        return (6);
    if (strcmp_(card->card->value, "7") == 0)
        return (7);
    if (strcmp_(card->card->value, "8") == 0)
        return (8);
    if (strcmp_(card->card->value, "9") == 0)
        return (9);
    if (strcmp_(card->card->value, "10") == 0)
        return (10);
    if (strcmp_(card->card->value, "11") == 0)
        return (11);
    if (strcmp_(card->card->value, "12") == 0)
        return (12);
    return (13);
}

/**
 * sort_deck - sort a deck of cards uses insertion algorithmn
 * @deck: pointer to the head
 *
 */
void sort_deck_kind(deck_node_t **deck)
{
    deck_node_t *count, *insert, *temp;

    for (count = (*deck)->next; count != NULL; count = temp)
OAOAOA    {
        temp = count->next;
OAOAOAOAOAOAOAOAOAOAOAOA        insert = count->prev;
        while (insert != NULL && insert->card->kind > count->card->kind)
        {
            insert->next = count->next;
            if (count->next != NULL)
                    count->next->prev = insert;
            count->prev = insert->next;
            count->next = insert;
            if (insert->prev != NULL)
                    insert->prev->next = count;
            else
                    *deck = count;
            insert->prev = count;
            insert = count->prev;
        }
    }
}

/**
 * sort_deck - sort a deck of cards uses insertion algorithmn
 * @deck: pointer to head
 *
 */
void sort_deck_value(deck_node_t **deck)
{
    deck_node_t *count, *insert, *temp;

    for (count = (*deck)->next; count != NULL; count = temp)
    {
        temp = count->next;
        insert = count->prev;
        while (insert != NULL &&
               insert->card->kind == count->card->kind &&
               get_value(insert) > get_value(count))
        {
            insert->next = count->next;
            if (count->next != NULL)
                    count->next->prev = insert;
            count->prev = insert->prev;
            count->next = insert;
            if (insert->prev != NULL)
                    insert->prev->next = count;
            else
                    *deck = count;
            insert->prev = count;
            insert = count->prev;
        }
    }
}

/**
 * sort_deck - Sort a deck of cards from ace to king and
 *             from spades to diamonds.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	sort_deck_kind(deck);
	sort_deck_value(deck);
}
