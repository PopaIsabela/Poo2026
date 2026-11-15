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
    Masina() : id(1), marca("Dacia"), model("Logan"), anFabricatie(2020), pretPeZi(100) { nrMasini++; }
    Masina(string marca, string model) : id(2), marca(marca), model(model), anFabricatie(2022), pretPeZi(150) { nrMasini++; }
    Masina(string marca, string model, int an, float pret, int idMasina)
        : id(idMasina), marca(marca), model(model), anFabricatie(an), pretPeZi(pret) {
        nrMasini++;
    }
    Masina(const Masina& m) : id(m.id), marca(m.marca), model(m.model), anFabricatie(m.anFabricatie), pretPeZi(m.pretPeZi) { nrMasini++; }
    ~Masina() { nrMasini--; }
    void afisare() const {
        cout << "Masina: " << marca << " " << model << ", ID: " << id
            << ", an: " << anFabricatie << ", pret/zi: " << pretPeZi << " lei\n";
    }
    static void afisareNrMasini() { cout << "Numar masini: " << nrMasini << "\n"; }
};
int Masina::nrMasini = 0;

class Client {
private:
    string nume;
    string telefon;
    int varsta;
public:
    Client() : nume("Necunoscut"), telefon("-"), varsta(18) {}
    Client(string nume, string telefon, int varsta)
        : nume(nume), telefon(telefon), varsta(varsta) {
    }
    Client(const Client& c) : nume(c.nume), telefon(c.telefon), varsta(c.varsta) {}
    ~Client() = default;
    void afisare() const {
        cout << "Client: " << nume << ", telefon: " << telefon
            << ", varsta: " << varsta << "\n";
    }
};

class Inchiriere {
private:
    int idInchiriere;
    int nrZile;
    float pretPeZi;
public:
    Inchiriere() : idInchiriere(1), nrZile(1), pretPeZi(100) {}
    Inchiriere(int id, int zile, float pret)
        : idInchiriere(id), nrZile(zile), pretPeZi(pret) {
    }
    Inchiriere(const Inchiriere& i) : idInchiriere(i.idInchiriere), nrZile(i.nrZile), pretPeZi(i.pretPeZi) {}
    ~Inchiriere() = default;
    float calculeazaCost() const { return nrZile * pretPeZi; }
    void afisare() const {
        cout << "Inchiriere #" << idInchiriere << ", zile: " << nrZile
            << ", cost total: " << calculeazaCost() << " lei\n";
    }
};

int main() {
    cout << "Tema 2 - Etapa 4: copiere si destructori\n";
    Masina m1;
    Masina m2("BMW", "Seria 3");
    Masina m3("Audi", "A4", 2023, 250, 3);
    m1.afisare(); m2.afisare(); m3.afisare();
    Masina::afisareNrMasini();
    Client c1;
    Client c2("Ana Popescu", "0712345678", 25);
    c1.afisare(); c2.afisare();
    Inchiriere i1;
    Inchiriere i2(2, 5, 250);
    i1.afisare(); i2.afisare();
    Masina m4 = m3;
    Client c3 = c2;
    Inchiriere i3 = i2;
    cout << "Obiecte copiate:\n";
    m4.afisare(); c3.afisare(); i3.afisare();
    Masina::afisareNrMasini();
    return 0;
}
