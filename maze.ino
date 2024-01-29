//code for maze

// Left wheel
int a_1a = 2;
int a_1b = 3;

// Right wheel
int b_1a = 4;
int b_1b = 5;

// Sensors
int IRSensorPin = 9;
int IRSensorPin2 = 10;

// Speed
int speed = 200;

//counter for turning.
int count = 0;

bool start = true;
void setup() {
  pinMode(a_1a, OUTPUT);
  pinMode(a_1b, OUTPUT);
  pinMode(b_1a, OUTPUT);
  pinMode(b_1b, OUTPUT);
  pinMode(IRSensorPin, INPUT);
  pinMode(IRSensorPin2, INPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(IRSensorPin) == HIGH && digitalRead(IRSensorPin2) == HIGH) {
    // Straight Path
    forward();
  }
  if (digitalRead(IRSensorPin) == HIGH && digitalRead(IRSensorPin2) == LOW) {
    // Left Turn
    left();
  }
  if (digitalRead(IRSensorPin) == LOW && digitalRead(IRSensorPin2) == HIGH) {
    // Turn Right
    right();
  }
  if (digitalRead(IRSensorPin) == LOW && digitalRead(IRSensorPin2) == LOW) {
    // U-Turn
    u_turn();
  }
  // if(start){
  //   forward();
  // }
  // //this is hardcoded following the mazes path.
  // if(sensorStatus == 0 && sensorStatus2 == 0) {
  //   //every time you are supposed to turn right, you turn right.
  //   start = false;
  //   if(count ==0 || count==1 || count==5 || count==6 || count==7 || count==10 || count==11 || count==12 || count==14) {
  //     right();
  //     delay(50);
  //     forward();
  //     count++;
  //   }//everytime you are supposed to turn left, you turn left.
  //    else if(count == 2 || count==3 || count==4 || count==8 || count==9 || count==13 || count==15){ 
  //     left();
  //     delay(50);
  //     forward();
  //     count++;
  // }
}

//functions for movement.
void forward(){
  analogWrite(b_1a, LOW);
  analogWrite(b_1b, speed);

  analogWrite(a_1a, speed);
  analogWrite(a_1b, LOW);
}

void right(){
  analogWrite(a_1a, LOW);
  analogWrite(a_1b, LOW);

  analogWrite(b_1a, LOW);
  analogWrite(b_1b, speed);
}

void left(){
  analogWrite(a_1a, speed);
  analogWrite(a_1b, LOW);

  analogWrite(b_1a, LOW);
  analogWrite(b_1b, LOW);
}

void u_turn() {
  analogWrite(b_1a, speed);
  analogWrite(b_1b, LOW);

  analogWrite(a_1a, LOW);
  analogWrite(a_1b, speed);}

void stop() {
  analogWrite(a_1a, LOW);
  analogWrite(a_1b, LOW);
  analogWrite(b_1a, LOW);
  analogWrite(b_1b, LOW);
}
