#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: pointer to to insert the right-child in
 * @value: what to store in the new node
 * Return: a pointer to the created node or NULL on failure
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *temp;

	if (parent == NULL)
		return (NULL);
	if (parent->right != NULL)
	{
		temp = parent->right;
		parent->right = SetNewNode(value);
		if (parent->right == NULL)
			return (NULL);
		parent->right->parent = parent;
		parent->right->right = temp;
		temp->parent = parent->right;
	} else
	{
		parent->right = SetNewNode(value);
		if (parent->right == NULL)
			return (NULL);
		parent->right->parent = parent;
	}
	return (parent->right);
}

