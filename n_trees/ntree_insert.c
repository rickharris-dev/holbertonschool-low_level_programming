#include "tree.h"
#include <string.h>
#include <stdlib.h>

/**
 * find_child - locates child node
 * @list: linked List nodes
 * @child: string to match from parents path
 * Description: Recurses linked list to find a matching Ntree node
 */
NTree *find_child(List *list, char *child)
{
	if (!list->node)
		return NULL;
	if (!list->node->str || !child)
		return NULL;
	if (strcmp(list->node->str, child) == 0)
		return list->node;

	return find_child(list->next, child);
}

/**
 * add_list - Creates a new List node
 * @first: first node in linked List
 * Description: Creates a new node at the beginning of linked List
 */
List *add_list(List *first)
{
	List *new;

	new = malloc(sizeof(List));
	new->node = NULL;
	new->next = first;
	return new;
}

/**
 * add_node - Creates a new NTree node
 * @data: string to be stored in the node
 * Description: Returns a new NTree node with string
 */
NTree *add_node(char *data)
{
	NTree *new;

	new = malloc(sizeof(NTree));
	new->str = strdup(data);
	new->children = NULL;
	return new;
}

/**
 * ntree_insert - Adds a new child node for parent path
 * @tree: Pointer to the root NTree node
 * @parents: Array of strings describing path to new node
 * @data: String to be added
 * Description: Adds a new node at the proper path
 */
int ntree_insert(NTree **tree, char **parents, char *data)
{
	int i;
	NTree *parent = NULL;

	/* Check if params are NULL */
	if (!*data)
		return -1;

	if (!*tree)
	{
		*tree = add_node(data);
		return 0;
	}

	/* Find parent node and add new node */
	parent = *tree;
	for (i = 1; parents[i]; i++)
		parent = find_child(parent->children, parents[i]);

	if (!parent)
		return -1;

	parent->children = add_list(parent->children);
	parent->children->node = add_node(data);
	return 0;
}
