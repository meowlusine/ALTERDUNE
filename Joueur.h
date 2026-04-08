#include<iostream>
using namespace std ;

class Joueur {

private:
    string nom;
    int hp_actuel;
    int hp_max;
    int nb_victoires;
    int nb_tues;
    int nb_epargnes;
    Item*[] inventaire;
    EntreeBestiaire*[] bestiaire;

public:

    //getters et setters

    string getNom(){ return nom; }
    int getHpActuel(){ return hp_actuel; }
    int getHpMax(){return hp_max; }
    int getNbVictoires(){ return nb_victoires; }
    int getNbTues(){ return nb_tues; }
    int getNbEpargnes(){ return nb_epargnes; }
    Item*[] getInventaire(){ return inventaire; }
    EntreeBestiaire*[] getBestiaire(){ return bestiaire; }

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

    void utiliserItem(int index);
    void afficherStats();
    void tour_joueur(Monstre& m);


};
