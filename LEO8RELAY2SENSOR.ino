const int TRIG_PIN1 = 2; 
const int ECHO_PIN1 = 3;

const int TRIG_PIN2 = 4;
const int ECHO_PIN2 = 5;



const int RELAY_PIN1_1 = 6;
const int RELAY_PIN1_2 = 7;
const int RELAY_PIN1_3 = 8;
const int RELAY_PIN1_4 = 9;

const int RELAY_PIN2_1 = 10;
const int RELAY_PIN2_2 = 11;
const int RELAY_PIN2_3 = 12;
const int RELAY_PIN2_4 = 13;


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
  pinMode(RELAY_PIN1_3, OUTPUT);
  pinMode(RELAY_PIN1_4, OUTPUT);

  pinMode(RELAY_PIN2_1, OUTPUT);
  pinMode(RELAY_PIN2_2, OUTPUT);
  pinMode(RELAY_PIN2_3, OUTPUT);
  pinMode(RELAY_PIN2_4, OUTPUT);

}

void disableRelays() {
  digitalWrite(RELAY_PIN1_1, LOW); digitalWrite(RELAY_PIN2_1, LOW); 
  digitalWrite(RELAY_PIN1_2, LOW); digitalWrite(RELAY_PIN2_2, LOW); 
  digitalWrite(RELAY_PIN1_3, LOW); digitalWrite(RELAY_PIN2_3, LOW); 
  digitalWrite(RELAY_PIN1_4, LOW); digitalWrite(RELAY_PIN2_4, LOW); 
  digitalWrite(RELAY_PIN1_1, HIGH); digitalWrite(RELAY_PIN2_1, HIGH); 
  digitalWrite(RELAY_PIN1_2, HIGH); digitalWrite(RELAY_PIN2_2, HIGH); 
  digitalWrite(RELAY_PIN1_3, HIGH); digitalWrite(RELAY_PIN2_3, HIGH); 
  digitalWrite(RELAY_PIN1_4, HIGH); digitalWrite(RELAY_PIN2_4, HIGH); 
  digitalWrite(RELAY_PIN1_1, HIGH); digitalWrite(RELAY_PIN1_2, HIGH); digitalWrite(RELAY_PIN1_3, HIGH); digitalWrite(RELAY_PIN1_4, HIGH); digitalWrite(RELAY_PIN2_1, HIGH); digitalWrite(RELAY_PIN2_2, HIGH); digitalWrite(RELAY_PIN2_3, HIGH); digitalWrite(RELAY_PIN2_4, HIGH); 
  digitalWrite(RELAY_PIN1_1, LOW); digitalWrite(RELAY_PIN1_2, LOW); digitalWrite(RELAY_PIN1_3, LOW); digitalWrite(RELAY_PIN1_4, LOW); digitalWrite(RELAY_PIN2_1, LOW); digitalWrite(RELAY_PIN2_2, LOW); digitalWrite(RELAY_PIN2_3, LOW); digitalWrite(RELAY_PIN2_4, LOW); 
}

void loop() {

  bool sensor1_triggered = true;
  bool sensor2_triggered = true;


  // Sensor 1
  digitalWrite(TRIG_PIN1, LOW);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN1, HIGH);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(ECHO_PIN1, HIGH);
  // calculate the distance
  distance_cm = 0.017 * duration_us;

  if(distance_cm > DISTANCE_THRESHOLD) {
    sensor1_triggered = false;
  }

  // Sensor 2
  digitalWrite(TRIG_PIN2, LOW);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN2, HIGH);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(ECHO_PIN2, HIGH);
  // calculate the distance
  distance_cm = 0.017 * duration_us;

  if(distance_cm > DISTANCE_THRESHOLD) {
    sensor2_triggered = false;
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
    digitalWrite(RELAY_PIN1_3, LOW); digitalWrite(RELAY_PIN2_3, LOW); 
    delay(100);
    digitalWrite(RELAY_PIN1_4, LOW); digitalWrite(RELAY_PIN2_4, LOW); 
    digitalWrite(RELAY_PIN1_1, HIGH); digitalWrite(RELAY_PIN2_1, HIGH); 
    delay(100);
    digitalWrite(RELAY_PIN1_2, HIGH); digitalWrite(RELAY_PIN2_2, HIGH); 
    delay(100);
    digitalWrite(RELAY_PIN1_3, HIGH); digitalWrite(RELAY_PIN2_3, HIGH); 
    delay(100);
    digitalWrite(RELAY_PIN1_4, HIGH); digitalWrite(RELAY_PIN2_4, HIGH); 
    delay(100);
    digitalWrite(RELAY_PIN1_1, HIGH); digitalWrite(RELAY_PIN1_2, HIGH); digitalWrite(RELAY_PIN1_3, HIGH); digitalWrite(RELAY_PIN1_4, HIGH); digitalWrite(RELAY_PIN2_1, HIGH); digitalWrite(RELAY_PIN2_2, HIGH); digitalWrite(RELAY_PIN2_3, HIGH); digitalWrite(RELAY_PIN2_4, HIGH); 
    delay(200);
    digitalWrite(RELAY_PIN1_1, LOW); digitalWrite(RELAY_PIN1_2, LOW); digitalWrite(RELAY_PIN1_3, LOW); digitalWrite(RELAY_PIN1_4, LOW); digitalWrite(RELAY_PIN2_1, LOW); digitalWrite(RELAY_PIN2_2, LOW); digitalWrite(RELAY_PIN2_3, LOW); digitalWrite(RELAY_PIN2_4, LOW); 
    delay(200);
    digitalWrite(RELAY_PIN1_1, HIGH); digitalWrite(RELAY_PIN1_2, HIGH); digitalWrite(RELAY_PIN1_3, HIGH); digitalWrite(RELAY_PIN1_4, HIGH); digitalWrite(RELAY_PIN2_1, HIGH); digitalWrite(RELAY_PIN2_2, HIGH); digitalWrite(RELAY_PIN2_3, HIGH); digitalWrite(RELAY_PIN2_4, HIGH);  
    delay(200);

    //pattern melingkar
    digitalWrite(RELAY_PIN1_1, LOW); 
    delay(300);
    digitalWrite(RELAY_PIN1_1, LOW);  digitalWrite(RELAY_PIN2_1, LOW);
    delay(300);

    disableRelays();
    } else {
    codeEnabled = true;
    digitalWrite(RELAY_PIN1_1, HIGH); digitalWrite(RELAY_PIN2_1, HIGH); 
    digitalWrite(RELAY_PIN1_2, HIGH); digitalWrite(RELAY_PIN2_2, HIGH); 
    digitalWrite(RELAY_PIN1_3, HIGH); digitalWrite(RELAY_PIN2_3, HIGH); 
    digitalWrite(RELAY_PIN1_4, HIGH); digitalWrite(RELAY_PIN2_4, HIGH); 
  }



  Serial.print("distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  delay(500);
}
