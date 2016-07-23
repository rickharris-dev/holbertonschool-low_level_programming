#include "tree.h"
#include <string.h>

/**
 * find_tree_recursion - Finds the matching node
 * @tree: Current BTree struct to evaluate
 * @str: String to find
 * Description: Recurses through the tree to find matching node
 */
BTree *find_tree_recursion(BTree *tree, char *str)
{
	int comp;

	if (!tree)
		return NULL;
	comp = strcmp(str, tree->str);
	if (comp == 0)
		return tree;
	else if (comp < 0)
		return find_tree_recursion(tree->left, str);
	else
		return find_tree_recursion(tree->right, str);
}

/**
 * btree_find - Finds a matching string in a node
 * @tree: Starting BTree node
 * @str: String to find
 * Description: Returns a node containing a matching string
 */
BTree *btree_find(BTree *tree, char *str)
{
	if (!tree || !str)
		return NULL;
	return find_tree_recursion(tree, str);
}
