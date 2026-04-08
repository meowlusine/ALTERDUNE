#include "Monstre.h"
using namespace std;

Monstre:: Monstre (string nom, int hp_actuel, int hp_max,
int attaque, int defense, int mercy_actuel, int mercy_goal, vector<string> ids_actions)
{
    this->nom = nom;
    this->hp_actuel = hp_actuel;
    this->hp_max = hp_max;
    this->attaque = attaque;
    this->defense = defense;
    this->mercy_actuel = mercy_actuel;
    this->mercy_goal = mercy_goal;
    this->ids_actions = ids_actions;
}
bool Monstre:: peutEtreEpargne()
{
    if(mercy_actuel == mercy_goal)
    {
        return true;
    }
    else{
        return false;
    }
}
void Monstre::subirDegats(int d)
{
    if()
    {
        hp_actuel -= d;
    }
}
void Monstre::modifierMercy(int delta)
{
    if()
    {
        mercy_actuel += delta;
    }
    else if()
    {
        mercy_actuel -= delta;
    }
}
