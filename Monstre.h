#include<iostream>
using namespace std;

class Monstre {
protected:
    const string nom;
    int hp_actuel;
    int hp_max;
    int attaque;
    int defense;
    int mercy_actuel;
    int mercy_goal;
    vector<string> ids_actions;

public:
    //getters
    string getNom(){return nom;}
    int getHp_actuel(){return hp_actuel;}
    int getHp_max(){return hp_max;}
    int getAttaque(){return attaque;}
    int getDefense(){return defense;}
    int getMercy_actuel(){return mercy_actuel;}
    int getMercy_goal(){return mercy_goal;}
    int getActions(){return ids_actions;}

    //setters
    void setHp_actuel(int hpA){this->hp_actuel = hpA;}
    void setHp_max(int hpM){this->hp_max = hpM;}
    int setAttaque(int atc){this->attaque = atc;}
    int setDefense(int def){this->defense = def;}

    virtual int getNbActions() const = 0;
    bool peutEtreEpargne() const;
    void subirDegats(int d);
    void modifierMercy(int delta);
    virtual void tour_monstre(class Joueur& j);
};
