#include "airlines.hpp"
#include <iterator>

Flight::Flight(int num,string from,string to,int numPas,int dist,int time) {
  flightNumber = num;
  takeOfCity = from;
  landingCity = to;
  numberOfPassengers = numPas;
  distance = dist;
  duration = time;
}

Flight::~Flight(){}

int Flight::getFlightNumber(){
  return flightNumber;
}
string Flight::getTakeOfCity(){
  return takeOfCity;
}
string Flight::getLandingCity(){
  return landingCity;
}
int Flight::getNumberOfPassengers(){
  return numberOfPassengers;
}
int Flight::getDistance(){
  return distance;
}
int Flight::getDuration(){
  return duration;
}

void Flight::setFlightNumber(int flightNumber){
  this->flightNumber = flightNumber;
}
void Flight::setTakeOfCity(string takeOfCity){
  this->takeOfCity = flightNumber;
}
void Flight::setLandingCity(string landingCity){
  this->landingCity = landingCity;
}
void Flight::setNumberOfPassengers(int numberOfPassengers){
  this->numberOfPassengers = numberOfPassengers;
}
void Flight::setDistance(int distance){
  this->distance = distance;
}
void Flight::setDuration(int duration){
  this->duration = duration;
}

void Flight::printFlight(){
  cout <<"flight number: " << Flight::flightNumber << ", from " << Flight::takeOfCity 
  << " to " << Flight::landingCity << ", number of passangers: " << Flight::numberOfPassengers<<", distance: "<<Flight::distance<<" miles"<<", duration: "
  <<Flight::duration<<" hours"<<endl;
}


Passenger::Passenger(string name, int passpNo,int flightNum, int luggage) {
  fullName = name;
  passportNo = passpNo;
  flightNumber = flightNum;
  numberOfLuggage = luggage;
}

Passenger::~Passenger(){}

string Passenger::getFullName(){
  return fullName;
}
int Passenger::getPassportNo(){
  return passportNo;
}
int Passenger::getFlightNumber(){
  return flightNumber;
}
int Passenger::getNumberOfLuggage(){
  return numberOfLuggage;
}

void  Passenger::setFullName(string fullName){
  this->fullName = fullName;
}
void  Passenger::setPassportNo(int passportNo){
  this->passportNo = passportNo;
}
void  Passenger::setFlightNumber(int flightNumber){
  this->flightNumber = flightNumber;
}
void  Passenger::setNumberOfLuggage(int numberOfLuggage){
  this->numberOfLuggage = numberOfLuggage;
}

void  Passenger::printPassenger(){
  cout <<"Passenger Name:" <<  fullName << " Passport No:  " <<  passportNo << " Flight Number: "
  <<flightNumber<< " Number of Luggages: "<<  numberOfLuggage<<endl;
}

void Passenger::changeReservation(int number){
  flightNumber = number;
  cout<<endl<< fullName <<"'s reservation has changed. The flight number is now: "<<flightNumber<<endl;
}

void Passenger::cancelReservation(){
  flightNumber = 0000;
  cout<<endl<<fullName<<"'s reservation canceled."<<endl;
}

Reservation::Reservation(int num, string name, int resNo, int luggage) {
  flightNumber = num;
  passengerName = name;
  reservationNo = resNo;
  numberOfLuggage = luggage;
}

Reservation::~Reservation(){}

int Reservation::getFlightNumber(){
  return flightNumber;
}
string Reservation::getPassengerName(){
  return passengerName;
}
int Reservation::getReservationNo(){
  return reservationNo;
}
int Reservation::getNumberOfLuggage(){
  return numberOfLuggage;
}

void Reservation::setFlightNumber(int flightNumber){
  this-> flightNumber = flightNumber;
}
void Reservation::setPassengerName(string passengerName){
  this-> passengerName = passengerName;
}
void Reservation::setReservationNo(int reservationNo){
  this-> reservationNo = reservationNo;
}
void Reservation::setNumberOfLuggage(int numberOfLuggage){
  this-> numberOfLuggage = numberOfLuggage;
}

void Reservation::printReservation(){
  cout <<endl<<"a new reservation! "<<"flight number: " <<  Reservation::flightNumber <<", passenger name: " <<  Reservation::passengerName 
  << ", reservation number: "<<  Reservation::reservationNo<<", number of luggage: "<< Reservation::numberOfLuggage<<endl;
}


Airline::Airline(int fleet, int numberOfPassg, int numberOfFlight, int miles) {
  this-> fleet = fleet;
  this-> numberOfPassg;
  this-> numberOfFlight;
  this-> hoursOfFlight;
  this-> miles;
}

Airline::~Airline(){}

int Airline::getFleet(){
  return fleet;
}
int Airline::getNumberOfPassg(){
  return numberOfPassg;
}
int Airline::getNumberOfFlight(){
  return numberOfFlight;
}
int Airline::getHoursOfFlight(){
  return hoursOfFlight;
}
int Airline::getMiles(){
  return miles;
}
vector<Flight> Airline::getFlights(){
  return flights;
}
map<int,Reservation> Airline::getFlightReservation(){
  return flightReservation;
}

void Airline::setFleet(int numberOfPlanes){
  fleet = numberOfPlanes;
}
void Airline::setNumberOfPassg(int number){
  numberOfPassg = number;
}
void Airline::setNumberOfFlight(int number){
  numberOfFlight = number;
}
void Airline::setHoursOfFlight(int hour){
  hoursOfFlight = hour;
}
void Airline::setMiles(int mile){
  miles = mile;
}
  
Flight Airline::addFlight(string from,string to,int numPas,int dist,int time){
  if (to == from){
    cout<<"Take of and landing citys cant be the same!"<<endl;
  }
  else{
    int max = 9999;
    int min = 1000;
    int flightNumber = rand()%(max-min) + min;
    Flight flight(flightNumber,from,to,numPas,dist,time);
    flights.push_back(flight);
    cout<<endl<<"a new flight! ";
    flight.printFlight();
    numberOfPassg += numPas;
    numberOfFlight += 1;
    hoursOfFlight += time;
    miles += dist;
    return flight;
  }
}

void Airline::makeReservation(Passenger pas, Flight flight){
  int flightNumber = flight.getFlightNumber();
  pas.setFlightNumber(flightNumber);
  string name = pas.getFullName();
  int reserNo = rand()%1000;
  int luggage = pas.getNumberOfLuggage();
  Reservation reservation(flightNumber,name,reserNo,luggage);
  Airline::flightReservation.insert(pair<int, Reservation>(flightNumber, reservation));
  reservation.printReservation();
}
void Airline::changeReservation(Flight flight, Passenger passenger){
  int number = flight.getFlightNumber();
  passenger.changeReservation(number);
  map<int,Reservation>::iterator itr;
  for(itr=flightReservation.begin();itr!=flightReservation.end();itr++){
    if((itr->second).getPassengerName() == passenger.getFullName()){
      Reservation res = itr->second;
      res.setFlightNumber(number);
      flightReservation.erase(itr);
      flightReservation.insert(pair<int, Reservation>(number, res));
      break;
    }
  }
}
void Airline::cancelReservation(Passenger passenger){
  passenger.cancelReservation();
  map<int,Reservation>::iterator itr;
  for(itr=flightReservation.begin();itr!=flightReservation.end();itr++){
    if((itr->second).getPassengerName() == passenger.getFullName()){
      Reservation* res = &(itr->second);
      delete[] res;
      flightReservation.erase(itr);
      break;
    }
  }
}