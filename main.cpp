#include "classes.cpp"
#include <iostream>

void DisplayMenu() {
    cout << "1. Add a new ticket\n";
    cout << "2. Display all tickets\n";
    cout << "3. Save tickets to binary file\n";
    cout << "4. Load tickets from binary file\n";
    cout << "5. Exit\n";
}

int main(int argc, char* argv[]) {

    if (argc > 1) {
        const string filename(argv[1]);
    }
    else {
        int choice;

        do {
            DisplayMenu();
            cout << "Enter your choice: ";

            while(!(cin>>choice) || choice < 1 || choice > 5) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Invald choice. Enter a number between 1 and 5: ";
            }

            switch(choice) {
                case 1: {
                    Ticket newTicket;
                    break;
                }
                case 2: {
                    break;
                }
                case 3: {
                    cout << "Tickets saved to binary file.\n";
                    break;
                }
                case 4: {
                    cout << "Tickets loaded from binary file.\n";
                    break;
                }
                case 5: {
                    cout << "Exiting program.\n";
                    break;
                }
                default: {
                    cout << "Invalid choice.\n";
                }
            }
        } while (choice != 5);
    }
}