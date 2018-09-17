#include <string>
#include <iostream>
#include "Time.h"
using namespace std;

Time::Time()
{
	oneToTwo = 0;
	twoToFive = 0;
	fiveToTen = 0;
	tenToFifteen = 0;
	fifteenToTwenty = 0;
	twentyPlus = 0;
}


void Time::display_stats()
{
	cerr << "1 hour to 2 hours:" << oneToTwo << endl;
	cerr << "2 hours to 5 hours: " << twoToFive << endl;
	cerr << "5 hours to 10 hours: " << fiveToTen << endl;
	cerr << "10 hours to 15 hours: " << tenToFifteen << endl;
	cerr << "15 hours to 20 hours: " << fifteenToTwenty << endl;
	cerr << "20 hours plus: " << twentyPlus << endl; 
}

void Time::choose(int choice)
{
	if (choice == 1)
	{
		add_one();
		cerr << "Sucessfully recorded" << endl;
	}
	else if (choice == 2)
	{
		add_two();
		cerr << "Sucessfully recorded" << endl;
	}
	else if (choice == 3)
	{
		add_three();
		cerr << "Sucessfully recorded" << endl;
	}
	else if (choice == 4)
	{
		add_four();
		cerr << "Sucessfully recorded" << endl;
	}
	else if (choice == 5)
	{
		add_five();
		cerr << "Sucessfully recorded" << endl;
	}
	else if (choice == 6)
	{
		add_six();
		cerr << "Sucessfully recorded" << endl;
	}

}
void Time::add_one()
{
	oneToTwo++;
}

void Time::add_two()
{
	twoToFive++;
}

void Time::add_three()
{
	fiveToTen++;
}

void Time::add_four()
{
	tenToFifteen++;
}

void Time::add_five()
{
	fifteenToTwenty++;
}

void Time::add_six()
{
	twentyPlus++;
}