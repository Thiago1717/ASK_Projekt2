# System Alarmowy na ATMega328P
![Schemat połączeń](images/schemat.png)
**Link do projektu w tinkercad**: https://www.tinkercad.com/things/kB7BH8ezySH-askproj2?sharecode=o86rJ7XlRn4ZpE0Tyh85V4lGz5SdO3RtpsPyIC5kAf8

## Opis projektu

Projekt systemu alarmowego opartego na mikrokontrolerze ATMega328P (Arduino), który obsługuje 5 czujników PIR. System umożliwia:

- Włączenie/wyłączenie każdego z PIR.
- Każdy z czujników PIR posiada diode LED:  
  - **LED świeci**, czujnik PIR jest aktywny.  
  - **LED zgaszony**, czujnik PIR jest nieaktywny.
- Panel led wyświetla status alarmu:  
  - **Symbol górnej kreski** oznacza aktywny alarm.  
  - **Symbol dolnej kreski** oznacza nieaktywny alarm.
- Na panelu led wyświetlana jest również liczba czujników PIR które wykryły ruch, liczba wyświetlana jest dopóki czujnik nie zostanie wyłączony.

---
## Użyte komponenty

- Mikrokontroler **ATMega328P** (np. Arduino UNO/Nano).
- 5x Czujniki PIR (podłączone do pinów 3, 4, 5, 6, 2).
- 5x Diody LED (podłączone do pinów A5, A4, A3, A2, A1).
- 5x Przyciski (podłączone do pinów 8, 9, 10, 11, 12).
- Wyświetlacz LED (7-segmentowy).
- Rejestr przesuwny 74HC595 (do podłączenia wyświetlacza LED).
- Rezystory, przewody, zasilanie.
---
## Działanie alarmu
**Alarm wyłączony** -> Żaden czujnik PIR nie jest włączony.

![Schemat połączeń](images/wyłączony.png)

---
**Alarm włączony** -> Conajmniej jeden czujnik PIR jest włączony.

![Schemat połączeń](images/włączony.png)

---
**Wykrywanie ruchu** -> Ekran wyświetla liczbę czujników PIR które wykryły ruch.

![Schemat połączeń](images/2czuj.png)

---
**Wyłączenie czujników** -> Gdy czujniki PIR wykryją ruch, liczba na ekranie nie zmienia się dopóki, czujnik nie zostanie wyłączony

![Schemat połączeń](images/po1wyłącz.png)

---

## Struktura Kodu
**Deklaracja pinów oraz zmiennych**
- pirPins[] - tablica przechowująca piny czujników PIR.
- buttonPins[] - tablica przechowująca piny przycisków.
- ledPins[] - tablica przechowująca piny diod LED.
- sensorEnabled[] - tablica przechowująca stany czujników.
- motionDetected[] - tablica przechowująca stan wykrycia ruchu.
- cyfry[5] = {121, 36, 48, 25, 18} - tablica zawierająca wartości binarne cyfr dla wyświetlacza od 1 do 5.
---

**Funkcja setup()**

```cpp
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
```
**Opis**
Funkcja ustawaia piny czujników PIR, przycisków oraz diod LED, konfiguruję komunikację szeregową a także ustawia piny wyświetlacza.

---
**Funkcja loop()**

```cpp
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

```
**Opis**
Zadaniem funkcji jest sprawdzenie, czy przyciski zostały naciśnięte, przełącza stany czujników oraz aktualizuje diody LED, następnie zlicza wykryte ruchy przez czujniki PIR, po czym wysyła do wyświetlacza.

---
**Funkcja sendToDisplay()**

```cpp
void sendToDisplay(byte symbol) {
  digitalWrite(latchpin, LOW);
  shiftOut(datapin, clockpin, MSBFIRST, symbol);
  digitalWrite(latchpin, HIGH);
}
```
**Opis**
Funkcja wysyła określony symbol do 7 - segmentowego wyświetlacza. 
