# AiSD_Lekcja4
## AiSD (4) - ADT LIST (implementacja wskaźnikowa)
### Lista jednokierunkowa w C++ (Zadanie 4.1)

Projekt zawiera implementację struktury danych ADT LIST w oparciu o listę powiązaną (jednokierunkową). 

Implementacja została zrealizowana jako szablon klasy `SingleList`, operującej wyłącznie na wskaźnikach `head` oraz `tail`. Poprawność działania wszystkich wbudowanych metod (w tym konstruktorów przenoszących, kopiujących i operacji na indeksach) jest weryfikowana w pliku `main.cpp` za pomocą testów z użyciem funkcji `assert()`.

### Zawartość
- `singlelist.hpp` - szablon klasy SingleList ze strukturą węzła oraz pełną implementacją metod.
- `main.cpp` - program testujący działanie struktury i jej interfejsu.
- `Makefile` - skrypt ułatwiający kompilację.

### Jak uruchomić?
Wymagany jest system z zainstalowanym kompilatorem g++ oraz programem make. W terminalu wpisać jedną z poniższych komend:
- `make run` – kompiluje program i od razu go uruchamia.
- `make` – tylko kompiluje program (tworzy plik main.out).
- `make clean` – usuwa pliki binarne i obiektowe wygenerowane podczas kompilacji.
