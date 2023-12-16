#include "passenger.hpp"

bool ticketStatus(passenger* pass)
{
    return pass->passenger_ticket->isReserved();
}

int ticketCost(passenger* pass)
{
    // cost() returns int*
    return *(pass->passenger_ticket->cost());
}
