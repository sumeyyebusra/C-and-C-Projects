#include "airlines.cpp"
int main() {
    
    Airline airline(100,500,100,15000);
    
    Passenger passenger("Sumeyye Busra Sirim",5874596,0000,2);

    Flight flight1 = airline.addFlight("London","Istanbul",50,1000,5);
    Flight flight2 = airline.addFlight("Istanbul","Izmir",45,150,2);

    airline.makeReservation(passenger,flight1);
    airline.changeReservation(flight2,passenger);
    airline.cancelReservation(passenger);

    return 0;
}