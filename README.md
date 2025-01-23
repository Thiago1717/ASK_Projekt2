# ASK_Projekt2

# System Alarmowy na ATMega328P

## Opis projektu

Projekt systemu alarmowego opartego na mikrokontrolerze ATMega328P (Arduino), który obsługuje minimum 5 czujników PIR. System umożliwia:

- Aktywację/dezaktywację każdego czujnika PIR indywidualnie.
- Wyświetlanie statusu każdego czujnika na dedykowanych diodach LED:  
  - **LED świeci**, gdy czujnik PIR jest aktywny.  
  - **LED zgaszony**, gdy czujnik PIR jest nieaktywny.
- Wyświetlanie na panelu LED statusu całego alarmu:  
  - **Symbol górnej kreski** oznacza aktywny alarm.  
  - **Symbol dolnej kreski** oznacza nieaktywny alarm.
- Liczenie i wyświetlanie na panelu LED liczby czujników, które wykryły ruch od momentu aktywacji alarmu.

System wykorzystuje mikrokontroler ATMega328P jako jednostkę sterującą oraz prosty interfejs użytkownika, co czyni go przystępnym i wszechstronnym rozwiązaniem dla systemów alarmowych.

---

## Funkcjonalności

- **Czujniki PIR:** Minimum 5 sztuk z indywidualną kontrolą.
- **Diody LED:** Sygnalizacja aktywności czujników.
- **Wyświetlacz LED:** Informacje o statusie alarmu i liczbie wykrytych ruchów.
- **Jednostka sterująca:** ATMega328P (Arduino).

---

## Wymagane komponenty

- Mikrokontroler **ATMega328P** (np. Arduino UNO/Nano).
- Czujniki PIR (5 sztuk).
- Diody LED (5 sztuk).
- Wyświetlacz LED (np. 7-segmentowy lub inny).
- Rezystory, przewody, zasilanie.

---
