#include "monty.h"

/**
 * check_func - Finds and calls the appropriate function based on the opcode.
 * @op_code: Opcode.
 * @value: Value associated with the opcode.
 * @line_number: Line number of the opcode.
 * @format: Format flag (0 for stack, 1 for queue).
 */
void check_func(char *op_code, char *value, int line_number, int format)
{
	int i = 0;
	int flag = 1;

	instruction_t func_list[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"nop", nop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", divide},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (op_code[0] == '#')
		return;
	while (func_list[i].opcode != NULL)
	{
		if (strcmp(op_code, func_list[i].opcode) == 0)
		{
			call_fun(func_list[i].f, op_code, value, line_number, format);
			flag = 0;
		}
		i++;
	}
	if (flag == 1)
		err(3, line_number, op_code);
}

