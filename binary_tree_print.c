#include <stdio.h>
#include <string.h>
#include "binary_trees.h"

/* Auxiliary function to print the tree */
void binary_tree_print(const binary_tree_t *);

/**
 * print_t - Prints a binary tree
 * @tree: Pointer to the root node of the tree to print
 * @offset: Offset for the next print
 * @depth: Depth of the current node
 * @s: Buffer
 *
 * Return: New offset
 */
static int print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
    char b[6];
    int width, left, right, is_left, i;

    if (!tree)
        return (0);
    is_left = (tree->parent && tree->parent->left == tree);
    width = sprintf(b, "(%03d)", tree->n);
    left = print_t(tree->left, offset, depth + 1, s);
    right = print_t(tree->right, offset + left + width, depth + 1, s);
    for (i = 0; i < width; i++)
        s[depth][offset + left + i] = b[i];
    if (depth && is_left)
    {
        for (i = 0; i < width + right; i++)
            s[depth - 1][offset + left + width / 2 + i] = '-';
        s[depth - 1][offset + left + width / 2] = '.';
    }
    else if (depth && !is_left)
    {
        for (i = 0; i < left + width; i++)
            s[depth - 1][offset - width / 2 + i] = '-';
        s[depth - 1][offset + left + width / 2] = '.';
    }
    return (left + width + right);
}

/**
 * _height - Computes the height of a tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the tree
 */
static int _height(const binary_tree_t *tree)
{
    int height_l;
    int height_r;

    if (!tree)
        return (0);
    height_l = tree->left ? 1 + _height(tree->left) : 0;
    height_r = tree->right ? 1 + _height(tree->right) : 0;
    return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_print - Prints a binary tree
 * @tree: Pointer to the root node of the tree to print
 */
void binary_tree_print(const binary_tree_t *tree)
{
    char **s;
    int i, j;
    int height = _height(tree);
    int width = 1024;

    if (!tree)
        return;
    s = malloc(sizeof(*s) * (height + 1));
    if (!s)
        return;
    for (i = 0; i < height + 1; i++)
    {
        s[i] = malloc(width);
        if (!s[i])
            return;
        memset(s[i], ' ', width);
        s[i][width - 1] = '\0';
    }
    print_t(tree, 0, 0, s);
    for (i = 0; i < height + 1; i++)
    {
        for (j = width - 1; j > 1; j--)
        {
            if (s[i][j] != ' ')
                break;
            s[i][j] = '\0';
        }
        printf("%s\n", s[i]);
        free(s[i]);
    }
    free(s);
}
