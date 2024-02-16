/**
 *
 * @file Password.h
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
 */
#ifndef PASSWORD_H
#define PASSWORD_H

// Arduino versioning.
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"	// for digitalRead, digitalWrite, etc
#else
#include "WProgram.h"
#endif

#define MAX_PASSWORD_LENGTH (20)

#define STRING_TERMINATOR '\0'

class Password {
public:
	/**
	 * @brief Construct object in memory, set all variables
	 * 
	 * @param pass 
	 */
	Password(char* pass);
	
	/**
	 * @brief Set the password
	 * 
	 * @param pass 
	 */
	void set(char* pass);
	/**
	 * @brief Evaluate a string, is it equal to the password?
	 * 
	 * @param pass 
	 * @return true 
	 * @return false 
	 */
	bool is(char* pass);
	/**
	 * @brief Append a char to the guessed password
	 * 
	 * @param character 
	 * @return true 
	 * @return false 
	 */
	bool append(char character);
	/**
	 * @brief Reset the guessed password, one can guess again
	 * 
	 */
	void reset();
	/**
	 * @brief Is the current guessed password equal to the target password?
	 * 
	 * @return true 
	 * @return false 
	 */
	bool evaluate();
	
	//char* getPassword();
	//char* getGuess();
	
	//operators
	/**
	 * @brief password using operator =
	 */
	Password &operator=(char* pass);
	/**
	 * @brief Test password using ==
	 */
	bool operator==(char* pass);
	/**
	 * @brief Test password using != 
	 */
	bool operator!=(char* pass);
	/**
	 * @brief Append to currently guessed password using operator <<
	 */
	Password &operator<<(char character);
	
private:
	char* target;
	char guess[ MAX_PASSWORD_LENGTH ];
	byte currentIndex;
};

#endif