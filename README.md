# SMART-CANE

## Problem Statement

Visually Impaired people face many difficulties in their lives, especially when they are walking somewhere they are new. They know the distance of all the objects and obstacles in their home, and they remember it and freely roam in their home using that data. But when they reach out to new places with their standard walking stick, they face many difficulties using the standard walking stick(the plain white stick they use for walking). Some struggles that they face while using the standard stick are:
  - The standard stick cannot easily detect lowered and elevated surfaces. They struggle to find them and often end up losing their balance.
  - The standard stick can detect only objects in the vicinity of around 0.8 to 1 m and cannot see moving objects.
Not at all times, the public will stand for their help😢. 

SMART WALKING STICK can help resolve this issue.
*This whole project is just a prototype and can work only at certain situations that a blind person faces in everyday life*

## Components Required

1. Arduino Nano
2. A small breadboard to place the Arduino Nano and make connections easier
3. 4x Ultrasonic Sensor
4. Battery(9V)
5. Connecting wires
6. Buzzers 

![RCS Final](https://user-images.githubusercontent.com/84440397/118788146-1d95a280-b8b1-11eb-86d2-a70a45803a74.png)

## Working
This project mainly relies on working on the various Ultrasonic sensors fitted in the stick at multiple positions and angles. All the Ultrasonic Sensors are positioned at different places to detect various obstacles and surfaces. 
Two out of Four Ultrasonic sensors are placed perpendicular to the ‘ground’ (perpendicular to a flat surface), which helps detect the obstacles present in front of the stick(tries to eliminate limitation no.1). The third and fourth Ultrasonic sensors are placed inclined to the stick. They can detect the distance from the ground to inform about the ground level and notify if a sudden elevated or lowered surface appears(tries to eliminate limitation no.2). 
Visually Impaired people are good at distinguishing sounds. This fact stands like a pro for them, and this idea is implemented using the buzzer. The buzzer attached to the stick sounds at different frequencies to show the difference in the obstacle/situation encountered. 

The two inclined Ultrasonic sensors are placed in a particular inclination. Since we know the distance of the Ultrasonic sensor from the bottom of the stick and the angle of inclination of the stick from the ground,  we can calculate the distance that the third sensor detects in a leveled ground. This information can be used to find whether the newly encountered surface is elevated or lowered. The fourth sensor works as a reference for the third sensor. It compares the distance located to see if the surface is elevated or lowered concerning the currently standing/walking surface.

Diagram representing the above explanation:

![IMG_20210517_150300446_HDR~2](https://user-images.githubusercontent.com/84440397/118812640-f1d3e600-b8cb-11eb-9879-0bcb8a826e60.jpg)

Since we know the exact positions of all Ultrasonic sensors, we use trigonometry to find the distance detected in a typical case(leveled ground). The distance detected by Ultrasonic sensor three is then compared with the distance detected by Ultrasonic sensor four.


## Conclusionn 

This idea can be implemented by replacing Arduino Nano with NodeMCU and adding an app support that can spell out the obstacles. 
This can also be accompanied by an PIR sensor to detect if the road is too busy with humans and to reduce the distance at which the sensor beeps that too in a low frequency to avoid noise pollution in public. 
