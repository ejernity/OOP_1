#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Train.h"
#include "Waggon.h"
#include "Passenger.h"
#include "Lists.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Please give 2 arguments" << endl;
		return 1;
	}
	if (atoi(argv[1]) < 3)
	{
		cout << "Please enter valid number of stations (>= 3)" << endl;
		return 2;
	}
	srand(time(NULL));	// Seed...
	cout << "Number of stations: " << argv[1] << endl;
	cout << "Number of waggons: " << argv[2] << endl;
	Train *train = new Train(atoi(argv[2]),atoi(argv[1]));
	train->operate();
	train->setTotalMoney();
	cout << "******************" << endl;
	train->printStatistics();
	cout << "******************" << endl;
	delete train;
	return 0;
}