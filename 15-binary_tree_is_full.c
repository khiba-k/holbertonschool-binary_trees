#include "binary_trees.h"

/**
 * binary_tree_children - count children of a node
 * @tree: pointer to node
 * Return: number of children
 */

size_t binary_tree_children(const binary_tree_t *tree)
{
	if (
		tree == NULL ||
		(tree->left == NULL && tree->right == NULL && tree->parent == NULL)
		)
		return (0);
	return (
		binary_tree_children(tree->left) + ((tree->left == NULL &&
		tree->right == NULL) || (tree->left != NULL && tree->right != NULL) ?
		2 : 0) + binary_tree_children(tree->right)
		);
}

/**
 * binary_tree_leaves - count number of leaves
 * @tree: pointer to root
 * Return: number of leaves
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (
		tree == NULL ||
		(tree->left == NULL && tree->right == NULL && tree->parent == NULL)
		)
		return (0);
	return (
		binary_tree_leaves(tree->left) +
		(tree->left == NULL && tree->right == NULL ? 1 : 0) +
		binary_tree_leaves(tree->right)
		);
}

/**
 *binary_tree_height - function measures the height of binary tree
 *@tree: pointer to the root node of the tree to measure the height
 *Return: value to return
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	int l_height, r_height;

	if (
		tree == NULL ||
		(tree->left == NULL && tree->right == NULL && tree->parent == NULL)
		)
		return (0);
	else if (tree->parent != NULL)
	{
		l_height = binary_tree_height(tree->left);
		r_height = binary_tree_height(tree->right);
		return (1 + (l_height >= r_height ? l_height : r_height));
	}
	return (binary_tree_height(tree->left));
	return (binary_tree_height(tree->right));
}

/**
 *binary_tree_balance - function measures the balance factor of a binary tree
 *@tree: pointer to the root node of the tree to measure the balance factor
 *Return: tree balance
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int right, left;

	if (
		tree == NULL ||
		(tree->left == NULL && tree->right == NULL && tree->parent == NULL)
	   	)
		return (0);
	right = binary_tree_height(tree->right) + 1;
	left = binary_tree_height(tree->left) + 1;
	if (
		left == 0 && tree->right != NULL &&
		(binary_tree_leaves(tree->right) % 2 != 0)
		)
		return (-right - 1);
	else if (
		right == 0 && tree->left != NULL &&
		(binary_tree_leaves(tree->left) % 2 != 0)
		)
		return (left + 1);
	return (left - right);
}

/**
 *binary_tree_is_full - function checks if binary tree is full
 *@tree: pointer to the root node of the tree to check
 *Return: value to return
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (
		(binary_tree_children(tree) % 2 == 0 &&
		binary_tree_leaves(tree) % 2 == 0 && binary_tree_balance(tree) >= 0) ||
		(tree->left == NULL && tree->right == NULL && tree->parent == NULL)
		)
		return (1);
	return (0);
}

