//
//  functions.cpp
//  hashingC++
//
//  Created by King Boo on 11/17/25.
//
#include "functions.h"

// Menu: code cracker menu selection
int menu(string password)
{
    // function local variables
    int choice;
    // menu
    cout << "\n=== Password Cracking Demo Menu ===" << endl;
    cout << "1. Enter/Change password (Current password: " << password << ")" << endl;
    cout << "2. Brute force current password" << endl;
    cout << "3. Dictionary attack current password" << endl;
    cout << "4. Compare password variants" << endl;
    cout << "5. Challenge mode (TBD)" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter choice: ";
    // selection
    cin >> choice;
    return choice;
}

// FUNCTION DEFINITION: hash password
size_t hashed(string password)
{
    size_t target_hash;
    hash<string> hasher;
    target_hash = hasher(password);
    return target_hash;
 /* hash<string> hasher;
    return hasher(password); */
}



// choice 1: enter/change password
string enterPassword()
{
    string password;
    bool valid = false;
    do {
        cout << "Enter new password: ";
        cin >> password;
        //---
        if (password.length() < 4 || password.length() > 5) {
            cout << "Error: Must be 4 or 5 characters long. Try again." << endl;
            continue;
        }
        //---
        
        //---
        bool allValid = true;
        for (char c : password) {
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || (c == '!' || c == '@' || c == '#' || c == '$')) {
                // do nothing, keep checking
            } else {
                cout << "Error: Invalid character found" << endl;
                allValid = false;
                break;
            }
        }
        //---
        
        //---
        if (allValid == true) {
            valid = true;
        }
        //---
    } while (valid != true);
    return password;
}

// choice 2: brute force a password (a-z, A-Z, 0-9, !@#$%^&*()-_+=)
size_t hashedPassword(string password)
{
    size_t hashValue;
    hash<string> hasher;
    hashValue = hasher(password);
    
    return hashValue;
}
void bruteForce(size_t hashValue, size_t passwordLength)
{
    hash<string> hasher;
    size_t hashTest;
    bool found = false;
    string testCharacters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$";
    if (passwordLength == 4) {
        cout << "Trying 4-char passwords..." << endl;
        // test 4 character password
        for (char c1 : testCharacters) {
            if (found) break;
            for (char c2 : testCharacters) {
                if (found) break;
                for (char c3 : testCharacters) {
                    if (found) break;
                    for (char c4 : testCharacters) {
                        string testPassword = string(1, c1) + string(1, c2) + string(1, c3) + string(1, c4);
                        hashTest = hasher(testPassword);
                        if (hashValue == hashTest) {
                            cout << "CRACKED! Hashed password: " << hashTest << endl;
                            found = true;
                            break;
                        }
                    }
                }
            }
        }
    } else if (passwordLength == 5) {
        cout << "Trying 5-char passwords..." << endl;
        // test 5 character password
        for (char c1 : testCharacters) {
            if (found) break;
            for (char c2 : testCharacters) {
                if (found) break;
                for (char c3 : testCharacters) {
                    if (found) break;
                    for (char c4 : testCharacters) {
                        if (found) break;
                        for (char c5 : testCharacters) {
                            string testPassword = string(1, c1) + string(1, c2) + string(1, c3) + string(1, c4) + string(1, c5);
                            hashTest = hasher(testPassword);
                            if (hashValue == hashTest) {
                                cout << "----------------------------------" << endl;
                                cout << "CRACKED! Hashed password: " << hashTest << endl;
                                found = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
    } else {
        cout << "----------------------------------" << endl;
        cout << "Failed to crack password. Congratulations: You beat the system!" << endl;
    }

}
