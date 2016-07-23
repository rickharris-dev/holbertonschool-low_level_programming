#include "tree.h"
#include <stdlib.h>

/**
 * btree_free - Frees each string and node
 * @tree: Current BTree struct to free
 * Description: Recurses through the tree and frees each string and node
 */
void btree_free(BTree *tree)
{
	if (!tree)
		return;
	if (tree->str)
		free(tree->str);
	btree_free(tree->left);
	btree_free(tree->right);
	free(tree);
}
