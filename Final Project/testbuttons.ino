#include <Servo.h> 

#define servoPin  6
#define switchPin 2
#define switchPin2 3

Servo servo;
int switchState ;
int previousSwitchState;
int switchState2 ;
int previousSwitchState2;

// call this when the input on pin 2 changes (LOW to HIGH *or* HIGH to LOW)
void ToggleSwitch(int switchState, int switchState2)
{    
  if (switchState == HIGH)
  {
    servo.writeMicroseconds(1415);  // Counter clockwise
    delay(20);
  }
  else if (switchState2 == HIGH)
  {
    servo.writeMicroseconds(1615);  // Clockwise
    delay(20);
  } else {
    servo.writeMicroseconds(1505);  // Clockwise
    delay(20);
  }
}

void setup()
{
  //Serial.begin(9600);
  //Serial.println("Useless Box Lab 5");

  pinMode(5,OUTPUT);
  digitalWrite(5,HIGH);
  // start with the box closed and the switch in the off postion
    servo.attach(servoPin);
  switchState = LOW;
  previousSwitchState = LOW;
  switchState2 = LOW;
  previousSwitchState2 = LOW;

  // we should probably pay attention to the switch
  pinMode(switchPin, INPUT); 
}

void loop()
{ 
  int switchState = digitalRead(switchPin);
  int switchState2 = digitalRead(switchPin2);
  ToggleSwitch(switchState, switchState2);
