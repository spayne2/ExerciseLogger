#include "WeightLifting.h"
/**
*Function to calculate the total weight for the set.
*/
int Weightlifting::calculateTotalWeight() //cumalative total weight
{
	return weight * (reps * sets);
}
/**
*function to ask user to add data to weightlifting, called from wherever a new weightlifting object is created
*/
void Weightlifting::addData()
{
	cout << "Type in weight in KG's" << endl;
	cin >> weight;
	cout << "Type in reps" << endl;
	cin >> reps;
	cout << "Type in sets" << endl;
	cin >> sets;
	cout << "Type in type" << endl;
	cin.ignore(1000, '\n');
	cin.clear();
	getline(cin, type);
}
/**
* function to display the weight lifting information
*/
void Weightlifting::display()
{
	cout << "WeightLifting: Weight: " << weight << " KG's reps: " << reps << " sets:" << sets << " Total Weight: " << calculateTotalWeight() << "KG's Type: " << type << endl;
}
/**
*getDataForFile formats the data for the file, makeing sure to start with the enum
*/
string Weightlifting::getDataForFile()
{					//record is labelled with the enum
	return to_string(ExerciseType::WEIGHT_LIFTING) + " " + to_string(weight) + " " + to_string(reps) + " " + to_string(sets) + " " + type;
}
/**
* Loads all the weightlifting data from the file
*/
void Weightlifting::loadDataFromFile(ifstream& file)
{
	file >> weight; //get the weight from the file
	file >> reps; //get the reps from the file
	file >> sets; //get the sets from the file
	getline(file, type); //get the type
}