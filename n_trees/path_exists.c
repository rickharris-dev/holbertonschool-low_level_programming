#include "tree.h"
#include <string.h>
#include <stdlib.h>

/**
 * find_child - locates child node
 * @list: linked List nodes
 * @child: string to match from parents path
 * Description: Recurses linked list to find a matching Ntree node
 */
NTree *find_child(List *list, char *child);
{
	if (!list || !list->node)
		return NULL;
	if (!list->node->str || !child)
		return NULL;
	if (strcmp(list->node->str, child) == 0)
		return list->node;

	return find_child(list->next, child);
}

/**
 * path_exists - Checks if path exists
 * @tree: NTree structure
 * @path: Array of strings to check path
 * Description: Checks path in array again existing NTree structure
 */
int path_exists(NTree *tree, char **path)
{
	int i;

	if (!tree || !path || !path[0])
		return 0;

	for (i = 0; path[i]; i++)
	{
		if (i == 0 && strcmp(tree->str, path[i]))
			tree = NULL;
		else if (i != 0)
			tree = find_child(tree->children, path[i]);
		if (!tree)
			return 0;
	}
	return 1;
}
