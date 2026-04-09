#ifndef ENTREEBESTIAIRE_H
#define ENTREEBESTIAIRE_H
#include<iostream>
#include <string>
#include "Monstre.h"

using namespace std ;

class EntreeBestiaire{
private:
    Monstre* monstre;
    string resultat;

public:

    EntreeBestiaire(Monstre* monstre, string resultat);

    // getters et setters
    Monstre* getMonstre(){ return monstre; }
    string getResultat() { return resultat; }
    void setMonstre(Monstre* m){monstre = m;};
    void setResultat(string r){resultat = r;};

    void afficher();

};

#endif

