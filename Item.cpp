#include <iostream>
#include <cassert>
#include "Item.h"
#include "Joueur.h"


using namespace std;

Item::Item(string nom, string type,int valeur, int quantite){
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
    quantite--;
}


// TESTS
void testerItem() {

    // --- setNom : valide ---
    Item i1("Potion", "HEAL", 15, 3);
    i1.setNom("SuperPotion");
    assert(i1.getNom() == "SuperPotion");

    // --- setNom : vide ignoré ---
    i1.setNom("");
    assert(i1.getNom() == "SuperPotion");

    // --- setType : valide ---
    i1.setType("HEAL_MAX");
    assert(i1.getType() == "HEAL_MAX");

    // --- setType : vide ignoré ---
    i1.setType("");
    assert(i1.getType() == "HEAL_MAX");

    // --- setValeur : positif accepté ---
    i1.setValeur(50);
    assert(i1.getValeur() == 50);

    // --- setValeur : négatif ignoré ---
    i1.setValeur(-10);
    assert(i1.getValeur() == 50);

    // --- setQuantite : positif accepté ---
    i1.setQuantite(5);
    assert(i1.getQuantite() == 5);

    // --- setQuantite : négatif ignoré ---
    i1.setQuantite(-1);
    assert(i1.getQuantite() == 5);

    // --- estDisponible : quantite > 0 ---
    Item i2("Snack", "HEAL", 8, 1);
    assert(i2.estDisponible());

    // --- estDisponible : quantite = 0 ---
    Item i3("Vide", "HEAL", 8, 0);
    assert(!i3.estDisponible());

    // --- utiliser HEAL : soigne le joueur ---
    Joueur j1("Frisk", 100, 0, 0, 0);
    j1.setHpActuel(50);
    Item potion("Potion", "HEAL", 30, 1);
    potion.utiliser(j1);
    assert(j1.getHpActuel() == 80);         // 50 + 30 = 80

    // --- utiliser HEAL : quantite diminue ---
    assert(potion.getQuantite() == 0);

    // --- utiliser HEAL : HP borné à hp_max ---
    Joueur j2("Test", 100, 0, 0, 0);
    j2.setHpActuel(90);
    Item grandePotion("GrandePotion", "HEAL", 50, 1);
    grandePotion.utiliser(j2);
    assert(j2.getHpActuel() == 100);        // 90 + 50 = 140 → borné à 100

    // --- utiliser HEAL_MAX : soigne à fond ---
    Joueur j3("Test2", 100, 0, 0, 0);
    j3.setHpActuel(10);
    Item elixir("Elixir", "HEAL_MAX", 0, 1);
    elixir.utiliser(j3);
    assert(j3.getHpActuel() == 100);        // remis à hp_max

    // --- utiliser HEAL_MAX : quantite diminue ---
    assert(elixir.getQuantite() == 0);

    cout << "Tous les tests Item passes !\n";
}






