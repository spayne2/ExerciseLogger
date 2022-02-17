#include "Hike.h"
string Hike::getDataForFile()
{				//record is labelled with the enum
	return to_string(ExerciseType::HIKE) + " " + to_string(distanceInKm) + " " + to_string(timeMins) + " " + to_string(timeSeconds) + " " + terrain;
}

/**
* function to display the run information
*/
void Hike::display()
{
	cout << "Hike: Disance: " << distanceInKm << "Kms, Time " << timeMins << "mm:" << timeSeconds << "ss, Pace: " << calculateAvgPace() << " Terain: " << terrain << endl;
}