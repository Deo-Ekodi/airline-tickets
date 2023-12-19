#pragma once
#include <iostream>
#include <string>


class ticket
{

private:
    int* price;
    static int ticketCount;
    const char* passengerName;
    int seatNumber = 0;
    bool reserved = false;

    friend class passenger;
    friend class flight;

public:

    ticket(/* args */)
    {
        ticketCount = 0;
        price = 0;
        reserved = false;
        passengerName = nullptr;
    }
    // ticket(const char*& name, int* seat)
    // {
    //     passengerName = name;
    //     seatNumber = seat;
    //     reserved = true;
    //     ticketCount++;
    // }
    ~ticket()
    {
        passengerName = nullptr;
        // seatNumber = nullptr;
    }
};
