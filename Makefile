CFLAGS=-g -ansi -pedantic -Wall -std=c++11 #-DMAP

exe : menu.o Chainon.o ListeChainee.o TrajetSimple.o Trajet.o TrajetComposee.o Catalogue.o
	g++ -o exe $(CFLAGS) menu.o Chainon.o ListeChainee.o Trajet.o TrajetSimple.o TrajetComposee.o Catalogue.o
Chainon.o : Chainon.cpp
	g++ -c $(CFLAGS) Chainon.cpp
menu.o :menu.cpp
	g++ -c $(CFLAGS) menu.cpp
ListeChainee.o : ListeChainee.cpp
	g++ -c $(CFLAGS) ListeChainee.cpp
Trajet.o : Trajet.cpp
	g++ -c $(CFLAGS) Trajet.cpp
TrajetSimple.o : TrajetSimple.cpp
	g++ -c $(CFLAGS) TrajetSimple.cpp
TrajetComposee.o : TrajetComposee.cpp
	g++ -c $(CFLAGS) TrajetComposee.cpp
Catalogue.o: Catalogue.cpp
	g++ -c $(CFLAGS) Catalogue.cpp
clean:
	rm exe *.o
