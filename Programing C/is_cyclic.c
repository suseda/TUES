#include <stdio.h>
#include <stdlib.h>


#include "is_cyclic_h.h"

struct node* add_cycle(struct node* list, int value)
{
	struct node* new_item = malloc(sizeof(struct node));
	if (list == NULL)
	{
		new_item->value = value;
		new_item->next = new_item->prev = NULL;
		return new_item;
	}
	else
		new_item->value = value;
		new_item->next = list;
		while (list->next != NULL)
			list = list->next;
		list->next = new_item; 
	
	return new_item;

}



struct node* add(struct node* list,int value)
{
	struct node* new_item = malloc(sizeof(struct node));
	if (list == NULL)
	{
		new_item->value = value;
		new_item->next = new_item->prev = NULL;
		return new_item;
	}

	new_item->value = value;
	new_item->next = list;
	list->prev = new_item;
	new_item->prev = NULL;
	return new_item;

}


int is_cyclic_next(struct node* node)
{
	struct node* slow = node;
	struct node* fast = node->next;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return 1;
	}
	return 0;
}

int is_cyclic_prev(struct node* node)
{
	struct node* slow = node;
	struct node* fast = node->prev;
	while (fast && fast->prev)
	{
		slow = slow->prev;
		fast = fast->prev->prev;
		if (slow == fast)
			return 1;
	}
	return 0;
}


int is_cyclic(struct node* node)
{
	if (is_cyclic_next(node) || is_cyclic_prev(node))
		return 1;
	return 0;
}

int main()
{
	struct node* normal_list = add(NULL, 3);
	normal_list = add(normal_list, 5);
	normal_list = add(normal_list, 8);
	normal_list = add(normal_list, 10);
	normal_list = add(normal_list, 12);
	normal_list = add(normal_list, 15);

	struct node* list_with_cycle = add(NULL, 3);
	list_with_cycle = add(list_with_cycle, 5);
	list_with_cycle = add(list_with_cycle, 8);
	list_with_cycle = add(list_with_cycle, 10);
	list_with_cycle = add(list_with_cycle, 12);
	list_with_cycle = add_cycle(list_with_cycle, 15);

	printf("%d", is_cyclic(normal_list));
	puts(" ");
	printf("%d", is_cyclic(list_with_cycle));

	return 0;
}
