/**
 * @file PasswordKeypad.ino
 * 
 * @brief Simple Password Entry Using Matrix Keypad 
 *  
 * @authors Nathan Sobieck (athan@Sobisource.com)
 * 
 * @note
 *  2012-05-04 - Nathan Sobieck : Simple Password Entry Using Matrix Keypad
 */

//* is to validate password   
//# is to reset password attempt

/////////////////////////////////////////////////////////////////

#include <Password.h> 
#include <Keypad.h>

Password password = Password( "1234" );

const byte ROWS = 4; ///< rows
const byte COLS = 4; ///<  columns
// Define the Keymap
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'} ///< * is to validate password
                    ///< # is to reset password attempt  
};

byte rowPins[ROWS] = 
    {9, 8, 7, 6};  ///< Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte colPins[COLS] = 
    {5, 4, 3, 2};  ///< Connect keypad COL0, COL1 and COL2 to these Arduino pins.

// Create the Keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){

  Serial.begin(9600);
  keypad.addEventListener(keypadEvent); ///< add an event listener for this keypad
}

void loop(){
  keypad.getKey();
}

///take care of some special events
void keypadEvent(KeypadEvent eKey){
  switch (keypad.getState()){
    case PRESSED:
	Serial.print("Pressed: ");
	Serial.println(eKey);
	switch (eKey){
	  case '*': checkPassword(); break;
	  case '#': password.reset(); break;
	  default: password.append(eKey);
     }
  }
}

void checkPassword(){
  if (password.evaluate()){
    Serial.println("Success");
    //Add code to run if it works
  }else{
    Serial.println("Wrong");
    //add code to run if it did not work
  }
}