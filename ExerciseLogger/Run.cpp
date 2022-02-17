#include "Run.h"

string Run::calculateAvgPace()
{
	int fullSeconds = (timeMins * 60) + timeSeconds;

	int secondsPerKm = fullSeconds / distanceInKm;

	double minutesPerKm = secondsPerKm / 60;
	int leftOverSeconds = secondsPerKm % 60;

	return to_string(minutesPerKm) + "'" + to_string(leftOverSeconds) + "\"";
}

void Run::addData()
{ //get data from user input
	cout << "Type in distance" << endl;
	cin >> distanceInKm;
	cout << "Type in minutes" << endl;
	cin >> timeMins;
	cout << "Type in seconds" << endl;
	cin >> timeSeconds;
	cout << "Type in terrain type" << endl;
	cin.ignore(1000, '\n');
	cin.clear();
	getline(cin, terrain);
}

/**
* function to display the run information
*/
void Run::display()
{
	cout << "Run: Disance: " << distanceInKm << "Kms, Time " << timeMins << "mm:" << timeSeconds << "ss, Pace: " << calculateAvgPace() << " Terain: " << terrain << endl;
}
/**
*getDataForFile formats the data for the file, makeing sure to start with the enum
*/
string Run::getDataForFile()
{				//record is labelled with the enum
	return to_string(ExerciseType::RUN) + " " + to_string(distanceInKm) + " " + to_string(timeMins) + " " + to_string(timeSeconds) + " " + terrain;
}
/**
* loadDataFromFile reads the data from the text file.
*/
void Run::loadDataFromFile(ifstream& file)
{
	file >> distanceInKm; //get the distance from the file
	file >> timeMins; //get the minutes from the file
	file >> timeSeconds; //get the time in seconds from the file
	getline(file, terrain); //get the terrain (getline so it can have spaces)
}