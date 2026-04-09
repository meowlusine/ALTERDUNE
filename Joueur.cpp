#include <iostream>
#include <cassert>
#include "Joueur.h"
#include "Item.h"

using namespace std;

Joueur::Joueur(string nom,int hp_max, int nb_victoires,int nb_tues, int nb_epargnes){
    this->nom = nom;
    this->hp_max = hp_max;
    this->hp_actuel = hp_max;
    this-> nb_victoires = nb_victoires;
    this->nb_tues = nb_tues;
    this->nb_epargnes = nb_epargnes;
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

void Joueur::utiliserItem(int index){
    if (index >= 0 && index < (int)inventaire.size()){
        if(inventaire[index].estDisponible()){
            inventaire[index].utiliser(*this);
        }
    }
}

void Joueur::afficherStats(){
    cout<< "Nom du joueur : "<<nom<<endl;
    cout<<"HP : "<<hp_actuel<<" / "<<hp_max<<endl;
    cout<<"Nombre de victoires : "<<nb_victoires<<" sur 10"<<endl;
    cout<<"Nombre de monstres tués : "<<nb_tues<<endl;
    cout<<"Nombre de monstres épargés : "<<nb_epargnes<<endl;
}



// TEST

void testerJoueur() {

    // --- Constructeur ---
    Joueur j("Frisk", 100, 0, 0, 0);
    assert(j.getNom()      == "Frisk");
    assert(j.getHpActuel() == 100);         // hp_actuel = hp_max au départ

    // --- setHpActuel : borne basse ---
    j.setHpActuel(-10);
    assert(j.getHpActuel() == 0);           // jamais sous 0

    // --- setHpActuel : borne haute ---
    j.setHpActuel(9999);
    assert(j.getHpActuel() == 100);         // jamais au dessus de hp_max

    // --- setHpMax ---
    j.setHpMax(200);
    assert(j.getHpMax() == 200);            // valeur positive acceptée

    j.setHpMax(-5);
    assert(j.getHpMax() == 200);            // valeur négative ignorée

    // --- setNom ---

    // donc on teste juste qu'un nom valide est bien assigné
    j.setNom("Chara");
    assert(j.getNom() == "Chara");          // setNom valide fonctionne

    // --- incrementers ---
    Joueur j2("Test", 100, 0, 0, 0);
    j2.incrementerVictoires();
    assert(j2.getNbVictoires() == 1);       // incrémente bien de 1

    j2.incrementerTues();
    j2.incrementerTues();
    assert(j2.getNbTues() == 2);            // double incrément correct

    // --- aGagne ---
    Joueur j3("Gagnant", 100, 0, 0, 0);
    for (int i = 0; i < 10; i++) j3.incrementerVictoires();
    assert(j3.aGagne());                    // 10 victoires → gagné

    Joueur j4("PasEncoreGagne", 100, 0, 0, 0);
    j4.incrementerVictoires();
    assert(!j4.aGagne());                   // 1 victoire → pas encore gagné

    // --- getFin ---
    Joueur j5("Pacifiste", 100, 0, 0, 0);
    j5.incrementerEpargnes();
    assert(j5.getFin() == "PACIFISTE");     // 0 tués → pacifiste

    Joueur j6("Genocidaire", 100, 0, 0, 0);
    j6.incrementerTues();
    assert(j6.getFin() == "GENOCIDAIRE");   // 0 épargnés → génocidaire

    Joueur j7("Neutre", 100, 0, 0, 0);
    j7.incrementerTues();
    j7.incrementerEpargnes();
    assert(j7.getFin() == "NEUTRE");        // les deux → neutre

    // --- utiliserItem ---

    // on crée un monstre bidon pour les tests
    Joueur j8("Soigne", 100, 0, 0, 0);
    j8.setHpActuel(50);
    Item potion("Potion", "HEAL", 30, 1);
    j8.ajouterItem(potion);

    j8.utiliserItem(0);
    assert(j8.getHpActuel() == 80);         // 50 + 30 = 80

    j8.utiliserItem(0);                  // quantite = 0, ignoré
    assert(j8.getHpActuel() == 80);         // HP inchangés

    // --- utiliserItem : index invalide ---
    j8.utiliserItem(-1);
    assert(j8.getHpActuel() == 80);         // index négatif ignoré

    j8.utiliserItem(99);
    assert(j8.getHpActuel() == 80);         // index trop grand ignoré

    cout << "Tous les tests Joueur passes !\n";
}
