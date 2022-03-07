#pragma once
#include "Exercise.h"
class Yoga : public Exercise
{
private:
	int timeInMins;
	int timeInSeconds;
	string complexity;
public:
	void display();
	string getDataForFile();
	void addData();
	void loadDataFromFile(ifstream&);
};

