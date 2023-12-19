#pragma once
// #include <vector>   // store flights in this container, store passengers in this container 
// std::vector has some downside..prefer linkedList.
#include <cassert>
#include "passenger.hpp"

class flight
{
private:
    const char* airline;
    int* flightCapacity;
    // std::vector<passenger> vec;
    passenger* head;
    passenger* tail;

public:
    flight(/* args */)
    {
        airline = nullptr;
        flightCapacity = 0;
        // head = tail = nullptr;
        head->next = tail;
        tail->prev = head;
        tail->next = nullptr;
    }
    flight(const char* name, int capacity)
    {
        this->flightCapacity = &capacity;
        this->airline = name;
        // head = tail = nullptr;
        head->next = tail;
        tail->prev = head;
        tail->next = nullptr;
    }
    // ~flight()
    // {
    //     delete airline;
    //     delete flightCapacity;

    //     tail = head = nullptr;
    //     flightCapacity = nullptr;
    //     airline = nullptr;
    // }


    // bool flightStatus();
    void cancelReservation(passenger *);
    // friend void cancelReservation(ticket*);
    void reserveTicket(passenger*);
    void displayPassengers();
};

void flight::cancelReservation(passenger *pass)
{
    assert(pass != nullptr);

    // iterators be trailing and head pointer.
    passenger *p = nullptr;
    passenger *q = nullptr;

    // delete from head
    if ((pass->passenger_ticket->seatNumber) == (head->passenger_ticket->seatNumber))
    {
        p = head;
        head = p->next;
        p->next = nullptr;
        delete p;
        return;
    }

    p = head;
    for (size_t i = 0; (p->passenger_ticket->seatNumber) != (pass->passenger_ticket->seatNumber); i++)
    {
        q = p;
        p = p->next;
    }

    // check if out of bounds!
    if (!p)
        return;
    q->next = p->next;
    delete p;
    p = nullptr;
}

void flight::reserveTicket(passenger *pass)
{
    // check insertion algorithms!
    passenger *p = head;
    passenger *temp = new passenger;
    // temp = pass;
    // temp->passenger_ticket->seatNumber = pass->passenger_ticket->seatNumber;
    // temp->passenger_ticket->passengerName = pass->passenger_ticket->passengerName;
    // temp->passenger_ticket->reserved = true;
    // temp->passenger_ticket->ticketCount++;


    while (((temp->passenger_ticket->seatNumber) < (p->passenger_ticket->seatNumber)) && ((temp->passenger_ticket->seatNumber) != (p->passenger_ticket->seatNumber)))
    {
        p = p->next;
    }
    temp->next = p->next;
    p->next = temp;

    delete temp;
    temp = nullptr;
}

void flight::displayPassengers()
{
    passenger *p = head;
    do
    {
        std::cout << (p->passenger_ticket->seatNumber) << " " << *(p->passenger_ticket->passengerName) << std::endl;
        p = p->next;
    } while (!(p != tail));
}