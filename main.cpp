#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Combat.h"
#include "Joueur.h"

using namespace std;

// Fonction pour charger le CSV des monstres
vector<DonneeMonstre> chargerMonstres(const string& cheminFichier) {
    vector<DonneeMonstre> bdd;
    ifstream fichier(cheminFichier);

    if (!fichier.is_open()) {
        cerr << "Erreur : Fichier " << cheminFichier << " introuvable !" << endl;
        exit(1);
    }

    string ligne;
    while (getline(fichier, ligne)) {
        stringstream ss(ligne);
        string token;
        DonneeMonstre dm;

        getline(ss, dm.categorie, ';');
        getline(ss, dm.nom, ';');

        getline(ss, token, ';'); dm.hp = stoi(token);
        getline(ss, token, ';'); dm.atk = stoi(token);
        getline(ss, token, ';'); dm.def = stoi(token);
        getline(ss, token, ';'); dm.mercyGoal = stoi(token);

        for (int i = 0; i < 4; ++i) {
            if (getline(ss, token, ';')) {
                if (token != "-" && !token.empty()) {
                    dm.actionsACT.push_back(token);
                }
            }
        }
        bdd.push_back(dm);
    }

    fichier.close();
    return bdd;
}

int main() {
    cout << "--- CHARGEMENT DU JEU ---\n" << endl;
    vector<DonneeMonstre> bddMonstres = chargerMonstres("monsters.csv");
    cout << bddMonstres.size() << " monstres charges avec succes !\n" << endl;

    string nomJoueur;
    cout << "Entrez votre nom : ";
    cin >> nomJoueur;
    Joueur joueur1(nomJoueur);

    cout << "\nLancement d'un combat\n" << endl;
    Combat monCombat(joueur1, bddMonstres);
    monCombat.lancer();

    return 0;
}
