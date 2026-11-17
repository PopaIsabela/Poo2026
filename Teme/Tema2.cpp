#include <iostream>
#include <string>
#include <vector>
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
    string getMarca() const { return marca; }
    string getModel() const { return model; }
    int getAnFabricatie() const { return anFabricatie; }
    float getPretPeZi() const { return pretPeZi; }
    int getId() const { return id; }
    void setMarca(const string& valoare) { marca = valoare; }
    void setModel(const string& valoare) { model = valoare; }
    void setAnFabricatie(int valoare) { if (valoare > 1885) anFabricatie = valoare; }
    void setPretPeZi(float valoare) { if (valoare >= 0) pretPeZi = valoare; }
    float calculeazaCost(int zile) const { return zile > 0 ? zile * pretPeZi : 0; }
    bool operator==(const Masina& alta) const { return id == alta.id && marca == alta.marca && model == alta.model; }
    bool operator<(const Masina& alta) const { return pretPeZi < alta.pretPeZi; }
    Masina operator+(float majorare) const { Masina copie(*this); copie.pretPeZi += majorare; return copie; }
    Masina& operator+=(float majorare) { pretPeZi += majorare; return *this; }
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
    string getNume() const { return nume; }
    string getTelefon() const { return telefon; }
    int getVarsta() const { return varsta; }
    void setNume(const string& valoare) { nume = valoare; }
    void setTelefon(const string& valoare) { telefon = valoare; }
    void setVarsta(int valoare) { if (valoare >= 18) varsta = valoare; }
    bool operator==(const Client& altul) const { return nume == altul.nume && telefon == altul.telefon; }
    bool operator<(const Client& altul) const { return varsta < altul.varsta; }
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
    int getIdInchiriere() const { return idInchiriere; }
    int getNrZile() const { return nrZile; }
    float getPretPeZi() const { return pretPeZi; }
    void setNrZile(int valoare) { if (valoare > 0) nrZile = valoare; }
    void setPretPeZi(float valoare) { if (valoare >= 0) pretPeZi = valoare; }
    bool operator==(const Inchiriere& alta) const { return idInchiriere == alta.idInchiriere; }
    bool operator<(const Inchiriere& alta) const { return calculeazaCost() < alta.calculeazaCost(); }
    Inchiriere operator+(int zile) const { Inchiriere copie(*this); copie.nrZile += zile; return copie; }
    Inchiriere& operator+=(int zile) { if (nrZile + zile > 0) nrZile += zile; return *this; }
    void afisare() const {
        cout << "Inchiriere #" << idInchiriere << ", zile: " << nrZile
            << ", cost total: " << calculeazaCost() << " lei\n";
    }
};

int main() {
    cout << "Tema 2 - Etapa 7: vectori si calcule inchirieri\n";
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
    cout << "\nTest getteri si setteri:\n";
    m1.setPretPeZi(120);
    c1.setNume("Maria Ionescu");
    i1.setNrZile(3);
    m1.afisare(); c1.afisare(); i1.afisare();
    cout << "Cost masina pentru 4 zile: " << m1.calculeazaCost(4) << " lei\n";
    cout << "\nTest operatori:\n";
    cout << "Masini egale? " << (m3 == m4 ? "da" : "nu") << "\n";
    cout << "Masina mai ieftina? " << (m1 < m3 ? "da" : "nu") << "\n";
    Masina m5 = m1 + 30;
    m5 += 10;
    m5.afisare();
    cout << "Clienti egali? " << (c2 == c3 ? "da" : "nu") << "\n";
    Inchiriere i4 = i2 + 2;
    i4 += 1;
    i4.afisare();
    cout << "\nFlota de masini:\n";
    vector<Masina> flota;
    flota.reserve(3);
    flota.push_back(m1);
    flota.push_back(m2);
    flota.push_back(m3);
    for (const Masina& masina : flota) masina.afisare();

    cout << "\nInchirieri active:\n";
    vector<Inchiriere> inchirieri;
    inchirieri.reserve(3);
    inchirieri.push_back(i1);
    inchirieri.push_back(i2);
    inchirieri.push_back(i4);
    float incasari = 0;
    int totalZile = 0;
    for (const Inchiriere& inchiriere : inchirieri) {
        inchiriere.afisare();
        incasari += inchiriere.calculeazaCost();
        totalZile += inchiriere.getNrZile();
    }
    cout << "Numar masini in flota: " << flota.size() << "\n";
    cout << "Total zile inchiriate: " << totalZile << "\n";
    cout << "Incasari estimate: " << incasari << " lei\n";
    return 0;
}
