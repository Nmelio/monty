#include "monty.h"

/**
  * A19- rotate stack at top
  *
  * @head: head
  * @counter: line
  *
  * Return: none
 */
void A19(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
	stack_t *k = *head;
	stack_t *q;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	q = (*head)->next;
	q->prev = NULL;
	while (k->next != NULL)
	{
		k = k->next;
	}
	k->next = *head;
	(*head)->next = NULL;
	(*head)->prev = k;
	(*head) = q;
}



/**
 * A10 - adde top two element
 *
 * @head: head
 * @counter: line
 *
 * Return: none
*/
void A10(stack_t **head, unsigned int counter)
{
	stack_t *a;
	int b = 0, c;

	a = *head;
	while (a)
	{
		a = a->next;
		b++;
	}
	if (b < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		A8(*head);
		exit(EXIT_FAILURE);
	}
	a = *head;
	c = a->n;
	a->n = a->next->n;
	a->next->n = c;
}
