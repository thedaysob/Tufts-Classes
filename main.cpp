#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include "HashTable.h"
#include "HashEntry.h"
#include "Classes.h"
using namespace std;

void fill_table(HashTable *);
void fill_entry(HashTable *, string, Classes, string);
int calculate_key(string);
void get_stat(HashTable *, string);

string get_class_topic(string);
void fill_classes(HashTable *, string);

int get_class_number(string);

void navigate(HashTable *);



int main()
{
	HashTable *table = new HashTable;
	fill_table(table);

	string answer;

	while (answer != "quit")
	{
		cerr << "This program is to help students judge their class work through their semester." << endl << endl;;

		cerr << "If you are here to help out the cause by logging your estimated class work time, please enter y." << endl;
		cerr << "Otherwise, please enter n." << endl;

		cin >> answer;

		if (answer == "y")
		{
			navigate(table);
		}
		else
		{
			do
			{
				cerr << "What class are you looking for?" << endl;
				cin >> answer;
				get_stat(table, answer);
			} while(answer != "quit");
		}
	}
}

void fill_table(HashTable *table)
{
	ifstream infile;
	infile.open("Classes.txt");

	if (!infile.is_open())
	{
		cerr << "Could not open Classes.txt" << endl;
		return;
	}

	string className;
	string topic;
	while(!infile.eof())
	{
		getline(infile, className);
		topic = get_class_topic(className);
		Classes classObject(className);
		fill_entry(table, topic, classObject, className);
	}
}

void fill_entry(HashTable *table, string topic, Classes classObject, string className)
{
	int location = calculate_key(topic);
	table->put(topic, location, classObject, className);
}

string get_class_topic(string className)
{
	int word_length = className.length();
	int j = 0;

	for (int i = 0; i < word_length; i++)
	{
		if (className[i] == '-')
			break;
		j++;
	}

	string topic = className.substr(0,j);
	return topic;
}

int calculate_key(string word)
{
	int word_length = word.length();
	int key = 0;
    for (int i = 0; i < word_length; i++)
    {
    	if (word[i] == '-')
    		break;
        key = key + (word[i] * i);
    }
    return key;
}

void get_stat(HashTable *table, string className)
{
	int location = calculate_key(className);


	HashEntry *entry;
	entry = table->get(location);
	

	Classes *classObject;

	classObject = entry->get_class(className);


	if (get_class_number(classObject->get_name()) == get_class_number(className))
	{
		cerr << className << " Stat: " << endl;
		classObject->get_stat();
	}
	else
		cerr << "Sorry" << endl;
}

int get_class_number(string className)
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
	return stoi(classNumber);
}

void navigate(HashTable *table)
{
	cerr << "Please enter your class name" << endl;

	string className;
	cin >> className;

	int location = calculate_key(className);

	HashEntry *entry;
	entry = table->get(location);
	

	Classes *classObject;

	classObject = entry->get_class(className);

	cerr << "Please enter your choice" << endl;
	cerr << "1.			1 ~ 2" << endl;
	cerr << "2.			2 ~ 5" << endl;
	cerr << "3.			5 ~ 10" << endl;
	cerr << "4.			10 ~ 15" << endl;
	cerr << "5.			15 ~ 20" << endl;
	cerr << "6.			20+" << endl;

	string choice;
	cin >> choice;

	int choiceInt = stoi(choice);

	classObject->record_stat(choiceInt);
}