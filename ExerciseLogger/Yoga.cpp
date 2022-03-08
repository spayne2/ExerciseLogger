#include "Yoga.h"

void Yoga::addData()
{
	cout << "Type in time in mins" << endl;
	cin >> timeInMins;
	cout << "Type in time in seconds" << endl;
	cin >> timeInSeconds;
	cout << "Type in complexity" << endl;
	cin.ignore(1000, '\n');
	cin.clear();
	getline(cin, complexity);
}
string Yoga::getDataForFile()
{				//record is labelled with the enum
	return to_string(ExerciseType::YOGA) + " " + to_string(timeInMins) + " " + to_string(timeInSeconds) + " " + complexity;
}

void Yoga::display()
{
	cout << "Yoga session: " << "Time was " << timeInMins << "mins & " << timeInSeconds << "seconds. The complexity was: " << complexity << endl;
}

void Yoga::loadDataFromFile(ifstream& file)
{
	file >> timeInMins; //get the distance from the file
	file >> timeInSeconds; //get the minutes from the file
	getline(file, complexity); //get the terrain (getline so it can have spaces)
}
