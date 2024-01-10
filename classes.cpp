#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Venue {
    int nr_seats;
	int nr_rows;
	string zones;
	int nrOfSeatsPerRow;
	bool** seats;
public:
    static const int MIN_SEATS = 5;
	static int totalLocations;
    // Default constructor
	Venue() {

		nr_seats = 0;
		nr_rows = 0;
		zones = "";
		nrOfSeatsPerRow = 0;
		seats = nullptr;

		totalLocations++;
	}

	//constructor with parameters
	Venue(int nr_seats, int nr_rows, string zones, int nrOfSeatsPerRow) {
		this->nr_seats = nr_seats;

		this->nr_rows = nr_rows;

		this->zones = zones;

        this->seats = new bool* [nr_rows];
		for (int i = 0; i < nr_rows; ++i) {
			seats[i] = new bool[nr_seats];
			for (int j = 0; j < nr_seats; ++j) {
				seats[i][j] = false; // Initialize seats as unbooked 
			}
		}

		this->nrOfSeatsPerRow = nrOfSeatsPerRow;

	}

    //copy constructor
	Venue(const Venue& other) {

		this->nr_seats = other.nr_seats;
		this->nr_rows = other.nr_rows;

		this->zones = other.zones;

		this->nrOfSeatsPerRow = other.nrOfSeatsPerRow;

	}

    //destructor
	~Venue() {
		
		for (int i = 0; i < nr_rows; ++i) {
			delete[] seats[i];
		}
		delete[] seats;

		totalLocations--;
	}

    //getters
	int getnr_seats() {
		return this->nr_seats;
	}

	int getnr_rows() {
		return this->nr_rows;
	}

	string getzones() {
		return this->zones;
	}

	int getnrOfSeatsPerRow() {
		return this->nrOfSeatsPerRow;
	}

    //setters

	virtual void setnr_seats(int x) {
		if (x > 0) {
			nr_seats = x; 
		}
		else {
			cout << "Invalid number of seats!" << endl;
		}
		
	}

	void setnr_rows(int n) {
		if (n > 0) {
			nr_rows = n;
		}
		else {
			cout << "Invalid number of rows!" << endl;

		}
	}

    void setzones(string newzone)
	{
		if (!this->zones.empty()) {
			this->zones = newzone;
		}
		else {
			cout << "Invalid!" << endl;
		}
	}

	void setnrOfSeatsPerRow(int n) {
		if (n > 0) {
			nrOfSeatsPerRow = n;
		}
		else {
			cout << "Invalid number of rows!" << endl;

		}
	}

    //overloading operator +=
	Venue& operator+=(int addSeats) {
		if (addSeats > 0) {
			nr_seats += addSeats;
		}
		else {
			throw runtime_error("Invalid number of additional seats!");
		}
		return *this;
	}

	//overloading operator-=
	Venue& operator-=(int removeSeats) {
		if (removeSeats > 0) {
			nr_seats -= removeSeats;
		}
		else {
			throw runtime_error("Invalid number of additional seats!");
		}
		return *this;
	}

	// Static method to get total locations
	static int getTotalLocations() {
		return totalLocations;
	}

    // Method to book a specific seat
	bool bookSpecificSeat(int row, int seat) {
		if (row >= 0 && row < nr_rows && seat >= 0 && seat < nr_seats) {
			if (!seats[row][seat]) {
				seats[row][seat] = true; // Book the seat
				return true; // Successfully booked
			}
			else {
				return false; // Seat already booked
			}
		}
		else {
			return false; // Invalid row or seat
		}
	}

	// Method to check if a specific seat is booked
	bool isSeatBooked(int row, int seat) {
		if (row >= 0 && row < nr_rows && seat >= 0 && seat < nr_seats) {
			return seats[row][seat];
		}
		else {
			return false; // Invalid row or seat
		}
	}

    // Overloading  operator <<
	friend ostream& operator<<(ostream& console, const Venue& ven) {
		console << "Number of seats: " << ven.nr_seats << "\nNumber of rows: " << ven.nr_rows << "\nZones: " << ven.zones << "\nNumber of seats per row: " << ven.nrOfSeatsPerRow;
		return console;
	}

    // Overloading  operator >>
	friend istream& operator>>(istream& console, Venue& ven) {
		int seats, rows, seatsPerRow;
		string zones;

		cout << "Enter number of seats: ";
		console >> seats;
		ven.setnr_seats(seats);

		cout << "Enter number of rows: ";
		console >> rows;
		ven.setnr_rows(rows);

		cout << "Enter zones: ";
		console >> zones;
		ven.setzones(zones);

		cout << "Enter number of seats per row: ";
		console >> seatsPerRow;
		ven.setnrOfSeatsPerRow(seatsPerRow);

		ven.seats = new bool* [rows];
		for (int i = 0; i < rows; ++i) {
			ven.seats[i] = new bool[seats];
			for (int j = 0; j < seats; ++j) {
				ven.seats[i][j] = false; // Initialize seats as unbooked
			}
		}

		return console;
	}
};

int Venue::totalLocations = 0;

class Event {
    char eventDate[11];      // dd/mm/yyyy
    string eventName;
    string eventTime;        // hh:mm
    int eventDuration;   //in minutes
    static int TOTAL_EVENTS;
public:
    static int getTotalEvents() {
        return Event::TOTAL_EVENTS;
    }

    //setters
    void setEventDate(const char* newDate) {
        if (strlen(newDate) != 10) {
            throw runtime_error("Wrong date.");
        }
        if (newDate[2] != '/' || newDate[5] != '/') {
            throw runtime_error("Wrong date format.");
        } 
        strncpy(this->eventDate, newDate, 11);
    }   

    void setEventName(const string& newName) {
        if (newName.empty()) {
            throw runtime_error("Provide a name, not an empty string.");
        }

        this->eventName = newName;
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

    void setEventDuration(int newDuration) {
        if (newDuration <= 0) {
            throw runtime_error("Provide a positive number.");
        }
        else {
            this->eventDuration = newDuration;
        }
    }

    //getters
    char* getEventDate() {
        char* dateCopy = new char[11];
		strncpy(dateCopy, this->eventDate, 11);
		return dateCopy;
    }

    string getEventName() {
		return this->eventName;
    }

    string getEventTime() {
        return this->eventTime;
    }

    int getEventDuration() {
        return this->eventDuration;
    }

    Event() {
        this->setEventDate("00/00/0000");
        this->setEventName("Unknown");
        this->setEventTime("00:00");
        this->setEventDuration(1);
        Event::TOTAL_EVENTS += 1;
    }

    Event (string eventName, const char* eventDate, string eventTime, int eventDuration) {
        this->setEventName(eventName);
        this->setEventDate(eventDate);
        this->setEventTime(eventTime);
        this->setEventDuration(eventDuration);
        Event::TOTAL_EVENTS += 1;
    }

    ~Event() {
        Event::TOTAL_EVENTS -= 1;
    }

    Event(Event& e) {
        this->setEventName(e.getEventName());
        this->setEventDate(e.getEventDate());
        this->setEventName(e.getEventName());
        this->setEventTime(e.getEventTime());
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
        if (attributeName == "Event Duration") {
            cout << "Event Duration: " << getEventDuration() << " minutes"<< endl;
        }
        if (attributeName == "Total Events") {
            cout << "Total Events: " << Event::TOTAL_EVENTS << endl;
        }
    }

    void operator=(const Event& source) {
        if (&source == this) {
            return;
        }

        this->setEventName(source.eventName);
        this->setEventDate(source.eventDate);
        this->setEventTime(source.eventTime);
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

    friend ostream& operator<<(ostream& console, Event& e);
    friend istream& operator>>(istream& console, Event& e);
};

ostream& operator<<(ostream& console, Event& e) {
    console << endl << "Event Name: " << e.getEventName();
    console << endl << "Event Date: " << e.getEventDate();
    console << endl << "Event Time: " << e.eventTime;
    console << endl << "Event Duration: " << e.eventDuration << " minutes";
    
    return console;
}

istream& operator>>(istream& console, Event& e) {
    cout << "Enter the event name: ";
    string newName;
    getline(console >> ws, newName);

    try {
        e.setEventName(newName);
    } catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
    }

    cout << "Enter the event date (dd/mm/yyyy): ";
    char newDate[11];
    console.getline(newDate, sizeof(newDate));
    e.setEventDate(newDate);

    cout << "Enter the event time (hh:mm): ";
    string newTime;
    getline(console, newTime);
    e.setEventTime(newTime);

    cout << "Enter the event duration (in minutes): ";
    int newDuration;
    console >> newDuration;
    e.setEventDuration(newDuration);

    return console;
}

int Event::TOTAL_EVENTS = 0;

class Ticket {
    int ticketId = 0;
    double ticketPrice = 0;
    string ticketHolderName = "";
    string purchaseDate = "";
    string purchaseTime = "";
    static int TOTAL_TICKETS;
public:
    int generateID() {
        srand(static_cast<unsigned int>(time(0)));
		return rand() % 10000 + 1000; // Generate a random number between 1000 and 9999
    }

    int getTotalTickets() const{
        return Ticket::TOTAL_TICKETS;
    }

    //getters
    int getTicketId() const{
        return this->ticketId;
    }

    double getTicketPrice() const{
        return this->ticketPrice;
    }

    string getTicketHolderName() const{
        return this->ticketHolderName;
    }

    string getPurchaseDate() const{
        return this->purchaseDate;
    }

    string getPurchaseTime() const{
        return this->purchaseTime;
    }

    //setters
    void setTicketID(int id) {
        this->ticketId = id;
    }
    void setTicketPrice(double price) {
        if (price <= 0) {
            throw runtime_error("Provide a positive value for the ticket");
        }
        else {
            this->ticketPrice = price;
        }
    }

    void setTicketHolderName(string newName) {
        this->ticketHolderName = newName;
    }

    void setPurchaseDate(string newDate) {
        this->purchaseDate = newDate;
    }

    void setPurchaseTime(string newTime) {
        this->purchaseTime = newTime;
    }


    Ticket() {
        this->setTicketID(this->generateID());
        this->setTicketPrice(1);
        this->setTicketHolderName("Unknown");
        this->setPurchaseDate("00/00/0000");
        this->setPurchaseTime("00:00:00");
        Ticket::TOTAL_TICKETS += 1;
    }

    Ticket(int ticketId, double ticketPrice, string ticketHolderName, string purchaseDate, string purchaseTime) {
        this->setTicketID(ticketId);
        this->setTicketPrice(ticketPrice);
        this->setTicketHolderName(ticketHolderName);
        this->setPurchaseDate(purchaseDate);
        this->setPurchaseTime(purchaseTime);
        Ticket::TOTAL_TICKETS += 1;
    }

    ~Ticket() {
        Ticket::TOTAL_TICKETS -= 1;
    }

    Ticket(Ticket& t) : ticketId(t.getTicketId()), ticketHolderName(nullptr) {
        this->setTicketPrice(t.getTicketPrice());
        this->setTicketHolderName(t.getTicketHolderName());
        this->setPurchaseDate(t.getPurchaseDate());
        this->setPurchaseTime(t.getPurchaseTime());
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
        if (attributeName == "Ticket Purchase Date") {
            cout << "Ticket Purchase Date: " << getPurchaseDate() << endl;
        }
        if (attributeName == "Ticket Puchase Time") {
            cout << "Ticket Purchase Time: " << getPurchaseTime() << endl;
        }
        if (attributeName == "Total Tickets") {
            cout << "Total Tickets: " << Ticket::TOTAL_TICKETS << endl;
        }
    }

    void operator=(const Ticket& source) {
        if (&source == this) {
            return;
        }

        this->setTicketPrice(source.ticketPrice);
        this->setTicketHolderName(source.ticketHolderName);
        this->setPurchaseDate(source.purchaseDate);
        this->setPurchaseTime(source.purchaseTime);
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

    friend ostream& operator<<(ostream& console, Ticket& t);
    friend istream& operator>>(istream& console, Ticket& t);

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

ostream& operator<<(ostream& console, Ticket& t) {
    console << endl << "Ticket ID: " << t.ticketId;
    console << endl << "Ticket Price: " << t.ticketPrice;
    console << endl << "Ticket Holder Name: " << t.getTicketHolderName();
    console << endl << "Ticket Purchase Date: " << t.getPurchaseDate();
    console << endl << "Ticket Purchase Time: " << t.purchaseTime;

    return console;
}

istream& operator>>(istream& console, Ticket& t) {
    cout << "Enter the ticket price: ";
    console >> t.ticketPrice;

    cout << "Enter the ticket holder name: ";
    getline(console >> ws, t.ticketHolderName);
    while (t.ticketHolderName.empty()) {
        cout << "Ticket Holder Name cannot be empty. Enter a valid name: ";
        getline(console >> ws, t.ticketHolderName);
    }

    cout << "Enter the purchase date (dd/mm/yyyy): ";
    getline(console >> ws, t.purchaseDate);

    cout << "Enter the purchase time (hh:mm:ss): ";
    getline(console >> ws, t.purchaseTime);

    return console;
}

int Ticket::TOTAL_TICKETS = 0;

void EnterDataFromConsole() {
    int seats, rows, seatsPerRow;
    string zones;

    cout << "-------------------------------" << endl;
    cout << "ENTER VENUE DETAILS " << endl;
    cout << "-------------------------------" << endl;

    cout << "Enter number of seats: ";
    cin >> seats;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter zones: ";
    cin.ignore();
    getline(cin, zones);

    cout << "Enter number of seats per row: ";
    cin >> seatsPerRow;

    Venue v(seats, rows, zones, seatsPerRow);

    cout << "-------------------------------" << endl;
    cout << "[ VENUE DETAILS ]\n" << v << endl;
    cout << "-------------------------------" << endl;

    cout << "-------------------------------" << endl;
    cout << "CHOOSE YOUR ROW AND YOUR SEAT! " << endl;
    cout << "-------------------------------" << endl;
	//  Booking specific seats
	int rowToBook, seatToBook;

	cout << "Enter row number you want to book: ";
	cin >> rowToBook;

	cout << "Enter seat number you want to book: ";
	cin >> seatToBook;

	// Book the specified seat using bool** seats
	if (v.bookSpecificSeat(rowToBook, seatToBook)) {
		cout << "ROW " << rowToBook << " SEAT " << seatToBook << " successfully booked!" << endl;
	}
	else {
		cout << "ROW " << rowToBook << " SEAT " << seatToBook << " is already booked!" << endl;
	}

    // Check if a seat is booked
	int rowToCheck, seatToCheck;

	cout << "\nEnter another row number to check if it's available: ";
	cin >> rowToCheck;

    cout << "Enter another seat number to check if it's available: ";
	cin >> seatToCheck;

	// Check if the specified seat is booked
	if (v.isSeatBooked(rowToCheck, seatToCheck)) {
		cout << "Row " << rowToCheck << " Seat " << seatToCheck << " is already booked." << endl;
	}
	else {
		cout << "Row " << rowToCheck << " Seat " << seatToCheck << " is available." << endl;
	}

    cout << "-------------------------------" << endl;
    cout << "ENTER THE EVENT DETAILS" << endl;
    cout << "-------------------------------" << endl;
    Event event;

    cin >> event;

    cout << "-------------------------------" << endl;
    cout << "ENTER THE TICKET DETAILS!" << endl;
    cout << "-------------------------------" << endl;
    Ticket ticket;

    cout << "Enter the ticket price: ";
    double ticketPrice;
    cin >> ticketPrice;
    ticket.setTicketPrice(ticketPrice);

    cout << "Enter the ticket holder name: ";
    string ticketHolderName;
    getline(cin >> ws, ticketHolderName);
    ticket.setTicketHolderName(ticketHolderName);

    cout << "Enter the purchase date (dd/mm/yyyy): ";
    char purchaseDate[11];
    cin.ignore();  
    cin.getline(purchaseDate, sizeof(purchaseDate));
    ticket.setPurchaseDate(purchaseDate);

    cout << "Enter the purchase time (hh:mm:ss): ";
    string purchaseTime;
    getline(cin, purchaseTime);
    ticket.setPurchaseTime(purchaseTime);

    cout << "-------------------------------" << endl;
    cout << "[ TICKET DETAILS ]" << endl; 
    cout << "-------------------------------" << endl;
    cout << event << endl;

    cout << ticket << endl;

	cout << "Seat: " << seatToBook << endl;
	cout << "Row: " << rowToBook << endl;


}

void ReadDataFromTextFile(const char* filename) {
    ifstream inFile(filename, ios::in);

    if (inFile.is_open()) {
        // Read data for Venue
        int nr_seats, nr_rows, nrOfSeatsPerRow;
        string zones;
        inFile >> nr_seats >> nr_rows >> zones >> nrOfSeatsPerRow;
        Venue venue(nr_seats, nr_rows, zones, nrOfSeatsPerRow);

        // Read data for Event
        char eventDate[11];
        char eventName[100];
        string eventTime;
        int eventDuration;
        inFile >>  eventName >> eventDate >> eventTime >> eventDuration;
        Event event;
        event.setEventName(eventName);
        event.setEventDate(eventDate);
        event.setEventTime(eventTime);
        event.setEventDuration(eventDuration);

        // Read data for Ticket
        int ticketId;
        double ticketPrice;
        string ticketHolderName;
        string purchaseDate;
        string purchaseTime;
        inFile >> ticketId >> ticketPrice >> ticketHolderName >> purchaseDate >> purchaseTime;
        Ticket ticket(ticketId, ticketPrice, ticketHolderName, purchaseDate, purchaseTime);

        // Display read data
        cout << "[ VENUE DETAILS ]\n" << venue << endl;
        cout << "[ EVENT DETAILS ]\n" << event << endl;
        cout << "[ TICKET DETAILS ]\n" << ticket << endl;

        inFile.close();
    } else {
        cout << "Unable to open file for reading." << endl;
    }
}

