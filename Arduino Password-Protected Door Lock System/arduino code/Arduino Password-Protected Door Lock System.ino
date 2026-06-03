#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// Define the keypad
const byte ROWS = 4; // Four rows
const byte COLS = 3; // Three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte rowPins[ROWS] = {5, 4, 3, 2}; // Connect to the row pinouts of the keypad
byte colPins[COLS] = {A3, A2, A1}; // Connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Define the LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define the Servo
Servo servo;
int servoPin = 6;

// Define the Buzzer
int buzzerPin = 8;

// Define the LED pins
int greenLEDPin = 9;
int redLEDPin = 10;

// Define the Push Button
int buttonPin = 7;

// Define the password
String password = "1234";
String input = "";

// Variables to manage the door state
bool doorUnlocked = false;
unsigned long unlockTime = 0;
const unsigned long doorOpenDuration = 5000; // 5 seconds

void setup() {
  Serial.begin(9600); // Initialize Serial Monitor for debugging

  lcd.init();
  lcd.backlight();
  lcd.print("Enter Password:");
  
  servo.attach(servoPin);
  pinMode(buzzerPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); // Internal pull-up resistor for the button
  
  // Set initial state
  servo.write(0); // Locked position
  digitalWrite(greenLEDPin, LOW);
  digitalWrite(redLEDPin, HIGH);
}

void loop() {
  char key = keypad.getKey();
  bool buttonPressed = digitalRead(buttonPin) == LOW;

  // Check for button press to unlock door
  if (buttonPressed && !doorUnlocked) {
    unlockDoor();
  }

  // Check for keypad input
  if (key && !doorUnlocked) {
    Serial.print("Key pressed: ");
    Serial.println(key); // Print the key pressed to the Serial Monitor
    
    if (key == '#') {
      if (input == password) {
        unlockDoor();
      } else {
        lcd.clear();
        lcd.print("Wrong Password");
        tone(buzzerPin, 1000, 1000); // Beep the buzzer
        digitalWrite(greenLEDPin, LOW);
        digitalWrite(redLEDPin, HIGH);
        delay(2000);
        lcd.clear();
        lcd.print("Enter Password:");
      }
      input = ""; // Reset the input
    } else if (key != '*' && key != '#') {
      input += key;
      lcd.setCursor(input.length(), 1);
      lcd.print('*');
      Serial.print("Current input: ");
      Serial.println(input); // Print the current input to the Serial Monitor
    }
  }

  // Check if door needs to be locked after unlock duration
  if (doorUnlocked && (millis() - unlockTime > doorOpenDuration)) {
    lockDoor();
  }
}

void unlockDoor() {
  lcd.clear();
  lcd.print("Access Granted");
  servo.write(90); // Unlock position
  digitalWrite(greenLEDPin, HIGH);
  digitalWrite(redLEDPin, LOW);
  doorUnlocked = true;
  unlockTime = millis(); // Record the unlock time
}

void lockDoor() {
  lcd.clear();
  lcd.print("Enter Password:");
  servo.write(0); // Lock position
  digitalWrite(greenLEDPin, LOW);
  digitalWrite(redLEDPin, HIGH);
  doorUnlocked = false;
}
