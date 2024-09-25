#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <malloc.h>
struct item
{
	struct item* next;
	char name[1];
};
struct queue
{
	struct item* head, * tail;
};
enum bool{ false, true } enqueue(struct queue* q, const char* added_name)
{
	struct item* new = malloc(sizeof * new + strlen(added_name));
	if (!new)
		return false;
	strcpy(new->name, added_name);
	new->next = 0;
	if (q->head == 0)
		q->tail = new;
	else
		q->head->next = new;
	q->head = new;
	return true;
}
enum bool dequeue(struct queue* q, char* out)
{
	if (q->tail == 0)
		return false;
	strcpy(out, q->tail->name);
	struct item* old = q->tail;
	q->tail = q->tail->next;
	if (q->tail == 0)
		q->head = 0;
	free(old);
	return true;
}
void main()
{
	struct queue q = { 0 };
	enqueue(&q, "first");
	enqueue(&q, "second");
	char buffer[100];
	dequeue(&q, buffer);
	dequeue(&q, buffer);
}
/*
	q->tail = q->tail->next;
	if(q->tail == 0)
		q->head = q->head->next;
*/