#pragma once
#include "Person.h"
const string FILENAME = "exercise_logger.txt";
/**
* Menu class, controls the program running, holds a vector of persons
*/
class Menu
{
private:
	vector<Person> persons; //vector to hold all the persons // composition (sort of)
	bool keepMenuGoing = true;
	/**
	* function to print person record
	*/
	void printPersonVector();
	/**
	* function to add a new person
	*/
	void addNewPerson();

	/**
	* function to add a new run for a user, called from the main menu
	*/
	void addNewExercise();

	/**
	* function to show person, called from the main menu
	*/
	void showPerson();
	/**
	* function to edit person, called from the main menu
	*/
	void editPerson();
	/**
	* function for writing all the info to a file
	*/
	void writeToFile();
	/**
	* function for loading all the info from a file
	*/
	void loadFromFile();

	void saveAndQuit();

public:
	/**
	*function to display the start menu
	*/
	void start();
};

