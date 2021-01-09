//Best suitable on Attiny25 as it has 2K Flash to just store this program
//Although Attiny45/85 can be used with 4K, 8K Flash, but that will be overkill.

const int redPin = 2; 
const int bluPin = 1; 
const int grnPin = 0; 
short T=550,times=10; //TRANSITION TIME//Time period of PWM='T'us and each cycle glows for 'times' times.
short t=1000; //RESOLUTION TIME in us
void setup()
{
  pinMode(redPin, OUTPUT);    
  pinMode(grnPin, OUTPUT);    
  pinMode(bluPin, OUTPUT);
}

void loop() {
  short int i=0;
//SHOWOFF
  i=0;while(i<1000){Red(); i++;}
  i=0;while(i<1000){Green(); i++;}
  i=0;while(i<1000){Blue(); i++;}
  i=0;while(i<1000){Yellow(); i++;}
  i=0;while(i<1000){Pink();   i++;}
  i=0;while(i<1000){Aqua();   i++;}
   i=0;while(i<1000){Orange(); i++;}
  i=0;while(i<1000){Violet(); i++;}
  i=0;while(i<1000){LemonYellow(); i++;}
  i=0;while(i<1000){Magenta(); i++;}
  i=0;while(i<1000){White(); i++;}

//WAVE
   digitalWrite(grnPin,LOW);digitalWrite(bluPin,LOW);digitalWrite(redPin,HIGH);
   delay(800);
   Red();
   redtoyellow();
   yellowtogreen();
   greentocyan();
   cyantoblue();
   bluetomagenta();
   magentatored();
   delay(800);
}

void Red()
{
  digitalWrite(redPin,HIGH);digitalWrite(bluPin,LOW);digitalWrite(grnPin,LOW);delay(1);
}
void Green()
{
  digitalWrite(redPin,LOW);digitalWrite(bluPin,LOW);digitalWrite(grnPin,HIGH);delay(1);
}
void Blue()
{
  digitalWrite(redPin,LOW);digitalWrite(bluPin,HIGH);digitalWrite(grnPin,LOW);delay(1);
}
void Cyan()
{
  digitalWrite(redPin,LOW);digitalWrite(bluPin,HIGH);digitalWrite(grnPin,HIGH);delay(1);
}
void Pink()
{
  digitalWrite(redPin,HIGH);digitalWrite(bluPin,HIGH);digitalWrite(grnPin,LOW); delay(1);
}
void White()
{
  digitalWrite(redPin,HIGH);digitalWrite(bluPin,HIGH);digitalWrite(grnPin,HIGH);delay(1);
}
void Yellow()
{ digitalWrite(bluPin, LOW);
  digitalWrite(redPin, HIGH);
  digitalWrite(grnPin, HIGH);
  short on  = 500;
  short off = t-on; //time period of PWM is 't'us.
      digitalWrite(grnPin, HIGH);
      delayMicroseconds(on);
      digitalWrite(grnPin, LOW);
      delayMicroseconds(off);
}
void LemonYellow()
{ digitalWrite(bluPin, LOW);
  digitalWrite(redPin, HIGH);
  digitalWrite(grnPin, HIGH);
  short on  = 500;
  short off = t-on; //time period of PWM is 't'us.
      digitalWrite(redPin, HIGH);
      delayMicroseconds(on);
      digitalWrite(redPin, LOW);
      delayMicroseconds(off);
}
void Orange()
{ digitalWrite(bluPin, LOW);
  digitalWrite(redPin, HIGH);
  digitalWrite(grnPin, HIGH);
  short on  = 150;
  short off = t-on;//time period of PWM is 't'us.
      digitalWrite(grnPin, HIGH);
      delayMicroseconds(on);
      digitalWrite(grnPin, LOW);
      delayMicroseconds(off);
}
void Violet()
{ digitalWrite(bluPin, HIGH);
  digitalWrite(redPin, HIGH);
  digitalWrite(grnPin, LOW);
  short on  = 250;
  short off = t-on;//time period of PWM is 't'us.
      digitalWrite(redPin, HIGH);
      delayMicroseconds(on);
      digitalWrite(redPin, LOW);
      delayMicroseconds(off);
}
void Magenta()
{ digitalWrite(bluPin, HIGH);
  digitalWrite(redPin, HIGH);
  digitalWrite(grnPin, LOW);
  short on  = 430;
  short off = t-on;//time period of PWM is 't'us.
      digitalWrite(redPin, HIGH);
      delayMicroseconds(on);
      digitalWrite(redPin, LOW);
      delayMicroseconds(off);
}
void Aqua()
{ digitalWrite(redPin, LOW);
  digitalWrite(bluPin, HIGH);
  digitalWrite(grnPin, HIGH);
  short on  = 500;
  short off = t-on; //time period of PWM is 't'us.
      digitalWrite(bluPin, HIGH);
      delayMicroseconds(on);
      digitalWrite(bluPin, LOW);
      delayMicroseconds(off);
}

//WAVE
void redtoyellow()
{
  digitalWrite(redPin, HIGH);
  digitalWrite(bluPin, LOW);
  // fade up green
  for(short i=0; i<=T; i++) {
    short on  = i;
    short off = T-on;       //time period of PWM is 'T'us.
    for( short a=0; a<times; a++ ) 
    {
      digitalWrite(grnPin, HIGH);
      delayMicroseconds(on);
      digitalWrite(grnPin, LOW);
      delayMicroseconds(off);
    }
  }
  digitalWrite(grnPin, HIGH);
}

void yellowtogreen()
{
  digitalWrite(grnPin, HIGH);
  digitalWrite(bluPin, LOW);

  // fade down red
  for(short i=1; i<T; i++) {
    short on  = T-i;
    short off = i;
    for( short a=0; a<times; a++ ) {
      digitalWrite(redPin, HIGH);
      delayMicroseconds(on);
      digitalWrite(redPin, LOW);
      delayMicroseconds(off);
    }
  }
  digitalWrite(redPin, LOW);
}

void greentocyan()
{
  digitalWrite(grnPin, HIGH);
  digitalWrite(redPin, LOW);

  // fade up blue
  for(short i=1; i<T; i++) {
    short on  = i;
    short off = T-on;
    for( short a=0; a<times; a++ ) {
      digitalWrite(bluPin, HIGH);
      delayMicroseconds(on);
      digitalWrite(bluPin, LOW);
      delayMicroseconds(off);
    }
  }
  digitalWrite(bluPin, HIGH);
}


void cyantoblue()
{
  digitalWrite(bluPin, HIGH);
  digitalWrite(redPin, LOW);

  // fade down green
  for(short i=1; i<T; i++) {
    short on  = T-i;
    short off = i;
    for( short a=0; a<times; a++ ) {
      digitalWrite(grnPin, HIGH);
      delayMicroseconds(on);
      digitalWrite(grnPin, LOW);
      delayMicroseconds(off);
    }
  }
  digitalWrite(grnPin, LOW);
}


void bluetomagenta()
{ 
  digitalWrite(bluPin, HIGH);
  digitalWrite(grnPin, LOW);

  // fade up red
  for(short i=1; i<T; i++) {
    short on  = i;
    short off = T-on;
    for( short a=0; a<times; a++ ) {
      digitalWrite(redPin, HIGH);
      delayMicroseconds(on);
      digitalWrite(redPin, LOW);
      delayMicroseconds(off);
    }
  }
  digitalWrite(redPin, HIGH);
}



void magentatored()
{
  digitalWrite(redPin, HIGH);
  digitalWrite(grnPin, LOW);

  // fade down blue
  for(short i=1; i<T; i++) {
    short on  = T-i;
    short off = i;
    for( short a=0; a<times; a++ ) {
      digitalWrite(bluPin, HIGH);
      delayMicroseconds(on);
      digitalWrite(bluPin, LOW);
      delayMicroseconds(off);
    }
  }
  digitalWrite(bluPin, LOW);
}
