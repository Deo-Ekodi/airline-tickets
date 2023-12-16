#pragma once
#include <iostream>
#include <string>



class ticket
{

private:
    int* price;
    static int ticketCount;
    const char* passengerName;
    int* seatNumber;
    bool reserved;

    friend class passenger;
    friend class flight;

public:

    ticket(/* args */)
    {
        ticketCount = 0;
        price = 0;
        reserved = false;
        passengerName = nullptr;
        seatNumber = 0;
    }
    ticket(const char*& name, int* seat)
    {
        passengerName = name;
        seatNumber = seat;
        reserved = true;
        ticketCount++;
    }
    int* seatNumber() const
    {
        return seatNumber;
    }
    const char* pssengerName() const
    {
        return passengerName;
    }
    int* cost() const
    {
        return price;
    }
    bool isReserved() const
    {
        return reserved;
    }

    ~ticket()
    {
        delete passengerName;
        delete seatNumber;

        passengerName = nullptr;
        seatNumber = nullptr;
    }
};
