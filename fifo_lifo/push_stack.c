#include "stack.h"
#include <string.h>
#include <stdlib.h>

/**
 * push_stack - Adds node to Stack
 * @list: Pointer to a Stack
 * @str: String to be stored in node on Stack
 * Description: Creates a new node and updates the Stack
 */
int push_stack(Stack **list, char *str)
{
	Stack *new;

	/* Create a new node for the stack */
	new = malloc(sizeof(Stack));
	if (!new)
		return 1;
	new->str = strdup(str);
	if (!new->str)
		return 1;
	new->next = *list;

	/* Update the stack pointer */
	*list = new;

	return 0;
}
