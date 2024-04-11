#include "binary_trees.h"

/**
 *_pow - function calculates base to the power of exponent
 *@base: base to insert
 *@exponent: exponent to insert
 */

int _pow(int base, int exponent) {
	int result = 1;
	int i;

	if (exponent < 0) {
		base = 1 / base;
		exponent = -exponent;
	}

	for (i = 0; i < exponent; i++) {
		result *= base;
	}
	result *= base;
	return (result);
}

/**
 *binary_tree_is_perfect - function checks if a binary is perfect
 *@tree: pointer to the root node of the tree to check
 *Return: value to return
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (_pow(2, binary_tree_height(tree)) - 1 == binary_tree_size(tree))
		return (1);
	return (0);
}
