#include "classes.cpp"
#include <iostream>

int main() {
    int key;
    cout << "WELCOME TO THE MENU!\n";
    cout << "1. Enter data from the console\n";
    cout << "2. Read data from a text file\n";
    cout << "3. Exit\n";

    cout << "Enter your choice: ";
    cin >> key;

    switch (key) {
        case 1:
            EnterDataFromConsole();
            break;
        case 2:
            char* filename;
            cout << "Provide the name of the file: ";
            cin >> filename;
            ReadDataFromTextFile(filename);
            break;
        case 3:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice.\n";
            break;
    }

    return 0;
}