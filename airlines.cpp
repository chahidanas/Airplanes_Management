#include "airlines.h"

// AirlineManagement methods implementation
void AirlineManagement::addDestination(const std::string& departureCity, const std::string& arrivalCity) {
    int id = destinations.empty() ? 1 : destinations.back()->getId() + 1;
    auto* dest = new Destination(id, departureCity, arrivalCity);
    destinations.push_back(dest);
}

void AirlineManagement::modifyDestination(int destinationID, const std::string& departureCity, const std::string& arrivalCity) {
    Destination* dest = findDestinationByID(destinationID);
    if (dest) {
        dest->setDepartureCity(departureCity);
        dest->setArrivalCity(arrivalCity);
    } else {
        std::cout << "Destination not found." << std::endl;
        system("pause");
    }
}
Destination* AirlineManagement::findDestinationByID(int destinationID) {
    auto it = std::find_if(destinations.begin(), destinations.end(),
                           [destinationID](Destination* dest) { return dest->getId() == destinationID; });
    return (it != destinations.end()) ? *it : nullptr;
}

void AirlineManagement::deleteDestination(int destinationID) {
    auto it = std::find_if(destinations.begin(), destinations.end(),
                           [destinationID](Destination* dest) { return dest->getId() == destinationID; });
    if (it != destinations.end()) {
        delete *it;
        destinations.erase(it);
    } else {
        std::cout << "Destination not found." << std::endl;
        system("pause");
    }
}

Destination* AirlineManagement::findDestinationByDepartureCity(const std::string& departureCity) {
    auto it = std::find_if(destinations.begin(), destinations.end(),
                           [departureCity](Destination* dest) { return dest->getDepartureCity() == departureCity; });
    return (it != destinations.end()) ? *it : nullptr;
}

Destination* AirlineManagement::findDestinationByArrivalCity(const std::string& arrivalCity) {
    auto it = std::find_if(destinations.begin(), destinations.end(),
                           [arrivalCity](Destination* dest) { return dest->getArrivalCity() == arrivalCity; });
    return (it != destinations.end()) ? *it : nullptr;
}

void AirlineManagement::createFlight(int destinationID, const std::string& flightNumber, const std::string& departureTime, int seats, float price) {
    Destination* dest = findDestinationByID(destinationID);
    if (dest) {
        int id = flights.empty() ? 1 : flights.back()->getId() + 1;
        auto* flight = new Flight(id, destinationID, flightNumber, departureTime, seats, price);
        flights.push_back(flight);
    } else {
        std::cout << "Destination not found." << std::endl;
        system("pause");
    }
}

void AirlineManagement::modifyFlight(int flightID, const std::string& flightNumber, const std::string& departureTime, float price) {
    Flight* flight = findFlightByID(flightID);
    if (flight) {
        flight->setFlightNumber(flightNumber);
        flight->setDepartureTime(departureTime);
        flight->setPrice(price);
    } else {
        std::cout << "Flight not found." << std::endl;
        system("pause");
    }
}

void AirlineManagement::deleteFlight(int flightID) {
    auto it = std::find_if(flights.begin(), flights.end(),
                           [flightID](Flight* flight) { return flight->getId() == flightID; });
    if (it != flights.end()) {
        delete *it;
        flights.erase(it);
    } else {
        std::cout << "Flight not found." << std::endl;
        system("pause");
    }
}
Flight* AirlineManagement::findFlightByID(int flightID) {
    auto it = std::find_if(flights.begin(), flights.end(),
                           [flightID](Flight* flight) { return flight->getId() == flightID; });
    return (it != flights.end()) ? *it : nullptr;
}

std::vector<Flight*> AirlineManagement::findFlightsByDestination(int destinationID) {
    std::vector<Flight*> result;
    for (Flight* flight : flights) {
        if (flight->getDestinationID() == destinationID) {
            result.push_back(flight);
        }
    }
    return result;
}

void AirlineManagement::makeReservation(int flightID, const std::string& passengerName) {
    Flight* flight = findFlightByID(flightID);
    if (flight) {
        if (checkAvailability(flightID)) {
            int id = reservations.empty() ? 1 : reservations.back()->getId() + 1;
            auto* reservation = new Reservation(id, flightID, passengerName);
            reservations.push_back(reservation);
            updateAvailability(flightID);
        } else {
            std::cout << "No available seats for this flight." << std::endl;
            system("pause");
        }
    } else {
        std::cout << "Flight not found." << std::endl;
        system("pause");
    }
}

void AirlineManagement::cancelReservation(int reservationID) {
    auto it = std::find_if(reservations.begin(), reservations.end(),
                           [reservationID](Reservation* reservation) { return reservation->getId() == reservationID; });
    if (it != reservations.end()) {
        int flightID = (*it)->getFlightID();
        delete *it;
        reservations.erase(it);
        updateAvailability(flightID);
    } else {
        std::cout << "Reservation not found." << std::endl;
        system("pause");
    }
}

std::vector<Reservation*> AirlineManagement::findReservationsByPassenger(const std::string& passengerName) {
    std::vector<Reservation*> result;
    for (Reservation* reservation : reservations) {
        if (reservation->getPassengerName() == passengerName) {
            result.push_back(reservation);
        }
    }
    return result;
}

std::vector<Reservation*> AirlineManagement::findReservationsByFlight(int flightID) {
    std::vector<Reservation*> result;
    for (Reservation* reservation : reservations) {
        if (reservation->getFlightID() == flightID) {
            result.push_back(reservation);
        }
    }
    return result;
}
Reservation* AirlineManagement::findReservationByID(int reservationID) {
    auto it = std::find_if(reservations.begin(), reservations.end(),
                           [reservationID](Reservation* reservation) { return reservation->getId() == reservationID; });
    return (it != reservations.end()) ? *it : nullptr;
}

void AirlineManagement::addPassenger(const std::string& name) {
    int id = passengers.empty() ? 1 : passengers.back()->getId() + 1;
    auto* passenger = new Passenger(id, name);
    passengers.push_back(passenger);
}

void AirlineManagement::modifyPassenger(int passengerID, const std::string& name) {
    Passenger* passenger = findPassengerByID(passengerID);
    if (passenger) {
        passenger->setName(name);
    } else {
        std::cout << "Passenger not found." << std::endl;
        system("pause");
    }
}

void AirlineManagement::deletePassenger(int passengerID) {
    auto it = std::find_if(passengers.begin(), passengers.end(),
                           [passengerID](Passenger* passenger) { return passenger->getId() == passengerID; });
    if (it != passengers.end()) {
        delete *it;
        passengers.erase(it);
    } else {
        std::cout << "Passenger not found." << std::endl;
        system("pause");
    }
}

std::vector<Passenger*> AirlineManagement::findPassengersByFlight(int flightID) {
    std::vector<Passenger*> result;
    for (Reservation* reservation : reservations) {
        if (reservation->getFlightID() == flightID) {
            Passenger* passenger = findPassengerByName(reservation->getPassengerName());
            if (passenger) {
                result.push_back(passenger);
            }
        }
    }
    return result;
}
Passenger* AirlineManagement::findPassengerByID(int passengerID) {
    auto it = std::find_if(passengers.begin(), passengers.end(),
                           [passengerID](Passenger* passenger) { return passenger->getId() == passengerID; });
    return (it != passengers.end()) ? *it : nullptr;
}

Passenger* AirlineManagement::findPassengerByName(const std::string& name) {
    auto it = std::find_if(passengers.begin(), passengers.end(),
                           [name](Passenger* passenger) { return passenger->getName() == name; });
    return (it != passengers.end()) ? *it : nullptr;
}

bool AirlineManagement::checkAvailability(int flightID) {
    // Logic to check the availability of seats for a flight
    Flight* flight = findFlightByID(flightID);
    if (flight) {
        // Assume totalSeats is the total number of seats for the flight
        int totalSeats = 100; // Example value, should be retrieved from flight data
        int reservedSeats = findReservationsByFlight(flightID).size();
        return reservedSeats < totalSeats;
    } else {
        std::cout << "Flight not found." << std::endl;
        system("pause");
        return false;
    }
}
void AirlineManagement::updateAvailability(int flightID) {
    // Logic to update the availability of seats after making or canceling a reservation
    Flight* flight = findFlightByID(flightID);
    if (flight) {
        int reservedSeats = findReservationsByFlight(flightID).size();
        flight->setAvailableSeats(flight->getTotalSeats() - reservedSeats);
    } else {
        std::cout << "Flight not found." << std::endl;
        system("pause");
    }
}

void AirlineManagement::recordHistory(int reservationID) {
    // Logic to record reservation and cancellation history
    // For simplicity, let's print a message indicating the action
    Reservation* reservation = findReservationByID(reservationID);
    if (reservation) {
        std::cout << "Recorded history for reservation with ID: " << reservationID << std::endl;
        system("pause");
        // Additional logic to log the reservation/cancellation details to a file or database
    } else {
        std::cout << "Reservation not found. Cannot record history." << std::endl;
        system("pause");
    }
}

// Destination constructor implementation
Destination::Destination(int id, const std::string& departureCity, const std::string& arrivalCity)
    : id(id), departureCity(departureCity), arrivalCity(arrivalCity) {}

// Flight constructor implementation
Flight::Flight(int ide, int destID, const std::string& flightNum, const std::string& departureT, int seats, float pr)
    : id(ide), destinationID(destID), flightNumber(flightNum), departureTime(departureT), totalSeats(seats), price(pr) {}

// Reservation constructor implementation
Reservation::Reservation(int id, int flightID, const std::string& passengerName)
    : id(id), flightID(flightID), passengerName(passengerName) {}

// Passenger constructor implementation
Passenger::Passenger(int id, const std::string& name)
    : id(id), name(name) {}

    int Destination::getId(){return id;}
    void Destination::setDepartureCity(std::string depC){departureCity=depC;}
    void Destination::setArrivalCity(std::string arrC){arrivalCity=arrC;}
    std::string Destination::getDepartureCity(){return departureCity;}
    std::string Destination::getArrivalCity(){return arrivalCity;}

    int Flight::getId(){return id;}
    int Flight::getDestinationID(){return destinationID;}
    std::string Flight::getFlightNumber(){return flightNumber;}
    void Flight::setFlightNumber(std::string flightN){flightNumber=flightN;}
    void Flight::setDepartureTime(std::string depT){departureTime=depT;}
    void Flight::setPrice(float pr){price=pr;}
    void Flight::setAvailableSeats(int availableSeats) {
    this->availableSeats = availableSeats;}
    int Flight::getTotalSeats() {
    return totalSeats;}

    int Reservation::getId(){return id;}
    int Reservation::getFlightID(){return flightID;}
    std::string Reservation::getPassengerName(){return passengerName;}

    int Passenger::getId(){return id;}
    std::string Passenger::getName(){return name;}
    void Passenger::setName(std::string n){name=n;}
