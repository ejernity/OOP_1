#ifndef _TRAIN_
#define _TRAIN_

#include "Lists.h"
#include "Waggon.h"

class Train
{
private:
	int numStations;
	int totalWaggons;
	int sumMoney;
	InfoWaggonList *list;
public:
	// Constructor
	Train(const int&, const int&);
	
	// Destructor
	~Train();

	// Operation function
	void operate();

	// Accessors
	int getTotalMoney() const { return sumMoney; }
	int getNoStations() const { return numStations; }
	int getNoWaggons() const { return totalWaggons; }
	InfoWaggonList* getList() const { return list; }

	// Mutator for total money
	void setTotalMoney();
	void printStatistics();
};

#endif