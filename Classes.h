#include <string>
#include "Time.h"
using namespace std;

#ifndef CLASSES_H_
#define CLASSES_H_

class Classes 
{
private:
	string info;
	Time hoursSpent;

public:
	Classes();
	Classes(string);

	void set_name(string);
	string get_name();
	void get_stat();

	void record_stat(int);
};

#endif