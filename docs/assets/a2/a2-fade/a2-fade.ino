/*
  Fade

  This example shows how to fade an LED on pin 9 using the analogWrite()
  function.

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/basics/Fade/
*/

int led = 9;         // the PWM pin the LED is attached to
int brightness = 0;  // how bright the LED is
int fadeAmount = 5;  // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of pin 9:
  analogWrite(led, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}





// pin for LED1 (on/off)
int LED1 = 12;
// pin for LED2 (PWM pin, for fade)
int LED2 = 10;
// pin for LED3 (on/off)
int LED3 = 8;
// pin for button
int BUTTON = 2;

// runs once at power on or reset
void setup() {
  // LED1 pin is an output
  pinMode(LED1, OUTPUT);
  // LED2 pin is an output
  pinMode(LED2, OUTPUT);
  // LED3 pin is an output
  pinMode(LED3, OUTPUT);
  // button pin is an input
  pinMode(BUTTON, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // check if the button is pressed (HIGH = pressed)
  if (digitalRead(BUTTON) == HIGH) {
    // LED1 on while LED2 fades up
    digitalWrite(LED1, HIGH);
    // LED3 off during fade up
    digitalWrite(LED3, LOW);
    // step brightness from 0 to 255 in increments of 5
    for (int b = 0; b <= 255; b += 5) {
      // set LED2 brightness to b using PWM
      analogWrite(LED2, b);
      // wait 10 ms so the fade is visible
      delay(10);
    }
    // LED1 off while LED2 fades down
    digitalWrite(LED1, LOW);
    // LED3 on during fade down
    digitalWrite(LED3, HIGH);
    // step brightness from 255 back to 0
    for (int b = 255; b >= 0; b -= 5) {
      // set LED2 brightness to b using PWM
      analogWrite(LED2, b);
      // wait 10 ms so the fade is visible
      delay(10);
    }
  } else {
    // button not pressed: turn LED1 off
    digitalWrite(LED1, LOW);
    // turn LED2 off
    analogWrite(LED2, 0);
    // turn LED3 off
    digitalWrite(LED3, LOW);
  }
}
