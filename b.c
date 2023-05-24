#include "monty.h"

/**
 * A16 - compute rest the division second by top element
 *
 * @head: head
 * @counter: line
 *
 * Return: none
*/
void A16(stack_t **head, unsigned int counter)
{
	stack_t *w;
	int x = 0, y;

	w = *head;
	while (w)
	{
		w = w->next;
		x++;
	}
	if (x < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		A8(*head);
		exit(EXIT_FAILURE);
	}
	w = *head;
	if (w->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		A8(*head);
		exit(EXIT_FAILURE);
	}
	y = w->next->n % w->n;
	w->next->n = y;
	*head = w->next;
	free(w);
}



/**
 * A15 - multiplie top two elements
 *
 * @head: head
 * @counter: line
 *
 * Return: none
*/
void A15(stack_t **head, unsigned int counter)
{
	stack_t *w;
	int x = 0, y;

	w = *head;
	while (w)
	{
		w = w->next;
		x++;
	}
	if (x < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		A8(*head);
		exit(EXIT_FAILURE);
	}
	w = *head;
	y = w->next->n * w->n;
	w->next->n = y;
	*head = w->next;
	free(w);
}



/**
  *A12- nullify
  *
  *@head: head
  *@counter: line
  *
  *Return: none
 */
void A12(stack_t **head, unsigned int counter)
{
	(void) counter;
	(void) head;
}



/**
 * A5 - print stack
 *
 * @head: head
 * @counter: line
 *
 * Return: no return
*/
void A5(stack_t **head, unsigned int counter)
{
	stack_t *w;
	(void)counter;

	w = *head;
	if (w == NULL)
		return;
	while (w)
	{
		printf("%d\n", w->n);
		w = w->next;
	}
}



/**
 * A17 - print char at top
 *
 * @head: head
 * @counter: line
 *
 * Return: none
*/
void A17(stack_t **head, unsigned int counter)
{
	stack_t *w;

	w = *head;
	if (!w)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		A8(*head);
		exit(EXIT_FAILURE);
	}
	if (w->n > 127 || w->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n",
			counter);
		fclose(bus.file);
		free(bus.content);
		A8(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", w->n);
}
