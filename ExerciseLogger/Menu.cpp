#include "Menu.h"
/**
* function to print person record
*/
void Menu::printPersonVector()
{
	for (int i = 0; i < persons.size(); i++)
	{
		cout << (i + 1) << " " << persons[i].getName() << endl;
	}
}
/**
* function to add a new person
*/
void Menu::addNewPerson()
{
	Person person; //initialize a person object
	person.addData(); //call the add data function;
	persons.push_back(person); // add to the vector stored in the menu object
}

/**
* function to add a new run for a user, called from the main menu
*/
void Menu::addNewExercise()
{
	cout << "Add exercise for which person?" << endl;

	printPersonVector();

	int input;
	cin >> input;

	persons[input - 1].addExercise();
}

/**
* function to show person, called from the main menu
*/
void Menu::showPerson() {
	cout << "Display which person" << endl;

	printPersonVector();

	int input;
	cin >> input;

	persons[input - 1].display();
}
/**
* function to edit person, called from the main menu
*/
void Menu::editPerson() {
	cout << "Edit which person" << endl;

	printPersonVector();

	int input;
	cin >> input;

	persons[input - 1].edit();
}
/**
* function for writing all the info to a file
*/
void Menu::writeToFile()
{
	ofstream outPutFile; //create output file objec
	outPutFile.open(FILENAME); //open the file wanted
	outPutFile << persons.size() << endl; //write the number of people to the file
	for (int i = 0; i < persons.size(); i++) //loop over all the person records
	{
		outPutFile << persons[i].getName() << endl; //send the name to the file 
		outPutFile << persons[i].getAge() << endl; //send the age to the file
		outPutFile << persons[i].getExercises().size() << endl; //write the number of exercises to the file
		for (auto exercise : persons[i].getExercises()) //send all the runs to the file
		{
			outPutFile << exercise->getDataForFile() << endl;;
		}
	}
}
/**
* function for loading all the info from a file
*/
void Menu::loadFromFile()
{
	ifstream inputFile;
	inputFile.open(FILENAME); //open  file needed
	if (inputFile)
	{
		int personCount = 0;
		inputFile >> personCount; //get the number of people from the file
		inputFile.ignore(1000, '\n');
		inputFile.clear();
		for (int i = 0; i < personCount; i++)
		{
			Person person; //create a person object
			person.loadDataFromFile(inputFile);  //load data from file
			persons.push_back(person); //add the person to the vector
		}
	}
}

void Menu::saveAndQuit()
{
	writeToFile();
	keepMenuGoing = false;
	cout << "Goodbye" << endl;
}

void Menu::start()
{
	loadFromFile();

	while (keepMenuGoing)
	{
		cout << "Welcome to the Exercise logger, please choose an option" << endl;
		cout << "1. Add a new person" << endl;
		cout << "2. Add a new Exercise" << endl;
		cout << "3. Show Person" << endl;
		cout << "4. Edit Person" << endl;
		cout << "5. Write to File" << endl;
		cout << "6. Load from file" << endl;
		cout << "7. Save & Quit" << endl;

		int input;
		cin >> input;

		switch (input)
		{
		case 1:
			addNewPerson();
			break;
		case 2:
			addNewExercise();
			break;
		case 3:
			showPerson();
			break;
		case 4:
			editPerson();
			break;
		case 5:
			writeToFile();
			break;
		case 6:
			loadFromFile();
			break;
		case 7:
			saveAndQuit();
			break;
		}
	}
}