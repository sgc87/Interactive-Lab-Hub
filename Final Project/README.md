# IDD-Fa19-Final-Project: 

## Team

**[Samuel Choi (sgc87)](https://github.com/sgc87/Interactive-Lab-Hub)**

**[Ankur Kapoor (ak2552)](https://github.com/ak2552/Interactive-Lab-Hub)** 

## Project Idea

The idea is to create a smart toaster. Using a microcontroller, a toaster will be turned into 
a smart device. Using a low powered, small microcontroller, using PWM output, the toaster will have its spring mechanism 
pushed down by a servo motor. It will be either alarm based or by command through Alexa over WiFi. 

The motive behind doing this project is that the current IoT toasters out on the market are ridiculously expensive. Costing anywhere between $200-$300 or more! With this project, we are hoping to prove that an IoT toaster can be made at the fraction of the cost yet be effective. 

## Expected Parts

[Adafruit Trinket Microcontroller](https://www.adafruit.com/product/1501)

Servo Motor

3D Printed actuating parts

Motor Mounts

## Interaction Plan

People will set a desired time through a phone app or through Alexa to have the toaster automatically toast bread for you. 

## Prototype Fair

![Sketch of Project](https://github.com/sgc87/Interactive-Lab-Hub/blob/master/Final%20Project/sketch.jpg)

## Development

### Hardware

The most time consuming part of this project was setting up the device physically. 

#### Taking the toaster apart
The toaster used for the prototype was a $12 Kitchensmith 2-slice toaster from Target. 

![Toaster](https://github.com/sgc87/Interactive-Lab-Hub/blob/master/Final%20Project/toaster_box.jpg)

First, to take off the plastic cover, two grey rubber feet have to be removed from the front two legs of the toaster. 
Next, a screw located inside the bottom end of each leg needs to be unscrewed. 
This next part is tricky. In order to be able to take the plastic cover off, the chrome piece attached to the lever for
activating the toaster needed to be removed. This part was the trickiest. There was a tab on the side that needed to be lifted, 
which was very difficult. Using a screwdriver is recommended to remove that part. 

Once removed the toaster should look like this. Be careful of the metal edges as they can be sharp and can cut skin easily. 

![Teardown](https://github.com/sgc87/Interactive-Lab-Hub/blob/master/Final%20Project/teardown.jpg)

#### Building the actuating mechanism

Next, a mechanism to actuate the lever down to activate to toaster was needed. For that, a high torque motor from 
Tinkersphere was used and a 3D rack and pinion were printed. A hole had to be drilled in the pinion (the gear) so 
that a screw could go through and be attached to the motor. 

Creating support for the rack was probably the most difficult part. First, an arm connected to the rack was needed. 
For this, a part was taken out of the waste bin for 3D printed parts, and our rack was attached to it. The following 
image is the result. 

![Rack_n_pinion](https://github.com/sgc87/Interactive-Lab-Hub/blob/master/Final%20Project/rack%26pinion.jpg)

The following are parts that were used / created. The 3D model was taken off an online 3D model repository. 

[3D Model used for the rack and pinion](https://github.com/sgc87/Interactive-Lab-Hub/blob/master/Final%20Project/Rack_and_pinion_-_4mm_rack_height.stl)

[4kg High Torque Motor used](https://tinkersphere.com/motors-wheels/241-high-torque-continuous-rotation-servo-4kg.html)

#### Creating Support and Adding Stabilization

Next was creating support for the arm/rack assembly. For that scrap wood lying around the maker space was used. 

Two small pieces were used to support the sides of the assembly. Wood glue was used to attach these two pieces. 

While testing this support, it was discovered that the amount of pushing force required to activate the electromagenctic 
circuit on the toaster circuit board was too strong. As a result, a portion of the spring used to push the lever back up 
was cut. This made pushing down the level much easier. 

However, the arm/rack assembly had a tendency to push back as it pushed down the level, so we created support for it by
nailing its wooden backboard support to a wooden platform that we also secured the toaster onto, using the holes in the legs
as the location to drill the screws to the platform. 

Despite creating the platform, the backboard still flexed a lot. So, a metal shelf bracket from Home Depot was purchased and 
drilled to the backboard and the platform. This solved the issue of pushback from the arm/rack assembly. 

[Shelf Bracket](https://www.homedepot.com/p/Everbilt-5-in-x-6-in-Gray-Shelf-Bracket-14815/202947664)

The gear kept on unscrewing itself out whenever the arm/rack assembly it a dead end. This also caused some slippage. To fix this, 
one of the black attachments had its arms and edges cut off so that the pinion could be glued to it and use its teeth to attach
to the motor properly. Also, the rack and pinion had a tendency to slip at times. To fix this issue, a small wooden block was 
drilled to the side of the backboard to press the motor up so that the rack and pinion had closer contact. 

#### Solving Power Issues

Initially, the motor was purely powered off of the Arduino board. However, whenever the motor had a lot of resistence, hence a lot of 
load and demand for current, it would short the board and the Arduino would freeze. The solution was to have an external power 
source conencted to the motor with a shared ground with the Arduino. We used a 9V battery for this, but wanted to have an AD-DC
adapter to power the motor. However, the resources for those weren't available before the final presentation, so a 9V was used. 
Nevertheless, the 9V battery solved our issues. 

#### Attaching an outlet plug

We didn't want our final prototype to look messy by requiring to use multiple plugs, so we soldered a socket to the power lines 
of the circuit board of the toaster and plugged in an AC-DC adapter for powering the Arduino. Since the circuit board of the 
toaster is directly connected to the outlet, we knew that it ran on AC. So, we jumped the power cables coming into the circuit 
board in parallel. Of course, electrical tape was used to cover the bare metal for safety after the soldering. The results are shown below. 

![Solder](https://github.com/sgc87/Interactive-Lab-Hub/blob/master/Final%20Project/socket.jpg)

#### Screen

We added the OLED screen that was used in previous labs for the final presentation. 

### Software

#### Testing the Actuation

To test the actution of the motor, the following code was used. It uses two push buttons: one to actuate the arm/rack assembly 
up and the other to actuate to assembly down. 

[Motor Actuation Code](https://github.com/sgc87/Interactive-Lab-Hub/blob/master/Final%20Project/testbuttons.ino)

[Video to Actuation Testing](https://www.youtube.com/watch?v=bmnzSQn7FpY&feature=share&fbclid=IwAR2vbEXca8XxnOJBcTPrY9735rfv8IHqWGr90zhE5MBVWhrvUoyvIya5clE)

#### Adding Bluetooth

We wanted to add an alarm clock set by a smartphone so that whenever the alarm set on the phone is activated, the Arduino would turn on the toaster. We initially tried using a BLE module that we had, but none of the phone apps or phone app tools that we worked with would work with BLE. 

[BLE Module Used](https://www.adafruit.com/product/2479)

We later tried to use an older bluetooth technology called TTL. We got some packets sent to the Arduino, but they were corrupted, so we weren't able to use it as well. We resorted to using an OLED and programming a timer alarm onto it. 
[Bluetooth TTL Module Used](https://www.sparkfun.com/products/12577)

[Code used to test the BLE](https://github.com/sgc87/Interactive-Lab-Hub/blob/master/Final%20Project/bt_test.ino)

The following is an image of the bluetooth modules. The BLE is on the left, and the TTL is on the right. 
![bt](https://github.com/sgc87/Interactive-Lab-Hub/blob/master/Final%20Project/bluetooth.jpg)

#### Phone App

An easy to use online App Development website was used: http://ai2.appinventor.mit.edu/

With this website, we took an alarm clock someone had created and added Bluetooth signal packets once the alarm was triggered. The following is the generated files from the website. This file may be uploaded to the website for use. 

[MIT App Developer Encoding File](https://github.com/sgc87/Interactive-Lab-Hub/blob/master/Final%20Project/AlarmClock.aia)

The website uses coding blocks to program the app. 

![appdev](https://github.com/sgc87/Interactive-Lab-Hub/blob/master/Final%20Project/appdev.png)

## Final Results

![final](https://github.com/sgc87/Interactive-Lab-Hub/blob/master/Final%20Project/final2.jpg)

Our toaster was able to successfully perform its task. Start toasting at a desired time by the user. The following video shows our toaster successfully working. 

[Final Prototype Demo Video](https://www.youtube.com/watch?v=eiY0KqnON_c&feature=share&fbclid=IwAR2uKsBrZ4PwMvqTWdIXbnD-ZxMo3ypB7ZAv1ZyHFzL0bpkde3fHnVNIFWs)
