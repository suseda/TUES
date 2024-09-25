#include <stdio.h>
#include <stdlib.h>


struct node_tree
{
	struct node_tree* left;
	struct node_tree *right;
	int data;
};

struct node_tree* init_node(int data)
{
	struct node_tree* new_item = (struct node_tree*)malloc(sizeof(struct node_tree*));
	new_item->left = new_item->right = NULL;
	new_item->data = data;
	return new_item;
}

int has_in_tree(struct node_tree* tree, int data)
{
	if (tree == NULL)
		return NULL;

	if (tree->data == data)
		return 1;

	int res1 = has_in_tree(tree->left, data);
	
	if (res1) return 1;

	int res2 = has_in_tree(tree->right, data);

	return res2;
}


struct node_tree* add2(struct node_tree* tree, int data)
{
	if (tree == NULL)
		return init_node(data);

	if (tree->data > data)
		tree->left = add2(tree->left, data);
	else 
		tree->right = add2(tree->right, data);

	return tree;
}

struct node_tree* add(struct node_tree* tree, int data)
{
	int flag = has_in_tree(tree, data);
	if (!flag)
		return add2(tree, data);
	return tree;
}

struct node_tree* search(struct node_tree* tree, int data)
{
	if (tree == NULL)
		return NULL;

	if (tree->data > data)
		tree->left = add(tree->left, data);
	else if (tree->data < data)
		tree->right = add(tree->right, data);
	else
		return tree;

	return tree;
}


struct node_tree* remove_node(struct node_tree* tree, int data)
{
	if (tree == NULL)
		return NULL;

	if (tree->data > data)
		tree->left = remove_node(tree->left, data);
	else if (tree->data < data)
		tree->right = remove_node(tree->right, data);
	else
	{
		if (tree->left == NULL) {
			struct node* temp = tree->right;
			free(tree);
			return temp;
		}
		else if (tree->right == NULL) {
			struct node* temp = tree->left;
			free(tree);
			return temp;
		}

		struct node_tree* curr = tree;

		while (curr && curr->left != NULL)
			curr = curr->left;


		tree->data = curr->data;
		tree->right = remove_node(tree->right, curr->data);
	}

	return tree;
}


void delete_tree(struct node_tree* tree)
{
	if (tree == NULL) return;

	delete_tree(tree->left);
	delete_tree(tree->right);

	printf("\n Deleting node: %d", tree->data);
	free(tree);
}


int main()
{
	struct node_tree* t = add(NULL,15);
	t = add(t, 25);
	t = add(t, 10);
	t = add(t, 12);
	t = add(t, 5);
	t = add(t, 20);
	t = add(t, 23);

	t = remove_node(t, 12);
	t = remove_node(t, 15);

	delete_tree(t);

	return 0;
}