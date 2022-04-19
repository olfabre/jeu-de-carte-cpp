#ifndef __MAILLONCARTE_HPP__
#define __MAILLONCARTE_HPP__
#include "dataCarte.hpp"

class maillonCarte
{
  
    private:

        friend class listeCarte;
        dataCarte dataCarte;
        maillonCarte * adresseCarteSuivante;

    public:

        maillonCarte(); // Constructeur par défaut
        maillonCarte(int argValeur, int argCouleur); // Constructeur d'initialisation
        maillonCarte(int argValeur, int argCouleur, maillonCarte * argPointeur); // Constructeur d'initialisation
        ~maillonCarte(); // Destructeur
};
#endif