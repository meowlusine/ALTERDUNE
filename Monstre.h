class Monstre {
protected:
    std::string nom;
    int hp_actuel, hp_max;
    int attaque, defense;
    int mercy_actuel, mercy_goal;
    std::vector<std::string> ids_actions; // identifiants dans le catalogue

public:
    virtual int getNbActions() const = 0; // PURE VIRTUELLE → classe abstraite
    bool peutEtreEpargne() const;
    void subirDegats(int d);
    void modifierMercy(int delta);
    virtual void tour_monstre(class Joueur& j);
    // getters/setters...
};
