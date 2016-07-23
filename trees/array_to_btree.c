#include "tree.h"
#include <string.h>
#include <stdlib.h>


/**
 * set_node - Sets the new tree node
 * @tree: Pointer to a BTree struct
 * @data: String
 * Description: Sets the new tree node
 */
int set_node(BTree **tree, char *data)
{
	BTree *new;

	new = malloc(sizeof(BTree))
	if (!new)
		return 1;
	new->str = strdup(data)
	if (!new->str)
		return 1;
	new->left = NULL;
	new->right = NULL;
	*tree = new;
	return 0;
}

/**
 * tree_recursion - Recurses through the tree
 * @tree: BTree struct
 * @data: String
 * Description: Recurses through the tree to set the new node
 */
int tree_recursion(BTree *tree, char *data)
{
	if (strcmp(data, tree->str) < 0)
	{
		if (!tree->left)
			return set_node(&(tree->left), data);
		else
			return tree_recursion(tree->left, data);
	}
	else
	{
		if (!tree->right)
			return set_node(&(tree->right), data);
		else
			return tree_recursion(tree->right, data);
	}
}

/**
 * btree_insert - Inserts a new node into a binary tree
 * @tree: Pointer to a BTree struct
 * @data: String
 * Description: Inserts a new node into a binary tree
 */
int btree_insert(BTree **tree, char *data)
{
	if (!tree || !data)
		return 1;
	if (!*tree)
		return set_node(tree, data);
	return tree_recursion(*tree, data);
}

/**
 * set_node - Converts an array of strings to a binary tree
 * @array: Pointer to a BTree struct
 * Description: Converts an array of strings to a binary tree
 */
BTree *array_to_btree(char **array)
{
	BTree *tree = NULL;
	int i;

	for (i = 0; array[i] != NULL; i++)
		btree_insert(&tree, array[i]);

	return tree;
}
