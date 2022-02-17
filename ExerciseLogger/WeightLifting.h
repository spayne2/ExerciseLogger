#pragma once
#include "Exercise.h"

class Weightlifting : public Exercise
{
private:
	int weight; //weights being lifted
	int reps; //reps per set
	int sets; //number of sets
	string type; //type of exericse

	/**
	* caclulateTotaWeight returns the total amount of weight that has been exercised with
	*/
	float calculateTotalWeight();
public:
	/**
	* Default constructor for weightlifting
	*/
	Weightlifting() { weight = 0; reps = 0; sets = 0; type = ""; }; //default constructor
	/**
	*function to ask user to add data to weightlifting, called from wherever a new run object is created
	*/
	void addData();
	/**
	* function to display the weight lifting information
	*/
	void display();
	/**
	*getDataForFile formats the data for the file, makeing sure to start with the enum
	*/
	string getDataForFile();
	/**
	* Loads all the weightlifting data from the file
	*/
	void loadDataFromFile(ifstream& file);
};

