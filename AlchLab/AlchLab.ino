
// CHALLENGES STATES
bool waterDone = false;
bool earthDone = false;
bool windDone = false;
bool fireDone = false;

bool done = false;

// RGB LEDS
int redPin0 = 11;
int greenPin0 = 10;
int bluePin0 = 9;

// PINS
int tempSens = 0; // A0
int earth1 = 4; // A1
int earth2 = 3; // A2
int earth3 = 2; // A3
int waterPin = 7; // 7
int windPin = 6; // 6

// PINS FOR TEAM LEDS FROR FOR FINISHING ROUTINE
int team1Pin = 41; // 41
int team2Pin = 42; // 42
int team3Pin = 43; // 43
int team4Pin = 44; // 44
int team5Pin = 45; // 45
int team6Pin = 46; // 46
int team7Pin = 47; // 47
int team8Pin = 48; // 48

// INIT VALUES
int initTemp = 0;
int initForce1 = 0;
int initForce2 = 0;
int initForce3 = 0;

// READING VALUES
int tempReading = 0;
int earth1Reading = 0;
int earth2Reading = 0;
int earth3Reading = 0;
int waterReading = 0;
int windReading = 0;

// THRESHOLD VALUES
int tempThresh = 3;

#define COMMON_ANODE // change if RGB LED is different

void setup() {
  Serial.begin(9600);

  // Define RGB LEDS
  pinMode(redPin0, OUTPUT);
  pinMode(greenPin0, OUTPUT);
  pinMode(bluePin0, OUTPUT);

  // Define team LEDs
  pinMode(team1Pin, OUTPUT);
  pinMode(team2Pin, OUTPUT);
  pinMode(team3Pin, OUTPUT);
  pinMode(team4Pin, OUTPUT);
  pinMode(team5Pin, OUTPUT);
  pinMode(team6Pin, OUTPUT);
  pinMode(team7Pin, OUTPUT);
  pinMode(team8Pin, OUTPUT);

  digitalWrite(earth1, HIGH);
  digitalWrite(earth2, HIGH);
  digitalWrite(earth3, HIGH);
  digitalWrite(waterPin, HIGH);
  digitalWrite(windPin, HIGH);

  setColor(0, 255, 255); // set inital RGB LEDs to off

  readInitValues(); // set all needed intial values
}

void loop() {
  // check if challenges are done
  // if they are not done yet
  if(!waterDone)
    readWater ();

  if(!earthDone)
    readEarth ();

  if(!windDone)
    readWind ();

  if (!fireDone)
    readFire ();

  // start finishing routine if all challenges are solved/done
  if(waterDone && earthDone && windDone && fireDone && !done)
    endLab ();
}

void readInitValues()
{
  initTemp = analogRead(tempSens); // read and set initial temperature value
}

void readWater ()
{
  waterReading = digitalRead(waterPin);

  // check if water circuit is closed
  if(waterReading == LOW)
  {
    setColor(0, 0, 255); // change color
    waterDone = true; // mark as done
  }
}

void readEarth ()
{
  earth1Reading = digitalRead(earth1);
  earth2Reading = digitalRead(earth2);
  earth3Reading = digitalRead(earth3);

  // check if all three circuits are closed
  if(earth1Reading == LOW && earth2Reading == LOW && earth3Reading == LOW)
  {
    setColor(0, 255, 0); // change color
    earthDone = true; // mark as done
    
  }
}

void readWind ()
{
  windReading = digitalRead(windPin);

  // check if wind circuit is closed
  if(windReading == LOW)
  {
    setColor(0, 255, 255); // change color
    windDone = true; // mark as done
  }
}

void readFire ()
{
  tempReading = analogRead(tempSens);

  // check if temperature surpassed the given threshold
  if(initTemp - tempReading >= tempThresh)
  {
    setColor(255, 0, 0); // change color
    fireDone = true; // mark as done
  }
}

// start finishing routine
void endLab()
{
  done = true;
  delay(500);
  setColor(255, 0, 255); // change potion color
  delay(500);
  
  // hardcoded routine to "animate" team LEDs
  // running through all of them and finally showing the correct one
  digitalWrite(team1Pin, HIGH);
  delay(200);
  digitalWrite(team1Pin, LOW);
  digitalWrite(team2Pin, HIGH);
  delay(200);
  digitalWrite(team2Pin, LOW);
  digitalWrite(team3Pin, HIGH);
  delay(200);
  digitalWrite(team3Pin, LOW);
  digitalWrite(team4Pin, HIGH);
  delay(200);
  digitalWrite(team4Pin, LOW);
  digitalWrite(team5Pin, HIGH);
  delay(200);
  digitalWrite(team5Pin, LOW);
  digitalWrite(team6Pin, HIGH);
  delay(200);
  digitalWrite(team6Pin, LOW);
  digitalWrite(team7Pin, HIGH);
  delay(200);
  digitalWrite(team7Pin, LOW);
  digitalWrite(team8Pin, HIGH);
  delay(200);
  digitalWrite(team8Pin, LOW);
  digitalWrite(team7Pin, HIGH);
  delay(200);
  digitalWrite(team7Pin, LOW);
  digitalWrite(team6Pin, HIGH);
  delay(200);
  digitalWrite(team6Pin, LOW);
  digitalWrite(team5Pin, HIGH);
  delay(200);
  digitalWrite(team5Pin, LOW);
  digitalWrite(team4Pin, HIGH);
  delay(200);
  digitalWrite(team4Pin, LOW);
  digitalWrite(team3Pin, HIGH);
  delay(200);
  digitalWrite(team3Pin, LOW);
  digitalWrite(team2Pin, HIGH);
  delay(200);
  digitalWrite(team2Pin, LOW);
  digitalWrite(team1Pin, HIGH);
  delay(200);
  digitalWrite(team1Pin, LOW);
  delay(600);
  digitalWrite(team4Pin, HIGH); // show correct LED
  
}

// set the color of RGB LEDs
void setColor(int red, int green, int blue)
{
  /*
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  */

  red = 255 - red;
  green = 255 - green;
  blue = 255 - blue;
  
  analogWrite(redPin0, red);
  analogWrite(greenPin0, green);
  analogWrite(bluePin0, blue);
}
