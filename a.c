/*An implementation of a Hash map in C programming language 
*GETNET ADUGNA ABITE 


the implementations are based on a separate chaining where each hashtable cell contatins linked lists of struct 
bindings.
*/

#include "a.h"
#include <stdlib.h>
#include <stdbool.h>
#include<string.h>

#define BUCKET_COUNT 1024
struct Binding{

    const char* key;
    int value;
    struct Binding* next;
};

struct HashTable{

    struct Binding* buckets[BUCKET_COUNT];
};


struct HashTable* create(){
  HashTable *hashTable = (HashTable*) malloc(sizeof(HashTable));
  for(int i=0;i<BUCKET_COUNT;i++){
     hashTable->buckets[i]=NULL;
  }

   return hashTable;
}


unsigned int hash(const char* key){


    unsigned int total=0;
  
    int PRIME_NUMBER=31;
 
    for (int i=0;i<BUCKET_COUNT;i++){
        char ch=key[i];
      
        int value=ch-'a';
        total=(total*PRIME_NUMBER+value)%BUCKET_COUNT;

    }
   
    return total;

}

bool add(struct HashTable* table, const char* key, int value){
   unsigned int index = hash(key);
   Binding * ptr_struct_binding=(Binding*) malloc(sizeof(Binding)); 
   ptr_struct_binding->value = value;
   ptr_struct_binding->key = key;
 
   ptr_struct_binding->next = NULL;
  if (table->buckets[index] == NULL ){
    
    table->buckets[index] = ptr_struct_binding;
    return true;
  }
  else{
    Binding *buffer = table->buckets[index];
   
   for(;;){
       if(buffer->next == NULL){
           break;
       } 
          if (strcmp(buffer->key,key)==0) {
       buffer->value = value;
       return 0;
     }
    
      buffer = buffer->next;
   }
    buffer->next = ptr_struct_binding; 
   return 0;
  }}

  Binding *find(HashTable* table, const char* key)
  {
    
      unsigned int index = hash(key);
      if(table->buckets[index] != NULL){
      if (table->buckets[index]->key== key) {
           return table->buckets[index];
      }    
  }

  return NULL; 

  }
  bool remove(HashTable* table, const char* key){
     
            unsigned int index= hash(key);
          
            Binding *ptr_struct_binding = table->buckets[index];
           
            if (table->buckets[index] != NULL){
           
            if (ptr_struct_binding->key==key){
                table->buckets[index] = ptr_struct_binding->next;
                free(ptr_struct_binding);
               
                return true;
            }
            else{
                  for(;;){
                    if(ptr_struct_binding->next == NULL){
                      break;
                    }
                      if (ptr_struct_binding->next->key== key) {
                         ptr_struct_binding->next = ptr_struct_binding->next->next;
                       free(ptr_struct_binding->next);
                        return true;}
                        ptr_struct_binding=ptr_struct_binding->next;
                  }
        
          return false;
            }  
    }
     
}
  

  void delete_table(HashTable* table){
      int i=0;
      while(i<BUCKET_COUNT){
          Binding *ptr_struct_binding=table->buckets[i];
         if(ptr_struct_binding != NULL){
             for(;;){
                 if(ptr_struct_binding->next==NULL){
                     break;
                 }
                  free(ptr_struct_binding);
	       ptr_struct_binding= ptr_struct_binding->next;
             }
          
      }
      i++;
    }
    
    free(table);   
  }






