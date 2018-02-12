#ifndef _WAGGONS_
#define _WAGGONS_

#include <iostream>
#include <cstdlib>
#include "Lists.h"
#include "Passenger.h"

using namespace std;

class passengerNode;

class Waggon
{
private:
	int maxCapacity;
	int updatedCapacity;
	int currentCapacity;
	int randomPassQuit;
	int sumMoney;
	int offendersNoChecked;
	int offenders;
	// list of passengers
	passengerNode *passengerList;
	passengerNode *auxPassengerListPtr;
	passengerNode *lastPassenger;
public:
	// Constructor
	Waggon(const int&);

	// Destructor
	~Waggon();

	// Accessors
	int getMaxCapacity() const { return maxCapacity; }
	int getCurrentCapacity() const { return currentCapacity; }
	int getUpdatedCapacity() const { return updatedCapacity; }
	int getRandomPassQuit() const { return randomPassQuit; }
	int getSumMoney() const { return sumMoney; }
	int getOffendersNoChecked() const { return offendersNoChecked; }
	int getOffenders() const { return offenders; }
	bool isEmpty();
	bool isFull();
	passengerNode* getPassengerList() const { return passengerList; }
	passengerNode* getAuxPassengerList() const { return auxPassengerListPtr; }
	passengerNode* getLastPassenger() const { return lastPassenger; }

	// Mutators
	void setCurrentCapacity() { currentCapacity = rand()%(maxCapacity+1-updatedCapacity); }
	void setUpdatedCapacity(int);
	void setRandomPassQuit() { randomPassQuit = rand()%(updatedCapacity+1); }
	void setOffendersNoChecked() { offendersNoChecked++; }
	void setOffenders() { offenders++; }
	void setSumMoneyReduced() { sumMoney += 30; }
	void setSumMoneyNonReduced() { sumMoney += 60; }
	void setPassengerList(passengerNode *firstPassenger) { this->passengerList = firstPassenger; }
	void setAuxPassengerList(passengerNode *passenger) { this->auxPassengerListPtr = passenger; }
	void setLastPassenger(passengerNode *lastPassenger) { this->lastPassenger = lastPassenger; }

	// other functions for waggon
	int inStation(const int&);
	void betweenStations();
	int insertPassenger(passengerNode *);
	int deletePassenger(passengerNode *);
	void printStatistics();
};


#endif