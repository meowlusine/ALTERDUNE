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


    void setNom(string n)   { nom = n; }
    void setHpMax(int v) { if (v > 0) hp_max = v; }
    void setHpActuel(int v) {
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

    // modif des attributs
    void incrementerVictoires()  { nb_victoires++; }
    void incrementerTues()       { nb_tues++; }
    void incrementerEpargnes()   { nb_epargnes++; }

    void ajouterItem(Item& item){ inventaire.push_back(item); }
    void ajouterEntreeBestiaire(EntreeBestiaire& e) { bestiaire.push_back(e); }

    bool estVivant(){ return hp_actuel > 0; }
    bool aGagne(){ return nb_victoires >= 10; }

    void utiliserItem(int index);
    void afficherStats() const;
    string getFin() const; // "GENOCIDAIRE" / "PACIFISTE" / "NEUTRE"
};
