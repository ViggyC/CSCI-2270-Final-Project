#include "hash.h"
#include <string>
#include<iostream>
using namespace std;

//this file handles all collision resolutions

// 1. chaining with LL
// 2. linear probing
// 3. quadratic probing

//CONSTRUCTOR
HashTable::HashTable(int size){ //seg faulting in here
   
    tableSize = 40009;
    //initialize table
    table = new node*[tableSize]; //array=hash table
    for(int i=0; i<tableSize; i++){
        //set key and next
       
        table[i]=NULL;
        //table[i] = createNode(0,NULL);
       
    }
    
}

//1)
///////////////////////////////////////// LL CHAINING ///////////////////////////////////////////

bool HashTable:: LLChaining(int key){ //LL chaining implementation
    int index= hashFunction(key); //retrieve index from hash fxn
    node*hashElement = new node; //pointer to new value to be inserted
    hashElement->key = key;
    
    if(table[index]==0){
        table[index] = hashElement;
    }else{ //add hashElement to head of linked list
        hashElement->next = table[index];
        table[index]=hashElement;

        numOfcolision++;
    }

}

//search via LL chaining
//traverse entire LL: worst case = O(N)
node * HashTable:: searchItemLL(int key){
    bool found = false;
    int index = hashFunction(key); //index from hash fxn
    node * search = table[index];

    while(search!=NULL){
        if(search->key ==key){
            cout<<"found key " << key<<endl;
            found = true;
            return search; //return node found with correct key value
        }
        
        search = search->next;

    }

    if(!found){
        cout<<"key "<<key<<" not found"<<endl;
        return NULL;
    }

}


//2)
///////////////////////////////////////// LINEAR PROBING ///////////////////////////////////////////

//insert via linear probing
bool HashTable:: linearProb(int key){

    node*hashElement = new node; //pointer to new value to be inserted
    hashElement->key = key;
    
    for(int i=0 ;i<tableSize;i++){
        if(table[(hashFunction(key)+i) % tableSize]==NULL){
            table[(hashFunction(key)+i) % tableSize]= hashElement;
            cout<<"Insert successful"<<endl;
            return true;
        }
        numOfcolision++;
    }
    

    cout<<"Table is full. Cannot insert"<<endl;
    return false;
}

//search via linear probing
node * HashTable:: searchItemLinear(int key){

    for(int i=0; i<tableSize;i++){
        if(table[(hashFunction(key)+i)%tableSize]->key==key){
            cout<<"Item found"<<endl;
            return table[(hashFunction(key)+i)%tableSize];
        }


    }

    cout<<"Item not found"<<endl;
    return NULL;
}


//3)
///////////////////////////////////////// QUADRATIC PROBING ///////////////////////////////////////////
 
//insert via quadratic probing
bool HashTable:: quadraticProb(int key){ 

    node*hashElement = new node; //pointer to new value to be inserted
    hashElement->key = key;

    for(int i=0 ;i<tableSize;i++){
        if(table[(hashFunction(key)+(i*i)) % tableSize]==NULL){
            table[(hashFunction(key)+(i*i)) % tableSize]= hashElement;
            cout<<"Insert successful"<<endl;
            return true;
        }
        numOfcolision++;
    }
    

    cout<<"Table is full. Cannot insert"<<endl;
    return false;
}


//search via quadratic probing
node * HashTable:: searchItemQuadtratic(int key){
    for(int i=0; i<tableSize;i++){
        if(table[(hashFunction(key)+(i*i))%tableSize]->key==key){
            cout<<"Item found"<<endl;
            return table[(hashFunction(key)+(i*i))%tableSize];
        }
    }

    cout<<"Item not found"<<endl;
    return NULL;

}





/////////////////////////////////////////////////////////////////////////////


//DIVISION METHOD
unsigned int HashTable:: hashFunction(int key){ 
        return key%tableSize; //index

}

void HashTable:: printTable(){

    for(int i=0; i<tableSize;i++){
        cout<<table[i]->key<<" ";
    }

    cout<<endl;


}


int HashTable:: getNumOfCollision(){
    return numOfcolision;
}


