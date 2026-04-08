class Joueur {
private:
    std::string nom;
    int hp_actuel, hp_max;
    int nb_victoires, nb_tues, nb_epargnes;
    std::vector<Item> inventaire;
    std::vector<EntreeBestiaire> bestiaire;
public:
    void utiliserItem(int index);
    void afficherStats() const;
    std::string getFin() const; // "GENOCIDAIRE" / "PACIFISTE" / "NEUTRE"
};
