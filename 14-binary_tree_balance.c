#include "binary_trees.h"

/**
 * right_height - calculates the height of the right subtree 
 * @tree: pointer to first node in right subtree
 * Return: height of right subtree
 */

int right_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_height(tree->right));
}

/**
 * left_height - calculate the height of the left subtree
 * @tree: pointer to first in left subtree
 * Return: height of left subtree
 */

int left_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_height(tree->left));
}

/**
 *binary_tree_balance - function measures the balance factor of a binary tree
 *@tree: pointer to the root node of the tree to measure the balance factor
 *Return: tree balance
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int right, left;

	if (tree == NULL)
		return (0);
	right = right_height(tree->right);
	left = left_height(tree->left);
	return (left - right);
}

