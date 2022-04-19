#ifndef __DATACARTE_HPP__
#define __DATACARTE_HPP__

class dataCarte
{
    private:

        friend class maillonCarte;
        friend class listeCarte;
        int attValeur; // 13 valeurs possibles: 2, 3, 4, 5, 6, 7, 8, 9, 10, 11=Valet, 12=Dame, 13=Roi, 14=As)
        int attCouleur; // 4 couleurs possibles: 0= Trèfle, 1=Carreau, 2=Coeur, 3=Pique

    public:

        dataCarte(); // Constructeur par défaut
        dataCarte(int argValeur, int argCouleur); // Constructeur d'initialisation   

};
#endif