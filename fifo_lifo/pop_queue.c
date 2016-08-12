#include "queue.h"
#include <stdlib.h>
#include <string.h>

/**
 * pop_queue - Return string from Queue node
 * @list: Pointer to a Queue node
 * Description: Returns a string from the first node in Queue and
 *				removes the node from Queue
 */
char *pop_queue(Queue **list)
{
	Queue *first;
	Queue *next;
	char *str;

	/* If no queue return NULL */
	if (*list == NULL)
		return NULL;

	/* Set first and next values */
	first = *list;
	next = (*list)->next;

	/* Store the pointer to the string and free the queue */
	str = first->str;
	free(first);

	/* Update the queue */
	*list = next;

	/* Returns stored string */
	return str;
}
