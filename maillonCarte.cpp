#include <iostream>
#include "maillonCarte.hpp"
using namespace std;

/* Class maillonCarte: constructeur par défaut */
maillonCarte :: maillonCarte(){
    (*this).dataCarte.attValeur     = 0;
    (*this).dataCarte.attCouleur    = 0;
    (*this).adresseCarteSuivante    = NULL;
};

/* Class maillonCarte: constructeur d'initialisation */
maillonCarte :: maillonCarte(int argValeur, int argCouleur){
    (*this).dataCarte.attValeur     = argValeur;
    (*this).dataCarte.attCouleur    = argCouleur;
    (*this).adresseCarteSuivante    = NULL;
};

/* Class maillonCarte: constructeur d'initialisation */
maillonCarte :: maillonCarte(int argValeur, int argCouleur, maillonCarte * argPointeur){
    (*this).dataCarte.attValeur     = argValeur;
    (*this).dataCarte.attCouleur    = argCouleur; 
    (*this).adresseCarteSuivante    = argPointeur;
};

/* Class maillonCarte: destructeur */
maillonCarte :: ~maillonCarte(){
if (adresseCarteSuivante != NULL){
    delete adresseCarteSuivante;
}
};