// Import libraries
#include <Arduino.h>
#include <U8x8lib.h>

// Creates an instance of the â€˜ U8X8_SSD1306_128X64_NONAME_HW_I2C â€˜ class
auto display = U8X8_SSD1306_128X64_NONAME_HW_I2C(U8X8_PIN_NONE);

/* -------------- Initialize the Grove board ------------- */
void setup () {
 pinMode (DD4, OUTPUT); // Sets the D4 pin ( LED ) to output

 Serial.begin (9600) ; // Enables serial communication
 display.begin () ; // start up the OLED display
 display.setFlipMode (0) ; // set to 1 or 0 , depending on orientation of board
 }

 /* --------------- Run this over and over ------------------- */
 void loop () {
 if (!Serial.available()) {
 return ; // we only want the rest of the stuff to run if â€˜Serial â€˜ is available
 }

 display.clearDisplay ();

 auto data = Serial . read () ; // we receive a byte of data via Java

 // Display your name
 display.setFont ( u8x8_font_profont29_2x3_r );
 display.setCursor (0 , 0) ;

 if ( data == ( byte ) -1) { // this indicates the countdown is over
  digitalWrite ( DD4 , HIGH );
  display.print (" Yay ");
 } else { // this indicates the countdown is in progress
 display.print ( data );
 }
 }
