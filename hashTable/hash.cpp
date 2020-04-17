#include "hash.hpp"
#include <string>
#include<iostream>
using namespace std;


//table size = 40009
//linear probing
//quadratic probing
//chaining with LL


HashTable::HashTable(int size){
    tableSize = 40009;
}


bool HashTable:: insertItem(int key){ //LL chaining implementation
    int index= hashFunction(key);
    node*hashElement = new node; //pointer to new value to be inserted
    hashElement->key = key;
    hashElement->next = NULL;

    if(table[index]==NULL){
        hashElement->prev = NULL; //?
        table[index] = hashElement;
    }else{
        node*temp = table[index];
        while(temp!=NULL){
            numOfcolision++;
            if(temp->key == key){
                return false;
            }
            temp = temp->next; //keep going
        }
        temp = table[index];
        while(temp!=NULL && hashElement->key>temp->key){
            temp = temp->next;
        }

        hashElement->next = temp;
        hashElement->prev = temp->prev;
        temp->prev->next = hashElement;
        temp->prev = hashElement;

    }

    return true;

}
 

//insert via linear probing
void HashTable:: linearProb(int key){ 
    node*hashElement = new node; //pointer to new value to be inserted
    hashElement->key = key;
    int index = hashFunction(key);
    while(table[index]!=NULL){
        numOfcolision++;
        index++;
        if(index==tableSize-1){
            index = 0;
        }
    }

    table[index] = hashElement;

    cout<<"Table is full. Cannot insert"<<endl;
    

}
 
//insert via quadratic probing
void HashTable:: quadraticProb(int key){ 
    node*hashElement = new node; //pointer to new value to be inserted
    hashElement->key = key;
    
    int i= hashFunction(key);
    int index = i;
    int a = 1;
    while(table[index]!=NULL){
        numOfcolision++;
        index=i+(a*a);
        a++;
    }

    table[index] = hashElement;
}


unsigned int HashTable:: hashFunction(int key){ //division method
        return key%tableSize; //index

}

void HashTable:: printTable(){

    for(int i=0; i<tableSize;i++){
        cout<<table[i]->key<<" "<<endl;
    }


}


int HashTable:: getNumOfCollision(){
    return numOfcolision;
}

node * HashTable:: searchItem(int key){
    for(int i=0; i<tableSize;i++){
        if(table[(hashFunction(key)+i)%tableSize]->key==key){
            return table[(hashFunction(key)+i)%tableSize];
        }
    }

    cout<<"Item not found"<<endl;
}