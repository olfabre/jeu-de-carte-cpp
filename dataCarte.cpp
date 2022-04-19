#include <iostream>
#include "dataCarte.hpp"

/* Class dataCarte: constructeur par défaut */
dataCarte :: dataCarte(){
    (*this).attValeur  = 0;
    (*this).attCouleur = 0;
};

/* Class dataCarte: constructeur d'initialisation */
dataCarte :: dataCarte(int argValeur, int argCouleur){
    (*this).attValeur  = argValeur;
    (*this).attCouleur = argCouleur;
};