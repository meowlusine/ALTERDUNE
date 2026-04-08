class MonstreMiniBoss : public Monstre {
public:
    Monstre();
    int getNbActions() const override { return 3; }
};
