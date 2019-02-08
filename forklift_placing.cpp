#include <Servo.h>

int servoFork = 9, val3=140,pos3=140; 

Servo myServoFork; 

int count,pos4=0;
int val7;
int analogPin5 = 7;
int PUL = 12;
int DIR = 13;
                                                //1-wall, 2-clamp
Servo myServoWall,myServoClamp,myServoLock;
int servopinlock=3;
int lockpos=110;
int openpos=20;

int pos1=20,pos2=10;

int ptr=6;                      //switch between wall and forklift servo (1-3)
int switch_val;                       //switch value

int servopin1=11;
int plsinKnob=5 ,comm;           //common analogpin for 1-3

int servopin2=10;  
int plsinClamp=4,bcomm;

void setup() {

  pinMode(ptr,INPUT);
  pinMode(plsinClamp,INPUT);
  pinMode(plsinKnob,INPUT);     //common pin 1-3
  myServoWall.attach(servopin1);
  myServoClamp.attach(servopin2);
  myServoFork.attach(servoFork);
  myServoLock.attach(servopinlock);
  Serial.begin(9600);

  pinMode(PUL, OUTPUT);
  pinMode(DIR, OUTPUT);
  
  pinMode(analogPin5, INPUT);
  
myServoLock.write(lockpos);
myServoWall.write(48);
myServoClamp.write(140);
myServoFork.write(158);

}


void loop() {
 
  val3= pulseIn(plsinClamp, HIGH);
  if (val3 < 1100){
    val3 = 1100;
  }
  else if (val3 > 1900){
    val3 = 1900;
  }
  val3= map(val3,1100,1900, 140, 15);
  if(abs(pos3-val3)>=4)
  {
    myServoClamp.write(val3);

    pos3=val3;//.................................................2-clamp
  }
  
  val7 = pulseIn(analogPin5, HIGH);
    
  if (val7 < 1000){
    val7 = 1000;
  }else if (val7 > 2000){
    val7 = 2000;
  }
  
  count = map(val7,1000,2000,0,470);

if(abs(pos4-count)>=40)
{
  
    
      while(pos4<count)
      {
        digitalWrite(DIR, HIGH);
        digitalWrite(PUL, HIGH);
        delayMicroseconds(1700);
        digitalWrite(PUL, LOW);
        delayMicroseconds(1700);

        pos4++;
      }

      while(pos4>count)
      {
        digitalWrite(DIR, LOW);
        digitalWrite(PUL, HIGH);
        delayMicroseconds(1700);
        digitalWrite(PUL, LOW);
        delayMicroseconds(1700);

        pos4--;
      }
      
} 
switch_val=pulseIn(ptr,HIGH);

if( switch_val<1300)
{
  //..................................................1-wall(knob )
  myServoLock.write(openpos);
  delay(5);
  
  comm= pulseIn(plsinKnob, HIGH);
  if (comm<1050){
    comm= 1050;
  }
  else if (comm>1950){
    comm= 1950;
  }
  comm= map(comm,1050,1950,48,140);
    
    myServoWall.write(comm);  

}

else if(switch_val>1700)
{
             //gripper rotation servo.............................................................knob channel
             myServoLock.write(lockpos);
             delay(5);
             
  bcomm= pulseIn(plsinKnob, HIGH);
    if (bcomm<1050){
    bcomm= 1050;
  }
  else if (bcomm>1950){
    bcomm= 1950;
  }

  bcomm= map(bcomm,1050,1950,158,88);
  
    myServoFork.write(bcomm);


}
else 
{
  myServoLock.write(lockpos);
}
                                                                                                                                            
}
