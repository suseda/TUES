#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


struct queue
{
	int data;
	int priority;
	struct queue* next;
	struct queue* prev;
};

//инициализиране, добавяне на елемент, премахване на елемент, унищожаване на цялата опашка

struct queue* init(int data, int priority)
{
	struct queue* new_item = (struct queue*)malloc(sizeof(struct queue));
	new_item->data = data;
	new_item->priority=priority;
	new_item->next = new_item->prev = NULL;
	return new_item;
}

void add(struct queue ** head, int data, int priority)
{
	struct queue* q = (*head);
    struct queue* node = init(data, priority);

	if ((*head)->priority > priority) 
	{
		node->next = *head;
		(*head) = node;
	}
	else 
	{
		while (q->next != NULL && q->next->priority < priority) 
		{
			q = q->next;
		}

		node->next = q->next;
		q->next = node;
	}
}



void remove_element(struct queue* q, int data)
{
	for (; q; q = q->next)
	{
		if (q->data == data)
		{
			struct queue* prev = q->prev;
			struct queue* next = q->next;
			free(q);
			prev->next = next;
			next->prev = prev;
		}
	}
}

void delete_queue(struct queue** q)
{
	struct queue* curr = *q;
	struct queue* next = NULL;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	*q = NULL;
}

void print_queue(struct queue* q)
{
	while (q)
	{
		printf("<=> %d ", q->data);
		q = q->next;
    }
}

int main()
{
	struct queue* q = NULL;
	add(q, 13, 5);
	add(q, 10, 8);
	add(q, 2, 3);
	add(q, 5, 10);
	add(q, 6, 6);

	print_queue(q);

	remove_element(q, 10);
	remove_element(q, 13);

	delete_queue(&q);

	return 0;
}