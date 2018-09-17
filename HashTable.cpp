#include <string>
#include <iostream>
#include "HashTable.h"
#include "HashEntry.h"
#include "Classes.h"
using namespace std;

// Constructor
HashTable::HashTable()
{
    table = new HashEntry[MAX_ITEMS];
}

HashTable::~HashTable()
{
    HashEntry *curr;
    HashEntry *next;

    for (int i = 0; i < MAX_ITEMS; i++)
    {
        curr = &table[i];
        curr = curr->get_next();
        while (curr != NULL)
        {
            next = curr->get_next();
            delete curr;
            curr = next;
        }
    }
    delete [] table;
}


void HashTable::put(string topic, int key, Classes classObject, string className)
{
	int index = key % MAX_ITEMS;

	if (table[index].get_name() == "Empty")
    {
		table[index].set_name(topic);
        table[index].add_classes(classObject);
    }
    else if (table[index].get_name() == topic)
    {
        if (!table[index].duplicates(className))
            table[index].add_classes(classObject);
    }
	else
	{
		HashEntry *entry = &table[index];
		while(!entry->next_null())
			entry = entry->get_next();

        if (entry->get_name() == topic)
        {
            if (!entry->duplicates(className))
                entry->add_classes(classObject);
            return;
        }

		entry->make_next();
		entry = entry->get_next();
		entry->set_name(topic);

        entry->add_classes(classObject);
	}
}

HashEntry* HashTable::get(int key)
{
    int index = key % MAX_ITEMS;

    return &table[index];
}
