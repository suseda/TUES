#include <malloc.h>
#include <string.h>

typedef unsigned long long key_t;
typedef unsigned char value_t;

struct item
{
	key_t key;
	value_t value;
};

struct hash_table
{
	struct item* array;
	unsigned n, used;
};

int hash(key_t key, unsigned n, int sequence)
{
	return (key * sequence) % n;
}

enum bool{ false, true };

enum bool create_hash(struct hash_table* t, unsigned n) // malloc, memset(,0,)
{
	struct item* new = malloc(sizeof * t->array * n);
	if (!new)
		return false;
	memset(new, 0, sizeof * t->array * n);
	t->array = new;
	t->n = n;
	t->used = 0;
	return true;
}

enum bool insert(struct hash_table* t, key_t key, value_t value) // malloc+free
{
	for (int seq = 1; seq <= 5; seq++)
	{
		int a = hash(key, t->n, seq);
		if (t->array[a].key == 0)
		{
			t->array[a].key = key;
			t->array[a].value = value;
			t->used++;
			return true;
		}
	}
	return false;
}

value_t find(struct hash_table* t, key_t key)
{
	int a;
	for (int seq = 1; seq <= 5; seq++)
	{
		a = hash(key, t->n, seq);
		if (t->array[a].key == key)
			return t->array[a].value;
	}
	return 0;
}

void destroy_hash(struct hash_table* t) // free
{
	free(t->array);
	t->n = 0;
	t->used = 0;
}

enum bool remove(struct hash_table* t, key_t key)
{
	struct hash_table e;
	enum bool w = false;
	for (int seq = 1; seq <= 5; seq++)
	{
		int a = hash(key, t->n, seq);
		if (t->array[a].key == key)
		{
			t->array[a].key = 0;
			t->array[a].value = 0;
			t->used--;
			w = true;
			break;
		}
	}
	if (t->used < (t->n / 4))
	{
		create_hash(&e, t->n / 2);
		for (unsigned c = 0; c < t->n; c++)
			if (t->array[c].key != 0)
				insert(&e, t->array[c].key, t->array[c].value);
		free(t->array);
		*t = e;

	}
	return w;
}

void main()
{
	/*struct hash_table t;
	create_hash(&t, 10);
	insert(&t, 966565, 198);
	insert(&t, 790077, 200);
	insert(&t, 286810, 160);
	insert(&t, 255240, 120);
	insert(&t, 870824, 173);
	find(&t, 286810);
	find(&t, 101010);
	remove(&t, 286810);
	remove(&t, 101010);
	destroy_hash(&t);*/
	struct hash_table t;
	create_hash(&t, 10000);
	insert(&t, 50003, 160);
	insert(&t, 30003, 180);
	insert(&t, 40000, 200);
	find(&t, 30003);
	remove(&t, 50003);
	find(&t, 30003);
	destroy_hash(&t);
}