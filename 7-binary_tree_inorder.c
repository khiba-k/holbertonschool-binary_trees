#include "binary_trees.h"

/**
 *binary_tree_postorder - function goes through a binary tree using in-order traversal
 *@tree - pointer to the root node of the tree to traverse
 *@func: pointer to function to call for each node
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if(tree != NULL) {
		binary_tree_postorder(tree->left, func);
		func(tree->n);
		binary_tree_postorder(tree->right, func);
	}
}
