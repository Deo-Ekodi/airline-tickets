#include "flight.hpp"
#include "passenger.hpp"
#include "ticket.hpp"

int main()
{
    const char* flight_name = "B747";
    const char* passenger_name = "Deo";
    int seat = 2;
    int capacity = 220;
    // int* cap = &capacity;
    flight fl(flight_name, capacity);

    passenger passx(passenger_name, seat);
    fl.reserveTicket(&passx);
    // fl.displayPassengers();
    return 0;
}
