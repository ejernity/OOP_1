#include <iostream>
#include <cstdlib>
#include "Lists.h"

using namespace std;

// Function memebers (methods) for class "InfoWaggonList"

// Constructor
InfoWaggonList::InfoWaggonList(const int& maxCapacity,const int& numberOfWaggons)
{
	firstWaggon = new waggonNode(maxCapacity);
	auxWaggon = firstWaggon;
	lastWaggon = firstWaggon;
	for (int j = 1; j < numberOfWaggons; j++)
	{
		lastWaggon = new waggonNode(maxCapacity);
		auxWaggon->setNextWaggonNode(lastWaggon);
		auxWaggon = lastWaggon;
	}
}

// Destructor
InfoWaggonList::~InfoWaggonList()
{
	while (firstWaggon->getNextWaggonNode() != NULL)
	{
		auxWaggon = firstWaggon->getNextWaggonNode();
		delete firstWaggon;
		firstWaggon = auxWaggon;
	};
	delete firstWaggon;		// to delete the last waggon
}

// Function memebers (methods) for class "waggonNode"

// Constructor
waggonNode::waggonNode(const int& maxCapacity) : nextWaggonNode(NULL)
{
	this->myWaggon = new Waggon(maxCapacity);
}

// Destructor
waggonNode::~waggonNode() { delete myWaggon; }

// Mutators
void waggonNode::setNextWaggonNode(waggonNode *tempWaggonPtr)
{
	this->nextWaggonNode = tempWaggonPtr;
}


// Function memebers (methods) for class "passengerNode"

// Constructor
passengerNode::passengerNode() : nextPassengerNode(NULL), prevPassengerNode(NULL)
{
	this->myPassenger = new Passenger();
}

// Destructor
passengerNode::~passengerNode()
{
	delete myPassenger;
}

// Mutators
void passengerNode::setNextPassengerNode(passengerNode *tempPassengerPtr)
{
	this->nextPassengerNode = tempPassengerPtr;
}

void passengerNode::setPrevPassengerNode(passengerNode *tempPassengerPtr)
{
	this->prevPassengerNode = tempPassengerPtr;
}