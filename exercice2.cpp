#include <iostream>
#include <string>

using namespace std;
class Forme {
public:
    virtual void afficher() = 0; 
    virtual ~Forme() {}      
};
class Cercle : public Forme {
public:
    void afficher() override {
        cout << "Je suis un cercle." << endl;
    }
};
class Carre : public Forme {
public:
    void afficher() override {
        cout << "Je suis un carre." << endl;
    }
};
class Triangle : public Forme {
public:
    void afficher() override {
        cout << "Je suis un triangle." << endl;
    }
};
class FabriqueForme {
public:
    static Forme* creerForme(const string& type) {
        if (type == "Cercle") {
            return new Cercle();
        } else if (type == "Carre") {
            return new Carre();
        } else if (type == "Triangle") {
            return new Triangle();
        }
        return nullptr;
    }
};
int main() {
    Forme* frm1 = FabriqueForme::creerForme("Cercle");
    Forme* frm2 = FabriqueForme::creerForme("Carre");
    Forme* frm3 = FabriqueForme::creerForme("Triangle");
    if (frm1 != nullptr) { frm1->afficher(); delete frm1; }
    if (frm2 != nullptr) { frm2->afficher(); delete frm2; }
    if (frm3 != nullptr) { frm3->afficher(); delete frm3; }
    return 0;
}