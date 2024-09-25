#include <stdio.h>
#include <stdlib.h>

#include "split_tree_h.h"


struct node_t* add(struct node_t* tree, int data)
{
	if (tree == NULL)
	{
		struct node_t* new_item = malloc(sizeof(struct node_t));
		new_item->left = NULL;
		new_item->right = NULL;
		new_item->data = data;
		return new_item;
	}

	if (tree->data > data)
		tree->left = add(tree->left, data);
	else if (tree->data < data)
		tree->right = add(tree->right, data);

	return tree;
}


void add_for_split(struct node_t** tree, int data)
{
	if (*tree == NULL)
	{
		struct node_t* new_item = malloc(sizeof(struct node_t));
		new_item->left = NULL;
		new_item->right = NULL;
		new_item->data = data;
		*tree = new_item;
		return;
	}

	struct node_t* copy_tree = *tree;
	while (copy_tree)
	{
		if (data > copy_tree->data)
		{
			if (copy_tree->right)
			{
				copy_tree = copy_tree->right;
			}
			else
			{
				struct node_t* new_item = malloc(sizeof(struct node_t));
				new_item->left = NULL;
				new_item->right = NULL;
				new_item->data = data;
				copy_tree->right = new_item;
				return;
			}
		}
		else
		{
			if (copy_tree->left)
			{
				copy_tree = copy_tree->left;
			}
			else
			{
				struct node_t* new_item = malloc(sizeof(struct node_t));
				new_item->left = NULL;
				new_item->right = NULL;
				new_item->data = data;
				copy_tree->left = new_item;
				return;
			}
		}

	}
}

int element_cnt(struct node_t* tree)
{
	if (tree == NULL) return NULL;
	return element_cnt(tree->left) + element_cnt(tree->right) + 1;
}

void split(struct node_t* tree, struct node_t** result1, struct node_t** result2)
{
	if (tree == NULL) return;

	split(tree->left, result1, result2);

	struct node_t* var1 = *result1;
	struct node_t* var2 = *result2;

	int cnt1 = element_cnt(var1);
	int cnt2 = element_cnt(var2);
	if (cnt1 != cnt2)
	{
		add_for_split(result2, tree->data);
    }
	else
	{
		add_for_split(result1, tree->data);
	}
	split(tree->right, result1, result2);
	return;
}

void print_tree(struct node_t* tree)
{
	if (tree == NULL) return NULL;
	printf("%d ", tree->data);
	print_tree(tree->left);
	print_tree(tree->right);
}

int main()
{
	struct node_t* tree = add(NULL, 10);
	tree = add(tree, 5);
	tree = add(tree, 15);
	tree = add(tree, 3);
	tree = add(tree, 6);
	tree = add(tree, 12);
	tree = add(tree, 18);
	tree = add(tree, 8);
	tree = add(tree, 13);
	puts("Normal Tree");
	print_tree(tree);
	struct node_t* result1 = 0;
	struct node_t* result2 = 0;

	split(tree, &result1, &result2);
	puts("");
	puts("Split Tree");
	print_tree(result1);
	puts("");
	print_tree(result2);
	return 0;
}