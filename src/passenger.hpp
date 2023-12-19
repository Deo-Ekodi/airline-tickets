#pragma once

#include "ticket.hpp"

class passenger
{
private:
    // const char* passenger_name;
    ticket* passenger_ticket;

    // ctrl linked list
    passenger* prev;
    passenger* next;

    friend class flight;
public:
    passenger(/* args */)
    {
        passenger_ticket = nullptr;
        prev = next = nullptr;
    }
    passenger(const char* name, int seat)
    {
        passenger_ticket->seatNumber = seat;
        passenger_ticket->passengerName = name;
        passenger_ticket->reserved = true;
        prev = next = nullptr;
    }
    const int seatNumber() const
    {
        return this->passenger_ticket->seatNumber;
    }
    const char *pasengerName() const
    {
        return this->passenger_ticket->passengerName;
    }
    int *cost() const
    {
        return this->passenger_ticket->price;
    }
    bool isReserved() const
    {
        return this->passenger_ticket->reserved;
    }

    // ~passenger()
    // {
    //     delete passenger_ticket;
    //     passenger_ticket = nullptr;
    // }

    friend bool ticketStatus(passenger*);
    friend int ticketCost(passenger*);
};

bool ticketStatus(passenger *pass)
{
    return pass->isReserved();
}

int ticketCost(passenger *pass)
{
    // cost() returns int*
    return *(pass->cost());
}
