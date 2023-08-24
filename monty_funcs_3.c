#include "monty.h"

void monty_nop(stack_t **stack, unsigned int line_number);
void monty_pchar(stack_t **stack, unsigned int line_number);
void monty_pstr(stack_t **stack, unsigned int line_number);

/**
 * monty_nop - Implements the 'nop' opcode for Monty, performing no operation.
 * @stack: Pointer to the top node of a stack_t linked list.
 * @line_number: Current line number in the Monty bytecodes file.
 */
void monty_nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}

/**
 * monty_pchar - Prints the character value of the top node in a stack_t linked list.
 * @stack: Pointer to the top node of a stack_t linked list.
 * @line_number: Current line number in the Monty bytecodes file.
 */
void monty_pchar(stack_t **stack, unsigned int line_number)
{
    if ((*stack)->next == NULL)
    {
        set_op_tok_error(pchar_error(line_number, "stack empty"));
        return;
    }
    if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
    {
        set_op_tok_error(pchar_error(line_number, "value out of range"));
        return;
    }

    printf("%c\n", (*stack)->next->n);
}

/**
 * monty_pstr - Prints the string from the stack_t linked list until null byte or non-printable character.
 * @stack: Pointer to the top node of a stack_t linked list.
 * @line_number: Current line number in the Monty bytecodes file.
 */
void monty_pstr(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp = (*stack)->next;

    while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
    {
        printf("%c", tmp->n);
        tmp = tmp->next;
    }

    printf("\n");

    (void)line_number;
}
