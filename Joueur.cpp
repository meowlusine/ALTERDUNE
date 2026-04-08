#include<iostream>
#include "Joueur.h"
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
