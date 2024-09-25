#include <stdio.h>
#include <malloc.h>

struct list
{
	struct list* next, * prev;
	int data;
	struct list** skip;
};


void*xor (void* a, void* b) 
{
	return (void*)((long unsigned int)a ^ (long unsigned int)b);
}


struct list* add(struct list* list, int data)
{
    struct list* item = malloc(sizeof(struct list));
    item->data = data;
    item->prev = NULL;
    item->next = NULL;
    item->skip = NULL;

    if (!list)
        return item;
    
    if (data < list->data)
    {
        item->next = list;
        list->prev = item;
        list = item;
    }
    else {
        struct list* curr = list;
        struct list* next = NULL;
        struct list* prev = NULL;

        if (item->skip != NULL)
            next = xor (prev,curr->skip[0]);

        while (item->skip != NULL && item->data < data)
        {
            prev = curr;
            curr = next;
            if (next->next == NULL || next->next->next == NULL)
                next = NULL;
            else
                next = next->next->next;
        }
        while (curr->next != NULL && curr->next->data < data) curr = curr->next;
        item->prev = curr;
        item->next = curr->next;

        if (curr->next != NULL) 
            curr->next->prev = item;
        curr->next = item;
    }

    struct list* tmp = list;
    while (tmp != NULL) 
    {
        if (tmp->skip) 
        {
            free(tmp->skip);
            tmp->skip = NULL;
        }

        tmp = tmp->next;
    }

    tmp = list;
    struct list* n = list->next->next;
    struct list* p = NULL;
    if (n != NULL) 
    {
        do
        { 
            tmp->skip = malloc(sizeof(struct list*));
            tmp->skip[0] = xor(p, n); 
            if (n->next == NULL || n->next->next == NULL)
                n = NULL;
            else
                n = n->next->next;
            p = tmp;
            tmp = tmp->skip[0]; 
        } while (n != NULL);
       
    }
    

    return list;

}


void print_list(struct list* list) 
{
    for (struct list* tmp = list; tmp != NULL; tmp = tmp->next)
    {
        printf("*=%p d=%d next=%p skip=%p", tmp, tmp->data, tmp->next, tmp->skip);
        if (tmp->skip)
            printf(" skip[0]=%p", tmp->skip[0]);
        puts("");
    }
}

int main()
{
    struct list* list = NULL;
    list = add(list, 7);
    list = add(list, 48);
    list = add(list, 27);
    list = add(list, 3);
    list = add(list, 41);
    list = add(list, 1);

    print_list(list);

    return 0;
}