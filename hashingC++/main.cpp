/*
    Orlando Garcia
    Oct-5-25
    Brute force hash cracking demonstration
*/

#include <iostream>
#include <string>
#include <functional> // Required for hashing
#include <chrono> // For timing
using namespace std;



// FUNCTION DECLERATIONS
int menu();
bool isValidLength(string password);
bool isAllLowercase(string password);
string validatedPassword();
size_t hashedPassword(string password);
void crackPassword(size_t target_hash);



int main() {

    // main local variables
    string password;
    size_t target_hash;
    int choice;

    // menu loop
    do {
        choice = menu();
        if (choice == 1) {
            password = validatedPassword();
            target_hash = hashedPassword(password);
            cout << "Hash: " << target_hash << endl;
            cout << "\nAttempting to crack..." << endl;
            crackPassword(target_hash);
    } else if (choice == 2) {
      cout << "Exiting program..." << endl;
    } else {
      cout << "Invalid choice. Please try again." << endl;
    }

  } while (choice != 2);

  return 0;
}



// FUNCTION DEFINITION: code cracker menu selection
int menu() {
    // function local variables
    int choice;
    // menu
    cout << "\n=== Hash Cracking Menu ===" << endl;
    cout << "1. Hash a password and crack it" << endl;
    cout << "2. Exit" << endl;
    cout << "Enter choice: ";
    // selection
    cin >> choice;
    return choice;
}

// FUNCTION DEFINITION: enter password and validate
string validatedPassword()
{
    bool valid = false;
    string password;
    while (!valid) {
        cout << "\nEnter a 4-character password to hash (lowercase letters only): ";
        cin >> password;
        if (isValidLength(password) && isAllLowercase(password)) {
            valid = true;
        } else {
            if (!isValidLength(password)) {
                cout << "Error: Password must be exactly 4 characters long." << endl;
            } else if (!isAllLowercase(password)) {
                cout << "Error: Password must contain only lowercase letters (a-z)." << endl;
            }
            continue;
        }
    }
    return password;
}

// FUNCTION DEFINITION: check password for length
bool isValidLength(string password)
{
    if (password.length() != 4) {
        return false;
    } else {
        return true;
    }
 /* return password.length() == 4; */
}

// FUNCTION DEFINITION: check password for all lowercase
bool isAllLowercase(string password)
{
    for (char c : password) {
        if (c < 'a' || c > 'z') {
            return false;
        }
    }
    return true;
}

// FUNCTION DEFINITION: hash password
size_t hashedPassword(string password)
{
    size_t target_hash;
    hash<string> hasher;
    target_hash = hasher(password);
    return target_hash;
 /* hash<string> hasher;
    return hasher(password); */
}

// FUNCTION DEFINITION: crack password
void crackPassword(size_t target_hash)
{
    hash<string> hasher;
    auto start = chrono::high_resolution_clock::now();
    bool found = false;
    for (char c1 = 'a'; c1 <= 'z' && !found; c1++) {
        for (char c2 = 'a'; c2 <= 'z' && !found; c2++) {
            for (char c3 = 'a'; c3 <= 'z' && !found; c3++) {
                for (char c4 = 'a'; c4 <= 'z' && !found; c4++) {
                    string test = string(1, c1) + string(1, c2) + string(1, c3) + string(1, c4);
      
                    if (hasher(test) == target_hash) {
                        auto end = chrono::high_resolution_clock::now();
                        chrono::duration<double> elapsed = end - start;
        
                        cout << "CRACKED! Password: " << test << endl;
                        cout << "Time: " << elapsed.count() << " seconds" << endl;
                        found = true;
                    }
                }
            }
        }
    }
}
