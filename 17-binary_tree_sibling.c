#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 **binary_tree_sibling - Finds the sibling of a node.
 *@node: Pointer to the node to find the sibling
 *
 *Return: ponter to the sibling node, NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
if (node == NULL || node->parent == NULL)
return (NULL);

if (node->parent->left == node)
return (node->parent->left);

return (node->parent->left);
}
