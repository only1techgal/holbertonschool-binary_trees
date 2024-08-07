#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 * @tree: Pointer to the node to measure the depth
 *
 * Return: Depth of the node, or 0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
size_t depth = 0;

while (tree && tree->parent)
{
tree = tree->parent;
depth++;
}
return (depth);
}

/**
 * is_perfect_recursive - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 * @depth: Expected depth of leaf nodes
 * @level: Current level of the node being checked
 *
 * Return: 1 if the binary tree is perfect, 0 otherwise
 */
static int is_perfect_recursive(const binary_tree_t *tree,
size_t depth, size_t level)
{
if (tree == NULL)
return (0);


if (tree->left == NULL && tree->right == NULL)
return (depth == level + 1);


if (tree->left && tree->right)
return (is_perfect_recursive(tree->left, depth, level + 1) &&
is_perfect_recursive(tree->right, depth, level + 1));

return (0);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the binary tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
size_t depth;

if (tree == NULL)
return (0);

depth = binary_tree_depth(tree);

return (is_perfect_recursive(tree, depth, 0));
}
