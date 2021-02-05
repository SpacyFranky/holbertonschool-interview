#include <stdlib.h>
#include "binary_trees.h"


/**
* new - creates a new node
* @parent: node's parent
* @value: node's value
* Return: the new node
*/
avl_t *new(avl_t *parent, int value)
{
	avl_t *node;

	node = (avl_t *)malloc(sizeof(avl_t));
	if (node == NULL)
		return (NULL);

	node->parent = parent;
	node->right = NULL;
	node->left = NULL;
	node->n = value;

	return (node);
}

/**
* avl - builds an AVL tree from an array
* @array: array of integers
* @first: first element
* @last: last element
* @parent: parent of node
* Return: a pointer to the root node of the created AVL tree,
* or NULL failure
*/
avl_t *avl(int *array, int first, int last, avl_t *parent)
{
	avl_t *tree;
	int mid;

	if (first > last)
		return (NULL);

	tree = (avl_t *)malloc(sizeof(avl_t));
	if (tree == NULL)
		return (NULL);

	mid = (first + last) / 2;
	tree = new(parent, array[mid]);
	tree->left = avl(array, first, mid - 1, tree);
	tree->right = avl(array, mid + 1, last, tree);

	return (tree);
}

/**
* sorted_array_to_avl - calls the avl function
* @array: array of integers
* @size: size of array
* Return: a pointer to the root node of the created AVL tree,
* or NULL failure
*/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree, *parent;

	if (size == 0)
		return (NULL);

	parent = NULL;
	tree = avl(array, 0, size - 1, parent);

	return (tree);
}
