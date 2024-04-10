#include "binary_trees.h"

/**
 *
 *
 *
 */
size_t binary_tree_children(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_children(tree->left) + ((tree->left == NULL &&
		tree->right == NULL) || (tree->left != NULL && tree->right != NULL) ?
		1 : 0) + binary_tree_children(tree->right));
}

/**
 *
 *
 *
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_leaves(tree->left) + (tree->left == NULL &&
		tree->right == NULL ? 1 : 0) + binary_tree_leaves(tree->right));
}

/**
 *binary_tree_is_full - function checks if binary tree is full
 *@tree: pointer to the root node of the tree to check
 *Return: value to return
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (binary_tree_children(tree) > 0 && (binary_tree_leaves(tree) % 2 == 0)
		&& (binary_tree_balance(tree)) < 0)
		return (1);
	return (0);
}
