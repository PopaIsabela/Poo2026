#include <iostream>
#include <string>
using namespace std;

class Masina {
private:
    string marca;
    string model;
    int anFabricatie;
    float pretPeZi;
    static int nrMasini;
    const int id;

public:
    Masina() : id(1) {
        marca = "Dacia";
        model = "Logan";
        anFabricatie = 2020;
        pretPeZi = 100;
        nrMasini++;
    }

    Masina(string marca, string model) : id(2) {
        this->marca = marca;
        this->model = model;
        anFabricatie = 2022;
        pretPeZi = 150;
        nrMasini++;
    }

    Masina(string marca, string model, int an, float pret, int idMasina)
        : id(idMasina) {
        this->marca = marca;
        this->model = model;
        anFabricatie = an;
        pretPeZi = pret;
        nrMasini++;
    }

    void afisare() const {
        cout << "Masina: " << marca << " " << model << endl;
        cout << "ID: " << id << endl;
        cout << "An fabricatie: " << anFabricatie << endl;
        cout << "Pret pe zi: " << pretPeZi << " lei" << endl;
        cout << "------------------------" << endl;
    }

    static void afisareNrMasini() {
        cout << "Numar masini: " << nrMasini << endl;
    }
};

int Masina::nrMasini = 0;

int main() {
    cout << "Sistem de inchirieri auto\n\n";

    Masina m1;
    Masina m2("BMW", "Seria 3");
    Masina m3("Audi", "A4", 2023, 250, 3);

    m1.afisare();
    m2.afisare();
    m3.afisare();

    Masina::afisareNrMasini();

    return 0;
}