#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 **binary_tree_uncle - Finds the uncle of a node
 *@node: Pointer to the node to find the uncle
 *
 *Return: Pointer to the uncle node, NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
binary_tree_t *parent, *grandparent;

if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
return (NULL);

parent = node->parent;
grandparent = parent->parent;

if (grandparent->left == parent)
return (grandparent->right);


return (grandparent->left);
}
