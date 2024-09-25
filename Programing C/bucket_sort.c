#include <stdio.h>
#include <malloc.h>

#define BUCKET_CNT 10

struct node
{
	int value;
	struct node *next;
};

void bucket_sort(int arr[], int len)
{
	int index, v = 0;;
	struct node** buckets = malloc(sizeof(struct Node*) * BUCKET_CNT);
	for (int i = 0; i < BUCKET_CNT; ++i) 
	    buckets[i] = NULL;


	for (int j = 0; j < len; j++) 
	{
		int bucket_index = arr[j]/BUCKET_CNT;
		struct node*  current = malloc(sizeof(struct node));
		current->value = arr[j];
		current->next = buckets[bucket_index];
		buckets[bucket_index] = current;
	}

	for (int p = 0; p < BUCKET_CNT; p++) 
		buckets[p] = bubble_sort(buckets[p]);

	for ( index=0; index < BUCKET_CNT; index++)
	{
		struct node* Node;
		Node = buckets[index];
		while (Node) 
		{
			arr[v] = Node->value;
			v++;
			Node = Node->next;
		}
	}

}

int bubble_sort(struct node* l)
{
	if (l == NULL || l->next == NULL)
		return l;
	struct node* l_copy = l;
	struct node* index = NULL;
	int tmp;
	for (; l != NULL; l=l->next)
	{
		for (index = l->next;index!=NULL;index=index->next)
		{
			if (l->value > index->value)
			{
				tmp = l->value;
				l->value = index->value;
				index->value = tmp;
			}
		}

	}
	return l_copy;
}

void print_list(int arr[],int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
}

int main()
{
	int arr[] = {29,25,3,49,9,37,21,43}; // работи с числа тип int между 0 и 100
	int size = sizeof(arr) / sizeof(int);
	bucket_sort(arr,size);
	print_list(arr, size);
}