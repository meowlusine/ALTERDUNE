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
    void utiliserItem(int index);
    void afficherStats() const;
    string getFin() const; // "GENOCIDAIRE" / "PACIFISTE" / "NEUTRE"
};
