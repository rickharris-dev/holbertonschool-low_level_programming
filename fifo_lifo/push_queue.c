#include "queue.h"
#include <stdlib.h>
#include <string.h>

/**
 * get_last - Returns last node in Queue
 * @node: Queue node
 * Description: Recurses through Queue and returns last node
 */
Queue *get_last(Queue *node)
{
	/* Returns last node in queue */
	if (node->next == NULL)
		return node;
	/* Recurses until last node */
	return get_last(node->next);
}

/**
 * push_queue - Adds new node to end of Queue
 * @list: Pointer to Queue node
 * @str: String to be stored in Queue
 * Description: Recurses through Queue and adds new node to end
 */
int push_queue(Queue **list, char *str)
{
	Queue *last;
	Queue *new;

	/* Create new node for queue */
	new = malloc(sizeof(Queue));
	if (!new)
		return 1;
	new->str = strdup(str);
	if (!new->str)
		return 1;
	new->next = NULL;

	if (*list != NULL)
	/* If there is a queue add node to the end */
	{
		last = get_last(*list);
		last->next = new;
	} else {
	/* Else start the queue */
		*list = new;
	}
	return 0;
}
