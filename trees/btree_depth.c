#include "tree.h"
#include <stdio.h>

/**
 * btree_depth_recursion - determines max depth
 * @tree: BTree struct node being evaluated
 * @depth: Integer value storing current depth
 * Description: Recurses through the tree to find the max depth
 */
int btree_depth_recursion(BTree *tree, int depth)
{
	int left;
	int right;

	if (!tree->left && !tree->right)
		return depth;
	else if (!tree->right)
		return btree_depth_recursion(tree->left, ++depth);
	else if (!tree->left)
		return btree_depth_recursion(tree->right, ++depth);
	left = btree_depth_recursion(tree->left, depth + 1);
	right = btree_depth_recursion(tree->right, depth + 1);
	if (left >= right)
		return left;
	return right;
}

/**
 * btree_depth - returns depth
 * @tree: Btree struct starting node
 * Description: Returns the depth of a given binary tree
 */
int btree_depth(BTree *tree)
{
	int depth = 0;

	if (!tree)
		return -1;
	return btree_depth_recursion(tree, depth);
}
