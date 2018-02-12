#ifndef _LISTS_
#define _LISTS_

#include "Passenger.h"
#include "Waggon.h"

class passengerNode
{
private:
	Passenger *myPassenger;
	passengerNode *nextPassengerNode;
	passengerNode *prevPassengerNode;
public:
	// Constructor
	passengerNode();

	// Destructor
	~passengerNode();

	// Accessors
	inline Passenger* getMyPassenger() const { return this->myPassenger; }
	inline passengerNode* getNextPassengerNode() const { return this->nextPassengerNode; }
	inline passengerNode* getPrevPassengerNode() const { return this->prevPassengerNode; }

	// Mutators
	void setNextPassengerNode(passengerNode *);
	void setPrevPassengerNode(passengerNode *);
};

class Waggon;

class waggonNode
{
private:
	Waggon *myWaggon;
	waggonNode *nextWaggonNode;
public:
	// Constructor
	waggonNode(const int&);

	// Destructor
	~waggonNode();

	// Accessors
	inline waggonNode* getNextWaggonNode() const { return this->nextWaggonNode; }
	inline Waggon* getMyWaggon() const { return this->myWaggon; }

	// Mutators
	void setNextWaggonNode(waggonNode *);
};

class InfoWaggonList
{
private:
	waggonNode *firstWaggon;
	waggonNode *auxWaggon;
	waggonNode *lastWaggon;
public:
	//Constructor
	InfoWaggonList(const int&, const int&);

	//Destructor
	~InfoWaggonList();

	// Accessors
	waggonNode* getFirstWaggonNode() const { return firstWaggon; }
	waggonNode* getAuxWaggonNode() const { return auxWaggon; }
	waggonNode* getLastWaggonNode() const { return lastWaggon; }

	// Mutators
	void setAuxWaggonNode(waggonNode *temp) { auxWaggon = temp; }
};

#endif