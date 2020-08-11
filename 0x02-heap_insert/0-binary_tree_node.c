#include "binary_trees.h"
#include <stdlib.h>
/**
* binary_tree_node - creates a binary tree node.
* @parent: parent node
* @value: value of new node
* Return: a pointer to the new node, or NULL on failure.
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *newnode;

    newnode = malloc(sizeof(binary_tree_t));
    if (newnode == NULL)
        return (NULL);
    
    newnode->parent = parent;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->n = value;

    return (newnode);
}