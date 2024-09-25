#include <stdio.h>
#include <stdlib.h>
enum bool{ false,true };
struct list
{
    struct list* p;
    int data;
};

void*xor (void* a, void* b) {
    return (void*)((long unsigned int)a ^ (long unsigned int)b);
}

struct list* x_remove(struct list* list)
{
    if (list == NULL) return NULL;
    struct list* next_item = list->p;
    free(list);
    if (next_item == NULL) return NULL;
    next_item->p = xor (list, next_item->p);
    return next_item;
}

struct list* destroy_list(struct list* list) {
    //for(struct list *curr_item=list; curr_item!=NULL;curr_item=x_remove(curr_item));
    for (; list != NULL; list = x_remove(list));

    return NULL;
}

struct list* add(struct list* list, int data)
{
    struct list* item = malloc(sizeof(struct list));
    item->data = data;

    /*if(!list->p)
      list->p = list->p ^ item;

    else
      list->p = (list->p ^ item) ^ list->p;*/

      //item -> p = NULL ^ list;
    item->p = list;
    // list->p = item ^ list->p;
    if (list != NULL) {
        list->p = xor (item, list->p);
        printf("add item %d\n", data);
        printf("item=%p data=%d p=%p\n", item, item->data, item->p);
        printf("list=%p data=%d p=%p\n", list, list->data, list->p);
    }
    puts("===========");
    return item;
}

enum bool check_data(struct list *list, int data)
{
    for (; list != NULL; list = list->p)
        if (list->data == data)  
            return true;
    return false;
}

struct list* index_remove(struct list* list, int index)
{
    if (list == NULL) return NULL;
    struct list* next_item = list->p;
    struct list* prev_item = xor (list, next_item);
    for (int i = 0; i < index; i++)
    {
        prev_item = xor (list,next_item);
        list = next_item;
        next_item = next_item->p;
    }
    prev_item->p = xor (next_item,prev_item->p);
    return prev_item;
}

void print_list(struct list* list) {
    struct list* prev = NULL;
    struct list* tmp = list;

    while (tmp != NULL) {
        printf("tmp=%p data=%d p=%p\n", tmp, tmp->data, tmp->p);

        struct list* tmp2 = tmp;
        //tmp = tmp->p ^ prev;
        tmp = xor (tmp->p, prev);
        prev = tmp2;
    }

    puts("");
}

int main() {
    //struct list list1= {NULL,5};
    //struct list* list = &list1;
    struct list* list = NULL;
    list = add(list, 5);
    list = add(list, 10);
    list = add(list, 15);
    list = add(list, 20);
    list = add(list, 13);
    print_list(list);

    list = index_remove(list, 1);
    check_data(list, 15);
    check_data(list, 20);
    check_data(list, 18);

    list = x_remove(list);
    list = x_remove(list);
    print_list(list);

    /*for(struct list* tmp = list; tmp != NULL; tmp = tmp->next)
    {
      printf("%d ", tmp->data);
    }
    puts("");*/
    return 0;
}
