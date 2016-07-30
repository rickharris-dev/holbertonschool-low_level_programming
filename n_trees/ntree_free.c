#include "header.h"

/**
 * free_node - Free a NTree struct
 * @tree: NTree struct to be freed
 * Description: Frees the given NTree string and struct
 */
void free_node(NTree *tree)
{
	free(tree->str);
	if (tree->children)
		free_list(tree->children);
	free(tree);
}

/**
 * free_list - Frees a List struct
 * @list: List struct to be freed
 * Description: Frees the given List node and struct
 */
void free_list(List *list)
{
	List *next;

	if (!list)
		return;
	next = list->next;
	if (list->node)
		free_node(list->node);
	free(list);
	free_list(next);
}

/**
 * ntree_free - Initializes the freeing of an NTree structure
 * @tree: The root NTree struct
 * Description: Initializes the freeing of each List and NTree struct
 */
void ntree_free(NTree *tree)
{
	free_list(tree->children);
	free(tree->str);
	free(tree);
}
