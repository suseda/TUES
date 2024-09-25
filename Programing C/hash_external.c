#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>

typedef int value_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;

struct item
{
	struct item* next;
	value_t value;
	char key[];
};
struct hash_table
{
	int n, used;
	struct item** array;
};
enum bool{ false, true };

uint32_t sqrt64(uint64_t r)
{
	uint64_t t, b, c = 0;

	for (b = 1ull << 62; b; b >>= 2)
	{
		t = c + b;
		c >>= 1;
		if (t <= r)
		{
			r -= t;
			c += b;
		}
	}
	return (uint32_t)c;
}

enum bool is_prime(unsigned n)
{
	if (n == 1) return false;
	if (n == 2 || n == 3) return true;
	if (n % 2 == 0 || n % 3 == 0) return false;

	unsigned sqn = sqrt64(n);
	for (unsigned i = 2; i < sqn; i++)
		if (n % i == 0)
			return false;

	return true;
}

unsigned find_nearest_prime_above(unsigned n)
{
	if (is_prime(n)) return n;
	while (1)
	{
		unsigned cur = n / 6 * 6;
		if (is_prime(cur + 1)) return cur + 1;
		if (is_prime(cur + 5)) return cur + 5;
		cur += 6;
	}
	return 0;
	/*for (unsigned nearest = n; nearest ; nearest++)
		if(is_prime(nearest))
			return nearest;
	return 0;*/
}

unsigned hash(const char* key, int n)
{
	char byte = 0;
	unsigned hash = 0;
	while (*key)
	{
		hash ^= *key << byte;
		key++;
		byte += 8;
		if (byte == 32)
			byte = 0;
	}
	return hash % n;

	/*int hash = 0;
	while (*key)
	{
		hash += *key;
		key++;
	}
	return hash % n;*/
}

enum bool create(struct hash_table* t, unsigned n)
{
	n = find_nearest_prime_above(n);
	t->array = malloc(sizeof * t->array * n);
	if (!t->array) return false;
	memset(t->array, 0, sizeof * t->array * n);
	t->n = n;
	t->used = 0;
	return true;
}
void destroy(struct hash_table* t)
{
	free(t->array);
	t->n = 0;
	t->used = 0;
}

enum bool push(struct item** p, const char* key, value_t value)
{
	struct item* new = malloc(sizeof * new + 1 + strlen(key));
	if (!new) return false;
	strcpy(new->key, key);
	new->value = value;
	new->next = *p;
	*p = new;
	return true;
}

enum bool rehash(struct hash_table* t, int size);
enum bool insert(struct hash_table* t, const char* key, value_t value)
{
	if (!push(t->array + hash(key, t->n), key, value)) return false;
	if (++t->used * 2 > t->n)
		rehash(t, t->n * 2);
	return true;
}

enum bool rehash(struct hash_table* t, int size)
{
	struct hash_table new;
	if (create(&new, size) == 0) return false;
	for (int i = 0; i < t->n; i++)
		if (t->array[i] != 0)
			insert(&new, t->array[i]->key, t->array[i]->value);
	free(t->array);
	*t = new;
	return true;
}

value_t find(struct hash_table* t, const char* key)
{
	for (struct item** p = t->array + hash(key, t->n); *p; p = &(**p).next)
		if (strcmp((**p).key, key) == 0)
			return (*p)->value;
	return 0;
}

value_t remove(struct hash_table* t, const char* key)
{
	value_t result = 0;
	for (struct item** p = t->array + hash(key, t->n); *p; p = &(**p).next)
		if (strcmp((**p).key, key) == 0)
		{
			struct item* temp = *p;
			result = temp->value;
			*p = (**p).next;
			free(temp);
			break;
		}
	if (--t->used < t->n / 4)
		rehash(t, t->n / 2);
	return result;
}

struct hash_table table;
void main()
{
	create(&table, 1000);

	insert(&table, "test1", 1);
	insert(&table, "test2", 2);
	insert(&table, "", 3);
	insert(&table, "", 4);

	find(&table, "test1");
	remove(&table, "");

	destroy(&table);
}

/*enum bool{ false, true };

struct item
{
	struct item *next;
	int value;
	char key[];
};

struct hash_table
{
	struct item **array;
};

rehash()
//

int hash(key_t key, int sequence, unsigned n)
{

}

enum bool create_hash(struct hash_table* t, unsigned n) // malloc, memset(,0,)
{
	t->array = malloc(sizeof * t->array * n);
	return !!t->array;
}

enum bool insert(struct hash_table* t, const char *key, int value)//ako ima koliziq
{
	struct item* new = malloc(sizeof * new + strlen(key) + 1);//tuk ima oshte
	...
	push(t->array + hash(key, t->n));
	if (n < ++used * 2)
		rehash(t,n*2);
}
int find(struct hash_table* t, const char *key)//nqma reheshirane(vsichki kolizii otivat v edin spisak)
{

}
int remove(struct hash_table* t, const char* key)//trqbva da ima edna zapazena stoynost(naprimer 0) koqto se vrushta ako ne namerim
{

	for (struct item** p = t->array + hash(key, t->n); *p; p=&(**p)->next)
		if( !strcmp((**p).key,key))
			*p=(**p).next;//tuk se pravi free() i drugi osvobojdavaniq

	if (--used < n/4)
		rehash(t, n / 2);
}

void destroy_hash(struct hash_table* t) // free
{
	free(t->array);
	t->array = 0;
}

struct item table;//statichna

void main()
{
	struct hash_table t;
	create_hash(&t, 10000);
	insert(&t, 10003, 1);
	insert(&t, 20003, 2);
	insert(&t, 30003, 3);
	find(&t, 30003);
	remove(&t, 30003);
	find(&t, 30003);
	destroy_hash(&t);
}*/
