#include <string>
#include <vector>
#include <iostream>
#include "Classes.h"
using namespace std;

#ifndef HASHENTRY_H_
#define HASHENTRY_H_

class HashEntry 
{
private:
	string info;
	HashEntry *next;
	vector<Classes> list;

public:
	HashEntry();
	HashEntry(const HashEntry &h);

	bool next_null();
	void make_next();
	HashEntry* get_next();
	void set_name(string);
	string get_name();

	void add_classes(Classes);
	bool duplicates(string);

	Classes* get_class(string);
	string get_class_number(string);
};

#endif

