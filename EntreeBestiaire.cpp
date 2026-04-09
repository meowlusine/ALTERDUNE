#include <iostream>
#include <cassert>
#include "Monstre.h"
#include "EntreeBestiaire.h"


using namespace std;

EntreeBestiaire::EntreeBestiaire(Monstre* monstre, string resultat){
    this->monstre = monstre;
    this->resultat = resultat;

}


void EntreeBestiaire::afficher(){
    cout<< "Monstre : "<<monstre<<"/ Resultat : "<<resultat<<endl;
}
