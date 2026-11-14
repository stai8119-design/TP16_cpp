#include <iostream>
#include <string>

using namespace std;

class Configuration {
private:
    string cheminFichier;
    string utilisateur;
    string motDePasse;
    Configuration() {
        cheminFichier = "log.txt";
        utilisateur = "admin";
        motDePasse = "root0612006";
    }

public:
    Configuration(const Configuration&) = delete;
    Configuration& operator=(const Configuration&) = delete;
    static Configuration& getInstance() {
        static Configuration instance;
        return instance;
    }
    void afficherParametres() const {
        cout << "Parametres de configuration:" << endl;
        cout << "Chemin du fichier : " << cheminFichier << endl;
        cout << "Utilisateur       : " << utilisateur << endl;
        cout << "Mot de passe      : " << motDePasse << endl;
    }
    void setParametres(string chemin, string user, string psw) {
        cheminFichier = chemin;
        utilisateur = user;
        motDePasse = psw;
    }
};
int main() {
    Configuration& config1 = Configuration::getInstance();
    config1.afficherParametres();
    cout << "\nMise a jour des parametres:" << endl;
    config1.setParametres("data/doc3/settings.ini", "superadmin", "secre990t");
    Configuration& config2 = Configuration::getInstance();
    cout << "\nAffichage depuis config2 :" << endl;
    config2.afficherParametres();
    cout << "\nAdresse de config1 : " << &config1 << endl;
    cout << "Adresse de config2 : " << &config2 << endl;
    return 0;
}