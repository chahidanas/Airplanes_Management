#ifndef AIRLINES_H
#define AIRLINES_H



#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ostream>

using namespace std;

class Destination;
class Flight;
class Reservation;
class Passenger;

class AirlineManagement {
public:
    void addDestination(const std::string& departureCity, const std::string& arrivalCity);
    void modifyDestination(int destinationID, const std::string& departureCity, const std::string& arrivalCity);
    Destination* findDestinationByID(int destinationID);
    void deleteDestination(int destinationID);
    Destination* findDestinationByDepartureCity(const std::string& departureCity);
    Destination* findDestinationByArrivalCity(const std::string& arrivalCity);

    void createFlight(int destinationID, const std::string& flightNumber, const std::string& departureTime, int seats, float price);
    void modifyFlight(int flightID, const std::string& flightNumber, const std::string& departureTime, float price);
    void deleteFlight(int flightID);
    Flight* findFlightByID(int flightID);
    std::vector<Flight*> findFlightsByDestination(int destinationID);

    void makeReservation(int flightID, const std::string& passengerName);
    void cancelReservation(int reservationID);
    std::vector<Reservation*> findReservationsByPassenger(const std::string& passengerName);
    std::vector<Reservation*> findReservationsByFlight(int flightID);
    Reservation* findReservationByID(int reservationID);

    void addPassenger(const std::string& name);
    void modifyPassenger(int passengerID, const std::string& name);
    void deletePassenger(int passengerID);
    Passenger* findPassengerByName(const std::string& name);
    Passenger* findPassengerByID(int passengerID);
    std::vector<Passenger*> findPassengersByFlight(int flightID);

    bool checkAvailability(int flightID);
    void updateAvailability(int flightID);

    void recordHistory(int reservationID);

private:
    std::vector<Destination*> destinations;
    std::vector<Flight*> flights;
    std::vector<Reservation*> reservations;
    std::vector<Passenger*> passengers;
};

class Destination {
public:
    Destination(int id, const std::string& departureCity, const std::string& arrivalCity);
    int getId();
    void setDepartureCity(std::string depC);
    void setArrivalCity(std::string arrC);
    std::string getDepartureCity();
    std::string getArrivalCity();

private:
    int id;
    std::string departureCity;
    std::string arrivalCity;
};

class Flight {
public:
    Flight(int id, int destinationID, const std::string& flightNumber, const std::string& departureTime,int seats, float price);
    int getId();
    int getDestinationID();
    std::string getFlightNumber();
    void setFlightNumber(std::string flightN);
    void setDepartureTime(std::string depT);
    void setPrice(float pr);
    void setAvailableSeats(int availableSeats);
    int getTotalSeats();

private:
    int id;
    int destinationID;
    int availableSeats;
    int totalSeats;
    std::string flightNumber;
    std::string departureTime;
    float price;
};

class Reservation {
public:
    Reservation(int id, int flightID, const std::string& passengerName);
    int getId();
    int getFlightID();
    std::string getPassengerName();

private:
    int id;
    int flightID;
    std::string passengerName;
};

class Passenger {
public:
    Passenger(int id, const std::string& name);
    int getId();
    std::string getName();
    void setName(std::string n);

private:
    int id;
    std::string name;
};

#endif //AIRLINES_H
