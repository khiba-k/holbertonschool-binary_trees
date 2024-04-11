#include <stdio.h>
#include "binary_trees.h"

/**
 *binary_tree_is_leaf - function checks if a node is a leaf
 *@node: pointer to the node to check
 *Return: value to return
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node->left == NULL && node->right == NULL)
		return (1);
	binary_tree_is_leaf(node->left);
	binary_tree_is_leaf(node->right);
	return (0);
}

