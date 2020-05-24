# PSiO_Projekt
Typ gry: Dungeon Crawler. Typowe dla tego gatunku podziemia multipoziomowe. Grając postać schodzi coraz niżej, przechodząc do głównego bossa na ostatnim poziomie. Jako fan pierwszych części Diablo, chciałbym wykonać grę osadzoną w tym uniwersum- charakter gry, nazwy postaci itd. ale w pełnym 2D a nie rzucie izometrycznym.
Biblioteki z których będę korzystał to na pewno SFML. Będę akutalizował ten opis o kolejne, jeśli takowe użyję w trakcie prac.

Wstępny zarys struktury programu:
Klasy potrzebne: 
Bohater(statystyki, możliwość poruszania się, hitbox), 
Przedmioty (klasa główna o wielu podklasach typu broń, pancerze, potiony, itd.), 
Potwory (Tu też mogą wystąpić podklasy jak Boss,mini-boss, normalny mob. Pojawią się tu statystyki, hitboxy, AI), 
NPC(postaci niezależne jak kupcy, zleceniodawcy zadań), 
Ściany/Przeszkody, 
Teleport/Schody (wszystko co przemieszcza mnie na inną mapę), 
Zaklęcia(może wystąpić podział na offensywne i defensywne), 
Powiązania:
Na pewno będą powiązania praktycznie wszystkiego z bohaterem. Myślę czy będę wstanie zrobić drop z potworów, jeśli mi się uda to na pewno powiążę tę klasę z przedmiotami.
