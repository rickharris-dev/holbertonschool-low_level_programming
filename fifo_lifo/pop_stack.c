#include "stack.h"
#include <stdlib.h>

/**
 * pop_stack - Returns string in node
 * @list: Pointer to a Stack node
 * Description: Returns string in the node at top of the stack
 * 				and removes the node from the Stack
 */
char *pop_stack(Stack **list)
{
	Stack *next;
	char *str;

	/* If the list is NULL return NULL */
	if (!*list)
		return NULL;

	/* Get persisting values from first node */
	next = (*list)->next;
	str = (*list)->str;

	/* Free the first node and update the stack */
	free(*list);
	*list = next;

	/* Return the string */
	return str;
}
