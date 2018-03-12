RUN: Main.o Escenario.o Item.o Jugador.o Tren.o Bombas.o Invisible.o V.o Normal.o Espina.o 
	g++ Main.o Escenario.o Item.o Jugador.o Invisible.o Tren.o Bombas.o V.o Normal.o Espina.o -o RUN -lncurses

Main.o: Main.cpp Escenario.h Item.h Jugador.h Tren.h Invisible.h Bombas.h V.h Normal.h Espina.h
	g++ -c Main.cpp

Escenario.o: Escenario.h Escenario.cpp
	g++ -c Escenario.cpp

Item.o: Item.h Item.cpp
	g++ -c Item.cpp 

Jugador.o: Jugador.h Jugador.cpp Item.h
	g++ -c Jugador.cpp

Tren.o: Tren.h Tren.cpp Escenario.h
	g++ -c Tren.cpp

Bombas.o: Bombas.h Bombas.cpp Item.h
	g++ -c Bombas.cpp

Invisible.o: Invisible.h Invisible.cpp Escenario.h
	g++ -c Invisible.cpp

V.o: V.h V.cpp Bombas.h
	g++ -c V.cpp

Normal.o: Normal.h Normal.cpp Bombas.h
	g++ -c Normal.cpp

Espina.o: Espina.h Espina.cpp Bombas.h
	g++ -c Espina.cpp




