#include <iostream>
#include "Waggon.h"

using namespace std;

// Constructor
Waggon::Waggon(const int& capacity) : maxCapacity(capacity), offenders(0), offendersNoChecked(0), sumMoney(0), currentCapacity(0), updatedCapacity(0), passengerList(NULL), auxPassengerListPtr(NULL), lastPassenger(NULL)
{
	cout << "A waggon with capacity for " 
		 << this->getMaxCapacity() 
		 << " passengers, was created" 
		 << endl;
}

// Destructor
Waggon::~Waggon()
{ cout << "A waggon was destroyed" << endl; }

// Print statistics
void Waggon::printStatistics()
{
	cout << "Total money from this waggon: " << this->getSumMoney() << endl;
	cout << "Offenders checked: " << this->getOffenders() << endl;
	cout << "Offenders non checked : " << this->getOffendersNoChecked() << endl;
}

// Capacity update
void Waggon::setUpdatedCapacity(int plus = 1)
{
	if (plus == 1)
	{ updatedCapacity++; } else	{ updatedCapacity--; }
}

// IsEmpty
bool Waggon::isEmpty()
{
	return (this->getUpdatedCapacity() == 0);
}

// IsFull
bool Waggon::isFull()
{
	return (this->getUpdatedCapacity() == this->getMaxCapacity());
}

// Implementation of member-function inStation
int Waggon::inStation(const int& lastStation)
{
	if (lastStation == -1)
	{
		this->printStatistics();
		while (this->getUpdatedCapacity() != 0)
			this->deletePassenger(auxPassengerListPtr);
		return 1;
	}
	if (lastStation != 0)	// An eimai sthn afethria mhn vgaleis epivates
	{
		// Apovivasi
		this->setRandomPassQuit();
		for (int j = 0; j < getRandomPassQuit(); j++)
			this->deletePassenger(auxPassengerListPtr);
	}
	// Epivivasi
	if (lastStation != -1)		// sthn teleftaia stash den tha yparxei epivivasi
	{
		this->setCurrentCapacity();
		for (int i = 0; i < getCurrentCapacity(); i++)
		{
			passengerNode *newPassenger = new passengerNode();
			this->insertPassenger(newPassenger);
		}
	}
	if (lastStation != -1)
	{
		if (rand()%2 == 1)
		{
			this->betweenStations();
			this->setAuxPassengerList(this->getPassengerList());
		} else
		{
			for (int m = 0; m < this->getUpdatedCapacity(); m++)
			{
				if (!this->getAuxPassengerList()->getMyPassenger()->getTicket())
					this->setOffendersNoChecked();
				this->setAuxPassengerList(this->getAuxPassengerList()->getNextPassengerNode());
			}
			this->setAuxPassengerList(this->getPassengerList());
		}
	}
}

// Implementation of member-function betweenStation
void Waggon::betweenStations()
{
	int last_passenger = getUpdatedCapacity();
	for (int current_passenger = 0; current_passenger < last_passenger; current_passenger++)	// for every passenger in this waggon
	{
		if (!this->getAuxPassengerList()->getMyPassenger()->getTicket())		// if a passenger doesn't have ticket
		{
			this->setOffenders();		// he will be checked and pay so : offenders++
			if (this->getAuxPassengerList()->getMyPassenger()->getIsReduced())	// how much he/she will pay
			{ this->setSumMoneyReduced(); } else { this->setSumMoneyNonReduced(); }
			this->deletePassenger(auxPassengerListPtr);
		} else { this->setAuxPassengerList(this->getAuxPassengerList()->getNextPassengerNode()); }
	}
}

// Insert a passenger to the passenger list
int Waggon::insertPassenger(passengerNode *currentPassengerNode)
{
	if (this->isFull())		// waggon full
	{return -1;}
	else if (this->isEmpty())		// waggon empty
	{
		// make current be the first passenger to go inside this waggon
		this->setPassengerList(currentPassengerNode);
		// also "this is the last passenger" initialization is to point to the first passenger
		this->setLastPassenger(currentPassengerNode);
		// same as last passenger pointer (initialize)
		this->setAuxPassengerList(currentPassengerNode);
		this->setUpdatedCapacity();
		return 1;
	} else			// insert a passenger to the waggon (last position of the list)
	{
		// make last passenger has as next the new (current) passenger of the list
		this->getLastPassenger()->setNextPassengerNode(currentPassengerNode);
		// make new passenger has as previous passenger the last passenger
		currentPassengerNode->setPrevPassengerNode(this->getLastPassenger());
		// make new passenger be the last one of the list
		this->setLastPassenger(currentPassengerNode);
		// next of new passenger is already points to NULL cause of constructor's initialization list (passengerNode)
		this->setUpdatedCapacity();
		return 0;
	}
}

// Delete a passenger from the passenger list
int Waggon::deletePassenger(passengerNode *auxPassengerNode)
{
	passengerNode *currentPassengerNode = auxPassengerNode;
	if (this->isEmpty())		// Empty waggon (nothing to delete)
	{ return -1; }
	else
	{
		if (currentPassengerNode->getNextPassengerNode() == NULL && currentPassengerNode->getPrevPassengerNode() == NULL)
		{
			setPassengerList(NULL);
			setAuxPassengerList(NULL);
			setLastPassenger(NULL);
		} else if (currentPassengerNode->getNextPassengerNode() == NULL)		// last passenger of the list
		{
			currentPassengerNode->getPrevPassengerNode()->setNextPassengerNode(NULL);
			setLastPassenger(currentPassengerNode->getPrevPassengerNode());
		} else if (currentPassengerNode->getPrevPassengerNode() == NULL)	// first passenger of the list
		{
			currentPassengerNode->getNextPassengerNode()->setPrevPassengerNode(NULL);		// as first passenger he has not passenger before him in the list
			setPassengerList(currentPassengerNode->getNextPassengerNode());
			setAuxPassengerList(currentPassengerNode->getNextPassengerNode());
		} else
		{
			currentPassengerNode->getPrevPassengerNode()->setNextPassengerNode(currentPassengerNode->getNextPassengerNode());
			currentPassengerNode->getNextPassengerNode()->setPrevPassengerNode(currentPassengerNode->getPrevPassengerNode());
			setAuxPassengerList(currentPassengerNode->getNextPassengerNode());
		}
		delete currentPassengerNode;		// delete passenger's node
		this->setUpdatedCapacity(0);
		return 0;
	}
}