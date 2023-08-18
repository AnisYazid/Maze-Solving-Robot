#include "motors.h"
#include "qtr.h"
// #include "tcs.h"  // dont need it in ARC 
#include "buzzer.h"
#include "pid.h"

int turningSpeed= 250; //speed that it turns with
int turningTimeR= 600; //time to turn Right 
int turningTimeL= 650; //time to turn Left
//int motorspeed1 = 150;  hadi mkch mnha 
//int motorspeed2 = 150;  also hadi 

/*start main*/
void setup() 
{
  //motor setup
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor1Speed, OUTPUT);
  pinMode(motor2Speed, OUTPUT);

  //qtr setup
  for (int i = 0; i < SensorCount; i++) 
  {
    pinMode(irSensorPins[i], INPUT);
  }

  //tcs setup
  //gammaSetup();
  // ledSetup();

  //buzzer setup
  pinMode(buzzerPin, OUTPUT);
  //indicate the beginning of the end
  buzzer();

}



void loop() 
{
  //this should be enough for line following
  
  irScan();
  detectPostion();

  if (!irNothing)
   {   //checks for line existance
      if(irMid)
       {                                                       //no intersections
         pidControl();                                         //apply correction speed
         forward(motorspeeda,motorspeedb );
       }

      else if(irRight)
      {
        right(turningSpeed, turningSpeed);
        delay(turningTimeR);
        forward(motorspeeda,motorspeedb );
        delay(100);
      } 

      else if(irLeft)
      { 
        left(turningSpeed, turningSpeed);
         delay(turningTimeL);
        forward(motorspeeda,motorspeedb );
        delay(100);
      }
   }  

  else         // when it doesn't find a line
   { 
         pidControl();                                     
         forward(motorspeeda,motorspeedb );
  }
}
