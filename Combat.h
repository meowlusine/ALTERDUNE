class Combat {
private:
    Joueur& joueur;
    Monstre* monstre;
public:
    void lancer();       // boucle principale
    void fight();
    void act(int choix);
    void mercy();
    void item(int index);
};
