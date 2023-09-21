#include "monty.h"
stack_t *head = NULL;

/**
 * read_line - reads line and separate to tokens
 * @content: line
 * @line_n: number of line
 * @format: 0 for stack, 1 for queues
 * Return: 0 if stack, 1 for queues
 */
int read_line(char *content, int line_n, int format)
{
	char *opcode, *data;

	if (content == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	opcode = strtok(content, "\n ");
	if (!opcode)
		return (format);
	data = strtok(NULL, "\n ");

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);
	execute(opcode, data, line_n, format);
	return (format);
}

/**
 * execute - executes the function
 * @opcode: opcode
 * @data: value entered
 * @line_n: number of line
 * @format: 0 for stack, 1 for queues
 */
void execute(char *opcode, char *data, int line_n, int format)
{
	int i, flag;

	instruction_t functions[] = {
		{"push", push},
		{"pall", print_all},
		{"pint", print_top},
		{"pop", pop},
		{"nop", nop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", divide},
		{"mul", mul},
		{"mod", mod},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};
	for (i = 0, flag = 1; functions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, functions[i].opcode) == 0)
		{
			execute_func(functions[i].f, opcode, data, line_n, format);
			flag = 0;
		}
	}
	if (flag == 1)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_n, opcode);
		exit(EXIT_FAILURE);
	}
}

/**
 * execute_func - executes the function
 * @func: function to be executed
 * @opcode: opcode
 * @data: data
 * @line_n: line number
 * @format: 0 for stacks, 1 for queues
 */
void execute_func(op_func func, char *opcode, char *data,
			int line_n, int format)
{
	int i, flag = 1;
	stack_t *node;

	if (strcmp(opcode, "push") == 0)
	{
		if (data != NULL && data[0] == '-')
		{
			data = data + 1;
			flag = -1;
		}
		if (data == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_n);
			exit(EXIT_FAILURE);
		}
		for (i = 0; data[i] != '\0'; i++)
			if (isdigit(data[i]) == 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_n);
				exit(EXIT_FAILURE);
			}
		node = make_node(atoi(data) * flag);
		if (format == 0)
			func(&node, line_n);
		if (format == 1)
			add_to_queue(&node, line_n);
	}
	else
		func(&head, line_n);
}

/**
 * make_node - makes a node
 * @n: data of node
 * Return: pointer to next node
 */
stack_t *make_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (!node)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * free_nodes - frees the nodes in the stack
 */
void free_nodes(void)
{
	stack_t *temp;

	if (head == NULL)
		return;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
