#ifndef __LISTECARTE_HPP__
#define __LISTECARTE_HPP__
#include "maillonCarte.hpp"

class listeCarte
{
  
    private:

        maillonCarte * adresseTete;     // Pointeur de référence à une variable de type carte sur la première carte
        maillonCarte * adresseQueue;    // Pointeur de référence à une variable de type carte sur la dernière carte

    public:
        
        listeCarte();   // Constructeur par defaut
        ~listeCarte();  // Destructeur

        void construireJeuCompletOrdonne(int argNbrDeCarte = 52); // Méthode pour construire un jeu complet ordonné
        
        void insererCarteFinListe(int argValeur, int argCouleur); // Méthode pour insèrer une nouvelle carte au début de la liste du jeu de carte

        bool estVide(); // Méthode pour retourner true si la liste est vide sinon false

        void afficher(); // Méthode pour un joli affiche de la liste de la liste du jeu de carte

        int compterMaillonCarte(); // Méthode pour compter le nbr de maillonCarte dans un liste de jeu de carte

        void triCroissant(); // Méthode pour trier les cartes par valeur et par couleur (croissant)

        void triDecroissant(); // Méthode pour trier les cartes par valeur et par couleur (décroissant)


};
#endif