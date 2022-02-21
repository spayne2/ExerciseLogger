#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

/**
*ENUM for labelling records int the text file
*/
enum ExerciseType
{
	RUN,
	WEIGHT_LIFTING,
	HIKE,
	SWIMMING
};

/**
*Abstract exercise class
*/
class Exercise
{
public:
	virtual void display() = 0;
	virtual string getDataForFile() = 0;
	virtual void addData() = 0;
	virtual void loadDataFromFile(ifstream& ) = 0;
};

