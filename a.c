#include "monty.h"

/**
 * A11 - add top two data of the stack
 *
 * @head: head
 * @counter: line
 *
 * Return: none
*/
void A11(stack_t **head, unsigned int counter)
{
	stack_t *v;
	int w = 0, x;

	v = *head;
	while (v)
	{
		v = v->next;
		w++;
	}
	if (w < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		A8(*head);
		exit(EXIT_FAILURE);
	}
	v = *head;
	x = v->n + v->next->n;
	v->next->n = x;
	*head = v->next;
	free(v);
}



/**
 * A21 - add node to h-stack
 *
 * @head: head
 * @n: new element
 *
 * Return: none
*/
void A21(stack_t **head, int n)
{

	stack_t *g;
	stack_t *f;

	f = *head;
	g = malloc(sizeof(stack_t));
	if (g == NULL)
	{ printf("Error\n");
		exit(0); }
	if (f)
		f->prev = g;
	g->n = n;
	g->next = *head;
	g->prev = NULL;
	*head = g;
}



/**
 * A14 - divide top 2 elements of stack
 *
 * @head: stack
 * @counter: line
 *
 * Return: none
*/
void A14(stack_t **head, unsigned int counter)
{
	stack_t *l;
	int m = 0, n;

	l = *head;
	while (l)
	{
		l = l->next;
		m++;
	}
	if (m < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		A8(*head);
		exit(EXIT_FAILURE);
	}
	l = *head;
	if (l->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		A8(*head);
		exit(EXIT_FAILURE);
	}
	n = l->next->n / l->n;
	l->next->n = n;
	*head = l->next;
	free(l);
}



/**
* A7 - execute opcode
*
* @stack: head linked list
* @counter: line
* @file: monty file
* @content: line
*
* Return: no return
*/
int A7(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", A4}, {"pall", A5},
				{"pint", A6}, {"pop", A9},
				{"swap", A10}, {"add", A11},
				{"nop", A12},
				{"sub", A13},
				{"div", A14},
				{"mul", A15},
				{"mod", A16},
				{"pchar", A17},
				{"pstr", A18},
				{"rotl", A19},
				{"rotr", A20},
				{"queue", A23},
				{"stack", A24},
				{NULL, NULL}
				};
	unsigned int a = 0;
	char *b;

	b = strtok(content, " \n\t");
	if (b && b[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[a].opcode && b)
	{
		if (strcmp(op, opst[a].opcode) == 0)
		{	opst[a].f(stack, counter);
			return (0);
		}
		a++;
	}
	if (b && opst[a].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, b);
		fclose(file);
		free(content);
		A8(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}



/**
* A8 - free linked list
*
* @head: head
*
* Return: none
*/
void A8(stack_t *head)
{
	stack_t *a;

	a = head;
	while (head)
	{
		a = head->next;
		free(head);
		head = a;
	}
}
