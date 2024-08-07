#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 *binary_tree_nodes - Counts the nodes with at least 1 child in binary tree
 *@tree: Pointer to the root node of the tree to count the number of nodes.
 *
 *Return: 0 if the tree is NULL
 *
 *Description: This function traverses the binary tree and counts nodes that
 *have atleast one child (left of right).
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);

if (tree->left != NULL || tree->right != NULL)
return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));

return (0);
}
