#include <iostream>
#include "Train.h"
#include "Waggon.h"

// Constructor
Train::Train(const int& numWaggons, const int& stationsNo) : totalWaggons(numWaggons), numStations(stationsNo), sumMoney(0)
{
	int maxCapacity;
	cout << "Enter the max capacity for waggons: ";
	cin >> maxCapacity;
	cout << endl;
	list = new InfoWaggonList(maxCapacity,numWaggons);
	cout << "A metro train with " << totalWaggons << " waggons, was created\n" << endl;
}

// Destructor
Train::~Train()
{
	delete list;
	cout << "A metro train was destroyed" << endl;
}

// Operation
void Train::operate()
{
	for (int i = 0; i < getNoStations(); i++)
	{
		if (i == getNoStations() - 1)		// flag : when we reach last station
			i = -1;
		for (int j = 0; j < getNoWaggons(); j++)
		{
			if (i == -1)
				cout << "Waggon: " << j+1 << endl;
			if (j == 0)
			{
				this->getList()->getFirstWaggonNode()->getMyWaggon()->inStation(i);
				this->getList()->setAuxWaggonNode(this->getList()->getFirstWaggonNode()->getNextWaggonNode());
			} else if (j == getNoWaggons() - 1)
			{
				this->getList()->getLastWaggonNode()->getMyWaggon()->inStation(i);
			} else
			{
				this->getList()->getAuxWaggonNode()->getMyWaggon()->inStation(i);
				this->getList()->setAuxWaggonNode(this->getList()->getAuxWaggonNode()->getNextWaggonNode());
			}
		}
		if (i == -1)
			break;
	}
}

void Train::setTotalMoney()
		{
	this->getList()->setAuxWaggonNode(this->getList()->getFirstWaggonNode());
	for (int i = 0; i < this->totalWaggons; i++)
	{
		this->sumMoney += this->getList()->getAuxWaggonNode()->getMyWaggon()->getSumMoney();
		this->getList()->setAuxWaggonNode(this->getList()->getAuxWaggonNode()->getNextWaggonNode());
	}
}

void Train::printStatistics()
{
	cout << "Money from all waggons: " << this->getTotalMoney() << endl;
}
