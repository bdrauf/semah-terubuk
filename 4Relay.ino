const int TRIG_PIN1 = A0; 
const int ECHO_PIN1 = A1;

const int TRIG_PIN2 = A2;
const int ECHO_PIN2 = A3;

const int RELAY_PIN1_1 = 2;
const int RELAY_PIN1_2 = 3;

const int RELAY_PIN2_1 = 4;
const int RELAY_PIN2_2 = 5;


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

  pinMode(RELAY_PIN1_1, OUTPUT);
  pinMode(RELAY_PIN1_2, OUTPUT);

  pinMode(RELAY_PIN2_1, OUTPUT);
  pinMode(RELAY_PIN2_2, OUTPUT);
}

void disableRelays() {
  digitalWrite(RELAY_PIN1_1, LOW); digitalWrite(RELAY_PIN2_1, LOW);
  digitalWrite(RELAY_PIN1_2, LOW); digitalWrite(RELAY_PIN2_2, LOW); 
  digitalWrite(RELAY_PIN1_1, HIGH); digitalWrite(RELAY_PIN2_1, HIGH); 
  digitalWrite(RELAY_PIN1_2, HIGH); digitalWrite(RELAY_PIN2_2, HIGH); 
  digitalWrite(RELAY_PIN1_1, HIGH); digitalWrite(RELAY_PIN1_2, HIGH);
  digitalWrite(RELAY_PIN1_1, LOW); digitalWrite(RELAY_PIN1_2, LOW);
}

void loop() {

  bool sensor1_triggered = true;
  bool sensor2_triggered = true;


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
  distance_cm = 0.001 * duration_us;

  if(distance_cm > DISTANCE_THRESHOLD) {
    sensor2_triggered = false;
  }



if (codeEnabled) {
  if (sensor1_triggered) {
    digitalWrite(RELAY_PIN1_1, LOW); 
    digitalWrite(RELAY_PIN1_2, LOW); 
    delay(100);
    digitalWrite(RELAY_PIN1_1, HIGH); 
    digitalWrite(RELAY_PIN1_2, HIGH); 
    delay(100);
    digitalWrite(RELAY_PIN1_1, HIGH); digitalWrite(RELAY_PIN1_2, HIGH); 
    delay(200);
    digitalWrite(RELAY_PIN1_1, LOW); digitalWrite(RELAY_PIN1_2, LOW); 
    delay(200);
    digitalWrite(RELAY_PIN1_1, HIGH); digitalWrite(RELAY_PIN1_2, HIGH); 
    delay(200);
  } else {
    digitalWrite(RELAY_PIN1_1, HIGH); 
    digitalWrite(RELAY_PIN1_2, HIGH); 
  }

  if (sensor2_triggered) {
    digitalWrite(RELAY_PIN2_1, LOW); 
    digitalWrite(RELAY_PIN2_2, LOW); 
    delay(100);
    digitalWrite(RELAY_PIN2_1, HIGH); 
    digitalWrite(RELAY_PIN2_2, HIGH); 
    delay(100);
    digitalWrite(RELAY_PIN2_1, HIGH); digitalWrite(RELAY_PIN2_2, HIGH); 
    delay(200);
    digitalWrite(RELAY_PIN2_1, LOW); digitalWrite(RELAY_PIN2_2, LOW);
    delay(200);
    digitalWrite(RELAY_PIN2_1, HIGH); digitalWrite(RELAY_PIN2_2, HIGH);
    delay(200);
  } else {
    digitalWrite(RELAY_PIN2_1, HIGH); 
    digitalWrite(RELAY_PIN2_2, HIGH); 
  }


}
  if (sensor1_triggered && sensor2_triggered) {
    // Trigger new pattern here
    // You can add your pattern logic here
    // For example, turn on all relays for a specific duration
      // generate 10-microsecond pulse to TRIG pin
    codeEnabled = false;
    digitalWrite(RELAY_PIN1_1, LOW); digitalWrite(RELAY_PIN2_1, LOW);
    delay(100);
    digitalWrite(RELAY_PIN1_2, LOW); digitalWrite(RELAY_PIN2_2, LOW);
    digitalWrite(RELAY_PIN1_1, HIGH); digitalWrite(RELAY_PIN2_1, HIGH);
    delay(100);
    digitalWrite(RELAY_PIN1_2, HIGH); digitalWrite(RELAY_PIN2_2, HIGH);
    delay(100);
    digitalWrite(RELAY_PIN1_1, HIGH); digitalWrite(RELAY_PIN1_2, HIGH); 
    delay(200);
    digitalWrite(RELAY_PIN1_1, LOW); digitalWrite(RELAY_PIN1_2, LOW);
    delay(200);
    digitalWrite(RELAY_PIN1_1, HIGH); digitalWrite(RELAY_PIN1_2, HIGH); 
    delay(200);

    //pattern melingkar
    digitalWrite(RELAY_PIN1_1, LOW); 
    delay(300);
    digitalWrite(RELAY_PIN1_1, LOW);  digitalWrite(RELAY_PIN2_1, LOW);
    delay(300);
    digitalWrite(RELAY_PIN1_1, LOW);  digitalWrite(RELAY_PIN2_1, LOW);digitalWrite(RELAY_PIN2_2, LOW);
    delay(300);
    digitalWrite(RELAY_PIN1_1, LOW);  digitalWrite(RELAY_PIN2_1, LOW);digitalWrite(RELAY_PIN2_2, LOW);digitalWrite(RELAY_PIN2_1, LOW);
    disableRelays();
    } else {
    codeEnabled = true;
    digitalWrite(RELAY_PIN1_1, HIGH); digitalWrite(RELAY_PIN2_1, HIGH); 
    digitalWrite(RELAY_PIN1_2, HIGH); digitalWrite(RELAY_PIN2_2, HIGH);  

  }



  Serial.print("distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  delay(500);
}