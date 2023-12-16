#pragma once

#include "ticket.hpp"

class passenger
{
private:
    const char* passenger_name;
    ticket* passenger_ticket;

    // ctrl linked list
    ticket* prev;
    ticket* next;

    friend class flight;
public:
    passenger(/* args */)
    {
        passenger_name = nullptr;
        passenger_ticket = nullptr;
    }
    passenger(const char* name)
    {
        passenger_name = name;
        passenger_ticket->reserved = true;
    }
    ~passenger()
    {
        delete passenger_name;
        delete passenger_ticket;

        passenger_name = nullptr;
        passenger_ticket = nullptr;
    }

    friend bool ticketStatus(passenger*);
    friend int ticketCost(passenger*);
    friend void del(passenger*);
};
