#ifndef MAIN_H
#define MAIN_H

/**
 * struct stack_s - doubly linked list representation of a stack (or a queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * forstack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instructin_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void verify_cmdline_arg(int n);
void _getline(FILE *file, char **instruction);
void verify_instruction(char **instruction, size_t line);
void push(int data);
void pall();
void pint();
void pop();
void swap();
void add();
void nop();
#endif
