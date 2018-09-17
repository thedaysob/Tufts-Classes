
#include <string>
#include <iostream>
#include <vector>
#include "HashEntry.h"
#include "Classes.h"
using namespace std;

HashEntry::HashEntry()
{
	info = "Empty";
	next = NULL;
}

HashEntry::HashEntry(const HashEntry &h)
{
	info = h.info;
	next = h.next;
}

bool HashEntry::next_null()
{
	if (next == NULL)
		return true;
	else
		return false;
}

void HashEntry::make_next()
{
	next = new HashEntry;
}

HashEntry* HashEntry::get_next()
{
	return next;
}

void HashEntry::set_name(string className)
{
	info = className;
}

string HashEntry::get_name()
{
	return info;
}

void HashEntry::add_classes(Classes className)
{
	list.push_back(className);
}

bool HashEntry::duplicates(string className)
{
	size_t sz = list.size();

	for (unsigned i = 0; i < sz; i++)
	{
		if (className == list[i].get_name())
			return true;
	}

	return false;
}

Classes* HashEntry::get_class(string className)
{
	size_t sz = list.size();
	string classNumber = get_class_number(className);

	for (unsigned i = 0; i < sz; i++)
	{
		string temp = list[i].get_name();
		string classNumberTemp = get_class_number(temp);
		
		int classNumberTempInt = stoi(classNumberTemp);
		int classNumberInt = stoi(classNumber);

		if (classNumberTempInt == classNumberInt)
		{
			cerr << "found" << endl;
			return &list[i];
		}
	}


	cerr << "Could not find class" << endl;

	return &list[0];
}

string HashEntry::get_class_number(string className)
{
	int word_length = className.length();
	int j = 0;

	for (int i = 0; i < word_length; i++)
	{
		if (className[i] == '-')
			break;
		j++;
	}

	string classNumber = className.substr(j+1,word_length-1);
	return classNumber;
}

