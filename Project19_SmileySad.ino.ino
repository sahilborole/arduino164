#include <LedControl.h> 
 
// MAX7219 pins: DIN = 11, CLK = 13, CS = 10 
LedControl lc = LedControl(11, 13, 10, 1); 
 
// Buttons 
const int smileyButton = 2; 
const int sadButton = 4; 
 
// Smiley face pattern (8x8) 
byte smiley[8] = { 
  B00111100, 
  B01000010, 
  B10100101, 
  B10000001, 
  B10100101, 
  B10011001, 
  B01000010, 
  B00111100 
}; 
 
// Sad face pattern (8x8) 
byte sad[8] = { 
  B00111100, 
  B01000010, 
  B10100101, 
  B10000001, 
  B10011001, 
  B10100101, 
  B01000010, 
  B00111100 
}; 
 
void setup() { 
  lc.shutdown(0, false);   // Wake up MAX7219 
  lc.setIntensity(0, 8);   // Brightness 0-15 
  lc.clearDisplay(0); 
 
pinMode(smileyButton, INPUT_PULLUP); 
pinMode(sadButton, INPUT_PULLUP); 
showSmiley(); // Default on startup 
} 
void showPattern(byte pattern[8]) { 
for (int row = 0; row < 8; row++) { 
lc.setRow(0, row, pattern[row]); 
} 
} 
void showSmiley() { showPattern(smiley); } 
void showSad()    
{ showPattern(sad);    
} 
void loop() { 
if (digitalRead(smileyButton) == LOW) { 
delay(50); // debounce 
showSmiley(); 
} 
if (digitalRead(sadButton) == LOW) { 
delay(50); // debounce 
showSad(); 
} 
}