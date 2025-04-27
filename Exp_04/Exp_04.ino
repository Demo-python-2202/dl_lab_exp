// Motor Driver 1 Pins
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5

// Motor Driver 2 Pins
#define IN5 6
#define IN6 7
#define IN7 8
#define IN8 9

// Ultrasonic Sensor Pins
#define trigPin 10
#define echoPin 11

// Distance threshold (in cm)
int distanceThreshold = 20;

void setup() {
  // Set motor pins as output
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);
  pinMode(IN7, OUTPUT);
  pinMode(IN8, OUTPUT);

  // Set ultrasonic pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Begin Serial (optional, for debugging)
  Serial.begin(9600);
}

void loop() {
  int distance = readDistance();

  if (distance > 0 && distance < distanceThreshold) {
    // Obstacle detected
    stopRobot();
    delay(500);       // Pause
    turnRight();
    delay(600);        // Adjust turning time
  } else {
    // No obstacle
    moveForward();
  }
}

// Function to read distance from ultrasonic sensor
int readDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;  // cm

  Serial.print("Distance: ");
  Serial.println(distance);

  return distance;
}

// Functions for Motor Movement
void moveForward() {
  // Motor Driver 1
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  
  // Motor Driver 2
  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
}

void turnRight() {
  // Motor Driver 1
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  
  // Motor Driver 2
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
}

void stopRobot() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, LOW);
}
