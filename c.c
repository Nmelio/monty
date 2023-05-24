#include "monty.h"

/**
 * A6 - prints top stack
 *
 * @head: head
 * @counter: line
 *
 * Return: none
*/
void A6(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		A8(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}



/**
 * A9 - prints top
 *
 * @head: head
 * @counter: line
 *
 * Return: none
*/
void A9(stack_t **head, unsigned int counter)
{
	stack_t *z;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		A8(*head);
		exit(EXIT_FAILURE);
	}
	z = *head;
	*head = z->next;
	free(z);
}



/**
 * A18 - print string start at top stack
 *
 * @head: head
 * @counter: line
 *
 * Return: none
*/
void A18(stack_t **head, unsigned int counter)
{
	stack_t *z;
	(void)counter;

	z = *head;
	while (z)
	{
		if (z->n > 127 || z->n <= 0)
		{
			break;
		}
		printf("%c", z->n);
		z = z->next;
	}
	printf("\n");
}



/**
 * A4 - add node to stack
 *
 * @head: head
 * @counter: line
 *
 * Return: none
*/
void A4(stack_t **head, unsigned int counter)
{
	int l, m = 0, o = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			m++;
		for (; bus.arg[m] != '\0'; m++)
		{
			if (bus.arg[m] > 57 || bus.arg[m] < 48)
				o = 1; }
		if (o == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			A8(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		A8(*head);
		exit(EXIT_FAILURE); }
	l = atoi(bus.arg);
	if (bus.lifi == 0)
		A21(head, l);
	else
		A22(head, l);
}
