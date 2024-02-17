/**
 *
 * @file HelloPassword.ino
 * @version 1.0
 * @author Alexander Brevig
 * @authors Alexander Brevig, Sam4uk
 *
 * @details A demonstration of the simple API of the Password library
 *
 */

#include <Password.h>

Password  //
    password = Password("1234");
const char  //
    _true_[] = "true",
    _false_[] = "false";

void setup() {
  Serial.begin(9600);

  password.append('1');    ///< add 1 to the guessed password
  password.append('2');    ///< add 2 to the guessed password
  password << '3' << '4';  ///< add 3 and 4 to the guessed password
  Serial.println(password.evaluate()
                     ? _true_
                     : _false_);  ///< should print true, since 1234 == 1234

  password.reset();  ///< reset the guessed password to NULL
  Serial.println(password.evaluate()
                     ? _true_
                     : _false_);  ///< should print false, since 1234 != NULL

  password.set("qwerty");  ///< set target password to qwerty
  Serial.println(password.is("qwerty")
                     ? _true_
                     : _false_);  ///< should print true, since qwerty == qwerty
  Serial.println(
      password == "qwirty"
          ? _true_
          : _false_);  ///< should print false, since qwerty != qwirty
}

void loop() { /*nothing to loop*/
}