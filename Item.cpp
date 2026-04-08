#include<iostream>
#include "Item.h"
using namespace std ;

Item:Item(string nom, string type,int valeur, int quantite=0){
    this->nom = nom;
    this->type = type;
    this->valeur = valeur;
    this->quantite = quantite;
}


void Item::setNom(string n){ if (!n.empty()) nom = n; }
void Item::setType(string t){ if (!t.empty()) type = t; }
void Item::setValeur(int v){ if (v >= 0) valeur = v; }
void Item::setQuantite(int q){ if (q >= 0) quantite = q; }

bool Item::estDisponible() { return quantite > 0; }

void Item::utiliser(Joueur& j) {
    if (type == "HEAL")
        j.setHpActuel(j.getHpActuel() + valeur);
    else if(type =="HEAL_MAX"){
        j.setHpActuel(j.getHpMax());
    }
    else if(type==""){
    }
    quantite--;
}
