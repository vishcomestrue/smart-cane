//This code is certainly written based on an already-decided
//positions of the Ultrasonic sensors and all the values 
//used in IF statements are calculations based on those 
//position values
//THE TWO HORIZONTAL ULTRASONIC SENSORS ARE PLACED 5 CM AND 70 CM
//ABOVE THE GROUND
//THE INCLINED ULTRASONIC SENSOR IS PLACED AT A DISTANCE OF 80 CM
//ABOVE THE GROUND AND INCLINED AT AN EXTRA ANGLE OF 10 DEGREE TO THE PERPENDICULAR TO THE STICK
//THE FINAL ULTRASONIC SENSOR FACING PARALLEL TO THE GROUND IS PLACED AT A DISTANCE OF 80 CM
//ABOVE THE GROUND

#define trigStraight1 13
#define echoStraight1 12
#define trigAngled1 11
#define echoAngled1 10
#define trigAngled2 9
#define echoAngled2 8
#define trigStraight2 7
#define echoStraight2 6
#define buzzer 3
#define buzzer2 5

void setup()
{
  pinMode(trigStraight1, OUTPUT);
  pinMode(trigStraight2, OUTPUT);
  pinMode(trigAngled1, OUTPUT);
  pinMode(trigAngled2, OUTPUT);
  pinMode(echoStraight1, INPUT);
  pinMode(echoStraight2, INPUT);
  pinMode(echoAngled1, INPUT);
  pinMode(echoAngled2, INPUT);
  Serial.begin(9600);
}

void loop()
{
  long distHor1, distHor2, distAng1, distAng2, dur1, dur2, dur3, dur4;
  //Write it individually since the whole thing didnt work
  digitalWrite(trigStraight1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigStraight1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigStraight1, LOW);
  dur1 = pulseIn(echoStraight1, HIGH);
  distHor1 = ((dur1)/2) / 29.1;
  
  digitalWrite(trigStraight2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigStraight2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigStraight2, LOW);
  dur2 = pulseIn(echoStraight2, HIGH);
  distHor2 = ((dur2)/2) / 29.1;
  
  
  digitalWrite(trigAngled1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigAngled1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigAngled1, LOW);
  dur3 = pulseIn(echoAngled1, HIGH);
  distAng1 = ((dur3)/2) / 29.1;
  
  
  digitalWrite(trigAngled2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigAngled2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigAngled2, LOW);
  dur4 = pulseIn(echoAngled2, HIGH);
  distAng2 = ((dur4)/2) / 29.1;
  
  //BUZZER TRIAL
  //tone(buzzer, 300, 100); --Success but the tone is not nice
  
  //Change the tone for each single notification
  
  noTone(buzzer);
  noTone(buzzer2);
  if((distHor1>22)&&(distHor1<31)) {                 //To find if the obstacle is something full or just a small obstacle that just hits the legs
    if((distHor2>62)&&(distHor2<69)){
      tone(buzzer, 600, 300);
      delay(500);
      noTone(buzzer);
    }
    else {
      tone(buzzer, 500, 300);
      delay(500);
      noTone(buzzer);
    }
  }
  if((distHor2>62)&&(distHor2<69)&&(distHor1>31)){   //To ensure that the object is barrier that of above ground
    tone(buzzer, 400, 300);
    delay(500);
    noTone(buzzer);
  }
  
  //TO CHECK FOR ELEVATED OR LOWERED GROUND
  
  if(distAng1>(distAng2/0.766)){                    //To notify that we are going from a upper to lower surface
    if(distAng1>123)
    {
      tone(buzzer2, 1500, 1000);		                //If the depth is more than 23cm in height from the present ground, this alarm rings
      delay(500);
      noTone(buzzer2);
    }
    else
    {
      tone(buzzer2, 1000, 400);                    //Therefore the tone is going from high to low
      delay(200);
      noTone(buzzer2);
      tone(buzzer2, 100, 200);
      delay(200);
      noTone(buzzer2);
    }
  }
  if(distAng1<(distAng2/0.766)){                  //To notify that we are going from a lower to upper surface
    tone(buzzer2, 100, 400);                      //Therefore the tone is going from low to high
    delay(200);
    noTone(buzzer2);
    tone(buzzer2, 1000, 200);
    delay(200);
    noTone(buzzer2);
  }
  
  //Write a print statement to check if its working correctly
  
  Serial.print(distHor1);
  Serial.print(" ");
  Serial.print(distHor2);
  Serial.print(" ");
  Serial.print(distAng1);
  Serial.print(" ");
  Serial.print(distAng2);
  Serial.println(" ");
}
