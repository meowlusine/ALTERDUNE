#include<iostream>
#include "Joueur.h"
#include "Item.h"
using namespace std ;

Joueur::Joueur(string nom,int hp_max=100,int hp_actuel=100, int nb_victoires=0,int nb_tues=0, int nb_epargnes=0){
    this->nom = nom;
    this->hp_max = hp_max;
    this->hp_actuel = hp_actuel;
    this-> nb_victoires = nb_victoires;
    this->nb_tues = nb_tues;
    this->nb_epargnes = nb_epargnes;
    Item*[] inventaire = new Item*[2];
    EntreeBestiaire*[] bestiaire = new EntreeBestiaire*[0];
}

void Joueur::setNom(string n)   { nom = n; }

void Joueur::setHpMax(int v) { if (v > 0) hp_max = v; }

void Joueur::setHpActuel(int v) {
    if(v < 0){
        hp_actuel = 0;
    }
    else if (v > hp_max){
        hp_actuel = hp_max;
    }
    else{
        hp_actuel = v;
    }
}


void Joueur::incrementerVictoires()  { nb_victoires++; }

void Joueur::incrementerTues()       { nb_tues++; }

void Joueur::incrementerEpargnes()   { nb_epargnes++; }

void Joueur::ajouterItem(Item& item){ inventaire.push_back(item); }

void Joueur::ajouterEntreeBestiaire(EntreeBestiaire& e) { bestiaire.push_back(e); }

bool Joueur::estVivant(){ return hp_actuel > 0; }

bool Joueur::aGagne(){ return nb_victoires >= 10; }

string Joueur::getFin(){
    if (nb_tues == 0){
        return "PACIFISTE";
    }
    if (nb_epargnes == 0){
        return "GENOCIDAIRE";
    }
    return "NEUTRE";
}

void Joueur::utiliser_item(int id){
    if (index > 0 && index <= inventaire.size()){
        if(inventaire[id].estDisponible()){
            inventaire[id].utiliser(*this);
        }
    }
}

