#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
class StrategieTri {
public:
    virtual void trier(vector<string>& vec) = 0;
    virtual ~StrategieTri() {}
};
class TriCroissant : public StrategieTri {
public:
    void trier(vector<string>& vec) override {
        sort(vec.begin(), vec.end());
    }
};
class TriDecroissant : public StrategieTri {
public:
    void trier(vector<string>& vec) override {
        sort(vec.begin(), vec.end(), greater<string>());
    }
};
class TriParLongueur : public StrategieTri {
public:
    void trier(vector<string>& vec) override {
        sort(vec.begin(), vec.end(), [](const string& a, const string& b) {
            return a.length() < b.length();
        });
    }
};
class GestionnaireTri {
private:
    StrategieTri* strategie;

public:
    GestionnaireTri(StrategieTri* strat) {
        strategie = strat;
    }
    void setStrategie(StrategieTri* strat) {
        strategie = strat;
    }
    void effectuerTri(vector<string>& vec) {
        if (strategie != nullptr) {
            strategie->trier(vec);
        }
    }
};
void afficherVecteur(const vector<string>& vec, const string& message) {
    cout << message << " : ";
    for (const string& s : vec) {
        cout << "'" << s << "' ";
    }
    cout << endl;
}
int main() {
    vector<string>& mots = *(new vector<string>{"Cpp", "Programmation", "Python", "Formation", "POO"});
    afficherVecteur(mots, "Vecteur initial");
    TriCroissant stratCroissant;
    TriDecroissant stratDecroissant;
    TriParLongueur stratLongueur;
    GestionnaireTri gestionnaire(&stratCroissant);
    gestionnaire.effectuerTri(mots);
    afficherVecteur(mots, "\nApres le tri croissant");
    gestionnaire.setStrategie(&stratDecroissant);
    gestionnaire.effectuerTri(mots);
    afficherVecteur(mots, "Apres changement dynamique vers le tri decroissant");
    gestionnaire.setStrategie(&stratLongueur);
    gestionnaire.effectuerTri(mots);
    afficherVecteur(mots, "Apres changement dynamique vers le tri par longueur");
    delete &mots;
    return 0;
}