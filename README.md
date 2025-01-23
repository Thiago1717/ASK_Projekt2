# System Alarmowy na ATMega328P
!(images/schemat.png)

## Opis projektu

Projekt systemu alarmowego opartego na mikrokontrolerze ATMega328P (Arduino), który obsługuje 5 czujników PIR. System umożliwia:

- Włączenie/wyłączenie każdego z pir.
- Każdy z czujników pir posiada diode LED:  
  - **LED świeci**, czujnik jest aktywny.  
  - **LED zgaszony**, czujnik  jest nieaktywny.
- Panel led wyświetla status alarmu:  
  - **Symbol górnej kreski** oznacza aktywny alarm.  
  - **Symbol dolnej kreski** oznacza nieaktywny alarm.
- Na panelu led wyświetlana jest również liczba czujników pir które wykryły ruch, liczba wyświetlana jest dopóki czujnik nie zostanie wyłączony.

---
## Użyte komponenty

- Mikrokontroler **ATMega328P** (np. Arduino UNO/Nano).
- Czujniki PIR (5 sztuk).
- Diody LED (5 sztuk).
- Przyciski (5 sztuk).
- Wyświetlacz LED (7-segmentowy).
- 8 - bitowy rejestr przesuwny (do podłączenia wyświetlacza LED).
- Rezystory, przewody, zasilanie.
---
## Działanie alarmu
**Alarm wyłączony** - żaden czujnik pir nie jest włączony.


