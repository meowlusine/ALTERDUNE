#include<iostream>
using namespace std ;

class Item {
private:
    string nom;
    string type;
    int valeur;
    int quantite;
public:
    void utiliser(class Joueur& j);
    bool estDisponible() const;
};

