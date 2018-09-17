#include <string>
using namespace std;

#ifndef TIME_H_
#define TIME_H_

class Time 
{
	public:
		Time();

		void display_stats();
		void choose(int);
		void add_one();
		void add_two();
		void add_three();
		void add_four();
		void add_five();
		void add_six();

	private:
		int oneToTwo;
		int twoToFive;
		int fiveToTen;
		int tenToFifteen;
		int fifteenToTwenty;
		int twentyPlus;
};

#endif