#include "binary_trees.h"

/**
 * right_height - calculates the height of the right subtree 
 * @tree: pointer to first node in right subtree
 * Return: height of right subtree
 */

int right_height(binary_tree_t *tree)
{
	int r_height;

	if (tree == NULL)
		return (0);
	r_height = right_height(tree->right);
	return (r_height) + 1;
}

/**
 * left_height - calculate the height of the left subtree
 * @tree: pointer to first in left subtree
 * Return: height of left subtree
 */

int left_height(binary_tree_t *tree)
{
	int l_height;

	if (tree == NULL)
		return (0);
	l_height = left_height(tree->left);
	return (l_height) + 1;
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

