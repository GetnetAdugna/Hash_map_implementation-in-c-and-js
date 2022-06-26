#include "a.c"
#define formatBool(b) ((b) ? "true" : "false")

int main(){
    struct HashTable *table=create();
  
    bool valu=add(table,"getnet",12);
    delete_table(table);
    /*sample to be tested*/
    remove(table,"getnet");
    find(table,"getnet");
  


    return 0;
}