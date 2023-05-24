#include "monty.h"

/**
 * A23 - prints top
 *
 * @head: head
 * @counter: line
 *
 * Return: none
*/
void A23(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 1;
}



/**
 * A22 - add node tail
 *
 * @n: new
 * @head: head
 *
 * Return: none
*/
void A22(stack_t **head, int n)
{
	stack_t *a, *b;

	b = *head;
	a = malloc(sizeof(stack_t));
	if (a == NULL)
	{
		printf("Error\n");
	}
	a->n = n;
	a->next = NULL;
	if (b)
	{
		while (b->next)
			b = b->next;
	}
	if (!b)
	{
		*head = a;
		a->prev = NULL;
	}
	else
	{
		b->next = a;
		a->prev = b;
	}
}



/**
  *A20- rotate stack bottom
  *
  *@head: head
  *@counter: line
  *
  *Return: none
 */
void A20(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *c;

	c = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (c->next)
	{
		c = c->next;
	}
	c->next = *head;
	c->prev->next = NULL;
	c->prev = NULL;
	(*head)->prev = c;
	(*head) = c;
}



/**
 * A24 - prints top
 *
 * @head: head
 * @counter: line
 *
 * Return: none
*/
void A24(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 0;
}



/**
  *A13- sub (minus)
  *
  *@head: head
  *@counter: line
  *
  *Return: none
 */
void A13(stack_t **head, unsigned int counter)
{
	stack_t *a;
	int b, c;

	a = *head;
	for (c = 0; a != NULL; c++)
		a = a->next;
	if (c < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		A8(*head);
		exit(EXIT_FAILURE);
	}
	a = *head;
	b = a->next->n - a->n;
	a->next->n = b;
	*head = a->next;
	free(a);
}
