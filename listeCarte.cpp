#include <iostream>
#include "dataCarte.hpp"
#include "maillonCarte.hpp"
#include "listeCarte.hpp"
using namespace std;

/* Class listeCarte: constructeur par défaut */
listeCarte :: listeCarte(){
(*this).adresseTete     = NULL;
(*this).adresseQueue    = NULL;
};

listeCarte :: ~listeCarte(){
if (adresseTete != NULL){
    delete adresseTete;
}
};


/* Class listeCarte: estVide */
bool listeCarte :: estVide(){
    if ((*this).adresseTete==NULL){ 
        return true;
    }else{
        return false;
    }
};


/* Class listeCarte: insererCarteFinListe */
void listeCarte :: insererCarteFinListe(int argValeur, int argCouleur){

    // Création d'une nouveau objet maillonCarte
    maillonCarte * adresseNouvelleCarte = new maillonCarte(argValeur, argCouleur);
    // cas ou la listeCarte est vide
    if ((*this).estVide()){    
        (*this).adresseTete = (*this).adresseQueue = adresseNouvelleCarte;
        cout << "\nadresse mémoire tete: " << (*this).adresseTete << "|->" << endl;
        cout << "Carte N°" << ((argValeur + (argCouleur*12))-1) << ": adresse mémoire= " << adresseNouvelleCarte << ", valeur=" << adresseNouvelleCarte->dataCarte.attValeur << ", couleur=" << adresseNouvelleCarte->dataCarte.attCouleur;
    }else{
        (*(*this).adresseQueue).adresseCarteSuivante = adresseNouvelleCarte;
        cout << ", adresse mémoire carte suivante= " << adresseNouvelleCarte << "|-> " << endl;
        cout << "Carte N°" << ((argValeur + (argCouleur*13))-1) << ": adresse mémoire= " << adresseNouvelleCarte << ", valeur=" << adresseNouvelleCarte->dataCarte.attValeur << ", couleur=" << adresseNouvelleCarte->dataCarte.attCouleur;
        (*this).adresseQueue = adresseNouvelleCarte;
    }
};


/* Méthode Class listeCarte: construireJeuComplet */
void listeCarte :: construireJeuCompletOrdonne(int argNbrDeCarte){

    /* 
    Jeu de carte complet composé de 52 objets cartes ordonnées:
        
    Dans un jeu de carte, les datas représentent:
            > 13 valeurs (j): 2, 3, 4, 5, 6, 7, 8, 9, 10, 11=Valet, 12=Dame, 13=Roi, 14=As
            > 4 couleurs (i): 0= Trèfle, 1=Carreau, 2=Coeur, 3=Pique
    */

    int couleurMax = 4;
    int valeurMax = 14;
    int cpteur = 0; 
    for (int i=0; i < couleurMax; i++){

        for (int j=2; j < valeurMax+1; j++ ){

            (*this).insererCarteFinListe(j,i);

        }; // fin de la boucle j
    }; // fin de la boucle for i

};

/* Méthode Class listeCarte: afficher */
void listeCarte :: afficher(){
maillonCarte * adresseMaillonCarte = (*this).adresseTete;
int compteur=0;

while(adresseMaillonCarte != NULL){
 
        int valeur = adresseMaillonCarte->dataCarte.attValeur;
        int couleur = adresseMaillonCarte->dataCarte.attCouleur;
        compteur++;
            cout << "\n\nmaillon " << compteur << endl;
            cout << "+-------+" << endl;
            if (couleur == 0) cout << "| ♣   ♣ |" << endl;
            if (couleur == 1) cout << "| ♦   ♦ |" << endl;
            if (couleur == 2) cout << "| ♥   ♥ |" << endl;
            if (couleur == 3) cout << "| ♠   ♠ |" << endl; 

            if (valeur == 2) cout << "|   2   |" << endl;
            if (valeur == 3) cout << "|   3   |" << endl;
            if (valeur == 4) cout << "|   4   |" << endl;
            if (valeur == 5) cout << "|   5   |" << endl;
            if (valeur == 6) cout << "|   6   |" << endl;
            if (valeur == 7) cout << "|   7   |" << endl;
            if (valeur == 8) cout << "|   8   |" << endl;
            if (valeur == 9) cout << "|   9   |" << endl;
            if (valeur == 10) cout << "|  10   |" << endl;
            if (valeur == 11) cout << "|   V   |" << endl;
            if (valeur == 12) cout << "|   D   |" << endl;
            if (valeur == 13) cout << "|   R   |" << endl;
            if (valeur == 14) cout << "|   1   |" << endl;

            if (couleur == 0) cout << "| ♣   ♣ |" << endl;
            if (couleur == 1) cout << "| ♦   ♦ |" << endl;
            if (couleur == 2) cout << "| ♥   ♥ |" << endl;
            if (couleur == 3) cout << "| ♠   ♠ |" << endl;    
            cout << "+-------+" << endl; 

            adresseMaillonCarte = adresseMaillonCarte->adresseCarteSuivante;

        }

};


/* Méthode Class listeCarte: compterMaillonCarte */
int listeCarte :: compterMaillonCarte(){

    maillonCarte * adresseMaillon = (*this).adresseTete;
    int nbr_maillonCarte = 0;

    while (adresseMaillon != NULL ){
        nbr_maillonCarte++;
        adresseMaillon= adresseMaillon->adresseCarteSuivante;
    };
        return nbr_maillonCarte;
};




/* Méthode Class listeCarte: triCroissant */
void listeCarte :: triCroissant(){

/*  
  Système de tri à bulle
*/ 

// Calcul du nombre de maillonCarte
int nbr_maillonCarte = (*this).compterMaillonCarte();
if (nbr_maillonCarte < 2) return;
cout << "-> Il y a " << nbr_maillonCarte << " cartes à trier";

maillonCarte * pointeurTemp, * pointeurP;
int permutationValeur, permutationCouleur;
maillonCarte * adresseDebut = (*this).adresseTete;

if (adresseDebut != NULL){

for (pointeurTemp = adresseDebut;pointeurTemp->adresseCarteSuivante!=NULL; pointeurTemp=pointeurTemp->adresseCarteSuivante ){

            for (pointeurP = pointeurTemp->adresseCarteSuivante; pointeurP != NULL; pointeurP=pointeurP->adresseCarteSuivante){

                if (pointeurP->dataCarte.attValeur < pointeurTemp->dataCarte.attValeur){

                    permutationValeur = pointeurP->dataCarte.attValeur;
                    permutationCouleur = pointeurP->dataCarte.attCouleur;

                    pointeurP->dataCarte.attValeur = pointeurTemp->dataCarte.attValeur;
                    pointeurP->dataCarte.attCouleur = pointeurTemp->dataCarte.attCouleur;
                    pointeurTemp->dataCarte.attValeur = permutationValeur;
                    pointeurTemp->dataCarte.attCouleur = permutationCouleur;

                };
            };
    };
};
};




/* Méthode Class listeCarte: triDecroissant */
void listeCarte :: triDecroissant(){

/*  
  Système de tri à bulle
*/ 

// Calcul du nombre de maillonCarte
int nbr_maillonCarte = (*this).compterMaillonCarte();
if (nbr_maillonCarte < 2) return;
cout << "-> Il y a " << nbr_maillonCarte << " cartes à trier";

maillonCarte * pointeurTemp, * pointeurP;
int permutationValeur, permutationCouleur;
maillonCarte * adresseDebut = (*this).adresseTete;

if (adresseDebut != NULL){

for (pointeurTemp = adresseDebut;pointeurTemp->adresseCarteSuivante!=NULL; pointeurTemp=pointeurTemp->adresseCarteSuivante ){

            for (pointeurP = pointeurTemp->adresseCarteSuivante; pointeurP != NULL; pointeurP=pointeurP->adresseCarteSuivante){

                if (pointeurP->dataCarte.attCouleur > pointeurTemp->dataCarte.attCouleur){

                    permutationValeur = pointeurP->dataCarte.attValeur;
                    permutationCouleur = pointeurP->dataCarte.attCouleur;

                    pointeurP->dataCarte.attValeur = pointeurTemp->dataCarte.attValeur;
                    pointeurP->dataCarte.attCouleur = pointeurTemp->dataCarte.attCouleur;
                    pointeurTemp->dataCarte.attValeur = permutationValeur;
                    pointeurTemp->dataCarte.attCouleur = permutationCouleur;

                };
            };

            for (pointeurP = pointeurTemp->adresseCarteSuivante; pointeurP != NULL; pointeurP=pointeurP->adresseCarteSuivante){

                if (pointeurP->dataCarte.attValeur > pointeurTemp->dataCarte.attValeur){

                    permutationValeur = pointeurP->dataCarte.attValeur;
                    permutationCouleur = pointeurP->dataCarte.attCouleur;

                    pointeurP->dataCarte.attValeur = pointeurTemp->dataCarte.attValeur;
                    pointeurP->dataCarte.attCouleur = pointeurTemp->dataCarte.attCouleur;
                    pointeurTemp->dataCarte.attValeur = permutationValeur;
                    pointeurTemp->dataCarte.attCouleur = permutationCouleur;

                };
            };




    };
};
};