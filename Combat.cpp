#include "Combat.h"
#include <random>

Combat::Combat(Joueur& j, const vector<DonneeMonstre>& bdd) : joueur(j), monstre(nullptr), combatGagne(false) {
    genererMonstreAleatoire(bdd);
}

Combat::~Combat() {
    if (monstre != nullptr) {
        delete monstre;
        monstre = nullptr;
    }
}


void Combat::genererMonstreAleatoire(const vector<DonneeMonstre>& bdd) {
    if (bdd.empty()) return;

    static random_device rd;  // Graine matérielle
    static mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, bdd.size() - 1); // Distribution entre 0 et max

    int index = distrib(gen); // Tirage
    DonneeMonstre data = bdd[index];
//On s'adapte au différents types de monster
    if (data.categorie == "NORMAL") {
        monstre = new MonstreNormal(data.nom, data.hp, data.atk, data.def, data.mercyGoal, data.actionsACT);
    } else if (data.categorie == "MINIBOSS") {
        monstre = new MiniBoss(data.nom, data.hp, data.atk, data.def, data.mercyGoal, data.actionsACT);
    } else if (data.categorie == "BOSS") {
        monstre = new Boss(data.nom, data.hp, data.atk, data.def, data.mercyGoal, data.actionsACT);
    }
}



void Combat::lancer() {
    cout << "Un " << monstre->getNom() << " apparait !" << endl;

    while (joueur.getHpActuel() > 0 && monstre->getHpActuel() > 0 && !combatGagne) {
        cout << "\n--- TOUR DU JOUEUR ---" << endl;
        cout << "HP Joueur: " << joueur.getHpActuel() << " | HP Monstre: " << monstre->getHpActuel() << endl;
        cout << "1. FIGHT\n2. ACT\n3. ITEM\n4. MERCY" << endl;
        cout << "Choix : ";

        int choix;
        cin >> choix;

        switch (choix) {
            case 1: fight(); break;
            case 2:
                int choixAct;
                cout << "Choisissez une action (1 a " << monstre->getNbActions() << ") : ";
                cin >> choixAct;
                act(choixAct);
                break;
            case 3:
                int choixItem;
                cout << "Index de l'item a utiliser : ";
                cin >> choixItem;
                item(choixItem);
                break;
            case 4: mercy(); break;
            default: cout << "Action invalide. Vous perdez votre tour !" << endl; break;
        }

        if (monstre->getHpActuel() > 0 && !combatGagne) {
            cout << "\n--- TOUR DU MONSTRE ---" << endl;
            monstre->tour_monstre(joueur);
        }
    }

    if (joueur.getHpActuel() <= 0) {
        cout << "GAME OVER... Vous etes mort." << endl;
    } else if (combatGagne) {
        joueur.incrementerVictoires();
        joueur.incrementerEpargne();
        cout << "Vous avez epargne le " << monstre->getNom() << ". Victoire !" << endl;
    } else {
        joueur.incrementerVictoires();
        joueur.incrementerTues();
        cout << "Vous avez vaincu le " << monstre->getNom() << ". Victoire !" << endl;
    }
}

void Combat::fight() {
    // --- Génération aléatoire propre (C++11) ---
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, monstre->getHpMax()); // Dégâts entre 0 et HP Max

    int degats = distrib(gen);

    if (degats == 0) {
        cout << "L'attaque rate !" << endl;
    } else {
        monstre->subirDegats(degats);
        cout << "Vous infligez " << degats << " degats au monstre !" << endl;
    }
}

void Combat::act(int choix) {
    cout << "Vous interagissez avec le monstre (Action " << choix << ")." << endl;
}

void Combat::item(int index) {
    joueur.utiliserItem(index);
    cout << "Vous avez utilise un objet." << endl;
}

void Combat::mercy() {
    if (monstre->peutEtreEpargne()) {
        combatGagne = true;
    } else {
        cout << "Le monstre n'est pas encore pret a etre epargne (Mercy actuel: "
             << monstre->getMercyActuel() << "/" << monstre->getMercyGoal() << ")." << endl;
    }
}
