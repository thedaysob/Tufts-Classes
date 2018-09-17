#include <string>
#include <iostream>
#include "Time.h"
#include "Classes.h"
using namespace std;

// Constructor
Classes::Classes()
{
	info = " ";
}

Classes::Classes(string className)
{
	info = className;
}

void Classes::set_name(string className)
{
	info = className;
}

string Classes::get_name()
{
	return info;
}

void Classes::get_stat()
{
	hoursSpent.display_stats();
}

void Classes::record_stat(int choice)
{
	hoursSpent.choose(choice);
}