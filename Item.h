#include<iostream>
using namespace std ;

class Item {
private:
    string nom;
    string type;
    int valeur;
    int quantite;

public:

    // getters et setters
    string getNom(){ return nom; }
    string getType() { return type; }
    int getValeur() { return valeur; }
    int getQuantite(){ return quantite; }
    void setNom(string n);
    void setType(string t);
    void setValeur(int v);
    void setQuantite(int q);


    bool estDisponible();
    void utiliser(Joueur& j);

};
