#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Flight {
  private:
    int flightNumber;
    string takeOfCity;
    string landingCity;
    int numberOfPassengers;
    int distance;
    int duration;

  public:
    Flight(int num, string from, string to, int numPas, int dist, int time);

    ~Flight();

    int getFlightNumber();
    string getTakeOfCity();
    string getLandingCity();
    int getNumberOfPassengers();
    int getDistance();
    int getDuration();

    void setFlightNumber(int flightNumber);
    void setTakeOfCity(string takeOfCity);
    void setLandingCity(string landingCity);
    void setNumberOfPassengers(int numberOfPassengers);
    void setDistance(int distance);
    void setDuration(int duration);

    void printFlight();
};

class Passenger {
  private:
    string fullName;
    int passportNo;
    int flightNumber;
    int numberOfLuggage;

  public:
    Passenger(string name, int passpNo,int flightNum, int luggage);

    ~Passenger();

    string getFullName();
    int getPassportNo();
    int getFlightNumber();
    int getNumberOfLuggage();
    
    void setFullName(string fullName);
    void setPassportNo(int passportNo);
    void setFlightNumber(int flightNumber);
    void setNumberOfLuggage(int numberOfLuggage);

    void printPassenger();
    void changeReservation(int flightNumber);
    void cancelReservation();

};

class Reservation {
  private:
    int flightNumber;
    string passengerName;
    int reservationNo;
    int numberOfLuggage;

  public:
    Reservation(int num, string name, int resNo, int luggage);

    ~Reservation();

    int getFlightNumber();
    string getPassengerName();
    int getReservationNo();
    int getNumberOfLuggage();

    void setFlightNumber(int flightNumber);
    void setPassengerName(string passengerName);
    void setReservationNo(int reservationNo);
    void setNumberOfLuggage(int numberOfLuggage);

    void printReservation();

};

class Airline {
  private:
    int fleet;
    vector<Flight> flights;
    map<int,Reservation> flightReservation;
    int numberOfPassg;
    int numberOfFlight;
    int hoursOfFlight;
    int miles;

  public:
    Airline(int fleet, int numberOfPassg, int numberOfFlight, int miles);

    ~Airline ();

    int getFleet();
    int getNumberOfPassg();
    int getNumberOfFlight();
    int getHoursOfFlight();
    int getMiles();
    vector<Flight> getFlights();
    map<int,Reservation> getFlightReservation();

    void setFleet(int numberOfPlanes);
    void setNumberOfPassg(int number);
    void setNumberOfFlight(int number);
    void setHoursOfFlight(int hour);
    void setMiles(int mile);
  
    Flight addFlight(string from,string to,int numPas,int dist,int time);
    void makeReservation(Passenger passenger, Flight flight);
    void changeReservation(Flight flight, Passenger passenger);
    void cancelReservation(Passenger passenger);

};