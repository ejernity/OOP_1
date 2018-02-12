#include <iostream>
#include <cstdlib>
#include "Passenger.h"

using namespace std;

// Constructor
Passenger::Passenger() : ticket(rand()%2 == 1), reducedTicket(rand()%2 == 1) {}