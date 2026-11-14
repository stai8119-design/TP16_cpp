#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
class Observateur {
public:
    virtual void mettreAJour(float temperature, float humidite, float pression) = 0;
    virtual ~Observateur() {}
};

class StationMeteo {
private:
    vector<Observateur*> observateurs;
    float temperature;
    float humidite;
    float pression;

public:
    void attacher(Observateur* o) {
        observateurs.push_back(o);
    }

    void detacher(Observateur* o) {
        observateurs.erase(remove(observateurs.begin(), observateurs.end(), o), observateurs.end());
    }

    void notifier() {
        for (auto* obs : observateurs) {
            obs->mettreAJour(temperature, humidite, pression);
        }
    }

    void setMesures(float t, float h, float p) {
        temperature = t;
        humidite = h;
        pression = p;
        cout << "\nMesures de la station meteo:" << endl;
        notifier();
    }
};

class AffichageTemperature : public Observateur {
public:
    void mettreAJour(float t, float h, float p) override {
        cout << "[Affichage Temperature] Temperature actuelle : " << t << " °C" << endl;
    }
};

class AffichageHumidite : public Observateur {
public:
    void mettreAJour(float t, float h, float p) override {
        cout << "[Affichage Humidite] Humidite actuelle : " << h << " %" << endl;
    }
};
class AffichagePression : public Observateur {
public:
    void mettreAJour(float t, float h, float p) override {
        cout << "[Affichage Pression] Pression atmospherique : " << p << " hPa" << endl;
    }
};

int main() {
    StationMeteo station;
    AffichageTemperature affTemp;
    AffichageHumidite affHum;
    AffichagePression affPress;
    station.attacher(&affTemp);
    station.attacher(&affHum);
    station.attacher(&affPress);
    station.setMesures(23.7, 67.0, 1546.22);
    cout << "\nDesabonnement de l'affichage de l'humidite" << endl;
    station.detacher(&affHum);
    station.setMesures(28.0, 50.0, 1010.0);

    return 0;
}