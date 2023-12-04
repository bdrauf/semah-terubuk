const int TRIG_PIN1 = 2; 
const int ECHO_PIN1 = 3;

const int TRIG_PIN2 = 4;
const int ECHO_PIN2 = 5;

const int TRIG_PIN3 = 6;
const int ECHO_PIN3 = 7; 

const int TRIG_PIN4 = 8;
const int ECHO_PIN4 = 9;

const int TRIG_PIN5 = 10;
const int ECHO_PIN5 = 11;

const int TRIG_PIN6 = 12;
const int ECHO_PIN6 = 13;

const int TRIG_PIN7 = A0;
const int ECHO_PIN7 = A1;

const int TRIG_PIN8 = A2;
const int ECHO_PIN8 = A3;

const int RELAY_PIN1_1 = 22;
const int RELAY_PIN1_2 = 24;
const int RELAY_PIN1_3 = 26;
const int RELAY_PIN1_4 = 28;

const int RELAY_PIN2_1 = 30;
const int RELAY_PIN2_2 = 32;
const int RELAY_PIN2_3 = 34;
const int RELAY_PIN2_4 = 36;

const int RELAY_PIN3_1 = 38;
const int RELAY_PIN3_2 = 40;
const int RELAY_PIN3_3 = 42;
const int RELAY_PIN3_4 = 44;

const int RELAY_PIN4_1 = 46;
const int RELAY_PIN4_2 = 48;
const int RELAY_PIN4_3 = 50;
const int RELAY_PIN4_4 = 52;

const int RELAY_PIN5_1 = 23;
const int RELAY_PIN5_2 = 25;
const int RELAY_PIN5_3 = 27;
const int RELAY_PIN5_4 = 29;

const int RELAY_PIN6_1 = 31;
const int RELAY_PIN6_2 = 33;
const int RELAY_PIN6_3 = 35;
const int RELAY_PIN6_4 = 37;

const int RELAY_PIN7_1 = 39;
const int RELAY_PIN7_2 = 41;
const int RELAY_PIN7_3 = 43;
const int RELAY_PIN7_4 = 45;

const int RELAY_PIN8_1 = 47;
const int RELAY_PIN8_2 = 49;
const int RELAY_PIN8_3 = 51;
const int RELAY_PIN8_4 = 53;

const int DISTANCE_THRESHOLD = 50; // centimeters

// variables will change:
float duration_us, distance_cm;

bool codeEnabled = true;

void setup() {
  Serial.begin (9600);       
  pinMode(TRIG_PIN1, OUTPUT);  
  pinMode(ECHO_PIN1, INPUT);  

  pinMode(TRIG_PIN2, OUTPUT);  
  pinMode(ECHO_PIN2, INPUT);  

  pinMode(TRIG_PIN3, OUTPUT);  
  pinMode(ECHO_PIN3, INPUT);

  pinMode(TRIG_PIN4, OUTPUT);  
  pinMode(ECHO_PIN4, INPUT);

  pinMode(TRIG_PIN5, OUTPUT);  
  pinMode(ECHO_PIN5, INPUT);

  pinMode(TRIG_PIN6, OUTPUT);  
  pinMode(ECHO_PIN6, INPUT);

  pinMode(TRIG_PIN7, OUTPUT);  
  pinMode(ECHO_PIN7, INPUT);

  pinMode(TRIG_PIN8, OUTPUT);  
  pinMode(ECHO_PIN8, INPUT);

  pinMode(RELAY_PIN1_1, OUTPUT);
  pinMode(RELAY_PIN1_2, OUTPUT);
  pinMode(RELAY_PIN1_3, OUTPUT);
  pinMode(RELAY_PIN1_4, OUTPUT);

  pinMode(RELAY_PIN2_1, OUTPUT);
  pinMode(RELAY_PIN2_2, OUTPUT);
  pinMode(RELAY_PIN2_3, OUTPUT);
  pinMode(RELAY_PIN2_4, OUTPUT);

  pinMode(RELAY_PIN3_1, OUTPUT);
  pinMode(RELAY_PIN3_2, OUTPUT);
  pinMode(RELAY_PIN3_3, OUTPUT);
  pinMode(RELAY_PIN3_4, OUTPUT);

  pinMode(RELAY_PIN4_1, OUTPUT);
  pinMode(RELAY_PIN4_2, OUTPUT);
  pinMode(RELAY_PIN4_3, OUTPUT);
  pinMode(RELAY_PIN4_4, OUTPUT);

  pinMode(RELAY_PIN5_1, OUTPUT);
  pinMode(RELAY_PIN5_2, OUTPUT);
  pinMode(RELAY_PIN5_3, OUTPUT);
  pinMode(RELAY_PIN5_4, OUTPUT);

  pinMode(RELAY_PIN6_1, OUTPUT);
  pinMode(RELAY_PIN6_2, OUTPUT);
  pinMode(RELAY_PIN6_3, OUTPUT);
  pinMode(RELAY_PIN6_4, OUTPUT);

  pinMode(RELAY_PIN7_1, OUTPUT);
  pinMode(RELAY_PIN7_2, OUTPUT);
  pinMode(RELAY_PIN7_3, OUTPUT);
  pinMode(RELAY_PIN7_4, OUTPUT);

  pinMode(RELAY_PIN8_1, OUTPUT);
  pinMode(RELAY_PIN8_2, OUTPUT);
  pinMode(RELAY_PIN8_3, OUTPUT);
  pinMode(RELAY_PIN8_4, OUTPUT);
}

void disableRelays() {
  digitalWrite(RELAY_PIN1_1, LOW); digitalWrite(RELAY_PIN2_1, LOW); digitalWrite(RELAY_PIN3_1, LOW); digitalWrite(RELAY_PIN4_1, LOW); digitalWrite(RELAY_PIN5_1, LOW); digitalWrite(RELAY_PIN6_1, LOW); digitalWrite(RELAY_PIN7_1, LOW); digitalWrite(RELAY_PIN8_1, LOW);
  digitalWrite(RELAY_PIN1_2, LOW); digitalWrite(RELAY_PIN2_2, LOW); digitalWrite(RELAY_PIN3_2, LOW); digitalWrite(RELAY_PIN4_2, LOW); digitalWrite(RELAY_PIN5_2, LOW); digitalWrite(RELAY_PIN6_2, LOW); digitalWrite(RELAY_PIN7_2, LOW); digitalWrite(RELAY_PIN8_2, LOW);
  digitalWrite(RELAY_PIN1_3, LOW); digitalWrite(RELAY_PIN2_3, LOW); digitalWrite(RELAY_PIN3_3, LOW); digitalWrite(RELAY_PIN4_3, LOW); digitalWrite(RELAY_PIN5_3, LOW); digitalWrite(RELAY_PIN6_3, LOW); digitalWrite(RELAY_PIN7_3, LOW); digitalWrite(RELAY_PIN8_3, LOW);
  digitalWrite(RELAY_PIN1_4, LOW); digitalWrite(RELAY_PIN2_4, LOW); digitalWrite(RELAY_PIN3_4, LOW); digitalWrite(RELAY_PIN4_4, LOW); digitalWrite(RELAY_PIN5_4, LOW); digitalWrite(RELAY_PIN6_4, LOW); digitalWrite(RELAY_PIN7_4, LOW); digitalWrite(RELAY_PIN8_4, LOW);
  digitalWrite(RELAY_PIN1_1, HIGH); digitalWrite(RELAY_PIN2_1, HIGH); digitalWrite(RELAY_PIN3_1, HIGH); digitalWrite(RELAY_PIN4_1, HIGH); digitalWrite(RELAY_PIN5_1, HIGH); digitalWrite(RELAY_PIN6_1, HIGH); digitalWrite(RELAY_PIN7_1, HIGH); digitalWrite(RELAY_PIN8_1, HIGH);
  digitalWrite(RELAY_PIN1_2, HIGH); digitalWrite(RELAY_PIN2_2, HIGH); digitalWrite(RELAY_PIN3_2, HIGH); digitalWrite(RELAY_PIN4_2, HIGH); digitalWrite(RELAY_PIN5_2, HIGH); digitalWrite(RELAY_PIN6_2, HIGH); digitalWrite(RELAY_PIN7_2, HIGH); digitalWrite(RELAY_PIN8_2, HIGH);
  digitalWrite(RELAY_PIN1_3, HIGH); digitalWrite(RELAY_PIN2_3, HIGH); digitalWrite(RELAY_PIN3_3, HIGH); digitalWrite(RELAY_PIN4_3, HIGH); digitalWrite(RELAY_PIN5_3, HIGH); digitalWrite(RELAY_PIN6_3, HIGH); digitalWrite(RELAY_PIN7_3, HIGH); digitalWrite(RELAY_PIN8_3, HIGH);
  digitalWrite(RELAY_PIN1_4, HIGH); digitalWrite(RELAY_PIN2_4, HIGH); digitalWrite(RELAY_PIN3_4, HIGH); digitalWrite(RELAY_PIN4_4, HIGH); digitalWrite(RELAY_PIN5_4, HIGH); digitalWrite(RELAY_PIN6_4, HIGH); digitalWrite(RELAY_PIN7_4, HIGH); digitalWrite(RELAY_PIN8_4, HIGH);
  digitalWrite(RELAY_PIN1_1, HIGH); digitalWrite(RELAY_PIN1_2, HIGH); digitalWrite(RELAY_PIN1_3, HIGH); digitalWrite(RELAY_PIN1_4, HIGH); digitalWrite(RELAY_PIN2_1, HIGH); digitalWrite(RELAY_PIN2_2, HIGH); digitalWrite(RELAY_PIN2_3, HIGH); digitalWrite(RELAY_PIN2_4, HIGH); digitalWrite(RELAY_PIN3_1, HIGH); digitalWrite(RELAY_PIN3_2, HIGH); digitalWrite(RELAY_PIN3_3, HIGH); digitalWrite(RELAY_PIN3_4, HIGH); digitalWrite(RELAY_PIN4_1, HIGH); digitalWrite(RELAY_PIN4_2, HIGH); digitalWrite(RELAY_PIN4_3, HIGH); digitalWrite(RELAY_PIN4_4, HIGH); digitalWrite(RELAY_PIN5_1, HIGH); digitalWrite(RELAY_PIN5_2, HIGH); digitalWrite(RELAY_PIN5_3, HIGH); digitalWrite(RELAY_PIN5_4, HIGH); digitalWrite(RELAY_PIN6_1, HIGH); digitalWrite(RELAY_PIN6_2, HIGH); digitalWrite(RELAY_PIN6_3, HIGH); digitalWrite(RELAY_PIN6_4, HIGH); digitalWrite(RELAY_PIN7_1, HIGH); digitalWrite(RELAY_PIN7_2, HIGH); digitalWrite(RELAY_PIN7_3, HIGH); digitalWrite(RELAY_PIN7_4, HIGH); digitalWrite(RELAY_PIN8_1, HIGH); digitalWrite(RELAY_PIN8_2, HIGH); digitalWrite(RELAY_PIN8_3, HIGH); digitalWrite(RELAY_PIN8_4, HIGH);
  digitalWrite(RELAY_PIN1_1, LOW); digitalWrite(RELAY_PIN1_2, LOW); digitalWrite(RELAY_PIN1_3, LOW); digitalWrite(RELAY_PIN1_4, LOW); digitalWrite(RELAY_PIN2_1, LOW); digitalWrite(RELAY_PIN2_2, LOW); digitalWrite(RELAY_PIN2_3, LOW); digitalWrite(RELAY_PIN2_4, LOW); digitalWrite(RELAY_PIN3_1, LOW); digitalWrite(RELAY_PIN3_2, LOW); digitalWrite(RELAY_PIN3_3, LOW); digitalWrite(RELAY_PIN3_4, LOW); digitalWrite(RELAY_PIN4_1, LOW); digitalWrite(RELAY_PIN4_2, LOW); digitalWrite(RELAY_PIN4_3, LOW); digitalWrite(RELAY_PIN4_4, LOW); digitalWrite(RELAY_PIN5_1, LOW); digitalWrite(RELAY_PIN5_2, LOW); digitalWrite(RELAY_PIN5_3, LOW); digitalWrite(RELAY_PIN5_4, LOW); digitalWrite(RELAY_PIN6_1, LOW); digitalWrite(RELAY_PIN6_2, LOW); digitalWrite(RELAY_PIN6_3, LOW); digitalWrite(RELAY_PIN6_4, LOW); digitalWrite(RELAY_PIN7_1, LOW); digitalWrite(RELAY_PIN7_2, LOW); digitalWrite(RELAY_PIN7_3, LOW); digitalWrite(RELAY_PIN7_4, LOW); digitalWrite(RELAY_PIN8_1, LOW); digitalWrite(RELAY_PIN8_2, LOW); digitalWrite(RELAY_PIN8_3, LOW); digitalWrite(RELAY_PIN8_4, LOW);
}

void loop() {

  bool sensor1_triggered = true;
  bool sensor2_triggered = true;
  bool sensor3_triggered = true;
  bool sensor4_triggered = true;
  bool sensor5_triggered = true;
  bool sensor6_triggered = true;
  bool sensor7_triggered = true;
  bool sensor8_triggered = true;

  // Sensor 1
  digitalWrite(TRIG_PIN1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN1, LOW);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(ECHO_PIN1, HIGH);
  // calculate the distance
  distance_cm = 0.017 * duration_us;

  if(distance_cm > DISTANCE_THRESHOLD) {
    sensor1_triggered = false;
  }

  // Sensor 2
  digitalWrite(TRIG_PIN2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN2, LOW);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(ECHO_PIN2, HIGH);
  // calculate the distance
  distance_cm = 0.017 * duration_us;

  if(distance_cm > DISTANCE_THRESHOLD) {
    sensor2_triggered = false;
  }

  // Sensor 3
  digitalWrite(TRIG_PIN3, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN3, LOW);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(ECHO_PIN3, HIGH);
  // calculate the distance
  distance_cm = 0.017 * duration_us;

  if(distance_cm > DISTANCE_THRESHOLD) {
    sensor3_triggered = false;
  }

    // Sensor 4
  digitalWrite(TRIG_PIN4, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN4, LOW);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(ECHO_PIN4, HIGH);
  // calculate the distance
  distance_cm = 0.017 * duration_us;

  if(distance_cm > DISTANCE_THRESHOLD) {
    sensor4_triggered = false;
  }

    // Sensor 5
  digitalWrite(TRIG_PIN5, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN5, LOW);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(ECHO_PIN5, HIGH);
  // calculate the distance
  distance_cm = 0.017 * duration_us;

  if(distance_cm > DISTANCE_THRESHOLD) {
    sensor5_triggered = false;
  }

    // Sensor 6
  digitalWrite(TRIG_PIN6, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN6, LOW);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(ECHO_PIN6, HIGH);
  // calculate the distance
  distance_cm = 0.017 * duration_us;

  if(distance_cm > DISTANCE_THRESHOLD) {
    sensor6_triggered = false;
  }

    // Sensor 7
  digitalWrite(TRIG_PIN7, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN7, LOW);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(ECHO_PIN7, HIGH);
  // calculate the distance
  distance_cm = 0.017 * duration_us;

  if(distance_cm > DISTANCE_THRESHOLD) {
    sensor7_triggered = false;
  }

   // Sensor 8
  digitalWrite(TRIG_PIN8, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN8, LOW);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(ECHO_PIN8, HIGH);
  // calculate the distance
  distance_cm = 0.017 * duration_us;

  if(distance_cm > DISTANCE_THRESHOLD) {
    sensor8_triggered = false;
  }

if (codeEnabled) {
  if (sensor1_triggered) {
    digitalWrite(RELAY_PIN1_1, LOW); 
    digitalWrite(RELAY_PIN1_2, LOW); 
    delay(100);
    digitalWrite(RELAY_PIN1_3, LOW); 
    delay(100);
    digitalWrite(RELAY_PIN1_4, LOW); 
    delay(100);
    digitalWrite(RELAY_PIN1_1, HIGH); 
    digitalWrite(RELAY_PIN1_2, HIGH); 
    delay(100);
    digitalWrite(RELAY_PIN1_3, HIGH); 
    delay(100);
    digitalWrite(RELAY_PIN1_4, HIGH); 
    delay(100);
    digitalWrite(RELAY_PIN1_1, HIGH); digitalWrite(RELAY_PIN1_2, HIGH); digitalWrite(RELAY_PIN1_3, HIGH); digitalWrite(RELAY_PIN1_4, HIGH); 
    delay(200);
    digitalWrite(RELAY_PIN1_1, LOW); digitalWrite(RELAY_PIN1_2, LOW); digitalWrite(RELAY_PIN1_3, LOW); digitalWrite(RELAY_PIN1_4, LOW);
    delay(200);
    digitalWrite(RELAY_PIN1_1, HIGH); digitalWrite(RELAY_PIN1_2, HIGH); digitalWrite(RELAY_PIN1_3, HIGH); digitalWrite(RELAY_PIN1_4, HIGH); 
    delay(200);
  } else {
    digitalWrite(RELAY_PIN1_1, HIGH); 
    digitalWrite(RELAY_PIN1_2, HIGH); 
    digitalWrite(RELAY_PIN1_3, HIGH); 
    digitalWrite(RELAY_PIN1_4, HIGH);
  }

  if (sensor2_triggered) {
    digitalWrite(RELAY_PIN2_1, LOW); 
    digitalWrite(RELAY_PIN2_2, LOW); 
    delay(100);
    digitalWrite(RELAY_PIN2_3, LOW); 
    delay(100);
    digitalWrite(RELAY_PIN2_4, LOW); 
    delay(100);
    digitalWrite(RELAY_PIN2_1, HIGH); 
    digitalWrite(RELAY_PIN2_2, HIGH); 
    delay(100);
    digitalWrite(RELAY_PIN2_3, HIGH); 
    delay(100);
    digitalWrite(RELAY_PIN2_4, HIGH); 
    delay(100);
    digitalWrite(RELAY_PIN2_1, HIGH); digitalWrite(RELAY_PIN2_2, HIGH); digitalWrite(RELAY_PIN2_3, HIGH); digitalWrite(RELAY_PIN2_4, HIGH); 
    delay(200);
    digitalWrite(RELAY_PIN2_1, LOW); digitalWrite(RELAY_PIN2_2, LOW); digitalWrite(RELAY_PIN2_3, LOW); digitalWrite(RELAY_PIN2_4, LOW);
    delay(200);
    digitalWrite(RELAY_PIN2_1, HIGH); digitalWrite(RELAY_PIN2_2, HIGH); digitalWrite(RELAY_PIN2_3, HIGH); digitalWrite(RELAY_PIN2_4, HIGH); 
    delay(200);
  } else {
    digitalWrite(RELAY_PIN2_1, HIGH); 
    digitalWrite(RELAY_PIN2_2, HIGH); 
    digitalWrite(RELAY_PIN2_3, HIGH); 
    digitalWrite(RELAY_PIN2_4, HIGH);
  }

  if (sensor3_triggered) {
    digitalWrite(RELAY_PIN3_1, LOW); 
    digitalWrite(RELAY_PIN3_2, LOW); 
    delay(100);
    digitalWrite(RELAY_PIN3_3, LOW); 
    delay(100);
    digitalWrite(RELAY_PIN3_4, LOW); 
    delay(100);
    digitalWrite(RELAY_PIN3_1, HIGH); 
    digitalWrite(RELAY_PIN3_2, HIGH); 
    delay(100);
    digitalWrite(RELAY_PIN3_3, HIGH); 
    delay(100);
    digitalWrite(RELAY_PIN3_4, HIGH); 
    delay(100);
    digitalWrite(RELAY_PIN3_1, HIGH); digitalWrite(RELAY_PIN3_2, HIGH); digitalWrite(RELAY_PIN3_3, HIGH); digitalWrite(RELAY_PIN3_4, HIGH); 
    delay(200);
    digitalWrite(RELAY_PIN3_1, LOW); digitalWrite(RELAY_PIN3_2, LOW); digitalWrite(RELAY_PIN3_3, LOW); digitalWrite(RELAY_PIN3_4, LOW);
    delay(200);
    digitalWrite(RELAY_PIN3_1, HIGH); digitalWrite(RELAY_PIN3_2, HIGH); digitalWrite(RELAY_PIN3_3, HIGH); digitalWrite(RELAY_PIN3_4, HIGH); 
    delay(200);
  } else {
    digitalWrite(RELAY_PIN3_1, HIGH); 
    digitalWrite(RELAY_PIN3_2, HIGH); 
    digitalWrite(RELAY_PIN3_3, HIGH); 
    digitalWrite(RELAY_PIN3_4, HIGH);
  }

  if (sensor4_triggered) {
    digitalWrite(RELAY_PIN4_1, LOW); 
    digitalWrite(RELAY_PIN4_2, LOW); 
    delay(100);
    digitalWrite(RELAY_PIN4_3, LOW); 
    delay(100);
    digitalWrite(RELAY_PIN4_4, LOW); 
    delay(100);
    digitalWrite(RELAY_PIN4_1, HIGH); 
    digitalWrite(RELAY_PIN4_2, HIGH); 
    delay(100);
    digitalWrite(RELAY_PIN4_3, HIGH); 
    delay(100);
    digitalWrite(RELAY_PIN4_4, HIGH); 
    delay(100);
    digitalWrite(RELAY_PIN4_1, HIGH); digitalWrite(RELAY_PIN4_2, HIGH); digitalWrite(RELAY_PIN4_3, HIGH); digitalWrite(RELAY_PIN4_4, HIGH); 
    delay(200);
    digitalWrite(RELAY_PIN4_1, LOW); digitalWrite(RELAY_PIN4_2, LOW); digitalWrite(RELAY_PIN4_3, LOW); digitalWrite(RELAY_PIN4_4, LOW);
    delay(200);
    digitalWrite(RELAY_PIN4_1, HIGH); digitalWrite(RELAY_PIN4_2, HIGH); digitalWrite(RELAY_PIN4_3, HIGH); digitalWrite(RELAY_PIN4_4, HIGH); 
    delay(200);
  } else {
    digitalWrite(RELAY_PIN4_1, HIGH); 
    digitalWrite(RELAY_PIN4_2, HIGH); 
    digitalWrite(RELAY_PIN4_3, HIGH); 
    digitalWrite(RELAY_PIN4_4, HIGH);
  }

  if (sensor5_triggered) {
    digitalWrite(RELAY_PIN5_1, LOW); 
    digitalWrite(RELAY_PIN5_2, LOW); 
    delay(100);
    digitalWrite(RELAY_PIN5_3, LOW); 
    delay(100);
    digitalWrite(RELAY_PIN5_4, LOW); 
    delay(100);
    digitalWrite(RELAY_PIN5_1, HIGH); 
    digitalWrite(RELAY_PIN5_2, HIGH); 
    delay(100);
    digitalWrite(RELAY_PIN5_3, HIGH); 
    delay(100);
    digitalWrite(RELAY_PIN5_4, HIGH); 
    delay(100);
    digitalWrite(RELAY_PIN5_1, HIGH); digitalWrite(RELAY_PIN5_2, HIGH); digitalWrite(RELAY_PIN5_3, HIGH); digitalWrite(RELAY_PIN5_4, HIGH); 
    delay(200);
    digitalWrite(RELAY_PIN5_1, LOW); digitalWrite(RELAY_PIN5_2, LOW); digitalWrite(RELAY_PIN5_3, LOW); digitalWrite(RELAY_PIN5_4, LOW);
    delay(200);
    digitalWrite(RELAY_PIN5_1, HIGH); digitalWrite(RELAY_PIN5_2, HIGH); digitalWrite(RELAY_PIN5_3, HIGH); digitalWrite(RELAY_PIN5_4, HIGH); 
    delay(200);
  } else {
    digitalWrite(RELAY_PIN5_1, HIGH); 
    digitalWrite(RELAY_PIN5_2, HIGH); 
    digitalWrite(RELAY_PIN5_3, HIGH); 
    digitalWrite(RELAY_PIN5_4, HIGH);
  }

  if (sensor6_triggered) {
    digitalWrite(RELAY_PIN6_1, LOW); 
    digitalWrite(RELAY_PIN6_2, LOW); 
    delay(100);
    digitalWrite(RELAY_PIN6_3, LOW); 
    delay(100);
    digitalWrite(RELAY_PIN6_4, LOW); 
    delay(100);
    digitalWrite(RELAY_PIN6_1, HIGH); 
    digitalWrite(RELAY_PIN6_2, HIGH); 
    delay(100);
    digitalWrite(RELAY_PIN6_3, HIGH); 
    delay(100);
    digitalWrite(RELAY_PIN6_4, HIGH); 
    delay(100);
    digitalWrite(RELAY_PIN6_1, HIGH); digitalWrite(RELAY_PIN6_2, HIGH); digitalWrite(RELAY_PIN6_3, HIGH); digitalWrite(RELAY_PIN6_4, HIGH); 
    delay(200);
    digitalWrite(RELAY_PIN6_1, LOW); digitalWrite(RELAY_PIN6_2, LOW); digitalWrite(RELAY_PIN6_3, LOW); digitalWrite(RELAY_PIN6_4, LOW);
    delay(200);
    digitalWrite(RELAY_PIN6_1, HIGH); digitalWrite(RELAY_PIN6_2, HIGH); digitalWrite(RELAY_PIN6_3, HIGH); digitalWrite(RELAY_PIN6_4, HIGH); 
    delay(200);
  } else {
    digitalWrite(RELAY_PIN6_1, HIGH); 
    digitalWrite(RELAY_PIN6_2, HIGH); 
    digitalWrite(RELAY_PIN6_3, HIGH); 
    digitalWrite(RELAY_PIN6_4, HIGH);
  }

 if (sensor7_triggered) {
    digitalWrite(RELAY_PIN7_1, LOW); 
    digitalWrite(RELAY_PIN7_2, LOW); 
    delay(100);
    digitalWrite(RELAY_PIN7_3, LOW); 
    delay(100);
    digitalWrite(RELAY_PIN7_4, LOW); 
    delay(100);
    digitalWrite(RELAY_PIN7_1, HIGH); 
    digitalWrite(RELAY_PIN7_2, HIGH); 
    delay(100);
    digitalWrite(RELAY_PIN7_3, HIGH); 
    delay(100);
    digitalWrite(RELAY_PIN7_4, HIGH); 
    delay(100);
    digitalWrite(RELAY_PIN7_1, HIGH); digitalWrite(RELAY_PIN7_2, HIGH); digitalWrite(RELAY_PIN7_3, HIGH); digitalWrite(RELAY_PIN7_4, HIGH); 
    delay(200);
    digitalWrite(RELAY_PIN7_1, LOW); digitalWrite(RELAY_PIN7_2, LOW); digitalWrite(RELAY_PIN7_3, LOW); digitalWrite(RELAY_PIN7_4, LOW);
    delay(200);
    digitalWrite(RELAY_PIN7_1, HIGH); digitalWrite(RELAY_PIN7_2, HIGH); digitalWrite(RELAY_PIN7_3, HIGH); digitalWrite(RELAY_PIN7_4, HIGH); 
    delay(200);
  } else {
    digitalWrite(RELAY_PIN7_1, HIGH); 
    digitalWrite(RELAY_PIN7_2, HIGH); 
    digitalWrite(RELAY_PIN7_3, HIGH); 
    digitalWrite(RELAY_PIN7_4, HIGH);
  }

  if (sensor8_triggered) {
    digitalWrite(RELAY_PIN8_1, LOW); 
    digitalWrite(RELAY_PIN8_2, LOW); 
    delay(100);
    digitalWrite(RELAY_PIN8_3, LOW); 
    delay(100);
    digitalWrite(RELAY_PIN8_4, LOW); 
    delay(100);
    digitalWrite(RELAY_PIN8_1, HIGH); 
    digitalWrite(RELAY_PIN8_2, HIGH); 
    delay(100);
    digitalWrite(RELAY_PIN8_3, HIGH); 
    delay(100);
    digitalWrite(RELAY_PIN8_4, HIGH); 
    delay(100);
    digitalWrite(RELAY_PIN8_1, HIGH); digitalWrite(RELAY_PIN8_2, HIGH); digitalWrite(RELAY_PIN8_3, HIGH); digitalWrite(RELAY_PIN8_4, HIGH); 
    delay(200);
    digitalWrite(RELAY_PIN8_1, LOW); digitalWrite(RELAY_PIN8_2, LOW); digitalWrite(RELAY_PIN8_3, LOW); digitalWrite(RELAY_PIN8_4, LOW);
    delay(200);
    digitalWrite(RELAY_PIN8_1, HIGH); digitalWrite(RELAY_PIN8_2, HIGH); digitalWrite(RELAY_PIN8_3, HIGH); digitalWrite(RELAY_PIN8_4, HIGH); 
    delay(200);
  } else {
    digitalWrite(RELAY_PIN8_1, HIGH); 
    digitalWrite(RELAY_PIN8_2, HIGH); 
    digitalWrite(RELAY_PIN8_3, HIGH); 
    digitalWrite(RELAY_PIN8_4, HIGH);
  }

}
  if (sensor1_triggered && sensor2_triggered && sensor3_triggered && sensor4_triggered && sensor5_triggered && sensor6_triggered && sensor7_triggered && sensor8_triggered) {
    // Trigger new pattern here
    // You can add your pattern logic here
    // For example, turn on all relays for a specific duration
      // generate 10-microsecond pulse to TRIG pin
    codeEnabled = false;
    digitalWrite(RELAY_PIN1_1, LOW); digitalWrite(RELAY_PIN2_1, LOW); digitalWrite(RELAY_PIN3_1, LOW); digitalWrite(RELAY_PIN4_1, LOW); digitalWrite(RELAY_PIN5_1, LOW); digitalWrite(RELAY_PIN6_1, LOW); digitalWrite(RELAY_PIN7_1, LOW); digitalWrite(RELAY_PIN8_1, LOW);
    delay(100);
    digitalWrite(RELAY_PIN1_2, LOW); digitalWrite(RELAY_PIN2_2, LOW); digitalWrite(RELAY_PIN3_2, LOW); digitalWrite(RELAY_PIN4_2, LOW); digitalWrite(RELAY_PIN5_2, LOW); digitalWrite(RELAY_PIN6_2, LOW); digitalWrite(RELAY_PIN7_2, LOW); digitalWrite(RELAY_PIN8_2, LOW);
    digitalWrite(RELAY_PIN1_3, LOW); digitalWrite(RELAY_PIN2_3, LOW); digitalWrite(RELAY_PIN3_3, LOW); digitalWrite(RELAY_PIN4_3, LOW); digitalWrite(RELAY_PIN5_3, LOW); digitalWrite(RELAY_PIN6_3, LOW); digitalWrite(RELAY_PIN7_3, LOW); digitalWrite(RELAY_PIN8_3, LOW);
    delay(100);
    digitalWrite(RELAY_PIN1_4, LOW); digitalWrite(RELAY_PIN2_4, LOW); digitalWrite(RELAY_PIN3_4, LOW); digitalWrite(RELAY_PIN4_4, LOW); digitalWrite(RELAY_PIN5_4, LOW); digitalWrite(RELAY_PIN6_4, LOW); digitalWrite(RELAY_PIN7_4, LOW); digitalWrite(RELAY_PIN8_4, LOW);
    digitalWrite(RELAY_PIN1_1, HIGH); digitalWrite(RELAY_PIN2_1, HIGH); digitalWrite(RELAY_PIN3_1, HIGH); digitalWrite(RELAY_PIN4_1, HIGH); digitalWrite(RELAY_PIN5_1, HIGH); digitalWrite(RELAY_PIN6_1, HIGH); digitalWrite(RELAY_PIN7_1, HIGH); digitalWrite(RELAY_PIN8_1, HIGH);
    delay(100);
    digitalWrite(RELAY_PIN1_2, HIGH); digitalWrite(RELAY_PIN2_2, HIGH); digitalWrite(RELAY_PIN3_2, HIGH); digitalWrite(RELAY_PIN4_2, HIGH); digitalWrite(RELAY_PIN5_2, HIGH); digitalWrite(RELAY_PIN6_2, HIGH); digitalWrite(RELAY_PIN7_2, HIGH); digitalWrite(RELAY_PIN8_2, HIGH);
    delay(100);
    digitalWrite(RELAY_PIN1_3, HIGH); digitalWrite(RELAY_PIN2_3, HIGH); digitalWrite(RELAY_PIN3_3, HIGH); digitalWrite(RELAY_PIN4_3, HIGH); digitalWrite(RELAY_PIN5_3, HIGH); digitalWrite(RELAY_PIN6_3, HIGH); digitalWrite(RELAY_PIN7_3, HIGH); digitalWrite(RELAY_PIN8_3, HIGH);
    delay(100);
    digitalWrite(RELAY_PIN1_4, HIGH); digitalWrite(RELAY_PIN2_4, HIGH); digitalWrite(RELAY_PIN3_4, HIGH); digitalWrite(RELAY_PIN4_4, HIGH); digitalWrite(RELAY_PIN5_4, HIGH); digitalWrite(RELAY_PIN6_4, HIGH); digitalWrite(RELAY_PIN7_4, HIGH); digitalWrite(RELAY_PIN8_4, HIGH);
    delay(100);
    digitalWrite(RELAY_PIN1_1, HIGH); digitalWrite(RELAY_PIN1_2, HIGH); digitalWrite(RELAY_PIN1_3, HIGH); digitalWrite(RELAY_PIN1_4, HIGH); digitalWrite(RELAY_PIN2_1, HIGH); digitalWrite(RELAY_PIN2_2, HIGH); digitalWrite(RELAY_PIN2_3, HIGH); digitalWrite(RELAY_PIN2_4, HIGH); digitalWrite(RELAY_PIN3_1, HIGH); digitalWrite(RELAY_PIN3_2, HIGH); digitalWrite(RELAY_PIN3_3, HIGH); digitalWrite(RELAY_PIN3_4, HIGH); digitalWrite(RELAY_PIN4_1, HIGH); digitalWrite(RELAY_PIN4_2, HIGH); digitalWrite(RELAY_PIN4_3, HIGH); digitalWrite(RELAY_PIN4_4, HIGH); digitalWrite(RELAY_PIN5_1, HIGH); digitalWrite(RELAY_PIN5_2, HIGH); digitalWrite(RELAY_PIN5_3, HIGH); digitalWrite(RELAY_PIN5_4, HIGH); digitalWrite(RELAY_PIN6_1, HIGH); digitalWrite(RELAY_PIN6_2, HIGH); digitalWrite(RELAY_PIN6_3, HIGH); digitalWrite(RELAY_PIN6_4, HIGH); digitalWrite(RELAY_PIN7_1, HIGH); digitalWrite(RELAY_PIN7_2, HIGH); digitalWrite(RELAY_PIN7_3, HIGH); digitalWrite(RELAY_PIN7_4, HIGH); digitalWrite(RELAY_PIN8_1, HIGH); digitalWrite(RELAY_PIN8_2, HIGH); digitalWrite(RELAY_PIN8_3, HIGH); digitalWrite(RELAY_PIN8_4, HIGH); 
    delay(200);
    digitalWrite(RELAY_PIN1_1, LOW); digitalWrite(RELAY_PIN1_2, LOW); digitalWrite(RELAY_PIN1_3, LOW); digitalWrite(RELAY_PIN1_4, LOW); digitalWrite(RELAY_PIN2_1, LOW); digitalWrite(RELAY_PIN2_2, LOW); digitalWrite(RELAY_PIN2_3, LOW); digitalWrite(RELAY_PIN2_4, LOW); digitalWrite(RELAY_PIN3_1, LOW); digitalWrite(RELAY_PIN3_2, LOW); digitalWrite(RELAY_PIN3_3, LOW); digitalWrite(RELAY_PIN3_4, LOW); digitalWrite(RELAY_PIN4_1, LOW); digitalWrite(RELAY_PIN4_2, LOW); digitalWrite(RELAY_PIN4_3, LOW); digitalWrite(RELAY_PIN4_4, LOW); digitalWrite(RELAY_PIN5_1, LOW); digitalWrite(RELAY_PIN5_2, LOW); digitalWrite(RELAY_PIN5_3, LOW); digitalWrite(RELAY_PIN5_4, LOW); digitalWrite(RELAY_PIN6_1, LOW); digitalWrite(RELAY_PIN6_2, LOW); digitalWrite(RELAY_PIN6_3, LOW); digitalWrite(RELAY_PIN6_4, LOW); digitalWrite(RELAY_PIN7_1, LOW); digitalWrite(RELAY_PIN7_2, LOW); digitalWrite(RELAY_PIN7_3, LOW); digitalWrite(RELAY_PIN7_4, LOW); digitalWrite(RELAY_PIN8_1, LOW); digitalWrite(RELAY_PIN8_2, LOW); digitalWrite(RELAY_PIN8_3, LOW); digitalWrite(RELAY_PIN8_4, LOW);
    delay(200);
    digitalWrite(RELAY_PIN1_1, HIGH); digitalWrite(RELAY_PIN1_2, HIGH); digitalWrite(RELAY_PIN1_3, HIGH); digitalWrite(RELAY_PIN1_4, HIGH); digitalWrite(RELAY_PIN2_1, HIGH); digitalWrite(RELAY_PIN2_2, HIGH); digitalWrite(RELAY_PIN2_3, HIGH); digitalWrite(RELAY_PIN2_4, HIGH); digitalWrite(RELAY_PIN3_1, HIGH); digitalWrite(RELAY_PIN3_2, HIGH); digitalWrite(RELAY_PIN3_3, HIGH); digitalWrite(RELAY_PIN3_4, HIGH); digitalWrite(RELAY_PIN4_1, HIGH); digitalWrite(RELAY_PIN4_2, HIGH); digitalWrite(RELAY_PIN4_3, HIGH); digitalWrite(RELAY_PIN4_4, HIGH); digitalWrite(RELAY_PIN5_1, HIGH); digitalWrite(RELAY_PIN5_2, HIGH); digitalWrite(RELAY_PIN5_3, HIGH); digitalWrite(RELAY_PIN5_4, HIGH); digitalWrite(RELAY_PIN6_1, HIGH); digitalWrite(RELAY_PIN6_2, HIGH); digitalWrite(RELAY_PIN6_3, HIGH); digitalWrite(RELAY_PIN6_4, HIGH); digitalWrite(RELAY_PIN7_1, HIGH); digitalWrite(RELAY_PIN7_2, HIGH); digitalWrite(RELAY_PIN7_3, HIGH); digitalWrite(RELAY_PIN7_4, HIGH); digitalWrite(RELAY_PIN8_1, HIGH); digitalWrite(RELAY_PIN8_2, HIGH); digitalWrite(RELAY_PIN8_3, HIGH); digitalWrite(RELAY_PIN8_4, HIGH); 
    delay(200);

    //pattern melingkar
    digitalWrite(RELAY_PIN1_1, LOW); 
    delay(300);
    digitalWrite(RELAY_PIN1_1, LOW);  digitalWrite(RELAY_PIN2_1, LOW);
    delay(300);
    digitalWrite(RELAY_PIN1_1, LOW);  digitalWrite(RELAY_PIN2_1, LOW);digitalWrite(RELAY_PIN3_1, LOW);
    delay(300);
    digitalWrite(RELAY_PIN1_1, LOW);  digitalWrite(RELAY_PIN2_1, LOW);digitalWrite(RELAY_PIN3_1, LOW);digitalWrite(RELAY_PIN4_1, LOW);
    delay(300);
    digitalWrite(RELAY_PIN1_1, LOW);  digitalWrite(RELAY_PIN2_1, LOW);digitalWrite(RELAY_PIN3_1, LOW);digitalWrite(RELAY_PIN4_1, LOW);digitalWrite(RELAY_PIN5_1, LOW);
    delay(300);
    digitalWrite(RELAY_PIN1_1, LOW);  digitalWrite(RELAY_PIN2_1, LOW);digitalWrite(RELAY_PIN3_1, LOW);digitalWrite(RELAY_PIN4_1, LOW);digitalWrite(RELAY_PIN5_1, LOW);digitalWrite(RELAY_PIN6_1, LOW);
    delay(300);
    digitalWrite(RELAY_PIN1_1, LOW);  digitalWrite(RELAY_PIN2_1, LOW);digitalWrite(RELAY_PIN3_1, LOW);digitalWrite(RELAY_PIN4_1, LOW);digitalWrite(RELAY_PIN5_1, LOW);digitalWrite(RELAY_PIN6_1, LOW);digitalWrite(RELAY_PIN7_1, LOW);
    delay(300);
    digitalWrite(RELAY_PIN1_1, LOW);  digitalWrite(RELAY_PIN2_1, LOW);digitalWrite(RELAY_PIN3_1, LOW);digitalWrite(RELAY_PIN4_1, LOW);digitalWrite(RELAY_PIN5_1, LOW);digitalWrite(RELAY_PIN6_1, LOW);digitalWrite(RELAY_PIN7_1, LOW);digitalWrite(RELAY_PIN8_1, LOW);
    delay(300);
    digitalWrite(RELAY_PIN1_1, LOW);  digitalWrite(RELAY_PIN2_1, LOW);digitalWrite(RELAY_PIN3_1, LOW);digitalWrite(RELAY_PIN4_1, LOW);digitalWrite(RELAY_PIN5_1, LOW);digitalWrite(RELAY_PIN6_1, LOW);digitalWrite(RELAY_PIN7_1, LOW);digitalWrite(RELAY_PIN8_1, LOW);digitalWrite(RELAY_PIN8_2, LOW); 
    delay(300);
    digitalWrite(RELAY_PIN1_1, LOW);  digitalWrite(RELAY_PIN2_1, LOW);digitalWrite(RELAY_PIN3_1, LOW);digitalWrite(RELAY_PIN4_1, LOW);digitalWrite(RELAY_PIN5_1, LOW);digitalWrite(RELAY_PIN6_1, LOW);digitalWrite(RELAY_PIN7_1, LOW);digitalWrite(RELAY_PIN8_1, LOW);digitalWrite(RELAY_PIN8_2, LOW); digitalWrite(RELAY_PIN7_2, LOW);
    delay(300);
    digitalWrite(RELAY_PIN1_1, LOW);  digitalWrite(RELAY_PIN2_1, LOW);digitalWrite(RELAY_PIN3_1, LOW);digitalWrite(RELAY_PIN4_1, LOW);digitalWrite(RELAY_PIN5_1, LOW);digitalWrite(RELAY_PIN6_1, LOW);digitalWrite(RELAY_PIN7_1, LOW);digitalWrite(RELAY_PIN8_1, LOW);digitalWrite(RELAY_PIN8_2, LOW); digitalWrite(RELAY_PIN7_2, LOW);digitalWrite(RELAY_PIN6_2, LOW);
    delay(300);
    digitalWrite(RELAY_PIN1_1, LOW);  digitalWrite(RELAY_PIN2_1, LOW);digitalWrite(RELAY_PIN3_1, LOW);digitalWrite(RELAY_PIN4_1, LOW);digitalWrite(RELAY_PIN5_1, LOW);digitalWrite(RELAY_PIN6_1, LOW);digitalWrite(RELAY_PIN7_1, LOW);digitalWrite(RELAY_PIN8_1, LOW);digitalWrite(RELAY_PIN8_2, LOW); digitalWrite(RELAY_PIN7_2, LOW);digitalWrite(RELAY_PIN6_2, LOW);digitalWrite(RELAY_PIN5_2, LOW);
    delay(300);
    digitalWrite(RELAY_PIN1_1, LOW);  digitalWrite(RELAY_PIN2_1, LOW);digitalWrite(RELAY_PIN3_1, LOW);digitalWrite(RELAY_PIN4_1, LOW);digitalWrite(RELAY_PIN5_1, LOW);digitalWrite(RELAY_PIN6_1, LOW);digitalWrite(RELAY_PIN7_1, LOW);digitalWrite(RELAY_PIN8_1, LOW);digitalWrite(RELAY_PIN8_2, LOW); digitalWrite(RELAY_PIN7_2, LOW);digitalWrite(RELAY_PIN6_2, LOW);digitalWrite(RELAY_PIN5_2, LOW);digitalWrite(RELAY_PIN4_2, LOW);
    delay(300);
    digitalWrite(RELAY_PIN1_1, LOW);  digitalWrite(RELAY_PIN2_1, LOW);digitalWrite(RELAY_PIN3_1, LOW);digitalWrite(RELAY_PIN4_1, LOW);digitalWrite(RELAY_PIN5_1, LOW);digitalWrite(RELAY_PIN6_1, LOW);digitalWrite(RELAY_PIN7_1, LOW);digitalWrite(RELAY_PIN8_1, LOW);digitalWrite(RELAY_PIN8_2, LOW); digitalWrite(RELAY_PIN7_2, LOW);digitalWrite(RELAY_PIN6_2, LOW);digitalWrite(RELAY_PIN5_2, LOW);digitalWrite(RELAY_PIN4_2, LOW);digitalWrite(RELAY_PIN3_2, LOW);
    delay(300);
    digitalWrite(RELAY_PIN1_1, LOW);  digitalWrite(RELAY_PIN2_1, LOW);digitalWrite(RELAY_PIN3_1, LOW);digitalWrite(RELAY_PIN4_1, LOW);digitalWrite(RELAY_PIN5_1, LOW);digitalWrite(RELAY_PIN6_1, LOW);digitalWrite(RELAY_PIN7_1, LOW);digitalWrite(RELAY_PIN8_1, LOW);digitalWrite(RELAY_PIN8_2, LOW); digitalWrite(RELAY_PIN7_2, LOW);digitalWrite(RELAY_PIN6_2, LOW);digitalWrite(RELAY_PIN5_2, LOW);digitalWrite(RELAY_PIN4_2, LOW);digitalWrite(RELAY_PIN3_2, LOW);digitalWrite(RELAY_PIN2_2, LOW);
    delay(300);
    digitalWrite(RELAY_PIN1_1, LOW);  digitalWrite(RELAY_PIN2_1, LOW);digitalWrite(RELAY_PIN3_1, LOW);digitalWrite(RELAY_PIN4_1, LOW);digitalWrite(RELAY_PIN5_1, LOW);digitalWrite(RELAY_PIN6_1, LOW);digitalWrite(RELAY_PIN7_1, LOW);digitalWrite(RELAY_PIN8_1, LOW);digitalWrite(RELAY_PIN8_2, LOW); digitalWrite(RELAY_PIN7_2, LOW);digitalWrite(RELAY_PIN6_2, LOW);digitalWrite(RELAY_PIN5_2, LOW);digitalWrite(RELAY_PIN4_2, LOW);digitalWrite(RELAY_PIN3_2, LOW);digitalWrite(RELAY_PIN2_2, LOW);digitalWrite(RELAY_PIN1_2, LOW);
    delay(300);
    digitalWrite(RELAY_PIN1_1, LOW);  digitalWrite(RELAY_PIN2_1, LOW);digitalWrite(RELAY_PIN3_1, LOW);digitalWrite(RELAY_PIN4_1, LOW);digitalWrite(RELAY_PIN5_1, LOW);digitalWrite(RELAY_PIN6_1, LOW);digitalWrite(RELAY_PIN7_1, LOW);digitalWrite(RELAY_PIN8_1, LOW);digitalWrite(RELAY_PIN8_2, LOW); digitalWrite(RELAY_PIN7_2, LOW);digitalWrite(RELAY_PIN6_2, LOW);digitalWrite(RELAY_PIN5_2, LOW);digitalWrite(RELAY_PIN4_2, LOW);digitalWrite(RELAY_PIN3_2, LOW);digitalWrite(RELAY_PIN2_2, LOW);digitalWrite(RELAY_PIN1_2, LOW);digitalWrite(RELAY_PIN1_3, LOW); 
    delay(300);
    digitalWrite(RELAY_PIN1_1, LOW);  digitalWrite(RELAY_PIN2_1, LOW);digitalWrite(RELAY_PIN3_1, LOW);digitalWrite(RELAY_PIN4_1, LOW);digitalWrite(RELAY_PIN5_1, LOW);digitalWrite(RELAY_PIN6_1, LOW);digitalWrite(RELAY_PIN7_1, LOW);digitalWrite(RELAY_PIN8_1, LOW);digitalWrite(RELAY_PIN8_2, LOW); digitalWrite(RELAY_PIN7_2, LOW);digitalWrite(RELAY_PIN6_2, LOW);digitalWrite(RELAY_PIN5_2, LOW);digitalWrite(RELAY_PIN4_2, LOW);digitalWrite(RELAY_PIN3_2, LOW);digitalWrite(RELAY_PIN2_2, LOW);digitalWrite(RELAY_PIN1_2, LOW);digitalWrite(RELAY_PIN1_3, LOW); digitalWrite(RELAY_PIN2_3, LOW);
    delay(300);
    digitalWrite(RELAY_PIN1_1, LOW);  digitalWrite(RELAY_PIN2_1, LOW);digitalWrite(RELAY_PIN3_1, LOW);digitalWrite(RELAY_PIN4_1, LOW);digitalWrite(RELAY_PIN5_1, LOW);digitalWrite(RELAY_PIN6_1, LOW);digitalWrite(RELAY_PIN7_1, LOW);digitalWrite(RELAY_PIN8_1, LOW);digitalWrite(RELAY_PIN8_2, LOW); digitalWrite(RELAY_PIN7_2, LOW);digitalWrite(RELAY_PIN6_2, LOW);digitalWrite(RELAY_PIN5_2, LOW);digitalWrite(RELAY_PIN4_2, LOW);digitalWrite(RELAY_PIN3_2, LOW);digitalWrite(RELAY_PIN2_2, LOW);digitalWrite(RELAY_PIN1_2, LOW);digitalWrite(RELAY_PIN1_3, LOW); digitalWrite(RELAY_PIN2_3, LOW);digitalWrite(RELAY_PIN3_3, LOW);
    delay(300);
    digitalWrite(RELAY_PIN1_1, LOW);  digitalWrite(RELAY_PIN2_1, LOW);digitalWrite(RELAY_PIN3_1, LOW);digitalWrite(RELAY_PIN4_1, LOW);digitalWrite(RELAY_PIN5_1, LOW);digitalWrite(RELAY_PIN6_1, LOW);digitalWrite(RELAY_PIN7_1, LOW);digitalWrite(RELAY_PIN8_1, LOW);digitalWrite(RELAY_PIN8_2, LOW); digitalWrite(RELAY_PIN7_2, LOW);digitalWrite(RELAY_PIN6_2, LOW);digitalWrite(RELAY_PIN5_2, LOW);digitalWrite(RELAY_PIN4_2, LOW);digitalWrite(RELAY_PIN3_2, LOW);digitalWrite(RELAY_PIN2_2, LOW);digitalWrite(RELAY_PIN1_2, LOW);digitalWrite(RELAY_PIN1_3, LOW); digitalWrite(RELAY_PIN2_3, LOW);digitalWrite(RELAY_PIN3_3, LOW);digitalWrite(RELAY_PIN4_3, LOW);
    delay(300);
    digitalWrite(RELAY_PIN1_1, LOW);  digitalWrite(RELAY_PIN2_1, LOW);digitalWrite(RELAY_PIN3_1, LOW);digitalWrite(RELAY_PIN4_1, LOW);digitalWrite(RELAY_PIN5_1, LOW);digitalWrite(RELAY_PIN6_1, LOW);digitalWrite(RELAY_PIN7_1, LOW);digitalWrite(RELAY_PIN8_1, LOW);digitalWrite(RELAY_PIN8_2, LOW); digitalWrite(RELAY_PIN7_2, LOW);digitalWrite(RELAY_PIN6_2, LOW);digitalWrite(RELAY_PIN5_2, LOW);digitalWrite(RELAY_PIN4_2, LOW);digitalWrite(RELAY_PIN3_2, LOW);digitalWrite(RELAY_PIN2_2, LOW);digitalWrite(RELAY_PIN1_2, LOW);digitalWrite(RELAY_PIN1_3, LOW); digitalWrite(RELAY_PIN2_3, LOW);digitalWrite(RELAY_PIN3_3, LOW);digitalWrite(RELAY_PIN4_3, LOW);digitalWrite(RELAY_PIN5_3, LOW);
    delay(300);
    digitalWrite(RELAY_PIN1_1, LOW);  digitalWrite(RELAY_PIN2_1, LOW);digitalWrite(RELAY_PIN3_1, LOW);digitalWrite(RELAY_PIN4_1, LOW);digitalWrite(RELAY_PIN5_1, LOW);digitalWrite(RELAY_PIN6_1, LOW);digitalWrite(RELAY_PIN7_1, LOW);digitalWrite(RELAY_PIN8_1, LOW);digitalWrite(RELAY_PIN8_2, LOW); digitalWrite(RELAY_PIN7_2, LOW);digitalWrite(RELAY_PIN6_2, LOW);digitalWrite(RELAY_PIN5_2, LOW);digitalWrite(RELAY_PIN4_2, LOW);digitalWrite(RELAY_PIN3_2, LOW);digitalWrite(RELAY_PIN2_2, LOW);digitalWrite(RELAY_PIN1_2, LOW);digitalWrite(RELAY_PIN1_3, LOW); digitalWrite(RELAY_PIN2_3, LOW);digitalWrite(RELAY_PIN3_3, LOW);digitalWrite(RELAY_PIN4_3, LOW);digitalWrite(RELAY_PIN5_3, LOW);digitalWrite(RELAY_PIN6_3, LOW);
    delay(300);
    digitalWrite(RELAY_PIN1_1, LOW);  digitalWrite(RELAY_PIN2_1, LOW);digitalWrite(RELAY_PIN3_1, LOW);digitalWrite(RELAY_PIN4_1, LOW);digitalWrite(RELAY_PIN5_1, LOW);digitalWrite(RELAY_PIN6_1, LOW);digitalWrite(RELAY_PIN7_1, LOW);digitalWrite(RELAY_PIN8_1, LOW);digitalWrite(RELAY_PIN8_2, LOW); digitalWrite(RELAY_PIN7_2, LOW);digitalWrite(RELAY_PIN6_2, LOW);digitalWrite(RELAY_PIN5_2, LOW);digitalWrite(RELAY_PIN4_2, LOW);digitalWrite(RELAY_PIN3_2, LOW);digitalWrite(RELAY_PIN2_2, LOW);digitalWrite(RELAY_PIN1_2, LOW);digitalWrite(RELAY_PIN1_3, LOW); digitalWrite(RELAY_PIN2_3, LOW);digitalWrite(RELAY_PIN3_3, LOW);digitalWrite(RELAY_PIN4_3, LOW);digitalWrite(RELAY_PIN5_3, LOW);digitalWrite(RELAY_PIN6_3, LOW);digitalWrite(RELAY_PIN7_3, LOW);
    delay(300);
    digitalWrite(RELAY_PIN1_1, LOW);  digitalWrite(RELAY_PIN2_1, LOW);digitalWrite(RELAY_PIN3_1, LOW);digitalWrite(RELAY_PIN4_1, LOW);digitalWrite(RELAY_PIN5_1, LOW);digitalWrite(RELAY_PIN6_1, LOW);digitalWrite(RELAY_PIN7_1, LOW);digitalWrite(RELAY_PIN8_1, LOW);digitalWrite(RELAY_PIN8_2, LOW); digitalWrite(RELAY_PIN7_2, LOW);digitalWrite(RELAY_PIN6_2, LOW);digitalWrite(RELAY_PIN5_2, LOW);digitalWrite(RELAY_PIN4_2, LOW);digitalWrite(RELAY_PIN3_2, LOW);digitalWrite(RELAY_PIN2_2, LOW);digitalWrite(RELAY_PIN1_2, LOW);digitalWrite(RELAY_PIN1_3, LOW); digitalWrite(RELAY_PIN2_3, LOW);digitalWrite(RELAY_PIN3_3, LOW);digitalWrite(RELAY_PIN4_3, LOW);digitalWrite(RELAY_PIN5_3, LOW);digitalWrite(RELAY_PIN6_3, LOW);digitalWrite(RELAY_PIN7_3, LOW);digitalWrite(RELAY_PIN8_3, LOW);
    delay(300);
    digitalWrite(RELAY_PIN1_1, LOW);  digitalWrite(RELAY_PIN2_1, LOW);digitalWrite(RELAY_PIN3_1, LOW);digitalWrite(RELAY_PIN4_1, LOW);digitalWrite(RELAY_PIN5_1, LOW);digitalWrite(RELAY_PIN6_1, LOW);digitalWrite(RELAY_PIN7_1, LOW);digitalWrite(RELAY_PIN8_1, LOW);digitalWrite(RELAY_PIN8_2, LOW); digitalWrite(RELAY_PIN7_2, LOW);digitalWrite(RELAY_PIN6_2, LOW);digitalWrite(RELAY_PIN5_2, LOW);digitalWrite(RELAY_PIN4_2, LOW);digitalWrite(RELAY_PIN3_2, LOW);digitalWrite(RELAY_PIN2_2, LOW);digitalWrite(RELAY_PIN1_2, LOW);digitalWrite(RELAY_PIN1_3, LOW); digitalWrite(RELAY_PIN2_3, LOW);digitalWrite(RELAY_PIN3_3, LOW);digitalWrite(RELAY_PIN4_3, LOW);digitalWrite(RELAY_PIN5_3, LOW);digitalWrite(RELAY_PIN6_3, LOW);digitalWrite(RELAY_PIN7_3, LOW);digitalWrite(RELAY_PIN8_3, LOW);digitalWrite(RELAY_PIN8_4, LOW); 
    delay(300);
    digitalWrite(RELAY_PIN1_1, LOW);  digitalWrite(RELAY_PIN2_1, LOW);digitalWrite(RELAY_PIN3_1, LOW);digitalWrite(RELAY_PIN4_1, LOW);digitalWrite(RELAY_PIN5_1, LOW);digitalWrite(RELAY_PIN6_1, LOW);digitalWrite(RELAY_PIN7_1, LOW);digitalWrite(RELAY_PIN8_1, LOW);digitalWrite(RELAY_PIN8_2, LOW); digitalWrite(RELAY_PIN7_2, LOW);digitalWrite(RELAY_PIN6_2, LOW);digitalWrite(RELAY_PIN5_2, LOW);digitalWrite(RELAY_PIN4_2, LOW);digitalWrite(RELAY_PIN3_2, LOW);digitalWrite(RELAY_PIN2_2, LOW);digitalWrite(RELAY_PIN1_2, LOW);digitalWrite(RELAY_PIN1_3, LOW); digitalWrite(RELAY_PIN2_3, LOW);digitalWrite(RELAY_PIN3_3, LOW);digitalWrite(RELAY_PIN4_3, LOW);digitalWrite(RELAY_PIN5_3, LOW);digitalWrite(RELAY_PIN6_3, LOW);digitalWrite(RELAY_PIN7_3, LOW);digitalWrite(RELAY_PIN8_3, LOW);digitalWrite(RELAY_PIN8_4, LOW); digitalWrite(RELAY_PIN7_4, LOW);
    delay(300);
    digitalWrite(RELAY_PIN1_1, LOW);  digitalWrite(RELAY_PIN2_1, LOW);digitalWrite(RELAY_PIN3_1, LOW);digitalWrite(RELAY_PIN4_1, LOW);digitalWrite(RELAY_PIN5_1, LOW);digitalWrite(RELAY_PIN6_1, LOW);digitalWrite(RELAY_PIN7_1, LOW);digitalWrite(RELAY_PIN8_1, LOW);digitalWrite(RELAY_PIN8_2, LOW); digitalWrite(RELAY_PIN7_2, LOW);digitalWrite(RELAY_PIN6_2, LOW);digitalWrite(RELAY_PIN5_2, LOW);digitalWrite(RELAY_PIN4_2, LOW);digitalWrite(RELAY_PIN3_2, LOW);digitalWrite(RELAY_PIN2_2, LOW);digitalWrite(RELAY_PIN1_2, LOW);digitalWrite(RELAY_PIN1_3, LOW); digitalWrite(RELAY_PIN2_3, LOW);digitalWrite(RELAY_PIN3_3, LOW);digitalWrite(RELAY_PIN4_3, LOW);digitalWrite(RELAY_PIN5_3, LOW);digitalWrite(RELAY_PIN6_3, LOW);digitalWrite(RELAY_PIN7_3, LOW);digitalWrite(RELAY_PIN8_3, LOW);digitalWrite(RELAY_PIN8_4, LOW); digitalWrite(RELAY_PIN7_4, LOW);digitalWrite(RELAY_PIN6_4, LOW);
    delay(300);
    digitalWrite(RELAY_PIN1_1, LOW);  digitalWrite(RELAY_PIN2_1, LOW);digitalWrite(RELAY_PIN3_1, LOW);digitalWrite(RELAY_PIN4_1, LOW);digitalWrite(RELAY_PIN5_1, LOW);digitalWrite(RELAY_PIN6_1, LOW);digitalWrite(RELAY_PIN7_1, LOW);digitalWrite(RELAY_PIN8_1, LOW);digitalWrite(RELAY_PIN8_2, LOW); digitalWrite(RELAY_PIN7_2, LOW);digitalWrite(RELAY_PIN6_2, LOW);digitalWrite(RELAY_PIN5_2, LOW);digitalWrite(RELAY_PIN4_2, LOW);digitalWrite(RELAY_PIN3_2, LOW);digitalWrite(RELAY_PIN2_2, LOW);digitalWrite(RELAY_PIN1_2, LOW);digitalWrite(RELAY_PIN1_3, LOW); digitalWrite(RELAY_PIN2_3, LOW);digitalWrite(RELAY_PIN3_3, LOW);digitalWrite(RELAY_PIN4_3, LOW);digitalWrite(RELAY_PIN5_3, LOW);digitalWrite(RELAY_PIN6_3, LOW);digitalWrite(RELAY_PIN7_3, LOW);digitalWrite(RELAY_PIN8_3, LOW);digitalWrite(RELAY_PIN8_4, LOW); digitalWrite(RELAY_PIN7_4, LOW);digitalWrite(RELAY_PIN6_4, LOW);digitalWrite(RELAY_PIN5_4, LOW);
    delay(300);
    digitalWrite(RELAY_PIN1_1, LOW);  digitalWrite(RELAY_PIN2_1, LOW);digitalWrite(RELAY_PIN3_1, LOW);digitalWrite(RELAY_PIN4_1, LOW);digitalWrite(RELAY_PIN5_1, LOW);digitalWrite(RELAY_PIN6_1, LOW);digitalWrite(RELAY_PIN7_1, LOW);digitalWrite(RELAY_PIN8_1, LOW);digitalWrite(RELAY_PIN8_2, LOW); digitalWrite(RELAY_PIN7_2, LOW);digitalWrite(RELAY_PIN6_2, LOW);digitalWrite(RELAY_PIN5_2, LOW);digitalWrite(RELAY_PIN4_2, LOW);digitalWrite(RELAY_PIN3_2, LOW);digitalWrite(RELAY_PIN2_2, LOW);digitalWrite(RELAY_PIN1_2, LOW);digitalWrite(RELAY_PIN1_3, LOW); digitalWrite(RELAY_PIN2_3, LOW);digitalWrite(RELAY_PIN3_3, LOW);digitalWrite(RELAY_PIN4_3, LOW);digitalWrite(RELAY_PIN5_3, LOW);digitalWrite(RELAY_PIN6_3, LOW);digitalWrite(RELAY_PIN7_3, LOW);digitalWrite(RELAY_PIN8_3, LOW);digitalWrite(RELAY_PIN8_4, LOW); digitalWrite(RELAY_PIN7_4, LOW);digitalWrite(RELAY_PIN6_4, LOW);digitalWrite(RELAY_PIN5_4, LOW);digitalWrite(RELAY_PIN4_4, LOW);
    delay(300);
    digitalWrite(RELAY_PIN1_1, LOW);  digitalWrite(RELAY_PIN2_1, LOW);digitalWrite(RELAY_PIN3_1, LOW);digitalWrite(RELAY_PIN4_1, LOW);digitalWrite(RELAY_PIN5_1, LOW);digitalWrite(RELAY_PIN6_1, LOW);digitalWrite(RELAY_PIN7_1, LOW);digitalWrite(RELAY_PIN8_1, LOW);digitalWrite(RELAY_PIN8_2, LOW); digitalWrite(RELAY_PIN7_2, LOW);digitalWrite(RELAY_PIN6_2, LOW);digitalWrite(RELAY_PIN5_2, LOW);digitalWrite(RELAY_PIN4_2, LOW);digitalWrite(RELAY_PIN3_2, LOW);digitalWrite(RELAY_PIN2_2, LOW);digitalWrite(RELAY_PIN1_2, LOW);digitalWrite(RELAY_PIN1_3, LOW); digitalWrite(RELAY_PIN2_3, LOW);digitalWrite(RELAY_PIN3_3, LOW);digitalWrite(RELAY_PIN4_3, LOW);digitalWrite(RELAY_PIN5_3, LOW);digitalWrite(RELAY_PIN6_3, LOW);digitalWrite(RELAY_PIN7_3, LOW);digitalWrite(RELAY_PIN8_3, LOW);digitalWrite(RELAY_PIN8_4, LOW); digitalWrite(RELAY_PIN7_4, LOW);digitalWrite(RELAY_PIN6_4, LOW);digitalWrite(RELAY_PIN5_4, LOW);digitalWrite(RELAY_PIN4_4, LOW);digitalWrite(RELAY_PIN3_4, LOW);
    delay(300);
    digitalWrite(RELAY_PIN1_1, LOW);  digitalWrite(RELAY_PIN2_1, LOW);digitalWrite(RELAY_PIN3_1, LOW);digitalWrite(RELAY_PIN4_1, LOW);digitalWrite(RELAY_PIN5_1, LOW);digitalWrite(RELAY_PIN6_1, LOW);digitalWrite(RELAY_PIN7_1, LOW);digitalWrite(RELAY_PIN8_1, LOW);digitalWrite(RELAY_PIN8_2, LOW); digitalWrite(RELAY_PIN7_2, LOW);digitalWrite(RELAY_PIN6_2, LOW);digitalWrite(RELAY_PIN5_2, LOW);digitalWrite(RELAY_PIN4_2, LOW);digitalWrite(RELAY_PIN3_2, LOW);digitalWrite(RELAY_PIN2_2, LOW);digitalWrite(RELAY_PIN1_2, LOW);digitalWrite(RELAY_PIN1_3, LOW); digitalWrite(RELAY_PIN2_3, LOW);digitalWrite(RELAY_PIN3_3, LOW);digitalWrite(RELAY_PIN4_3, LOW);digitalWrite(RELAY_PIN5_3, LOW);digitalWrite(RELAY_PIN6_3, LOW);digitalWrite(RELAY_PIN7_3, LOW);digitalWrite(RELAY_PIN8_3, LOW);digitalWrite(RELAY_PIN8_4, LOW); digitalWrite(RELAY_PIN7_4, LOW);digitalWrite(RELAY_PIN6_4, LOW);digitalWrite(RELAY_PIN5_4, LOW);digitalWrite(RELAY_PIN4_4, LOW);digitalWrite(RELAY_PIN3_4, LOW);digitalWrite(RELAY_PIN2_4, LOW);
    delay(300);
    digitalWrite(RELAY_PIN1_1, LOW);  digitalWrite(RELAY_PIN2_1, LOW);digitalWrite(RELAY_PIN3_1, LOW);digitalWrite(RELAY_PIN4_1, LOW);digitalWrite(RELAY_PIN5_1, LOW);digitalWrite(RELAY_PIN6_1, LOW);digitalWrite(RELAY_PIN7_1, LOW);digitalWrite(RELAY_PIN8_1, LOW);digitalWrite(RELAY_PIN8_2, LOW); digitalWrite(RELAY_PIN7_2, LOW);digitalWrite(RELAY_PIN6_2, LOW);digitalWrite(RELAY_PIN5_2, LOW);digitalWrite(RELAY_PIN4_2, LOW);digitalWrite(RELAY_PIN3_2, LOW);digitalWrite(RELAY_PIN2_2, LOW);digitalWrite(RELAY_PIN1_2, LOW);digitalWrite(RELAY_PIN1_3, LOW); digitalWrite(RELAY_PIN2_3, LOW);digitalWrite(RELAY_PIN3_3, LOW);digitalWrite(RELAY_PIN4_3, LOW);digitalWrite(RELAY_PIN5_3, LOW);digitalWrite(RELAY_PIN6_3, LOW);digitalWrite(RELAY_PIN7_3, LOW);digitalWrite(RELAY_PIN8_3, LOW);digitalWrite(RELAY_PIN8_4, LOW); digitalWrite(RELAY_PIN7_4, LOW);digitalWrite(RELAY_PIN6_4, LOW);digitalWrite(RELAY_PIN5_4, LOW);digitalWrite(RELAY_PIN4_4, LOW);digitalWrite(RELAY_PIN3_4, LOW);digitalWrite(RELAY_PIN2_4, LOW);digitalWrite(RELAY_PIN1_4, LOW);
    delay(300);
    disableRelays();
    } else {
    codeEnabled = true;
    digitalWrite(RELAY_PIN1_1, HIGH); digitalWrite(RELAY_PIN2_1, HIGH); digitalWrite(RELAY_PIN3_1, HIGH); digitalWrite(RELAY_PIN4_1, HIGH); digitalWrite(RELAY_PIN5_1, HIGH); digitalWrite(RELAY_PIN6_1, HIGH); digitalWrite(RELAY_PIN7_1, HIGH); digitalWrite(RELAY_PIN8_1, HIGH); 
    digitalWrite(RELAY_PIN1_2, HIGH); digitalWrite(RELAY_PIN2_2, HIGH); digitalWrite(RELAY_PIN3_2, HIGH); digitalWrite(RELAY_PIN4_2, HIGH); digitalWrite(RELAY_PIN5_2, HIGH); digitalWrite(RELAY_PIN6_2, HIGH); digitalWrite(RELAY_PIN7_2, HIGH); digitalWrite(RELAY_PIN8_2, HIGH); 
    digitalWrite(RELAY_PIN1_3, HIGH); digitalWrite(RELAY_PIN2_3, HIGH); digitalWrite(RELAY_PIN3_3, HIGH); digitalWrite(RELAY_PIN4_3, HIGH); digitalWrite(RELAY_PIN5_3, HIGH); digitalWrite(RELAY_PIN6_3, HIGH); digitalWrite(RELAY_PIN7_3, HIGH); digitalWrite(RELAY_PIN8_3, HIGH); 
    digitalWrite(RELAY_PIN1_4, HIGH); digitalWrite(RELAY_PIN2_4, HIGH); digitalWrite(RELAY_PIN3_4, HIGH); digitalWrite(RELAY_PIN4_4, HIGH); digitalWrite(RELAY_PIN5_4, HIGH); digitalWrite(RELAY_PIN6_4, HIGH); digitalWrite(RELAY_PIN7_4, HIGH); digitalWrite(RELAY_PIN8_4, HIGH);
  }



  Serial.print("distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  delay(500);
}
