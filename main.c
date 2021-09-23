#include "monty.h"

/**
 * main - main function
 * @argc: argument counts
 * @argv: arguments passed
 * Return: success
 */
int main(int argc, char **argv)
{
	FILE *file;
	char *buff = NULL, *string;
	size_t s = 0;
	unsigned int linenum = 1;
	stack_t *stack = NULL;

	variables.check = 0;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&buff, &s, file) != -1)
	{
		if (*buff != '\n')
		{
			string = strtok(buff, "\n");
			_tokenizer(string, &stack, linenum);
		}
		linenum++;
	}
	fclose(file);
	free(buff);
	if (stack != NULL)
		free_stack(&stack, linenum);
	return (EXIT_SUCCESS);
}

/**
 * _tokenizer - function to tokenize strings and commands
 * @string: string to be tokenized
 * @stack: pointer to the stack
 * @linenum: line numbers
 * Return: void
 */
void _tokenizer(char *string, stack_t **stack, unsigned int linenum)
{
	char *token;
	char *tokens;

	token = strtok(string, " ");
	if (token == NULL || *token == ' ' || *token == '\n' || *token == '#')
		return;
	if (strcmp(token, "push") == 0)
	{
		tokens = token;
		token = strtok(NULL, " ");
		if (!check_digit(token))
		{
			printf("L%d: usage: push integer\n", linenum);
			free_stack(stack, linenum);
			exit(EXIT_FAILURE);
		}
		variables.holder = atoi(token);
		_ops(tokens, stack, linenum);
	}
	else
		_ops(token, stack, linenum);
}

/**
 * check_digit - checks if string is a number
 * @token: string to check
 * Return: 1 if number, 0 if not
 */
int check_digit(char *token)
{
	if (token == NULL)
		return (0);
	if (*token == '-')
		token++;
	while (*token != '\0')
	{
		if (!isdigit(*token))
			return (0);
		token++;
	}
	token++;
	return (1);
}
