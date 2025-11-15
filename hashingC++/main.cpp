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

// DECLERATION: code cracker menu selection
void menu(int choice);

int main() {

  // variables
  string password;
  size_t target_hash;
  hash<string> hasher;
  int choice;

  //------------------------------------

  // Menu loop
  do {
      void menu(choice);

    // option 1
    if (choice == 1) {
      bool valid = false; // set
      while (!valid) {
        cout << "\nEnter a 4-character password to hash (lowercase letters only): ";
        cin >> password;
        
        if (password.length() != 4) {
          cout << "Error: Password must be exactly 4 characters long." << endl;
          continue;
        }
        
        // Check if all characters are lowercase letters
        valid = true;
        for (char c : password) {
          if (c < 'a' || c > 'z') {
            cout << "Error: Password must contain only lowercase letters (a-z)." << endl;
            valid = false;
            break;
          }
        }
      }

      // hash it
      target_hash = hasher(password);
      cout << "Hash: " << target_hash << endl;

      //------------------------------------
      
      // Brute force cracking
      cout << "\nAttempting to crack..." << endl;
      
      auto start = chrono::high_resolution_clock::now(); // Start timer
      bool found = false;
      
      // Try all 4-character combinations (a-z lowercase)
      for (char c1 = 'a'; c1 <= 'z' && !found; c1++) {
        for (char c2 = 'a'; c2 <= 'z' && !found; c2++) {
          for (char c3 = 'a'; c3 <= 'z' && !found; c3++) {
            for (char c4 = 'a'; c4 <= 'z' && !found; c4++) {
              string test = string(1, c1) + string(1, c2) + string(1, c3) + string(1, c4);
              
              if (hasher(test) == target_hash) {
                auto end = chrono::high_resolution_clock::now(); // End timer
                chrono::duration<double> elapsed = end - start;
                
                cout << "CRACKED! Password: " << test << endl;
                cout << "Time: " << elapsed.count() << " seconds" << endl;
                found = true;
              }
            }
          }
        }
      }
    } else if (choice == 2) {
      cout << "Exiting program..." << endl;
    } else {
      cout << "Invalid choice. Please try again." << endl;
    }

  } while (choice != 2);

  return 0;
}

// DEFINITION: code cracker menu selection
void menu(int choice) {
    cout << "\n=== Hash Cracking Menu ===" << endl;
    cout << "1. Hash a password and crack it" << endl;
    cout << "2. Exit" << endl;
    cout << "Enter choice: ";
    cin >> choice;
}
