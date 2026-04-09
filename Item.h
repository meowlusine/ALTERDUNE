#ifndef ITEM_H
#define ITEM_H

#include<iostream>
#include <string>
#include "Item.h"

class Joueur;


using namespace std ;

class Item {
private:
    string nom;
    string type;
    int valeur;
    int quantite;

public:

    Item(string nom, string type,int valeur, int quantite);
    // getters et setters
    string getNom(){ return nom; }
    string getType() { return type; }
    int getValeur() { return valeur; }
    int getQuantite(){ return quantite; }
    void setNom(string n);
    void setType(string t);
    void setValeur(int v);
    void setQuantite(int q);


    bool estDisponible();
    void utiliser(Joueur& j);

};

#endif
