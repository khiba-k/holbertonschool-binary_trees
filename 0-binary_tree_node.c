#include "binary_trees.h"

/**
 * SetNewNode - sets the values of a newly created node
 * @value: what is stored in the new node
 * Return: pointer to new node
 */

binary_tree_t *SetNewNode(int value)
{
	binary_tree_t *NewNode = malloc(sizeof(binary_tree_t));

	if (NewNode == NULL)
		return (NULL);
	NewNode->n = value;
	NewNode->left = NULL;
	NewNode->right = NULL;
	return (NewNode);
}

/**
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to parent node
 * @value: value to store in the new node
 * Return: pointer to the new node or NULL on failure
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	if (parent == NULL)
	       return (SetNewNode(value));
	if (value < parent->n)
	{
		if  (parent->left == NULL)
		{
			parent->left = SetNewNode(value);
			parent->left->parent = parent;
			return (parent->left);
		} else
			return (binary_tree_node(parent->left, value));
	} else if (value > parent->n)
	{
		if (parent->right == NULL)
		{
			parent->right = SetNewNode(value);
			parent->right->parent = parent;
			return (parent->right);
		} else
			return (binary_tree_node(parent->right, value));
	}
	return (parent);
}

