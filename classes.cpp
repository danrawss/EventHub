#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Venue {
    char* location = nullptr;
    int maxNoSeats = 0;
    int noSeatsAvailable = 0;
    int noRows = 0;
    int entranceNo = 0;
    int maxNoEntrances = 0;
    string venueType = "";
public:
    void setLocation(const char* newLocation) {
        delete[] this->location;
        if (strlen(newLocation) == 0) {
            throw runtime_error("Provide a name, not an empty string.");
        }
        this->location = new char[strlen(newLocation) + 1];
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

    Venue(char* location, int maxNoSeats, int maxNoEntrances) {
        this->setLocation(location);
        this->setNoRows(1);
        this->setMaxNoSeats(maxNoSeats);
        this->setNoSeatsAvailable(1);
        this->setMaxNoEntrances(maxNoEntrances);
        this->setEntranceNo(1);
        this->setVenueType("Unknown");
    }

    Venue(const char* location, int maxNoSeats, int noRows, int noSeatsAvailable, int maxNoEntrances, int entranceNo, string venueType) {
        this->setLocation(location);
        this->setMaxNoSeats(maxNoSeats);
        this->setNoRows(noRows);
        this->setNoSeatsAvailable(noSeatsAvailable);
        this->setMaxNoEntrances(maxNoEntrances);
        this->setEntranceNo(entranceNo);
        this->setVenueType(venueType);
    }

    Venue(Venue& v) : location(nullptr) {
        this->setLocation(v.getLocation());
        this->setMaxNoSeats(v.getMaxNoSeats());
        this->setNoRows(v.getNoRows());
        this->setNoSeatsAvailable(v.getNoAvailiableSeats());
        this->setMaxNoEntrances(v.getMaxNoEntrances());
        this->setEntranceNo(v.getEntranceNo());
        this->setVenueType(v.getVenueType());
    }


    ~Venue() {
        delete[] this->location;
    }

    void displayAttribute(string attributeName) {
        if (attributeName == "Location") {
            cout << endl << "Location: " << getLocation() << endl;
        }
        else if (attributeName == "Max No Of Seats") {
            cout << endl <<"Max No Of Seats: " << getMaxNoSeats() << endl;
        }
        else if (attributeName == "No Of Rows") {
            cout << endl <<"No Of Rows: " << getNoRows() << endl;
        }
        else if (attributeName == "No Of Seats Available") {
            cout << endl << "No Of Seats Available: " << getNoAvailiableSeats() << endl;
        }
        else if (attributeName == "Entrance No") {
            cout << endl << "Entrance No: " << getEntranceNo() << endl;
        }
        else if (attributeName == "Max No Of The Entrances") {
            cout << endl << "Max No Of The Entrances: " << getMaxNoEntrances() << endl;
        }
        else if (attributeName == "Venue Type") {
            cout << endl << "Venue Type: " << getVenueType() << endl;
        }
        else {
            cout << endl << "Unknown attribute." << endl;
        }
    }

    bool isVenueAvailable() {
        return (getNoAvailiableSeats() > 0);
    }

    void operator=(const Venue& source) {
        if (&source == this) {
            return;
        }

        delete[] this->location;
        this->location = new char[strlen(source.location) + 1];
        this->setLocation(source.location);
        this->setMaxNoSeats(source.maxNoSeats);
        this->setNoRows(source.noRows);
        this->setNoSeatsAvailable(source.noSeatsAvailable);
        this->setMaxNoEntrances(source.maxNoEntrances);
        this->setEntranceNo(source.entranceNo);
        this->setVenueType(source.venueType);
    }

    void operator+=(int s) {
        if (this->maxNoSeats += s <= 0) {
            throw runtime_error("Provide another value.");
        }
        else {
            this->maxNoSeats += s;
        }
    }

    //postfix 
    Venue operator++(int) {
        Venue copy = *this;
        this->maxNoEntrances += 1;
        return copy;
    }

    //prefix
    Venue operator++() {
        this->maxNoEntrances += 1;
        return *this;
    }

    bool operator!() {
        return getNoAvailiableSeats() == 0; 
    }

    bool operator>=(Venue v) {
        return (this->getNoAvailiableSeats() >= v.noSeatsAvailable);
    }

    bool operator==(Venue v) {
        return (strcmp(this->getLocation(), v.location) == 0);
    }

    friend void operator<<(ostream& console, Venue& v);
    friend void operator>>(istream& console, Venue& v);

    static void ProcessFromFile(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error opening file: " << filename << endl;
            return;
        }

        file.close();
    }

    void displayInformation();

    static void SaveToBinary();
    static void LoadFromBinary();
};

void operator<<(ostream& console, Venue& v) {
    console << endl << "Venue Location: " << v.location;
    console << endl << "Venue Max No Of Seats: " << v.maxNoSeats;
    console << endl << "Venue No Of Rows: " << v.noRows;
    console << endl << "Venue No Of Seats Available: " << v.noSeatsAvailable;
    console << endl << "Venue Max No Of The Entrances: " << v.maxNoEntrances;
    console << endl << "Entrance No: " << v.entranceNo;
    console << endl << "Venue Type: " << v.venueType;
}

void operator>>(istream& console, Venue& v) {
    cout << "Enter the location: ";
    char newLocation[100];   
    console.getline(newLocation, sizeof(newLocation));
    v.setLocation(newLocation);

    cout << "Enter Max No Of Seats: ";
    int maxNoOfSeats;
    console >> maxNoOfSeats;
    v.setMaxNoSeats(maxNoOfSeats);

    cout << "Enter The No Of Rows: ";
    int noRows;
    console >> noRows;
    v.setNoRows(noRows);

    cout << "Enter No Of Seats Available: ";
    int noSeatsAvailable;
    console >> noSeatsAvailable;
    v.setNoSeatsAvailable(noSeatsAvailable);

    cout << "Enter Max No Of Entrances: ";
    int maxNoEntrances;
    console >> maxNoEntrances;
    v.setMaxNoEntrances(maxNoEntrances);

    cout << "Enter The Entrance No: ";
    int entranceNo;
    console >> entranceNo;
    v.setEntranceNo(entranceNo);

    cout << "Enter Venue Type: ";
    string venueType;
    getline(console, venueType);
    v.setVenueType(venueType);
}

class Event {
    char eventDate[11] = "";      // dd/mm/yyyy
    char* eventName = nullptr;
    string eventTime = "";        // hh:mm
    string eventType = "";
    int eventDuration = 0;   //in minutes
    static int TOTAL_EVENTS;
public:
    static int getTotalEvents() {
        return Event::TOTAL_EVENTS;
    }

    void setEventDate(const char* newDate) {
        if (strlen(newDate) != 10) {
            throw runtime_error("Wrong date.");
        }
        if (newDate[2] != '/' || newDate[5] != '/') {
            throw runtime_error("Wrong date format.");
        } 
        strncpy(this->eventDate, newDate, 11);
    }   

    char* getEventDate() {
        char* dateCopy = new char[11];
		strncpy(dateCopy, this->eventDate, 11);
		return dateCopy;
    }

    void setEventName(const char* newName) {
        delete[] this->eventName;
        if (strlen(newName) == 0) {
            throw runtime_error("Provide a name, not an empty string.");
        }
        this->eventName = new char[strlen(newName) + 1];
        strncpy(this->eventName, newName, strlen(newName) + 1);
    }

    char* getEventName() {
        char* nameCopy = new char[strlen(this->eventName) + 1];
		strncpy(nameCopy, this->eventName, strlen(this->eventName) + 1);
		return nameCopy;
    }

    void setEventTime(string newTime) {
        if (strlen(newTime.c_str()) != 5) {
            throw runtime_error("Wrong time.");
        }
        if (newTime[2] != ':') {
            throw runtime_error("Wrong time format.");
        }
        this->eventTime = newTime;
    }

    string getEventTime() {
        return this->eventTime;
    }

    void setEventType(string newType) {
        if (strlen(newType.c_str()) == 0) {
            throw runtime_error("Wrong type was provived.");
        }
        this->eventType = newType;
    }

    string getEventType() {
        return this->eventType;
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
        this->setEventDate("00/00/0000");
        this->setEventName("Unknown");
        this->setEventTime("00:00");
        this->setEventType("Unknown");
        this->setEventDuration(1);
        Event::TOTAL_EVENTS += 1;
    }

    Event (char* eventDate, string eventTime, int eventDuration) {
        this->setEventDate(eventDate);
        this->setEventName("Unknown");
        this->setEventTime(eventTime);
        this->setEventType("Unknown");
        this->setEventDuration(eventDuration);
        Event::TOTAL_EVENTS += 1;
    }

    Event (const char* eventDate, const char* eventName, string eventTime, string eventType, int eventDuration) {
        this->setEventDate(eventDate);
        this->setEventName(eventName);
        this->setEventTime(eventTime);
        this->setEventType(eventType);
        this->setEventDuration(eventDuration);
        Event::TOTAL_EVENTS += 1;
    }

    ~Event() {
        delete[] this->eventName;
        Event::TOTAL_EVENTS -= 1;
    }

    Event(Event& e) : eventName(nullptr) {
        this->setEventDate(e.getEventDate());
        this->setEventName(e.getEventName());
        this->setEventTime(e.getEventTime());
        this->setEventType(e.getEventType());
        this->setEventDuration(e.getEventDuration());
    }

    void displayAttribute(string attributeName) {
        if (attributeName == "Event Name") {
            cout << "Event Name: " << getEventName() << endl;
        }
        if (attributeName == "Event Date") {
            cout << "Event Date: " << getEventDate() << endl;
        }
        if (attributeName == "Event Time") {
            cout << "Event Time: " << getEventTime() << endl;
        }
        if (attributeName == "Event Type") {
            cout << "Event Type: " << getEventType() << endl;
        }
        if (attributeName == "Event Duration") {
            cout << "Event Duration: " << getEventDuration() << " minutes"<< endl;
        }
        if (attributeName == "Total Events") {
            cout << "Total Events: " << Event::TOTAL_EVENTS << endl;
        }
    }

    bool isEventTypeConcert() {
        return (getEventType() == "Concert");
    }

    void operator=(const Event& source) {
        if (&source == this) {
            return;
        }

        delete[] this->eventName;
        this->eventName = new char[strlen(source.eventName) + 1];
        this->setEventName(source.eventName);
        this->setEventDate(source.eventDate);
        this->setEventTime(source.eventTime);
        this->setEventType(source.eventType);
        this->setEventDuration(source.eventDuration);
    }

    void operator-=(int d) {
        if (this->eventDuration -= d <= 0) {
            throw runtime_error("Provide another value.");
        }
        else {
            this->eventDuration -= d;
        }
    }

    //postfix
    Event operator++(int) {
        Event copy = *this;
        this->eventDuration += 1;
        return copy;
    }

    //prefix
    Event operator++() {
        this->eventDuration += 1;
        return *this;
    }

    bool operator!() {
        return getEventDuration() == 0;
    }

    bool operator<=(Event e) {
        return (this->getEventDuration() <= e.eventDuration);
    }

    bool operator==(Event e) {
        return (strcmp(this->getEventDate(), e.eventDate) == 0);
    }

    friend void operator<<(ostream& console, Event& e);
    friend void operator>>(istream& console, Event& e);

    static void ProcessFromFile(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error opening file: " << filename << endl;
            return;
        }

        file.close();
    }

    void displayInformation();

    static void SaveToBinary();
    static void LoadFromBinary();
};

void operator<<(ostream& console, Event& e) {
    console << endl << "Event Name: " << e.getEventName();
    console << endl << "Event Date: " << e.getEventDate();
    console << endl << "Event Time: " << e.eventTime;
    console << endl << "Event Type: " << e.eventType;
    console << endl << "Event Duration: " << e.eventDuration << " minutes.";
}

void operator>>(istream& console, Event& e) {
    cout << "Enter the event name: ";
    char newName[100]; 
    console.getline(newName, sizeof(newName));
    e.setEventName(newName);

    cout << "Enter the event date (dd/mm/yyyy): ";
    char newDate[11];
    console.getline(newDate, sizeof(newDate));
    e.setEventDate(newDate);

    cout << "Enter the event time (hh:mm:ss): ";
    string newTime;
    getline(console, newTime);
    e.setEventTime(newTime);

    cout << "Enter the event type: ";
    string newType;
    getline(console, newType);
    e.setEventType(newType);

    cout << "Enter the event duration (in minutes): ";
    int newDuration;
    console >> newDuration;
    e.setEventDuration(newDuration);
}

int Event::TOTAL_EVENTS = 0;

class Ticket {
    const int ticketId = 0;
    string ticketType = "";
    double ticketPrice = 0;
    char* ticketHolderName = nullptr;
    char purchaseDate[11] = "";
    string purchaseTime = "";
    bool isValid = false;
    static int TOTAL_TICKETS;
public:
    int getTotalTickets() {
        return Ticket::TOTAL_TICKETS;
    }

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

    void setTicketHolderName(const char* newName) {
        delete[] this->ticketHolderName;
        if (strlen(newName) == 0) {
            throw runtime_error("Provide a name, not an empty string.");
        }
        this->ticketHolderName = new char[strlen(newName) + 1];
        strncpy(this->ticketHolderName, newName, strlen(newName) + 1);
    }

    char* getTicketHolderName() {
        char* ticketHolderCopy = new char[strlen(this->ticketHolderName) + 1];
        strncpy(ticketHolderCopy, this->ticketHolderName, strlen(this->ticketHolderName) + 1);
        return ticketHolderCopy;
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
        char* purchaseDateCopy = new char[11];
        strncpy(purchaseDateCopy, this->purchaseDate, 11);
        return purchaseDateCopy;
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

    Ticket() : ticketId(0){
        this->setTicketType("Unknown");
        this->setTicketPrice(1);
        this->setTicketHolderName("Unknown");
        this->setPurchaseDate("00/00/0000");
        this->setPurchaseTime("00:00:00");
        this->setIsValid(false);
        Ticket::TOTAL_TICKETS += 1;
    }

    Ticket(int ticketId, double ticketPrice, bool isValid) : ticketId(ticketId){
        this->setTicketType("Unknown");
        this->setTicketPrice(ticketPrice);
        this->setTicketHolderName("Unknown");
        this->setPurchaseDate("00/00/0000");
        this->setPurchaseTime("00:00:00");
        this->setIsValid(isValid);
        Ticket::TOTAL_TICKETS += 1;
    }

    Ticket(int ticketId, string ticketType, double ticketPrice, const char* ticketHolderName, const char* purchaseDate, string purchaseTime, bool isValid) : ticketId(ticketId){
        this->setTicketType(ticketType);
        this->setTicketPrice(ticketPrice);
        this->setTicketHolderName(ticketHolderName);
        this->setPurchaseDate(purchaseDate);
        this->setPurchaseTime(purchaseTime);
        this->setIsValid(isValid);
        Ticket::TOTAL_TICKETS += 1;
    }

    ~Ticket() {
        delete[] this->ticketHolderName;
        Ticket::TOTAL_TICKETS -= 1;
    }

    Ticket(Ticket& t) : ticketId(t.getTicketId()), ticketHolderName(nullptr) {
        this->setTicketType(t.getTicketType());
        this->setTicketPrice(t.getTicketPrice());
        this->setTicketHolderName(t.getTicketHolderName());
        this->setPurchaseDate(t.getPurchaseDate());
        this->setPurchaseTime(t.getPurchaseTime());
        this->setIsValid(t.getIsValid());
    }

    void displayAttribute(string attributeName) {
        if (attributeName == "Ticket ID") {
            cout << "Ticket ID: " << getTicketId() << endl;
        }
        if (attributeName == "Ticket Price") {
            cout << "Ticket Price: " << getTicketPrice() << endl;
        }
        if (attributeName == "Ticket Holder Name") {
            cout << "Ticket Holder Name: " << getTicketHolderName() << endl;
        }
        if (attributeName == "Ticket Type") {
            cout << "Ticket Type: " << getTicketType() << endl;
        }
        if (attributeName == "Ticket Purchase Date") {
            cout << "Ticket Purchase Date: " << getPurchaseDate() << endl;
        }
        if (attributeName == "Ticket Puchase Time") {
            cout << "Ticket Purchase Time: " << getPurchaseTime() << endl;
        }
        if (attributeName == "Is Ticket Valid") {
            if (getIsValid() == true) {
                cout << "Ticket Is Valid" << endl;
            }
            else {
                cout << "Ticket Is Not Valid" << endl;
            }
        }
        if (attributeName == "Total Tickets") {
            cout << "Total Tickets: " << Ticket::TOTAL_TICKETS << endl;
        }
    }

    bool isTicketVIP() {
        return (getTicketType() == "VIP");
    }

    void operator=(const Ticket& source) {
        if (&source == this) {
            return;
        }

        this->setTicketPrice(source.ticketPrice);
        delete[] this->ticketHolderName;
        this->ticketHolderName = new char[strlen(source.ticketHolderName) + 1];
        this->setTicketHolderName(source.ticketHolderName);
        this->setTicketType(source.ticketType);
        this->setPurchaseDate(source.purchaseDate);
        this->setPurchaseTime(source.purchaseTime);
        this->setIsValid(source.isValid);
    }

    void operator *=(double m) {
        if (m <= 0) {
            throw runtime_error("Provide positive value.");
        }
        else {
            this->ticketPrice *= m;
        }
    }

    //postfix
    Ticket operator++(int) {
        Ticket copy = *this;
        this->ticketPrice += 1;
        return copy;
    }

    //prefix
    Ticket operator++() {
        this->ticketPrice += 1;
        return *this;
    }

    bool operator!() {
        return getTicketPrice() == 0;
    }

    bool operator>=(Ticket t) {
        return (this->getTicketPrice() >= t.ticketPrice);
    }

    bool operator==(Ticket t) {
        return (strcmp(this->getTicketHolderName(), t.ticketHolderName) == 0);
    }

    friend void operator<<(ostream& console, Ticket& t);
    friend void operator>>(istream& console, Ticket& t);

    static void ProcessFromFile(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error opening file: " << filename << endl;
            return;
        }

        file.close();
    }

    void displayInformation();

    static void SaveToBinary();
    static void LoadFromBinary();
};

void operator<<(ostream& console, Ticket& t) {
    console << endl << "Ticket ID: " << t.ticketId;
    console << endl << "Ticket Price: " << t.ticketPrice;
    console << endl << "Ticket Holder Name: " << t.getTicketHolderName();
    console << endl << "Ticket Type: " << t.ticketType;
    console << endl << "Ticket Purchase Date: " << t.getPurchaseDate();
    console << endl << "Ticket Purchase Time: " << t.purchaseTime;
    if (t.isValid == true) {
        console << endl << "Ticket Is Valid";
    }
    else {
        console << endl << "Ticket Is Not Valid";
    }
}

void operator>>(istream& console, Ticket& t) {
    cout << "Enter the ticket price: ";
    double newPrice;
    console >> newPrice;
    t.setTicketPrice(newPrice);

    cout << "Enter the ticket holder name: ";
    string ticketHolderName;
    getline(console >> ws, ticketHolderName);
    while (ticketHolderName.empty()) {
        cout << "Ticket Holder Name cannot be empty. Enter a valid name: ";
        getline(console >> ws, ticketHolderName);
    }
    t.setTicketHolderName(ticketHolderName.c_str());

    cout << "Enter the ticket type: ";
    string newType;
    getline(console, newType);
    t.setTicketType(newType);

    cout << "Enter the purchase date (dd/mm/yyyy): ";
    char newDate[11];
    console.getline(newDate, sizeof(newDate));
    t.setPurchaseDate(newDate);

    cout << "Enter the purchase time (hh:mm:ss): ";
    string newTime;
    getline(console, newTime);
    t.setPurchaseTime(newTime);

    cout << "Is the ticket valid? (1 for true, 0 for false): ";
    bool isValid;
    console >> isValid;
    t.setIsValid(isValid);
}

int Ticket::TOTAL_TICKETS = 0;
