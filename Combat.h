#ifndef COMBAT_H
#define COMBAT_H

#include <iostream>
#include <vector>
#include <string>
#include "Joueur.h"
#include "Monstre.h"

using namespace std;

// Structure pour stocker les données lues depuis le CSV
struct DonneeMonstre {
    string categorie;
    string nom;
    int hp;
    int atk;
    int def;
    int mercyGoal;
    vector<string> actionsACT;
};

class Combat {
private:
    Joueur& joueur;
    Monstre* monstre;
    bool combatGagne;

    void genererMonstreAleatoire(const vector<DonneeMonstre>& bdd);

public:
    Combat(Joueur& j, const vector<DonneeMonstre>& bdd);
    ~Combat();

    void lancer();
    void fight();
    void act(int choix);
    void mercy();
    void item(int index);
};

#endif
