#include "Swimming.h"
int Swimming::calcTotalDistance()
{
	return length * laps;
}

/**
	*function to ask user to add data to weightlifting, called from wherever a new run object is created
	*/
void Swimming::addData()
{ //get data from user input
	cout << "Type in length" << endl;
	cin >> length;
	cout << "Type in laps" << endl;
	cin >> laps;
	cout << "Type in stroke type" << endl;
	cin.ignore(1000, '\n');
	cin.clear();
	getline(cin, stroke);
}
/**
* function to display the run information
*/
void Swimming::display()
{
	cout << "Swimming: Length: " << length << " meters, Laps: " << laps << " Stroke: " << stroke << " Total Distance: " << calcTotalDistance() << " meters" << endl;
}
/**
*getDataForFile formats the data for the file, makeing sure to start with the enum
*/
string Swimming::getDataForFile()
{				//record is labelled with the enum
	return to_string(ExerciseType::SWIMMING) + " " + to_string(length) + " " + to_string(laps) + " " + stroke;
}
/**
* loadDataFromFile loads all the swim data from the file
*/
void Swimming::loadDataFromFile(ifstream& file)
{
	file >> length; //get the distance from the file
	file >> laps; //get the minutes from the file
	getline(file, stroke); //get the terrain (getline so it can have spaces)
}