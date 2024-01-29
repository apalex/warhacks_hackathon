//code for follow line.

//left wheel
int a_1a = 2;
int a_1b = 3;

//right wheel
int b_1a = 4;
int b_1b = 5;

//sensors
int IRSensorPin = 9;
int IRSensorPin2 = 10;

//speed
int speed = 150;

  int sensorStatus =digitalRead(IRSensorPin);

  int sensorStatus2 = digitalRead(IRSensorPin2);

void setup() {
  Serial.begin(9600);
  pinMode(a_1a, OUTPUT);
  pinMode(a_1b, OUTPUT);
  pinMode(b_1a, OUTPUT);
  pinMode(b_1b, OUTPUT);

}

void loop() {
  int sensorStatus  =digitalRead(IRSensorPin);

  int sensorStatus2 = digitalRead(IRSensorPin2);

  Serial.println("first" + sensorStatus);
  Serial.println("Second" + sensorStatus2);


  if(sensorStatus == 1 && sensorStatus2 == 0) {
    left();
  }else if(sensorStatus2 == 1 && sensorStatus == 0) {
    right();
  }else if(sensorStatus == 1 && sensorStatus2 == 1){
      stop();
  }else{
    forward();
  }
}
//functions for movement.
void forward(){
  analogWrite(a_1a, speed);
  analogWrite(a_1b, LOW);
  analogWrite(b_1a, LOW);
  analogWrite(b_1b, speed);
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

void stop() {
  analogWrite(a_1a, LOW);
  analogWrite(a_1b, LOW);
  analogWrite(b_1a, LOW);
  analogWrite(b_1b, LOW);
}
