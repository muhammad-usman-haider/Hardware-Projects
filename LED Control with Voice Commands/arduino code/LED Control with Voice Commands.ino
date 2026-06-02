int Green = 3;
int Orange = 4;
int Red = 5;

void setup() {
  Serial.begin(9600);
  pinMode(Green, OUTPUT);
  pinMode(Orange, OUTPUT);
  pinMode(Red, OUTPUT);
}

String voice;

void loop() {
  if (Serial.available() > 0) {
    voice = Serial.readString();
    voice.trim(); // Trim any leading/trailing whitespace
    Serial.print(voice + '\n');
    
    if (voice.equalsIgnoreCase("green")) {
      digitalWrite(Green, HIGH);
    } else if (voice.equalsIgnoreCase("green off")) {
      digitalWrite(Green, LOW);
    }

    if (voice.equalsIgnoreCase("orange")) {
      digitalWrite(Orange, HIGH);
    } else if (voice.equalsIgnoreCase("orange off")) {
      digitalWrite(Orange, LOW);
    }

    if (voice.equalsIgnoreCase("red")) {
      digitalWrite(Red, HIGH);
    } else if (voice.equalsIgnoreCase("red off")) {
      digitalWrite(Red, LOW);
    }
  }
}
