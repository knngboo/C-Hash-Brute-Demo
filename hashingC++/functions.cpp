//
//  functions.cpp
//  hashingC++
//
//  Created by King Boo on 11/17/25.
//
#include "functions.h"

// MENU FUNCTION
// Displays the main menu and returns user's choice
int menu(string password)
{
    int choice;
    cout << "\n=== Password Cracking Demo Menu ===" << endl;
    cout << "1. Enter/Change password (Current password: " << password << ")" << endl;
    cout << "2. Brute force current password" << endl;
    cout << "3. Dictionary attack current password" << endl;
    cout << "4. Compare password variants" << endl;
    cout << "5. Challenge mode (TBD)" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter choice: ";
    cin >> choice;
    return choice;
}

// ENTER/CHANGE PASSWORD FUNCTION
// Prompts user to enter a password and validates it
// Valid passwords: 4-5 chars, letters/numbers/!@#$ only
string enterPassword()
{
    string password;
    bool valid = false;
    
    do {
        cout << "Enter new password: ";
        cin >> password;
        
        // Check length (must be 4 or 5 characters)
        if (password.length() < 4 || password.length() > 5) {
            cout << "Error: Must be 4 or 5 characters long. Try again." << endl;
            continue;
        }
        
        // Check each character is valid (a-z, A-Z, 0-9, !@#$)
        bool allValid = true;
        for (char c : password) {
            if ((c >= 'a' && c <= 'z') ||
                (c >= 'A' && c <= 'Z') ||
                (c >= '0' && c <= '9') ||
                (c == '!' || c == '@' || c == '#' || c == '$')) {
                // Valid character, continue checking
            } else {
                cout << "Error: Invalid character found. Only a-z, A-Z, 0-9, !@#$ allowed." << endl;
                allValid = false;
                break;
            }
        }
        
        // If all checks pass, password is valid
        if (allValid) {
            valid = true;
        }
        
    } while (!valid);
    
    return password;
}

// HASH PASSWORD FUNCTION
// Takes a password string and returns its hash value
size_t hashedPassword(string password)
{
    hash<string> hasher;
    size_t hashValue = hasher(password);
    return hashValue;
}

// BRUTE FORCE ATTACK FUNCTION
// Tries all possible combinations of characters to crack the hash
// Parameters:
//   hashValue - the target hash to crack
//   passwordLength - length of password (4 or 5)
void bruteForce(size_t hashValue, size_t passwordLength)
{
    // Start timer
    auto start = high_resolution_clock::now();
    
    // Initialize variables
    hash<string> hasher;
    size_t hashTest;
    bool found = false;
    
    // Character set: lowercase, uppercase, digits, special chars
    string testCharacters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$";
    
    // Handle 4-character passwords
    if (passwordLength == 4) {
        cout << "Trying 4-char passwords..." << endl;
        
        // Nested loops try every combination
        // Total combinations: 66^4 = 18,974,736
        for (char c1 : testCharacters) {
            if (found) break;
            for (char c2 : testCharacters) {
                if (found) break;
                for (char c3 : testCharacters) {
                    if (found) break;
                    for (char c4 : testCharacters) {
                        // Build test password
                        string testPassword = string(1, c1) + string(1, c2) +
                                            string(1, c3) + string(1, c4);
                        
                        // Hash and compare
                        hashTest = hasher(testPassword);
                        if (hashValue == hashTest) {
                            // Password found! Stop timer and display results
                            auto end = high_resolution_clock::now();
                            auto duration_ms = duration_cast<milliseconds>(end - start);
                            
                            cout << "----------------------------------" << endl;
                            cout << "CRACKED! Password: " << testPassword << endl;
                            cout << "Hashed value: " << hashTest << endl;
                            cout << "Time: " << duration_ms.count() << " milliseconds" << endl;
                            found = true;
                            break;
                        }
                    }
                }
            }
        }
    }
    // Handle 5-character passwords
    else if (passwordLength == 5) {
        cout << "Trying 5-char passwords..." << endl;
        
        // Total combinations: 66^5 = 1,252,332,576
        for (char c1 : testCharacters) {
            if (found) break;
            for (char c2 : testCharacters) {
                if (found) break;
                for (char c3 : testCharacters) {
                    if (found) break;
                    for (char c4 : testCharacters) {
                        if (found) break;
                        for (char c5 : testCharacters) {
                            // Build test password
                            string testPassword = string(1, c1) + string(1, c2) +
                                                string(1, c3) + string(1, c4) +
                                                string(1, c5);
                            
                            // Hash and compare
                            hashTest = hasher(testPassword);
                            if (hashValue == hashTest) {
                                // Password found! Stop timer and display results
                                auto end = high_resolution_clock::now();
                                auto duration_ms = duration_cast<milliseconds>(end - start);
                                
                                cout << "----------------------------------" << endl;
                                cout << "CRACKED! Password: " << testPassword << endl;
                                cout << "Hashed value: " << hashTest << endl;
                                cout << "Time: " << duration_ms.count() << " milliseconds" << endl;
                                found = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    // Handle invalid lengths
    else {
        cout << "----------------------------------" << endl;
        cout << "Password length not supported." << endl;
    }
    
    // If password wasn't found
    if (!found) {
        auto end = high_resolution_clock::now();
        auto duration_ms = duration_cast<milliseconds>(end - start);
        cout << "----------------------------------" << endl;
        cout << "Failed to crack password." << endl;
        cout << "Time spent: " << duration_ms.count() << " milliseconds" << endl;
    }
}

// DICTIONARY ATTACK FUNCTION
// Tries common passwords from a file to crack the hash
// Parameters:
//   hashValue - the target hash to crack
//   filename - path to dictionary file (one password per line)
void dictionaryAttack(size_t hashValue, string filename)
{
    // Hardcoded dictionary - no file needed!
    vector<string> dictionary = {
        "pass", "test", "demo", "user", "admin", "love", "help", "baby",
        "king", "star", "cool", "blue", "fire", "dark", "moon", "code",
        "Pass", "Test", "Demo", "User", "Admin", "Pass1", "Test1", "Demo1",
        "P@ss", "T3st", "D3mo", "Us3r", "Adm1n", "Pass!", "Test!", "Demo!",
        "pass1", "test1", "demo1", "user1", "Code1", "Data1", "d3mo!"
    };
    
    cout << "Loading dictionary (" << dictionary.size() << " passwords)..." << endl;
    
    // Initialize variables
    hash<string> hasher;
    int attempts = 0;
    bool found = false;
    
    // Start timer
    auto start = high_resolution_clock::now();
    
    // Try each password in dictionary
    for (string password : dictionary) {
        attempts++;
        
        // Hash the password
        size_t hashTest = hasher(password);
        
        // Compare with target hash
        if (hashTest == hashValue) {
            auto end = high_resolution_clock::now();
            auto duration_ms = duration_cast<milliseconds>(end - start);
            
            cout << "----------------------------------" << endl;
            cout << "CRACKED! Password: " << password << endl;
            cout << "Hashed value: " << hashTest << endl;
            cout << "Attempts: " << attempts << endl;
            cout << "Time: " << duration_ms.count() << " milliseconds" << endl;
            found = true;
            break;
        }
    }
    
    if (!found) {
        auto end = high_resolution_clock::now();
        auto duration_ms = duration_cast<milliseconds>(end - start);
        
        cout << "----------------------------------" << endl;
        cout << "Password not found in dictionary." << endl;
        cout << "Tried " << attempts << " passwords in " << duration_ms.count() << " milliseconds" << endl;
    }
}

