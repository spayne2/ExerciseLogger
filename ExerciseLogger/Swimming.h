#pragma once
#include "Exercise.h"
class Swimming : public Exercise
{
private:
	int length;
	int laps;
	string stroke;
	/**
	*calcTotalDistnace calculates the total distance that has been swam
	*/
	int calcTotalDistance();
public:
	/**
	*Default Constructor for swimming
	*/
	Swimming() { length = 0; laps = 0; stroke = ""; };
	/**
	*function to ask user to add data to swimming, called from wherever a new swim object is created
	*/
	void addData();
	/**
	* function to display the run information
	*/
	void display();
	/**
	*getDataForFile formats the data for the file, makeing sure to start with the enum
	*/
	string getDataForFile();
	/**
	* loadDataFromFile loads all the swim data from the file
	*/
	void loadDataFromFile(ifstream& file);
};
//class to represent a person object

