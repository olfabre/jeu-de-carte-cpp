main: main.cpp listeCarte.o maillonCarte.o dataCarte.o
	g++ -o main dataCarte.o maillonCarte.o listeCarte.o main.cpp

dataCarte.o: dataCarte.hpp dataCarte.cpp
	g++ -c dataCarte.cpp

maillonCarte.o: maillonCarte.hpp maillonCarte.cpp dataCarte.hpp
	g++ -c maillonCarte.cpp

listeCarte.o: listeCarte.hpp listeCarte.cpp dataCarte.hpp maillonCarte.hpp
	g++ -c listeCarte.cpp

