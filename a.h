/*This is a description of (an interface of) the hash map that we are going to implement in the a.c file the main methods are
listed bellow .*/
#include<stdbool.h>

struct HashTable; 
struct Binding; 


typedef struct Binding Binding;   
typedef struct HashTable HashTable; 

HashTable *create();//Only the declaration, no implementation here.

unsigned int hash(const char *key);//Only the declaration, no implementation here.

bool add(HashTable* table, const char* key, int value);//Only the declaration, no implementation here.

Binding *find(HashTable* table, const char* key);//Only the declaration, no implementation here.

bool remove(HashTable* table, const char* key);//Only the declaration, no implementation here.

void delete_table(HashTable* table);//Only the declaration, no implementation here.
