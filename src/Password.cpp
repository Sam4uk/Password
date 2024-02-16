/**
 * @file Password.cpp
 * @version 1.2.1
 * @author Alexander Brevig
 * @authors Alexander Brevig,Nathan Sobieck, Sam4uk
 *
 * @details Handle passwords easily
 *
 * @note
 *
 * 	1.2.1  2024-02-16 - Sam4uk : Availability of the library in the library
 *                      manager
 *
 * 	1.2    2012-05-12 - Nathan Sobieck : Arduino IDE v1.0 With BAckwards
 *                      compatibility
 *
 *  1.1    2009-06-17 - Alexander Brevig : Added assignment operator =, equality
 *                      operators == != and insertion operator <<
 *
 *  1.0    2009-06-17 - Alexander Brevig : Initial Release
 *
 */

#include "Password.h"

Password::Password(char* pass) {
  set(pass);
  reset();
}

void Password::set(char* pass) { target = pass; }

bool Password::is(char* pass) {
  byte i = 0;
  while (*pass && i < MAX_PASSWORD_LENGTH) {
    guess[i] = pass[i];
    i++;
  }
  return evaluate();
}

bool Password::append(char character) {
  if (currentIndex + 1 == MAX_PASSWORD_LENGTH) {
    return false;
  } else {
    guess[currentIndex++] = character;
    guess[currentIndex] = STRING_TERMINATOR;  // ensure a valid c string
  }
  return true;
}

void Password::reset() {
  currentIndex = 0;
  guess[currentIndex] = STRING_TERMINATOR;
}

bool Password::evaluate() {
  char pass = target[0];
  char guessed = guess[0];
  for (byte i = 1; i < MAX_PASSWORD_LENGTH; ++i) {
    // check if guessed char is equal to the password char
    if ((STRING_TERMINATOR == pass) && (STRING_TERMINATOR == guessed)) {
      return true;  // both strings ended and all previous characters are equal
    } else if ((pass != guessed) || (STRING_TERMINATOR == pass) ||
               (STRING_TERMINATOR == guessed)) {
      return false;  // difference OR end of string has been reached
    }

    // read next char
    pass = target[i];
    guessed = guess[i];
  }
  return false;  // a 'true' condition has not been met
}

Password& Password::operator=(char* pass) {
  set(pass);
  return *this;
}

bool Password::operator==(char* pass) { return is(pass); }

bool Password::operator!=(char* pass) { return !is(pass); }

Password& Password::operator<<(char character) {
  append(character);
  return *this;
}