#include "binary_trees.h"

/**
 *binary_tree_t - function finds the uncle of a node
 *@node: pointer to the node to find the uncle
 *Return: value to return
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	return (binary_tree_sibling(node->parent));
}
