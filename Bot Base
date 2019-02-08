int Num;   //VD^2
//int Switch=9;                 // for toggling btw speeds
//int SwitchRead;              //val of Switch
//unsigned long time1;
int VD;  //robot speed
double ThetaD;     //angle fron y axis clockwise
int VTheta;     //Rotation Speed
double ThetaD45;     //Theta+45
//int PrevVD;      //previous values
//int PrevVTheta;u
//int PreVThetaD;
double V1, V2, V3, V4;
int OutV1=8, OutV2=9, OutV3=10, OutV4=11;      
double RGT=2, FRD =3, CCW=4;

void setup() {
  pinMode (FRD, INPUT);
  pinMode (RGT, INPUT);
  pinMode (CCW, INPUT);
//  pinMode (9, INPUT);
  pinMode (OutV1, OUTPUT);
  pinMode (OutV2, OUTPUT);
  pinMode (OutV3, OUTPUT);
  pinMode (OutV4, OUTPUT);
//  Serial.begin(9600);
}

void loop() {

  FRD=pulseIn(3, HIGH);
  RGT=pulseIn(2, HIGH);
  CCW=pulseIn(4, HIGH);
//SwitchRead=pulseIn(9, HIGH);
//Serial.println(Switch);

//Serial.print(RGT);
//Serial.print("\t");
//Serial.print(FRD);
//Serial.print("\t");
//Serial.println(CCW);
//Serial.println(RGT/FRD);
  
if(RGT == 0 || FRD == 0 || CCW == 0){
         V1 = 0;
         V2 = 0;
         V3 = 0;
         V4 = 0;
}
else{
} 
if (RGT < 1450){

         RGT = (RGT - 1450);        
         
}
else if (RGT > 1550){

         RGT = (RGT - 1550);
         
}
else     {RGT = 0;}

if (CCW < 1450){
         CCW = (CCW - 1450);
        
}
else if (CCW > 1550){
         CCW = (CCW -1550);
        
}
else  {CCW = 0;}

VTheta=CCW;
VTheta=VTheta/1.2/1.5;
//Serial.println(VTheta);

if (FRD < 1450){

         FRD = (FRD - 1450);
         
}         
else if (FRD > 1550){

         FRD = (FRD - 1550);
        }

else     {FRD = 0;}
//Serial.println(FRD);

FRD=FRD/4;
RGT=RGT/4;

Num=((FRD*FRD)+(RGT*RGT));
VD = sqrt(Num);

//Serial.print(FRD);
//Serial.print("\t");
//Serial.println(RGT);
//Serial.print("\t");
//Serial.println(Num);
//Serial.print("\t");
//Serial.println(VD); 
//Serial.println(RGT/FRD);

if(FRD!=0){
  ThetaD= atan(RGT/FRD);
  if(FRD<0){ThetaD= ThetaD+3.1415;}
}
else if(FRD==0){
    if(RGT>0){
    ThetaD=3.1415/2;
  }
   else if(RGT<0){
    ThetaD=-3.1415/2;
  }   
  else if(RGT==0){
    ThetaD=0;
  }
  }
  
ThetaD45=ThetaD+(3.1415/4);
//Serial.println(ThetaD);
//Serial.print("\t");
//Serial.println(ThetaD45);

VD=VD*4*1.2/1.75;

//if (SwitchRead<1250) {VD = VD; VTheta= VTheta;}
//else if (SwitchRead>1250 && SwitchRead<1750) {VD = VD/2; VTheta= VTheta/2;}
//else if (SwitchRead>1750) {VD=VD/4; VTheta = VTheta/4;}

V1= VD*sin(ThetaD45)+1500+VTheta;
V2= VD*cos(ThetaD45)+1500-VTheta;

V3= VD*cos(ThetaD45)+1490+VTheta;
V4= VD*sin(ThetaD45)+1490-VTheta;

//Serial.print(VD);
//Serial.print("\t");
//Serial.print(V1);
//Serial.print("\t");
//Serial.print(V2);
//Serial.print("\t");
//Serial.print(V3);
//Serial.print("\t"); 
//Serial.println(V4);

for (int i=0; i<10; i++){  

    digitalWrite(OutV1,HIGH);
    delayMicroseconds(V1);
    digitalWrite(OutV1,LOW);
    delayMicroseconds(V1);
    digitalWrite(OutV2,HIGH);
    delayMicroseconds(V2);
    digitalWrite(OutV2,LOW);
    delayMicroseconds(V2);

    digitalWrite(OutV3,HIGH);
    delayMicroseconds(V3);
    digitalWrite(OutV3,LOW);
    delayMicroseconds(V3);
    digitalWrite(OutV4,HIGH);
    delayMicroseconds(V4);
    digitalWrite(OutV4,LOW);
    delayMicroseconds(V4);
}

/*time1 = millis();
Serial.println(time1);
*/
}
