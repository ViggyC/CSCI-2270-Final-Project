#ifndef HASH_HPP
#define HASH_HPP

#include <string>


using namespace std;

struct node
{
    int key; //record
    struct node* next;
    struct node* prev; //added by Vignesh for LL chaining 
};

class HashTable
{
    int tableSize;  // No. of buckets (linked lists)

    // Pointer to an array containing buckets
    node* *table; 
    int numOfcolision =0;
    node* createNode(int key, node* next);
public:
    HashTable(int bsize);  // Constructor

    //inserts a key into hash table
    //utilize collision resolution - Vignesh
    bool LLChaining(int key); 
    bool linearProb(int key); //added by Vignesh
    bool quadraticProb(int key); //added by Vignesh

    // hash function to map values to key
    unsigned int hashFunction(int key);

    void printTable();
    int getNumOfCollision();

    node* searchItemLL(int key); //need to do
    node* searchItemLinear(int key); //done
    node* searchItemQuadtratic(int key); //need to do
};

#endif