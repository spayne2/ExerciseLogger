#pragma once
#include "Run.h"
#include "WeightLifting.h"
#include "Swimming.h"
#include "Hike.h"
#include "Yoga.h"
class Person
{
private:
	string name; //store the name
	int age; //store the age
	vector<Exercise*> exercises; //store a list of exercises; //composition
public:
	/***
	*Person default constructor
	*/
	Person() { age = 0; }
	/**
	* function to add exercises for a user
	*/
	void addExercise();	
	/**
	*function to add data from the user to the person object
	*/
	void addData();
	
	/**
	* function to return the name of the person
	*/
	string getName();
	/**
	* function to return the age of the person
	*/
	int getAge();
	
	/**
	* function to return the exercises that the person has stored
	*/
	vector<Exercise*> getExercises();
	
	/**
	* function to print the ecercises to the console;
	*/
	void printExercises();
	
	/**
	* display function to show all user info
	*/
	void display();

	/**
	*edit function to edit the users info
	*/
	void edit();
	
	/**
	* loadDataFrom file, loads all the data from the file, and switched between exercise types
	*/
	void loadDataFromFile(ifstream& file);
	
};

