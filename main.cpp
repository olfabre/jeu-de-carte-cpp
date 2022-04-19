///     ___  _ _       _             _____     _
///    / _ \| (_)_   _(_) ___ _ __  |  ___|_ _| |__  _ __ ___
///   | | | | | \ \ / / |/ _ \ '__| | |_ / _` | '_ \| '__/ _ \
///   | |_| | | |\ V /| |  __/ |    |  _| (_| | |_) | | |  __/
///    \___/|_|_| \_/ |_|\___|_|    |_|  \__,_|_.__/|_|  \___|
///
///         mon code en ligne: https://github.com/olfabre

/*
   Structure du programme

 > Les fichiers d'en-tête qui contiennent les classes avec leurs attributs et le prototype de leurs méthodes
    . dataCarte.hpp  
    . maillonCarte.hpp
    . listeCarte.hpp

> Les fichiers qui implémentent les prototypes des classes déclarés précédemment
    . dataCarte.cpp
    . maillonCarte.cpp
    . ListeCarte.cpp

> Le fichier de point d'entrée
    . main.cpp  
*/

#include <iostream>
#include "dataCarte.hpp"
#include "maillonCarte.hpp"
#include "listeCarte.hpp"
using namespace std;






/* fonction: rendre propre le Terminal à l'execution */
  void effacerTerminal()
  {
    system("cls");   // Windows
    system("clear"); // Linux
  }


int main(){

effacerTerminal();
cout << "Olivier Fabre - Groupe MI-I1 - TP Listes chaînées en bataille" << endl;
cout << "-------------------------------------------------------------" << endl;
	
char symboles[15+1]={226, 153, 160, '-', 226, 153, 163, '-', 226, 153, 165, '-', 226, 153, 166, 0};
fprintf(stdout, "%s\n", symboles);

/* Création d'un jeu de carte vide */
listeCarte JeuDeCarte;
cout << "\n✓ Création d'un objet listeCarte vide sans objet carte -> Appel implicite pour créer un objet listeCarte à partir de son constructeur par défaut." << endl;


cout << "\n\n✓ On ajoute un jeu complet de 52 cartes à cet objet -> Appel implicite à partir d'une méthode de la class listeCarte." << endl;
/* Création d'un jeu de carte complet */
JeuDeCarte.construireJeuCompletOrdonne();

cout << "\n\n✓ Joli affichage du jeu de carte  " << endl;
/* Afficher joliement un jeu de carte */
JeuDeCarte.afficher();

cout << "\n\n✓ Tri croissant sur valeur et couleur" << endl;
/* Tri croissant */
JeuDeCarte.triCroissant();
  
JeuDeCarte.afficher();
cout << "\n\n✓ Affichage d'un tri croissant sur valeur et couleur" << endl;


listeCarte JeuDeCarte2;
JeuDeCarte2.construireJeuCompletOrdonne();

cout << "\n\n✓ Tri décroissant sur couleur et valeur" << endl;
/* Tri décroissant */
JeuDeCarte2.triDecroissant();

JeuDeCarte2.afficher();
cout << "\n\n✓ Affichage d'un tri décroissant sur couleur et valeur" << endl;





    cout << "\n\n\n0/0" << endl;
    return(0);

};