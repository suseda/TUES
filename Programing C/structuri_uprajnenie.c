#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


struct  box
{
	int height, width, weight, length;
};


struct list
{
	struct list* next;
	struct list* prev;
	struct box* box;
};

struct map
{
	struct list* values;
	char* key;
};


struct list * add_list(struct list* list, struct box* box)
{
		struct list *new_item = malloc(sizeof(struct list));
		new_item->prev = NULL;
		new_item->next = list;
		new_item->box = box;
		return new_item;
}

struct box* add_box(int height,int width,int length,int weight)
{
	struct box* new_item = malloc(sizeof(struct box*));
	new_item->height = height;
	new_item->width = width;
	new_item->length = length;
	new_item->weight = weight;
	return new_item;
}

char hash_weight(int weight)
{
	char val = 0;
	itoa(weight, val, 10);
	return val;
}

char hash_volume(int height, int width, int length)
{
	char val = 0;
	itoa(height*width*length, val, 10);
	return val;
}

struct map* lookupByWeight(struct list *list)
{
	struct map* hash_map = malloc(sizeof(struct map*));
	while (list)
	{
		hash_map->key= hash_weight(list->box->weight);
		hash_map->values->box = list->box;
		list = list->next;
	}
	return hash_map;
}

struct map* lookupByVolume(struct list *list)
{
	struct map* hash_map = malloc(sizeof(struct map*));
	while (list)
	{
		hash_map->key = hash_volume(list->box->height, list->box->width, list->box->length);
		hash_map->values = list->box;
		list = list->next;
	}
	return hash_map;
}



int main()
{
	struct list* list1;
	struct box* box = add_box(9,10,11,12);
	struct box* box2 = add_box(13,14,15,16);
	struct box* box3 = add_box(17,18,19,20);
	list1 = add_list(list1,box);
	list1 = add_list(list1, box2);
	list1 = add_list(list1, box3);

	lookupByWeight(list1);
	lookupByVolume(list1);


	return 0;
}