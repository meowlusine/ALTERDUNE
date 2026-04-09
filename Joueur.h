#ifndef JOUEUR_H
#define JOUEUR_H
#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
#include "EntreeBestiaire.h"

class Joueur {

private:
    string nom;
    int hp_actuel;
    int hp_max;
    int nb_victoires;
    int nb_tues;
    int nb_epargnes;
    vector<Item> inventaire;
    vector<EntreeBestiaire> bestiaire;

public:

    Joueur(string nom,int hp_max, int nb_victoires,int nb_tues, int nb_epargnes);

    //getters et setters

    string getNom(){ return nom; }
    int getHpActuel(){ return hp_actuel; }
    int getHpMax(){return hp_max; }
    int getNbVictoires(){ return nb_victoires; }
    int getNbTues(){ return nb_tues; }
    int getNbEpargnes(){ return nb_epargnes; }
    vector<Item> getInventaire(){ return inventaire; }
    vector<EntreeBestiaire> getBestiaire(){ return bestiaire; }

    bool estVivant();
    void setNom(string n);
    void setHpMax(int v);
    void setHpActuel(int v);
    void incrementerVictoires();
    void incrementerTues();
    void incrementerEpargnes();
    void ajouterItem(Item& item);
    void ajouterEntreeBestiaire(EntreeBestiaire& e);
    bool aGagne();
    string getFin();

    void utiliserItem(int id);
    void afficherStats();


};

#endif
