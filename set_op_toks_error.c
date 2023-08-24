#include "monty.h"

/**
 * set_op_tok_error - Sets last element of op_toks to be an error code.
 * @error_code: Integer to store as a string in op_toks.
 */
void set_op_tok_error(int error_code)
{
	int toks_leng = 0, i = 0;
	char *exit_string = NULL;
	char **new_toks = NULL;

	toks_leng = token_arr_len();
	new_toks = malloc(sizeof(char *) * (toks_leng + 2));
	if (!op_toks)
	{
		malloc_error();
		return;
	}
	while (i < toks_leng)
	{
		new_toks[i] = op_toks[i];
		i++;
	}
	exit_string = get_int(error_code);
	if (!exit_string)
	{
		free(new_toks);
		malloc_error();
		return;
	}
	new_toks[i++] = exit_string;
	new_toks[i] = NULL;
	free(op_toks);
	op_toks = new_toks;
}
