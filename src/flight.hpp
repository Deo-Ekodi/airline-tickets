#pragma once
// #include <vector>   // store flights in this container, store passengers in this container 
// std::vector has some downside..prefer linkedList.
#include "passenger.hpp"

class flight
{
private:
    const char* airline;
    int* flightCapacity;
    // std::vector<passenger> vec;
    passenger* first;
    passenger* last;

public:
    flight(/* args */)
    {
        airline = nullptr;
        flightCapacity = 0;
        first = last = nullptr;
    }
    flight(char* name, int capacity)
    {
        this->flightCapacity = &capacity;
        this->airline = name;
        first = last = nullptr;
    }
    ~flight()
    {
        delete airline;
        delete flightCapacity;

        last = first = nullptr;
        flightCapacity = nullptr;
        airline = nullptr;
    }


    bool flightStatus();
    flight *create(char *, int *);
    void cancelReservation(passenger *);
    // friend void cancelReservation(ticket*);
    void reserveTicket(passenger*);
    friend std::ostream& displayPassengers(std::ostream&, flight&);
};
