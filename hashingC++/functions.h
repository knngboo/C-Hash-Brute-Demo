//
//  functions.h
//  hashingC++
//
//  Created by King Boo on 11/17/25.
//
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <functional> // for hashing
#include <chrono> // for timer
#include <fstream> // for file reading

using namespace std;
using namespace std::chrono;

// FUNCTION DECLARATIONS
int menu(string password);
string enterPassword();
size_t hashedPassword(string password);
void bruteForce(size_t hashValue, size_t passwordLength);
void dictionaryAttack(size_t hashValue, string filename);

#endif // FUNCTIONS_H
