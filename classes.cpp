#include <iostream>
#include <string>

using namespace std;

class Venue {
    char* location = "";
    int maxNoSeats = 0;
    int noSeatsAvailable = 0;
    int noRows = 0;
    int entranceNo = 0;
    int maxNoEntrances = 0;
    string venueType = "";
public:
    void setLocation(char* newLocation) {
        delete[] this->location;
        if (strlen(newLocation) == 0) {
            throw runtime_error("Provide a name, not an empty string.");
        }
        strncpy(this->location, newLocation, strlen(newLocation) + 1);
    }

    char* getLocation() {
        char* locationCopy = new char[strlen(this->location) + 1];
        strncpy(locationCopy, this->location, strlen(this->location) + 1);
        return locationCopy;
    }

    void setMaxNoSeats(int mSeats) {
        if (mSeats <= 0) {
            throw runtime_error("Wrong number was provided.");
        }
        else {
            this->maxNoSeats = mSeats;
        }
    }

    int getMaxNoSeats() {
        return this->maxNoSeats;
    }

    void setNoSeatsAvailable(int seats) {
        if (seats < 0) {
            throw runtime_error("Provide a positive number.");
        } 
        else {
            this->noSeatsAvailable = seats;
        }
    }

    int getNoAvailiableSeats() {
        return this->noSeatsAvailable;
    }

    void setNoRows(int rows) {
        if (rows <= 0) {
            throw runtime_error("Provide a positive number.");
        }
        else {
            this->noRows = rows;
        }
    }

    int getNoRows() {
        return this->noRows;
    }

    void setEntranceNo(int entrance) {
        if (entrance <= 0 || entrance > this->maxNoEntrances) {
            throw runtime_error("Provide a valid no of the entrance.");
        }
        else {
            this->entranceNo = entrance;
        }
    }

    int getEntranceNo() {
        return this->entranceNo;
    }

    void setMaxNoEntrances(int mEntrance) {
        if (mEntrance <= 0) {
            throw runtime_error("Provide a valid max no of the entrances.");
        }
        else {
            this->maxNoEntrances = mEntrance;
        }
    }

    int getMaxNoEntrances() {
        return this->maxNoEntrances;
    }

    void setVenueType(string type) {
        if (strlen(type.c_str()) == 0) {
            throw runtime_error("Provide not an empty string.");
        }
        this->venueType = type;
    }

    string getVenueType() {
        return this->venueType;
    }

    Venue() {
        this->setLocation("Unknown");
        this->setNoRows(1);
        this->setMaxNoSeats(1);
        this->setNoSeatsAvailable(1);
        this->setMaxNoEntrances(1);
        this->setEntranceNo(1);
        this->setVenueType("Unknown");
    }

    Venue(char* location, int maxNoSeats, int noRows, int noSeatsAvailable, int entranceNo, int maxNoEntrances, string venueType) {
        if (maxNoSeats <= 0 || noSeatsAvailable < 0 || noRows <= 0 || entranceNo < 0 || maxNoEntrances <= 0) {
            throw std::runtime_error("Invalid input. Ensure positive values for maximum seats, available seats, rows, entrance number, and maximum entrances.");
        }
        this->setLocation(location);
        this->setMaxNoSeats(maxNoSeats);
        this->setNoRows(noRows);
        this->setNoSeatsAvailable(noSeatsAvailable);
        this->setEntranceNo(entranceNo);
        this->setMaxNoEntrances(maxNoEntrances);
        this->setVenueType(venueType);
    }

    Venue(Venue& v) {
        this->setLocation(v.getLocation());
        this->setMaxNoSeats(v.maxNoSeats);
        this->setNoRows(v.noRows);
        this->setNoSeatsAvailable(v.noSeatsAvailable);
        this->setEntranceNo(v.entranceNo);
        this->setMaxNoEntrances(v.maxNoEntrances);
        this->setVenueType(v.venueType);
    }

    ~Venue() {
        delete[] this->location;
    }

    void displayAttribute(string attributeName) {
        if (attributeName == "Location") {
            cout << "Location" << getLocation() << endl;
        }
        else if (attributeName == "Max No Of Seats") {
            cout << "Max No Of Seats" << getMaxNoSeats() << endl;
        }
        else if (attributeName == "No Of Rows") {
            cout << "No Of Rows" << getNoRows() << endl;
        }
        else if (attributeName == "No Of Seats Available") {
            cout << "No Of Seats Available" << getNoAvailiableSeats() << endl;
        }
        else if (attributeName == "Entrance No") {
            cout << "Entrance No" << getEntranceNo() << endl;
        }
        else if (attributeName == "Max No Of The Entrances") {
            cout << "Max No Of The Entrances" << getMaxNoEntrances() << endl;
        }
        else if (attributeName == "Venue Type") {
            cout << "Venue Type" << getVenueType() << endl;
        }
        else {
            cout << "Unknown attribute." << endl;
        }
    }

    friend void operator<<(ostream& console, Venue& v);
};

void operator<<(ostream& console, Venue& v){
    console << endl << "Venue Location: " << v.getLocation();
    console << endl << "Venue Max No Of Seats: " << v.maxNoSeats;
    console << endl << "Venue No Of Rows" << v.noRows;
    console << endl << "Venue No Of Seats Available" << v.noSeatsAvailable;
    console << endl << "Entrance No" << v.entranceNo;
    console << endl << "Venue Max No Of The Entrances" << v.maxNoEntrances;
    console << endl << "Venue Type" << v.venueType;
}

class Event {
    char eventDate[11] = "";      // dd/mm/yyyy
    char* eventName = nullptr;
    string eventTime = "";        // hh:mm:ss
    string eventType = "";
    int eventDuration = 0;   //in minutes
    static int TOTAL_EVENTS;
public:
    static int getTotalEvents() {
        return Event::TOTAL_EVENTS;
    }

    void setDate(const char* newDate) {
        if (strlen(newDate) != 10) {
            throw runtime_error("Wrong date.");
        }
        if (newDate[2] != '/' || newDate[5] != '/') {
            throw runtime_error("Wrong date format.");
        } 
        strncpy(this->eventDate, newDate, 11);
    }   

    char* getDate() {
        char* dateCopy = new char[11];
		strncpy(dateCopy, this->eventDate, 11);
		return dateCopy;
    }

    void setName(char* newName) {
        delete[] this->eventName;
        if (strlen(newName) == 0) {
            throw runtime_error("Provide a name, not an empty string.");
        }
        strncpy(this->eventName, newName, strlen(newName) + 1);
    }

    char* getName() {
        char* nameCopy = new char[strlen(this->eventName) + 1];
		strncpy(nameCopy, this->eventName, strlen(this->eventName) + 1);
		return nameCopy;
    }

    void setEventTime(string newTime) {
        if (strlen(newTime.c_str()) != 8) {
            throw runtime_error("Wrong time.");
        }
        if (newTime[2] != ':' || newTime[5] != ':') {
            throw runtime_error("Wrong time format.");
        }
        this->eventTime = newTime;
    }

    string getEventTime() {
        return this->eventTime;
    }

    void setEventDuration(int newDuration) {
        if (newDuration <= 0) {
            throw runtime_error("Provide a positive number.");
        }
        else {
            this->eventDuration = newDuration;
        }
    }

    int getEventDuration() {
        return this->eventDuration;
    }

    Event() {

    }

    ~Event() {

    }
};

int Event::TOTAL_EVENTS = 0;

class Ticket {
    const int ticketId = 0;
    string ticketType = "";
    double ticketPrice = 0;
    string ticketHolderName = "";
    char purchaseDate[11] = "";
    string purchaseTime = "";
    bool isValid = false;
public:
    int getTicketId() {
        return this->ticketId;
    }

    void setTicketType(string type) {
        if (strlen(type.c_str()) == 0) {
            throw runtime_error("Please provide correct ticket type");
        }
        else {
            this->ticketType = type;
        }
    }

    string getTicketType() {
        return this->ticketType;
    }

    void setTicketPrice(double price) {
        if (price <= 0) {
            throw runtime_error("Provide a positive value for the ticket");
        }
        else {
            this->ticketPrice = price;
        }
    }

    double getTicketPrice() {
        return this->ticketPrice;
    }

    void setTicketHolderName(string name) {
        if (strlen(name.c_str()) == 0) {
            throw runtime_error("Provide a name, not an empty string.");
        }
        else {
            this->ticketHolderName = name;
        }
    }

    string getTicketHolderName() {
        return this->ticketHolderName;
    }

    void setPurchaseDate(const char* newDate) {
        if (strlen(newDate) != 10) {
            throw runtime_error("Wrong date.");
        }
        if (newDate[2] != '/' || newDate[5] != '/') {
            throw runtime_error("Wrong date format.");
        }
        strncpy(this->purchaseDate, newDate, 11);
    }

    char* getPurchaseDate() {
        char* copy = new char[11];
        strncpy(copy, this->purchaseDate, 11);
        return copy;
    }

    void setPurchaseTime(string newTime) {
        if (strlen(newTime.c_str()) != 8) {
            throw runtime_error("Wrong time.");
        }
        if (newTime[2] != ':' || newTime[5] != ':') {
            throw runtime_error("Wrong time format.");
        }
        this->purchaseTime = newTime;
    }

    string getPurchaseTime() {
        return this->purchaseTime;
    }

    void setIsValid (bool isValid) {
        this->isValid = isValid;
    }

    bool getIsValid () {
        return this->isValid;
    }
};

int main() {

}