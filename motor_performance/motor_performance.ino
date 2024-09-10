// Motor driver pins
const int motor1Pin1 = 2;  // Motor 1 forward
const int motor1Pin2 = 3;  // Motor 1 backward
const int motor2Pin1 = 4;  // Motor 2 forward
const int motor2Pin2 = 5;  // Motor 2 backward

// Enable pins for speed control
const int ENA = 9;  // Enable Motor 1
const int ENB = 10; // Enable Motor 2

// Sample coordinates (x, y) where rover needs to move
int targetX = 10; // Example target coordinates
int targetY = 5;

// Motor speed (0-255)
int motorSpeed = 100; // Adjust the speed as needed

void setup() {
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(ENA, OUTPUT);  // Motor 1 speed control
  pinMode(ENB, OUTPUT);  // Motor 2 speed control

  // Set initial motor speeds
  analogWrite(ENA, motorSpeed);  // Set Motor 1 speed
  analogWrite(ENB, motorSpeed);  // Set Motor 2 speed

  Serial.begin(9600);
}

void loop() {
  // Sample movements: Rover reaches the coordinate (10, 5)
  // You can use a more sophisticated method to reach the target like GPS or sensors
  
  // Move forward
  moveForward();
  delay(5000);  // Move forward for 5 seconds (change as needed)

  // Move backward
  moveBackward();
  delay(5000);  // Move backward for 5 seconds

  // Turn left
  turnLeft();
  delay(1000);  // Adjust delay based on how long it takes to turn

  // Turn right
  turnRight();
  delay(1000);  // Adjust delay based on how long it takes to turn

  // Stop the rover after reaching the target
  stopMotors();
}

void moveForward() {
  analogWrite(ENA, motorSpeed);  // Set Motor 1 speed
  analogWrite(ENB, motorSpeed);  // Set Motor 2 speed
  
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

void moveBackward() {
  analogWrite(ENA, motorSpeed);  // Set Motor 1 speed
  analogWrite(ENB, motorSpeed);  // Set Motor 2 speed
  
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
}

void turnLeft() {
  // Stop left motor, move right motor forward
  analogWrite(ENA, 0);  // Stop Motor 1 (left)
  analogWrite(ENB, motorSpeed);  // Set Motor 2 speed
  
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

void turnRight() {
  // Stop right motor, move left motor forward
  analogWrite(ENA, motorSpeed);  // Set Motor 1 speed
  analogWrite(ENB, 0);  // Stop Motor 2 (right)
  
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
}

void stopMotors() {
  analogWrite(ENA, 0);  // Stop Motor 1
  analogWrite(ENB, 0);  // Stop Motor 2
  
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
}
