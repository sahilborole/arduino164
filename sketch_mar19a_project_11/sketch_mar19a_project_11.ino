int tilt = 8; 
int led = 9; 
void setup()  
{ 
pinMode(tilt, INPUT_PULLUP);  // Use internal pull-up 
pinMode(led, OUTPUT); 
} 
void loop()  
{ 
if (digitalRead(tilt) == LOW)  
{    
digitalWrite(led, HIGH); 
}  
else { 
digitalWrite(led, LOW); 
} 
} 