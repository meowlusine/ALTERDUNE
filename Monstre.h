#include<iostream>
using namespace std;

class Monstre {
protected:
    string nom;
    int hp_actuel;
    int hp_max;
    int attaque;
    int defense;
    int mercy_actuel;
    int mercy_goal;
    vector<string> ids_actions;

public:
    virtual int getNbActions() const = 0;
    bool peutEtreEpargne() const;
    void subirDegats(int d);
    void modifierMercy(int delta);
    virtual void tour_monstre(class Joueur& j);
};
