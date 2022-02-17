#include "Person.h"

/**
* function to add exercises for a user
*/
void Person::addExercise()
{
	cout << "What type of exercise ?" << endl;
	cout << "1. Run " << endl;
	cout << "2. Weight Lifting" << endl;
	cout << "3. Hike" << endl;
	cout << "4. Swim" << endl;
	int userInput;
	cin >> userInput;
	if (userInput == 1)
	{
		cout << "Add info of most recent run" << endl;
		Run* run = new Run; //initiliase
		run->addData(); //add data
		exercises.push_back(run); //add to the vector
	}
	else if (userInput == 2)
	{
		cout << "Add info of most recent weightlifting" << endl;
		Weightlifting* wl = new Weightlifting; //initiliase
		wl->addData(); //add data
		exercises.push_back(wl); //add to the vector
	}
	else if (userInput == 3)
	{
		cout << "Add info of most recent Hike" << endl;
		Hike* hike = new Hike; //initiliase
		hike->addData(); //add data
		exercises.push_back(hike); //add to the vector
	}
	else if (userInput == 4)
	{
		cout << "Add info of most recent Swim" << endl;
		Swimming* swim = new Swimming; //initiliase
		swim->addData(); //add data
		exercises.push_back(swim); //add to the vector
	}

}
/**
*function to add data from the user to the person object
*/
void Person::addData()
{
	cout << "Type in persons name" << endl;
	cin.ignore(1000, '\n');
	cin.clear();
	getline(cin, name);
	cout << "Type in persons age" << endl;
	cin >> age;
	addExercise();
}
/**
* function to return the name of the person
*/
string Person::getName()
{
	return name;
}
/**
* function to return the age of the person
*/
int Person::getAge()
{
	return age;
}
/**
* function to return the exercises that the person has stored
*/
vector<Exercise*> Person::getExercises()
{
	return exercises;
}
/**
* function to print the ecercises to the console;
*/
void Person::printExercises()
{
	for (int i = 0; i < exercises.size(); i++)
	{
		cout << "Exercise " << (i + 1) << endl;
		exercises[i]->display();
	}
	cout << endl;
}
/**
* display function to show all user info
*/
void Person::display()
{
	cout << "Name: " << name << " Age: " << age << endl;
	cout << "Exercises: " << endl;
	printExercises();
}
/**
*edit function to edit the users info
*/
void Person::edit()
{
	cout << "Type in new name" << endl;
	cin.ignore(1000, '\n'); //clears the input buffer before using getline
	cin.clear();
	getline(cin, name);

	cout << "Type in new age" << endl;
	cin >> age;
}
/**
* loadDataFrom file, loads all the data from the file, and switched between exercise types
*/
void Person::loadDataFromFile(ifstream& file)
{
	getline(file, name); //get the name, allows for spaces
	file >> age; //get the age


	int exerciseCount;
	file >> exerciseCount; //get the number of exercises from the file
	file.ignore(1000, '\n');
	file.clear();
	for (int i = 0; i < exerciseCount; i++)
	{

		int exerciseType;
		file >> exerciseType;
		switch (exerciseType)
		{
		case ExerciseType::RUN:
		{
			Run* run = new Run;
			run->loadDataFromFile(file); //call the load data from file for run
			exercises.push_back(run); //add the run to the vector
			break;
		}
		case ExerciseType::WEIGHT_LIFTING:
		{
			Weightlifting* wl = new Weightlifting;
			wl->loadDataFromFile(file); //call the load data from file for run
			exercises.push_back(wl); //add the run to the vector
			break;
		}
		case ExerciseType::HIKE:
		{
			Hike* hike = new Hike;
			hike->loadDataFromFile(file); //call the load data from file for run
			exercises.push_back(hike); //add the run to the vector
			break;
		}
		case ExerciseType::SWIMMING:
		{
			Swimming* swim = new Swimming;
			swim->loadDataFromFile(file); //call the load data from file for run
			exercises.push_back(swim); //add the run to the vector
			break;
		}

		default:
			break;
		}
		//assume there will always be one run

	}
}