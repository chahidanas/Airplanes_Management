#include "introLoad.h"
#include "airlines.h"

using namespace std;

int menu() {
    int choix;
    system("cls");
    cout <<
            "_______________________________________________________________________________________________________________________"
            << endl;
    cout << "\n\t\t\t\t\tChahid AirLines: " << endl << endl;
    cout << "1)Page Destination" << endl;
    cout << "2)Page Vols" << endl;
    cout << "3)Page Reservation" << endl;
    cout << "4)Page Passagers" << endl;
    cout << "0)Quittez" << endl;
    cout <<
            "_______________________________________________________________________________________________________________________"
            << endl;
    cout <<
            "_______________________________________________________________________________________________________________________"
            << endl;
    cout << "Entrer le numero du menu choisi:";
    cin >> choix;
    system("cls");
    return choix;
}

int menu_destinations() {
    int choix;
    system("cls");
    cout <<
            "_______________________________________________________________________________________________________________________"
            << endl;
    cout << "\n\t\t\t\t\tPage Destinations : " << endl << endl;
    cout << "1)Ajouter Destination:" << endl;
    cout << "2)Supprimer Destination:" << endl;
    cout << "3)Chercher destination par id:" << endl;
    cout << "4)Chercher destination par ville depart:" << endl;
    cout << "5)Chercher destination par ville arrivee:" << endl;
    cout << "0)Retour" << endl;
    cout <<
            "_______________________________________________________________________________________________________________________"
            << endl;
    cout <<
            "_______________________________________________________________________________________________________________________"
            << endl;
    cout << "Entrer le numero du choix desire:";
    cin >> choix;
    cin.ignore();
    system("cls");
    return choix;
}

int menu_vols() {
    int choix;
    system("cls");
    cout <<
            "_______________________________________________________________________________________________________________________"
            << endl;
    cout << "\n\t\t\t\t\tPage Vols : " << endl << endl;
    cout << "1)Ajouter vol:" << endl;
    cout << "2)Supprimer vol:" << endl;
    cout << "3)Chercher vol par id destination:" << endl;
    cout << "4)Chercher vol par id vol:" << endl;
    cout << "5)Modifier vol:" << endl;
    cout << "0)Retour" << endl;
    cout <<
            "_______________________________________________________________________________________________________________________"
            << endl;
    cout <<
            "_______________________________________________________________________________________________________________________"
            << endl;
    cout << "Entrer le numero du choix desire:";
    cin >> choix;
    cin.ignore();
    system("cls");
    return choix;
}

int menu_reservations() {
    int choix;
    system("cls");
    cout <<
            "_______________________________________________________________________________________________________________________"
            << endl;
    cout << "\n\t\t\t\t\tPage reservations : " << endl << endl;
    cout << "1)Reserver:" << endl;
    cout << "2)Annuler reservation:" << endl;
    cout << "3)Chercher reservation par id:" << endl;
    cout << "4)Chercher reservations par passager:" << endl;
    cout << "5)Chercher reservations par vol:" << endl;
    cout << "0)Retour" << endl;
    cout <<
            "_______________________________________________________________________________________________________________________"
            << endl;
    cout <<
            "_______________________________________________________________________________________________________________________"
            << endl;
    cout << "Entrer le numero du choix desire:";
    cin >> choix;
    cin.ignore();
    system("cls");
    return choix;
}

int menu_passager() {
    int choix;
    system("cls");
    cout <<
            "_______________________________________________________________________________________________________________________"
            << endl;
    cout << "\n\t\t\t\t\tPage Passagers : " << endl << endl;
    cout << "1)Ajouter passager:" << endl;
    cout << "2)Supprimer passager:" << endl;
    cout << "3)Chercher passager par id:" << endl;
    cout << "4)Chercher passager par nom:" << endl;
    cout << "5)Chercher passagers par vol id:" << endl;
    cout << "6)Modifier passager:" << endl;
    cout << "0)Retour" << endl;
    cout <<
            "_______________________________________________________________________________________________________________________"
            << endl;
    cout <<
            "_______________________________________________________________________________________________________________________"
            << endl;
    cout << "Entrer le numero du choix desire:";
    cin >> choix;
    cin.ignore();
    system("cls");
    return choix;
}

int main() {
    introLoad();
    system("cls");
    cout <<
            "_______________________________________________________________________________________________________________________"
            << endl;
    cout << "\n\t\t\t\t\tWelcome to Chahid AirLines  " << endl;
    AirlineManagement airline;
    int choix;
    do {
        choix = menu();
        switch (choix) {
            case 1:
                int choix_destination;
                do {
                    choix_destination = menu_destinations();
                    switch (choix_destination) {
                        case 1: {
                            string departC;
                            string arrC;
                            cout << "Ville depart: ";
                            cin >> departC;
                            cout << "Ville arrivee: ";
                            cin >> arrC;
                            airline.addDestination(departC, arrC);
                            break;
                        }
                        case 2: {
                            int destS;
                            cout << "id destination: ";
                            cin >> destS;
                            airline.deleteDestination(destS);
                            break;
                        }
                        case 3: {
                            int ide;
                            cout << "id destination: ";
                            cin >> ide;
                            if (airline.findDestinationByID(ide) != nullptr) {
                                cout << "Disponible!" << endl;
                                cout << "ID: " << airline.findDestinationByID(ide)->getId() << endl;
                                cout << "Depart: " << airline.findDestinationByID(ide)->getDepartureCity() << endl;
                                cout << "Arrivee: " << airline.findDestinationByID(ide)->getArrivalCity() << endl;
                            } else
                                cout << "Non Disponible!" << endl;
                            system("pause");

                            break;
                        }
                        case 4: {
                            string departCity;
                            cout << "Ville depart: ";
                            cin >> departCity;
                            if (airline.findDestinationByDepartureCity(departCity) != nullptr) {
                                cout << "Disponible!" << endl;
                                cout << "ID: " << airline.findDestinationByDepartureCity(departCity)->getId() << endl;
                                cout << "Depart: " << airline.findDestinationByDepartureCity(departCity)->
                                        getDepartureCity() << endl;
                                cout << "Arrivee: " << airline.findDestinationByDepartureCity(departCity)->
                                        getArrivalCity() << endl;
                            } else
                                cout << "Non Disponible!" << endl;
                            system("pause");

                            break;
                        }
                        case 5: {
                            string arrCity;
                            cout << "Ville arrivee: ";
                            cin >> arrCity;
                            if (airline.findDestinationByArrivalCity(arrCity) != nullptr) {
                                cout << "Disponible!" << endl;
                                cout << "ID: " << airline.findDestinationByArrivalCity(arrCity)->getId() << endl;
                                cout << "Depart: " << airline.findDestinationByArrivalCity(arrCity)->getDepartureCity()
                                        << endl;
                                cout << "Arrivee: " << airline.findDestinationByArrivalCity(arrCity)->getArrivalCity()
                                        << endl;
                            } else
                                cout << "Non Disponible!" << endl;
                            system("pause");

                            break;
                        }
                        default:
                            cout << "Choix invalide!";;
                    }
                } while (choix_destination != 0);

                break;
            case 2:
                int choix_vol;
                do {
                    choix_vol = menu_vols();
                    switch (choix_vol) {
                        case 1: {
                            int id, destinationID, seats;
                            string flightNumber, departureTime;
                            float price;
                            cout << "ID: ";
                            cin >> id;
                            cout << "Destination ID: ";
                            cin >> destinationID;
                            cout << "Number of seats: ";
                            cin >> seats;
                            cout << "Flight Number: ";
                            cin >> flightNumber;
                            cout << "Departure Time: ";
                            cin >> departureTime;
                            cout << "Price: ";
                            cin >> price;
                            airline.createFlight(destinationID, flightNumber, departureTime, seats, price);

                            break;
                        }
                        case 2: {
                            int idvol;
                            cout << "entrer le id du vol : ";
                            cin >> idvol;
                            airline.deleteFlight(idvol);
                            break;
                        }
                        case 3: {
                            int iddt;
                            cout << "entrer le id du destination : ";
                            cin >> iddt;
                            vector<Flight *> flightss = airline.findFlightsByDestination(iddt);
                            for (Flight *flight: flightss) {
                                cout << "-----" << endl;
                                cout << "Flight Number: " << flight->getFlightNumber() << endl;
                                cout << "id destination : " << flight->getDestinationID() << endl;
                                cout << "nombre totale des places : " << flight->getTotalSeats() << endl;
                                cout << "id du vol : " << flight->getId() << endl;
                            }
                            system("pause");
                            break;
                        }
                        case 4: {
                            int idvl;
                            cout << "entrer le id du vol : ";
                            cin >> idvl;
                            if (airline.findFlightByID(idvl) != nullptr) {
                                cout << "ID destination: " << airline.findFlightByID(idvl)->getDestinationID() << endl;
                                cout << "Nombre de places : " << airline.findFlightByID(idvl)->getTotalSeats() << endl;
                                cout << "Numero vol : " << airline.findFlightByID(idvl)->getFlightNumber() << endl;
                                cout << "ID vol : " << airline.findFlightByID(idvl)->getId() << endl;
                            }
                            system("pause");
                            break;
                        }
                        case 5: {
                            int vidd;
                            cout << "entrer le id du vol : ";
                            cin >> vidd;
                            if (airline.findFlightByID(vidd) != nullptr) {
                                string departuret;
                                float prix;
                                string number;
                                cout << "entrer le nombre du vol : ";
                                cin >> number;
                                cout << "entrer le temp de depart du vol : ";
                                cin >> departuret;
                                cout << "entrer le prix du vol : ";
                                cin >> prix;
                                airline.modifyFlight(vidd, number, departuret, prix);
                            }
                            system("pause");
                            break;
                        }
                        default:
                            cout << "Choix invalide!";;
                    }
                } while (choix_vol != 0);

                break;
            case 3:
                int choix_reservation;
                do {
                    choix_reservation = menu_reservations();
                    switch (choix_reservation) {
                        case 1: {
                            int vid;
                            string nom;
                            cout << "entrer le id du vol : ";
                            cin >> vid;
                            cout << "entrer le nom du passager : ";
                            cin >> nom;
                            airline.makeReservation(vid, nom);
                            break;
                        }
                        case 2: {
                            int idre;
                            cout << "entrer le id du reservation : ";
                            cin >> idre;
                            airline.cancelReservation(idre);
                            break;
                        }
                        case 3: {
                            int idres;
                            cout << "entrer le id du reservation : ";
                            cin >> idres;
                            if (airline.findReservationByID(idres) != nullptr) {
                                cout << "Disponible!" << endl;
                                cout << "ID: " << idres << endl;
                                cout << "Passager: " << airline.findReservationByID(idres)->getPassengerName() << endl;
                            } else
                                cout << "non Disponible!" << endl;
                            system("pause");
                            break;
                        }
                        case 4: {
                            int idpass3;
                            cout << "entrer le id du passager : ";
                            cin >> idpass3;
                            vector<Reservation *> reservationsPass = airline.findReservationsByPassenger(
                                airline.findPassengerByID(idpass3)->getName());
                            for (Reservation *res: reservationsPass) {
                                cout << "Vol Numero: " << res->getFlightID() << endl;
                                cout << "Reservation Num: " << res->getId() << std::endl;
                                cout << "Passenger Nom: " << res->getPassengerName() << std::endl;
                            }
                            break;
                        }
                        case 5: {
                            int vid;
                            cout << "entrer le id du vol : ";
                            cin >> vid;
                            vector<Reservation *> reservationsPass = airline.findReservationsByFlight(vid);
                            for (Reservation *res: reservationsPass) {
                                cout << "Vol Numero: " << res->getFlightID() << endl;
                                cout << "Reservation Num: " << res->getId() << std::endl;
                                cout << "Passenger Nom: " << res->getPassengerName() << std::endl;
                            }
                            break;
                        }
                        default: cout << "Choix invalide!";
                    }
                } while (choix_reservation != 0);

                break;
            case 4:
                int choix_passager;
                do {
                    choix_passager = menu_passager();
                    switch (choix_passager) {
                        case 1: {
                            string nom;
                            cout << "entrer le nom du passager : ";
                            cin >> nom;
                            airline.addPassenger(nom);
                            break;
                        }
                        case 2: {
                            int idpass2;
                            cout << "entrer le id du passager : ";
                            cin >> idpass2;
                            airline.deletePassenger(idpass2);
                            break;
                        }
                        case 3: {
                            int idpass3;
                            cout << "entrer le id du passager : ";
                            cin >> idpass3;
                            if (airline.findPassengerByID(idpass3) != nullptr) {
                                cout << "ID: " << idpass3 << endl;
                                cout << "Name: " << airline.findPassengerByID(idpass3)->getName() << endl;
                            }
                            break;
                        }
                        case 4: {
                            string nnom;
                            cout << "entrer le nom du passager : ";
                            cin >> nnom;
                            if (airline.findPassengerByName(nnom) != nullptr) {
                                cout << "ID: " << airline.findPassengerByName(nnom)->getId() << endl;
                                cout << "Name: " << nnom << endl;
                            }
                            break;
                        }
                        case 5: {
                            int vid;
                            cout << "entrer le id du vol : ";
                            cin >> vid;
                            vector<Passenger *> volPass = airline.findPassengersByFlight(vid);
                            for (Passenger *pass: volPass) {
                                cout << "Passager num: " << pass->getId() << endl;
                                cout << "Nom: " << pass->getName() << endl << endl << endl;
                            }
                            break;
                        }
                        case 6: {
                            int idpp;
                            string nnam;
                            cout << "entrer le nouveau id du passager : ";
                            cin >> idpp;
                            cout << "entrer le nouveau nom du passager : ";
                            cin >> nnam;
                            airline.modifyPassenger(idpp, nnam);
                            break;
                        }
                        default:
                            cout << "Choix invalide!";
                    }
                } while (choix_passager != 0);

                break;
            default:
                cout << "Choix invalide!";
        }
    } while (choix != 0);
    system("cls");
    constexpr char namex[] = "Exiting program......";
    for (int i = 0; namex[i] != '\0'; i++) {
        cout << namex[i];
        Sleep(100);
    }
    return 0;
}
