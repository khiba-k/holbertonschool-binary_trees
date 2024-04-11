#include "binary_trees.h"

/**
 * SetNewNode - sets the values of a newly created node
 * @value: what is stored in the new node
 * Return: pointer to new node
 */

binary_tree_t *SetNewNode_Values(int value)
{
	binary_tree_t *NewNode;
	NewNode = malloc(sizeof(binary_tree_t));

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
	binary_tree_t *Leaf = parent, *New;

	if (parent == NULL)
	{
		parent = SetNewNode(value);
		return (parent);
	}
	if (value < parent->n)
	{
		if  (parent->left == NULL)
		{
			Leaf->left = SetNewNode(value);
			Leaf->left->parent = parent;
			New = Leaf->left;
		} else
			return (binary_tree_node(parent->left, value));
	} else if (value > parent->n)
	{
		if (parent->right == NULL)
		{
			Leaf->right = SetNewNode(value);
			Leaf->right->parent = parent;
			New = Leaf->right;
		} else
			return (binary_tree_node(parent->right, value));
	}
	return (New);
}

