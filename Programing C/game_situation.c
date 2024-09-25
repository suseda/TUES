#include <stdio.h>
#include <stdlib.h>


struct node_t
{
    struct node_t* left, * right;
	char question,left_ans,right_ans;
};


struct node_t* add(struct node_t* tree, char question,char right_ans, char left_ans, int flag[],int i)
{
    if (tree == NULL) 
    {
        struct node_t* new_node = malloc(sizeof(struct node_t));
        new_node->question=question;
        new_node->left_ans = left_ans;
        new_node->right_ans = right_ans;
        new_node->left = new_node->right = NULL;
        return new_node;
    }

    while (flag[i])
    {
        if (flag[i] == 1)
        {
            i++;
            tree->right = add(tree->right, question, right_ans, left_ans, flag,i);
        }
        else
        {
            i++;
            tree->left = add(tree->left, question, right_ans, left_ans, flag,i);
        }
    }
    return tree;

}


void printArray(int arr[], int len)
{

    for (int i = 0; i < len; i++)
    {
        printf("%s -> ", arr[i]);
    }
}

void print_path(struct node_t* tree, int path[], int pathLen, struct node_t* end)
{
    if (tree == NULL)
        return;

    path[pathLen] = tree->question;
    pathLen++;


    if (tree->left == NULL && tree->right == NULL)
    {
        printArray(path, pathLen);
    }
    else
    {
        print_path(tree->left, path, pathLen, end);
        print_path(tree->right, path, pathLen, end);
    }
}

void find_paths(struct node* tree, struct node_t *end)
{
    int path[1000];
    print_path(tree, path, 0, end);
}



int main()
{
    struct node_t *tree = NULL;
    tree = add(tree, "How are you?","Good","Sad",[1],0);
    tree = add(tree, "Why?","I am punished.","I am depressed.", [1,0],0);
    tree = add(tree, "Are you male?","Yes","No", [1,1],0);
    tree = add(tree, "Dont worry!","Ok","Mhm",[1,0,1],0);


    find_paths(tree, "Dont worry!");

	return 0;
}