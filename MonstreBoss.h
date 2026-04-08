class MonstreBoss : public Monstre {
public:
    Monstre();
    int getNbActions() const override { return 4; }
};
