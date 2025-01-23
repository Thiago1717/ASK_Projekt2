const int pirPins[] = {3, 4, 5, 6, 2};
const int buttonPins[] = {8, 9, 10, 11, 12};
const int ledPins[] = {A5, A4, A3, A2, A1};
const int numSensors = 5;
const int datapin = A0;
const int latchpin = 7;
const int clockpin = 13;
const int cyfry[5] = {121, 36, 48, 25, 18};
const byte dolnaKreska = 247;
const byte gornaKreska = 254;

bool sensorEnabled[numSensors] = {false};
bool motionDetected[numSensors] = {false};

void setup() {
  for (int i = 0; i < numSensors; i++) {
    pinMode(pirPins[i], INPUT);
    pinMode(buttonPins[i], INPUT_PULLUP);
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(datapin, OUTPUT);
  pinMode(latchpin, OUTPUT);
  pinMode(clockpin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int activeSensorsCount = 0;
  bool anySensorEnabled = false;

  for (int i = 0; i < numSensors; i++) {
    if (digitalRead(buttonPins[i]) == LOW) {
      sensorEnabled[i] = !sensorEnabled[i];
      if (!sensorEnabled[i]) motionDetected[i] = false;
      delay(300);
    }

    digitalWrite(ledPins[i], !sensorEnabled[i]);

    if (sensorEnabled[i]) {
      anySensorEnabled = true;
      if (digitalRead(pirPins[i]) == HIGH) motionDetected[i] = true;
      if (motionDetected[i]) activeSensorsCount++;
    }
  }

  if (!anySensorEnabled) {
    sendToDisplay(dolnaKreska);
  } else if (activeSensorsCount == 0) {
    sendToDisplay(gornaKreska);
  } else {
    if (activeSensorsCount >= 1 && activeSensorsCount <= 5) {
      sendToDisplay(cyfry[activeSensorsCount - 1]);
    }
  }
}

void sendToDisplay(byte symbol) {
  digitalWrite(latchpin, LOW);
  shiftOut(datapin, clockpin, MSBFIRST, symbol);
  digitalWrite(latchpin, HIGH);
}
