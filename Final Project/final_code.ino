#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


#include <Servo.h> 

#define servoPin  6
#define switchPin 2
#define switchPin2 3

int oled = 0;

Servo servo;
int switchState ;
int previousSwitchState;
int switchState2 ;
int previousSwitchState2;
int counter = 0;
int tmpdata;
int timer;

void setup() {
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

  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
}

void loop() {
  
  int switchState = digitalRead(switchPin);
  int switchState2 = digitalRead(switchPin2);
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print(F("Time:"));
  display.setCursor(0, 13);
  display.print(counter);
  display.display();
  delay(100);
  display.clearDisplay();

  if (switchState == HIGH) {
    counter++;
    delay(50);
    display.setCursor(0, 13);
    display.print(counter);
    display.display();
    delay(100);
    display.clearDisplay();
  }
  if (switchState2 == HIGH) {
    while (counter > 0) {
      --counter;
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setCursor(0,0);
      display.print(F("Time:"));
      delay(50);
      display.setCursor(0, 13);
      display.print(counter);
      display.display();
      delay(100);
      display.clearDisplay();
      delay(1000);
      if (counter == 0) {
        servo.writeMicroseconds(1615);  // Clockwise
        delay(2200);
        servo.writeMicroseconds(1505);  // Clockwise
        delay(500);
        servo.writeMicroseconds(1415);  // Clockwise
        delay(2000);
        servo.writeMicroseconds(1505);  // Clockwise
        delay(500);
      }
  }
  }
}
