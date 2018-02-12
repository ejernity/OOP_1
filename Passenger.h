#ifndef _PASSENGER_
#define _PASSENGER_

#include <iostream>
#include <cstdlib>

using namespace std;

class Passenger
{
private:
	bool ticket;
	bool reducedTicket;
public:
	// Constructor (Initializator for new passenger)
	Passenger();
	
	// Accessors
	inline bool getTicket() const { return ticket; }
	inline bool getIsReduced() const { return reducedTicket; }
};

#endif