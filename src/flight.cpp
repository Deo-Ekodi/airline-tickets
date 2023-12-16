#include "flight.hpp"
#include <cassert>

flight *flight::create(char* name, int *capacity)
{
    flight* _flight = new flight;
    _flight->airline = name;
    _flight->flightCapacity = capacity;

    if(_flight->flightCapacity <= 0)
    {
        throw(std::cerr, "cannot process 0 passengers!");
        return;
    }

    _flight->first = nullptr;
    _flight->last = nullptr;

    return _flight;
}

// bool flight::flightStatus()
// {
//     return;
// }



void flight::cancelReservation(passenger* pass)
{
    assert(pass!= nullptr);

    passenger* temp;
    passenger* curr;
    curr = first;

    if(first->prev->seatNumber == pass->prev->seatNumber)
    {
        temp->prev = first->next;
        delete first->prev;
        
        first->prev = temp->prev;
        delete temp;
    }
    else
    {
        for (size_t i = 0; first->next != nullptr; i++)
        {
            // algo for deleting ith element from LL
            
        }
    }
}

void flight::reserveTicket(passenger *pass)
{
    if(first == nullptr)
    {
        first = pass;
        return;
    }

    // check insertion algorithms!
}

std::ostream &displayPassengers(std::ostream &os, flight &fl)
{
}