 float Kp = 0.15; //related to the proportional control term; 
//change the value by trial-and-error (ex: 0.07).
float Ki = 0.0000; //related to the integral control term; 
//change the value by trial-and-error (ex: 0.0008).
float Kd = 0.135; //related to the derivative control term; 
//change the value by trial-and-error (ex: 0.6).

int P;
int I;
int D;
int lastError = 0;

// Motor speed variables (choose between 0 - no speed, and 255 - maximum speed)
const uint8_t maxspeeda = 255;
const uint8_t maxspeedb = 255;

const uint8_t minspeeda = 60;
const uint8_t minspeedb = 60;  

const uint8_t basespeeda = 250;
const uint8_t basespeedb = 250;

int motorspeeda=0;
int motorspeedb=0;

//calcs corrected motor speeds
void pidControl() 
{ 
  int error = 3500 - position; //3500 is the ideal position (the center)

  P = error;
  I = I + error;
  D = error - lastError;
  lastError = error;

  int motorspeed = P*Kp + I*Ki + D*Kd; //calculate the correction
  
  motorspeeda = basespeeda - motorspeed;
  motorspeedb = basespeedb + motorspeed;
  
  if (motorspeeda > maxspeeda) {
    motorspeeda = maxspeeda;
  }
  if (motorspeedb > maxspeedb) {
    motorspeedb = maxspeedb;
  }
  if (motorspeeda < minspeeda) {
    motorspeeda = minspeeda;
  }
  if (motorspeedb < minspeedb) {
    motorspeedb = minspeedb;
  } 
}
