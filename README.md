# Proiect Arduino - Sistem de irigatie automata
Proiectul va implementa un sistem de monitorizare si udare automata a plantelor. 
Acesta foloseste doua surse de alimentare (una pentru arduino si alta pentru pompa) 

## Mod de funtionare
Se alimenteaza circuitul, se citeste temperatura si umiditatea, daca umiditatea e sub 20 ne intoarcem la pasul anterior, daca e peste 20 se trece la temperatura, daca acesta este mai mica de 30 de grade, porneste pompa, daca este mai mare de 30 se intoarce la pasul cu citierea temperaturii si umiditatii, dupa ce pompa porneste, se revine la pasul cu citirea temperaturii si umiditatii
Pe LCD apar informatii referitoare la temperatura si umiditate si cand pompa este pornita



## 🛠 Componente necesare
 Arduino Uno R3 
ATmega328P 
LCD 1602
Senzor temperatuta si umiditate DHT11
Modul cu senzor de umiditate sol
LED 
Modul releu 5V
Baterie 9V
Rezistori
Pompa de apa
condensator electrolitic

