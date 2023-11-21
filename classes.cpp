#include <iostream>
#include <string>

using namespace std;

class Venue {
    string location = "";
    int maxNoSeats = 0;
    int noSeatsAvailiable = 0;
    int noRows = 0;
public:
    void setLocation(string location) {
        this->location = location;
    }

    string getLoctaion() {
        return this->location;
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

    void setNoAvailiableSeats(int seats) {
        if (seats < 0) {
            throw runtime_error("Provide a positive number.");
        } 
        else {
            this->noSeatsAvailiable = seats;
        }
    }

    int getNoAvailiableSeats() {
        return this->noSeatsAvailiable;
    }
    void setNoRows(int rows) {
        this->noRows = rows;
    }

    int getNoRows() {
        return this->noRows;
    }

    Venue() {
        this->setLocation("Unknown");
        this->setNoRows(1);
        this->setMaxNoSeats(1);
        this->setNoAvailiableSeats(1);
    }

    Venue(string location, int maxNoSeats, int noRows) : location(location), maxNoSeats(maxNoSeats), noRows(noRows) {
        this->setLocation(location);
        this->setMaxNoSeats(maxNoSeats);
        this->setNoAvailiableSeats(maxNoSeats);
        this->setNoRows(noRows);
    }
    ~Venue() {

    }
};


class Event {
    char date[11] = "";
    char* name = nullptr;
    string time = "";
public:
    void setDate(char date[11]) {

    }

    char* getDate() {
        char* dateCopy = new char[strlen(this->date) + 1];
		strncpy(dateCopy, this->date, strlen(this->date) + 1);
		return dateCopy;
    }

    void setName(char* name) {
        delete[] this->name;
    }

    char* getName() {
        char* nameCopy = new char[strlen(this->name) + 1];
		strncpy(nameCopy, this->name, strlen(this->name) + 1);
		return nameCopy;
    }

    void setTime(string time) {

    }

    string getTime() {
        return this->time;
    }

    Event() {

    }

    ~Event() {

    }
};

class Ticket {

};

class Menu {

};

int main() {

}