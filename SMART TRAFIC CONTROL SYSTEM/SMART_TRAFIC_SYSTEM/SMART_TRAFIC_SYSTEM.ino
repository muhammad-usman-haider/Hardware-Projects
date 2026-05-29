#include <SPI.h>
#include <MFRC522.h>

/* ---------- PIN DEFINITIONS ---------- */
#define RED_LED     8
#define YELLOW_LED  9
#define GREEN_LED   10

#define IR1_PIN     2
#define IR2_PIN     3

#define SS_PIN      7
#define RST_PIN     6

MFRC522 rfid(SS_PIN, RST_PIN);

/* ---------- TIMING (ms) ---------- */
#define YELLOW_TIME   3000
#define RED_TIME      10000
#define RFID_GREEN    30000

#define GREEN_LOW     10000
#define GREEN_MEDIUM  20000
#define GREEN_HIGH    40000

/* ---------- STATE MACHINE ---------- */
enum TrafficState {
  RED,
  GREEN,
  YELLOW,
  RFID_MODE
};

TrafficState currentState = RED;
unsigned long stateStartTime = 0;
unsigned long greenDuration = GREEN_LOW;

/* ---------- EMERGENCY RFID UID ---------- */
byte emergencyUID[4] = {0x63, 0xF0, 0x0A, 0x0E};  // CHANGE THIS

/* ---------- FUNCTION DECLARATIONS ---------- */
void setRed();
void setYellow();
void setGreen();
bool checkRFID();
void updateTrafficDensity();

void setup() {
  Serial.begin(9600);

  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  pinMode(IR1_PIN, INPUT);
  pinMode(IR2_PIN, INPUT);

  SPI.begin();
  rfid.PCD_Init();

  setRed();
  stateStartTime = millis();

  Serial.println("Smart Traffic System Initialized");
}

void loop() {

  /* ---------- RFID HAS HIGHEST PRIORITY ---------- */
  if (checkRFID()) {
    currentState = RFID_MODE;
    stateStartTime = millis();
    setGreen();
    Serial.println("RFID PRIORITY MODE");
  }

  unsigned long currentMillis = millis();

  switch (currentState) {

    case RED:
      if (currentMillis - stateStartTime >= RED_TIME) {
        updateTrafficDensity();
        currentState = GREEN;
        stateStartTime = currentMillis;
        setGreen();
      }
      break;

    case GREEN:
      if (currentMillis - stateStartTime >= greenDuration) {
        currentState = YELLOW;
        stateStartTime = currentMillis;
        setYellow();
      }
      break;

    case YELLOW:
      if (currentMillis - stateStartTime >= YELLOW_TIME) {
        currentState = RED;
        stateStartTime = currentMillis;
        setRed();
      }
      break;

    case RFID_MODE:
      if (currentMillis - stateStartTime >= RFID_GREEN) {
        currentState = RED;
        stateStartTime = currentMillis;
        setRed();
        Serial.println("RFID MODE ENDED");
      }
      break;
  }
}

/* ---------- FUNCTIONS ---------- */

void updateTrafficDensity() {
  int ir1 = digitalRead(IR1_PIN);
  int ir2 = digitalRead(IR2_PIN);

  if (ir1 == HIGH && ir2 == HIGH) {
    greenDuration = GREEN_LOW;
    Serial.println("Traffic: NONE");
  }
  else if (ir1 == HIGH && ir2 == LOW) {
    greenDuration = GREEN_MEDIUM;
    Serial.println("Traffic: LOW");
  }
	  else if (ir1 == LOW && ir2 == HIGH) {
    greenDuration = GREEN_MEDIUM;
    Serial.println("Traffic: LOW");
  }
  else {
    greenDuration = GREEN_HIGH;
    Serial.println("Traffic: HIGH");
  }
}

bool checkRFID() {
  if (!rfid.PICC_IsNewCardPresent()) return false;
  if (!rfid.PICC_ReadCardSerial()) return false;

  for (byte i = 0; i < 4; i++) {
    if (rfid.uid.uidByte[i] != emergencyUID[i]) {
      rfid.PICC_HaltA();
      rfid.PCD_StopCrypto1();
      return false;
    }
  }

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
  return true;
}

/* ---------- LED CONTROL ---------- */

void setRed() {
  digitalWrite(RED_LED, HIGH);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
}

void setYellow() {
  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, HIGH);
  digitalWrite(GREEN_LED, LOW);
}

void setGreen() {
  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, HIGH);
}
