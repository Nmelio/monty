#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t bus;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

char *A1(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t A2(char **lineptr, int file);
char  *A3(char *content);
void A4(stack_t **head, unsigned int number);
void A5(stack_t **head, unsigned int number);
void A6(stack_t **head, unsigned int number);
int A7(char *content, stack_t **head, unsigned int counter, FILE *file);
void A8(stack_t *head);
void A9(stack_t **head, unsigned int counter);
void A10(stack_t **head, unsigned int counter);
void A11(stack_t **head, unsigned int counter);
void A12(stack_t **head, unsigned int counter);
void A13(stack_t **head, unsigned int counter);
void A14(stack_t **head, unsigned int counter);
void A15(stack_t **head, unsigned int counter);
void A16(stack_t **head, unsigned int counter);
void A17(stack_t **head, unsigned int counter);
void A18(stack_t **head, unsigned int counter);
void A19(stack_t **head, unsigned int counter);
void A20(stack_t **head, __attribute__((unused)) unsigned int counter);
void A21(stack_t **head, int n);
void A22(stack_t **head, int n);
void A23(stack_t **head, unsigned int counter);
void A24(stack_t **head, unsigned int counter);

#endif
