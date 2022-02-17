#pragma once
#include "Exercise.h"
/**
*Run class to represent a run object.
*/
class Run : public Exercise
{
protected:
	double distanceInKm; //overall distnace of the run
	int timeMins; // time in minutes 
	int timeSeconds; //time in seconds
	string terrain; //the terrain type of the run e.g. road, track, trail
	/**
	* function to caclculate the average pace of the run, to be called when the runs are displayed
	*/
	string calculateAvgPace();
	
public:
	/**
	*Run default constructor
	*/
	Run() { distanceInKm = 0; timeMins = 0; timeSeconds = 0; terrain = ""; }
	/**
	*function to ask user to add data to run, called from wherever a new run object is created
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
	* loadDataFromFile reads the data from the text file.
	*/
	void loadDataFromFile(ifstream& file);
	
};

