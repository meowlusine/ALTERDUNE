#include<iostream>
using namespace std;

class MonstreNormal : public Monstre {
public:
    int getNbActions() const override { return 2; }
};
