#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//enum Bool { False, True };

struct node_t
{
    int mat[9];
    struct node_t* parent;
    double heuristic;
    int level;
    int empty_index;
    int *child_board;
    struct node_t* next;
};


void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

double Heuristic(int* mat)
{
    int cnt = 1;
    int in_pos = 0;
    for (int i = 0; i < 8; i++)
    {
        if (mat[i] == cnt)
        {
            in_pos++;
        }
        cnt++;
    }
    return in_pos / 8;
}

int* best_child(struct node_t* parent) // *A star
{
    switch (parent->empty_index)
    {
    case 0://{1, 3}
    {
        int arr[2] = { 1,3 };
        int best_index = arr[0];
        double heuristic = 0;
        for (int j = 0; j < 2; j++)
        {
            int curr[9];
            for (int l = 0; l < 9; l++)
            {
                curr[l] = parent->mat[l];
            }
            swap(curr[parent->empty_index], curr[arr[j]]);

            if (Heuristic(curr) > heuristic)
            {
                heuristic = Heuristic(curr);
                best_index = arr[j];
            }
        }
        swap(parent->mat[parent->empty_index], parent->mat[best_index]);
        return parent->mat;
    }
    case 1://{0, 2, 4}
    {
        int arr[3] = { 0, 2, 4 };
        int best_index = arr[0];
        double heuristic = 0;
        for (int j = 0; j < 3; j++)
        {
            int curr[9];
            for (int l = 0; l < 9; l++)
            {
                curr[l] = parent->mat[l];
            }
            swap(curr[parent->empty_index], curr[arr[j]]);

            if (Heuristic(curr) > heuristic)
            {
                heuristic = Heuristic(curr);
                best_index = arr[j];
            }
        }
        swap(parent->mat[parent->empty_index], parent->mat[best_index]);
        return parent->mat;
    }
    case 2://{1, 5}
    {
        int arr[2] = { 1,5 };
        int best_index = arr[0];
        double heuristic = 0;
        for (int j = 0; j < 2; j++)
        {
            int curr[9];
            for (int l = 0; l < 9; l++)
            {
                curr[l] = parent->mat[l];
            }
            swap(curr[parent->empty_index], curr[arr[j]]);

            if (Heuristic(curr) > heuristic)
            {
                heuristic = Heuristic(curr);
                best_index = arr[j];
            }
        }
        swap(parent->mat[parent->empty_index], parent->mat[best_index]);
        return parent->mat;
    }
    case 3://{4, 0, 6}
    {
        int arr[3] = { 4,0,6 };
        int best_index = arr[0];
        double heuristic = 0;
        for (int j = 0; j < 3; j++)
        {
            int curr[9];
            for (int l = 0; l < 9; l++)
            {
                curr[l] = parent->mat[l];
            }
            swap(curr[parent->empty_index], curr[arr[j]]);

            if (Heuristic(curr) > heuristic)
            {
                heuristic = Heuristic(curr);
                best_index = arr[j];
            }
        }
        swap(parent->mat[parent->empty_index], parent->mat[best_index]);
        return parent->mat;
    }
    case 4://{3, 5, 1, 7}
    {
        int arr[4] = { 3,5,1,7 };
        int best_index = arr[0];
        double heuristic = 0;
        for (int j = 0; j < 4; j++)
        {
            int curr[9];
            for (int l = 0; l < 9; l++)
            {
                curr[l] = parent->mat[l];
            }
            swap(curr[parent->empty_index], curr[arr[j]]);

            if (Heuristic(curr) > heuristic)
            {
                heuristic = Heuristic(curr);
                best_index = arr[j];
            }
        }
        swap(parent->mat[parent->empty_index], parent->mat[best_index]);
        return parent->mat;
    }
    case 5://{4, 2, 8}
    {
        int arr[3] = { 4,2,8 };
        int best_index = arr[0];
        double heuristic = 0;
        for (int j = 0; j < 3; j++)
        {
            int curr[9];
            for (int l = 0; l < 9; l++)
            {
                curr[l] = parent->mat[l];
            }
            swap(curr[parent->empty_index], curr[arr[j]]);

            if (Heuristic(curr) > heuristic)
            {
                heuristic = Heuristic(curr);
                best_index = arr[j];
            }
        }
        swap(parent->mat[parent->empty_index], parent->mat[best_index]);
        return parent->mat;
    }
    case 6://{7, 3}
    {
        int arr[2] = { 7,3 };
        int best_index = arr[0];
        double heuristic = 0;
        for (int j = 0; j < 2; j++)
        {
            int curr[9];
            for (int l = 0; l < 9; l++)
            {
                curr[l] = parent->mat[l];
            }
            swap(curr[parent->empty_index], curr[arr[j]]);

            if (Heuristic(curr) > heuristic)
            {
                heuristic = Heuristic(curr);
                best_index = arr[j];
            }
        }
        swap(parent->mat[parent->empty_index], parent->mat[best_index]);
        return parent->mat;
    }
    case 7://{6, 8, 4}
    {
        int arr[3] = { 6,8,4 };
        int best_index = arr[0];
        double heuristic = 0;
        for (int j = 0; j < 3; j++)
        {
            int curr[9];
            for (int l = 0; l < 9; l++)
            {
                curr[l] = parent->mat[l];
            }
            swap(curr[parent->empty_index], curr[arr[j]]);

            if (Heuristic(curr) > heuristic)
            {
                heuristic = Heuristic(curr);
                best_index = arr[j];
            }
        }
        swap(parent->mat[parent->empty_index], parent->mat[best_index]);
        return parent->mat;
    }
    case 8://{7, 5}
    {
        int arr[2] = { 7,5 };
        int best_index = arr[0];
        double heuristic = 0;
        for (int j = 0; j < 2; j++)
        {
            int curr[9];
            for (int l = 0; l < 9; l++)
            {
                curr[l] = parent->mat[l];
            }
            swap(curr[parent->empty_index], curr[arr[j]]);

            if (Heuristic(curr) > heuristic)
            {
                heuristic = Heuristic(curr);
                best_index = arr[j];
            }
        }
        swap(parent->mat[parent->empty_index], parent->mat[best_index]);
        return parent->mat;
    }
    }

}

/*enum Bool compare_heuristic(struct node_t* n1, struct node_t* n2)
{
    return (n1->heuristic + n1->level) > (n2->heuristic + n2->level);
}*/

struct node_t* new_node(int initial[9], struct node_t* parent, int level, int empty_index)
{
    struct node_t* new_node = malloc(sizeof(struct node_t*));
    //new_node->mat = calloc(9,sizeof(int));
    for (int i = 0; i < 9; i++)
    {
        new_node->mat[i] = initial[i];
    }
    
    new_node->parent = parent;
    new_node->heuristic = Heuristic(new_node->mat);
    new_node->level = level;
    new_node->empty_index = empty_index;
    new_node->next = NULL;
    new_node->child_board = best_child(new_node);

    return new_node;
}



void print_board(int* mat)
{
    int var = 0;
    for (int i = 0; i < 9; i++)
    {
        if (var != 2)
        {
            var++;
            printf("[%d]", mat[i]);
        }
        else
        {
            var = 0;
            printf("[%d]\n", mat[i]);
        }
    }
    puts("\n");
}



void Solve(int board[9], int empty_index)
{
    struct node_t* root = new_node(board[9], NULL, 0, empty_index);

    while (root->heuristic != 1.0)
    {
        print_board(root->mat);

        int child_empty_index = 0;
        for (int i = 0; i < 9; i++)
        {
            if (root->child_board[i] == 0)
            {
                child_empty_index = i;
                break;
            }
        }

        root->next = new_node(root->child_board, root, root->level + 1, child_empty_index);
        root = root->next;
    }

    print_board(root->mat);

    return;
}


int main()
{
    FILE* name = fopen("Integers.txt", "r");
    int board[9];
    int empty_ind = 0;
    if (name == NULL)
    {
        printf("File can't be open");
    }

    int i = 0;
    char ch;
    while ((ch = fgetc(name)) != EOF)
    {
        if (ch == "-")
        {
            board[i] = 0;
            empty_ind = i;
        }
        else
        {
            int num = atoi(ch);
            board[i] = num;
        }
        i++;
    }
    fclose(name);

    

    Solve(board, empty_ind);

    return 0;
}

