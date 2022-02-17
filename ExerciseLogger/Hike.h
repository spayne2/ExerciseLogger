#pragma once
#include "Run.h"

class Hike :public Run
{
public:
	/**
	*Default constructor for Hike
	*/
	Hike() :Run() {};
	/**
	*getDataForFile formats the data for the file, makeing sure to start with the enum
	*/
	string getDataForFile();

	/**
	* function to display the run information
	*/
	void display();

};

