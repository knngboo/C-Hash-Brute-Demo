/*
    Orlando Garcia
    Oct-5-25
    Brute force hash cracking demonstration
*/
#include <iostream>
#include <string>
#include "functions.h"

using namespace std;

// MAIN FUNCTION
int main() {

    // main local variables
    int choice;
    string password = "d3mo!";
    size_t passwordLength = password.length();
    size_t hashValue;

    // menu loop
    do {
        // display menu
        choice = menu(password);
        
        if (choice == 1) {
            cout << "Current password: " << password << endl;
            cout << "Password length: " << passwordLength << endl;
            
            // enter/change password
            password = enterPassword();
            passwordLength = password.length();

        } else if (choice == 2) {
            // brute force password
            cout << "----------------------------------" << endl;
            cout << "Option 2: Brute forcing a password." << endl;
            hashValue = hashedPassword(password);
            cout << "Your password's hashed value: " << hashValue << endl;
            cout << "Attempting a brute force attack..." << endl;
            bruteForce(hashValue, passwordLength);
            
        } else if (choice == 3) {
            // dictionary attack password
            cout << "----------------------------------" << endl;
            cout << "Option 3: Dictionary attack." << endl;
            hashValue = hashedPassword(password);
            cout << "Your password's hashed value: " << hashValue << endl;
            cout << "Attempting a dictionary attack..." << endl;
            dictionaryAttack(hashValue, "");
            
        } else if (choice == 4) {
            // compare password variants
            cout << "----------------------------------" << endl;
            cout << "Option 4: Compare password variants" << endl;
            cout << "Feature coming soon!" << endl;
            
        } else if (choice == 5) {
            // challenge mode
            cout << "----------------------------------" << endl;
            cout << "Option 5: Challenge mode" << endl;
            cout << "Feature coming soon!" << endl;
            
        } else if (choice == 6) {
            cout << "Exiting program..." << endl;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 6);

    return 0;
}

