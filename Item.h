class Item {
private:
    std::string nom, type; // type = "HEAL"
    int valeur, quantite;
public:
    void utiliser(class Joueur& j);
    bool estDisponible() const;
};
