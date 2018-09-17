#include <iostream>
#include <string>
#include <vector>
#include "HashEntry.h"
#include "Classes.h"
using namespace std;

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

const int MAX_ITEMS = 200;

class HashTable
{
private:
    HashEntry *table;
    
public:
    HashTable();
    ~HashTable();

    void put(string, int, Classes, string);
    HashEntry* get(int);
};

#endif