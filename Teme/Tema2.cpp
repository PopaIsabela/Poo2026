#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
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
    Masina() : marca("Dacia"), model("Logan"),
        anFabricatie(2020), pretPeZi(100), id(1) {
        nrMasini++;
    }

    Masina(string marca, string model)
        : marca(marca), model(model),
        anFabricatie(2022), pretPeZi(150), id(2) {
        nrMasini++;
    }

    Masina(string marca, string model, int an, float pret, int idMasina)
        : marca(marca), model(model),
        anFabricatie(an), pretPeZi(pret), id(idMasina) {
        nrMasini++;
    }

    Masina(const Masina& m)
        : marca(m.marca), model(m.model),
        anFabricatie(m.anFabricatie),
        pretPeZi(m.pretPeZi), id(m.id) {
        nrMasini++;
    }

    ~Masina() {
        nrMasini--;
    }

    void afisare() const {
        cout << "Masina: " << marca << " " << model
            << ", ID: " << id
            << ", an: " << anFabricatie
            << ", pret pe zi: " << pretPeZi << " lei\n";
    }

    static void afisareNrMasini() {
        cout << "Numar masini: " << nrMasini << endl;
    }

    string getMarca() const {
        return marca;
    }

    string getModel() const {
        return model;
    }

    int getAnFabricatie() const {
        return anFabricatie;
    }

    float getPretPeZi() const {
        return pretPeZi;
    }

    int getId() const {
        return id;
    }

    void setMarca(string marca) {
        this->marca = marca;
    }

    void setModel(string model) {
        this->model = model;
    }

    void setAnFabricatie(int an) {
        if (an > 1885)
            anFabricatie = an;
    }

    void setPretPeZi(float pret) {
        if (pret >= 0)
            pretPeZi = pret;
    }

    float calculeazaCost(int zile) const {
        if (zile > 0)
            return zile * pretPeZi;
        return 0;
    }

    bool operator==(const Masina& m) const {
        return id == m.id && marca == m.marca
            && model == m.model;
    }

    bool operator<(const Masina& m) const {
        return pretPeZi < m.pretPeZi;
    }

    Masina operator+(float pret) const {
        Masina copie(*this);
        copie.pretPeZi += pret;
        return copie;
    }

    Masina& operator+=(float pret) {
        pretPeZi += pret;
        return *this;
    }
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

    Client(const Client& c)
        : nume(c.nume), telefon(c.telefon), varsta(c.varsta) {
    }

    ~Client() = default;

    void afisare() const {
        cout << "Client: " << nume
            << ", telefon: " << telefon
            << ", varsta: " << varsta << endl;
    }

    string getNume() const {
        return nume;
    }

    string getTelefon() const {
        return telefon;
    }

    int getVarsta() const {
        return varsta;
    }

    void setNume(string nume) {
        this->nume = nume;
    }

    void setTelefon(string telefon) {
        this->telefon = telefon;
    }

    void setVarsta(int varsta) {
        if (varsta >= 18)
            this->varsta = varsta;
    }

    bool operator==(const Client& c) const {
        return nume == c.nume && telefon == c.telefon;
    }

    bool operator<(const Client& c) const {
        return varsta < c.varsta;
    }
};

class Inchiriere {
private:
    int idInchiriere;
    int nrZile;
    float pretPeZi;

public:
    Inchiriere()
        : idInchiriere(1), nrZile(1), pretPeZi(100) {
    }

    Inchiriere(int id, int zile, float pret)
        : idInchiriere(id), nrZile(zile), pretPeZi(pret) {
    }

    Inchiriere(const Inchiriere& i)
        : idInchiriere(i.idInchiriere),
        nrZile(i.nrZile), pretPeZi(i.pretPeZi) {
    }

    ~Inchiriere() = default;

    float calculeazaCost() const {
        return nrZile * pretPeZi;
    }

    int getIdInchiriere() const {
        return idInchiriere;
    }

    int getNrZile() const {
        return nrZile;
    }

    float getPretPeZi() const {
        return pretPeZi;
    }

    void setNrZile(int zile) {
        if (zile > 0)
            nrZile = zile;
    }

    void setPretPeZi(float pret) {
        if (pret >= 0)
            pretPeZi = pret;
    }

    bool operator==(const Inchiriere& i) const {
        return idInchiriere == i.idInchiriere;
    }

    bool operator<(const Inchiriere& i) const {
        return calculeazaCost() < i.calculeazaCost();
    }

    Inchiriere operator+(int zile) const {
        Inchiriere copie(*this);
        copie.nrZile += zile;
        return copie;
    }

    Inchiriere& operator+=(int zile) {
        if (nrZile + zile > 0)
            nrZile += zile;
        return *this;
    }

    void afisare() const {
        cout << "Inchiriere: " << idInchiriere
            << ", zile: " << nrZile
            << ", cost total: " << calculeazaCost()
            << " lei" << endl;
    }
};

void salveazaText(const vector<Masina>& flota,
    const vector<Inchiriere>& inchirieri) {

    ofstream out("inchirieri_auto.txt");

    if (!out) {
        cout << "Eroare la deschiderea fisierului" << endl;
        return;
    }

    out << flota.size() << endl;

    for (const Masina& m : flota) {
        out << quoted(m.getMarca()) << " "
            << quoted(m.getModel()) << " "
            << m.getAnFabricatie() << " "
            << m.getPretPeZi() << " "
            << m.getId() << endl;
    }

    out << inchirieri.size() << endl;

    for (const Inchiriere& i : inchirieri) {
        out << i.getIdInchiriere() << " "
            << i.getNrZile() << " "
            << i.getPretPeZi() << endl;
    }

    out.close();
}

void citesteText() {
    ifstream in("inchirieri_auto.txt");

    if (!in) {
        cout << "Fisierul nu poate fi citit" << endl;
        return;
    }

    int n;

    if (!(in >> n) || n < 0 || n > 10000)
        return;

    cout << "\nMasini din fisierul text:" << endl;

    for (int j = 0; j < n; j++) {
        string marca, model;
        int an, id;
        float pret;

        if (!(in >> quoted(marca) >> quoted(model)
            >> an >> pret >> id))
            return;

        Masina m(marca, model, an, pret, id);
        m.afisare();
    }

    if (!(in >> n) || n < 0 || n > 10000)
        return;

    cout << "\nInchirieri din fisierul text:" << endl;

    for (int j = 0; j < n; j++) {
        int id, zile;
        float pret;

        if (!(in >> id >> zile >> pret))
            return;

        Inchiriere i(id, zile, pret);
        i.afisare();
    }

    in.close();
}

void salveazaBinar(const vector<Inchiriere>& inchirieri) {
    ofstream out("inchirieri_auto.bin", ios::binary);

    if (!out) {
        cout << "Eroare la deschiderea fisierului binar" << endl;
        return;
    }

    int n = (int)inchirieri.size();

    out.write((char*)&n, sizeof(n));

    for (const Inchiriere& i : inchirieri) {
        int id = i.getIdInchiriere();
        int zile = i.getNrZile();
        float pret = i.getPretPeZi();

        out.write((char*)&id, sizeof(id));
        out.write((char*)&zile, sizeof(zile));
        out.write((char*)&pret, sizeof(pret));
    }

    out.close();
}

void citesteBinar() {
    ifstream in("inchirieri_auto.bin", ios::binary);

    if (!in) {
        cout << "Fisierul binar nu poate fi citit" << endl;
        return;
    }

    int n;

    if (!in.read((char*)&n, sizeof(n))
        || n < 0 || n > 10000)
        return;

    cout << "\nInchirieri din fisierul binar:" << endl;

    for (int j = 0; j < n; j++) {
        int id, zile;
        float pret;

        if (!in.read((char*)&id, sizeof(id)))
            return;

        if (!in.read((char*)&zile, sizeof(zile)))
            return;

        if (!in.read((char*)&pret, sizeof(pret)))
            return;

        Inchiriere i(id, zile, pret);
        i.afisare();
    }

    in.close();
}

int main() {
    cout << "Firma de inchirieri auto\n\n";

    Masina m1;
    Masina m2("BMW", "Seria 3");
    Masina m3("Audi", "A4", 2023, 250, 3);

    m1.afisare();
    m2.afisare();
    m3.afisare();

    Masina::afisareNrMasini();

    Client c1;
    Client c2("Ana Popescu", "0712345678", 25);

    c1.afisare();
    c2.afisare();

    Inchiriere i1;
    Inchiriere i2(2, 5, 250);

    i1.afisare();
    i2.afisare();

    Masina m4 = m3;
    Client c3 = c2;
    Inchiriere i3 = i2;

    cout << "\nObiecte copiate:" << endl;

    m4.afisare();
    c3.afisare();
    i3.afisare();

    Masina::afisareNrMasini();

    m1.setPretPeZi(120);
    c1.setNume("Maria Ionescu");
    i1.setNrZile(3);

    m1.afisare();
    c1.afisare();
    i1.afisare();

    cout << "Cost pentru 4 zile: "
        << m1.calculeazaCost(4) << " lei" << endl;

    if (m3 == m4)
        cout << "Masinile sunt egale" << endl;

    if (m1 < m3)
        cout << "Prima masina este mai ieftina" << endl;

    Masina m5 = m1 + 30;
    m5 += 10;
    m5.afisare();

    if (c2 == c3)
        cout << "Clientii sunt egali" << endl;

    Inchiriere i4 = i2 + 2;
    i4 += 1;
    i4.afisare();

    vector<Masina> flota;

    flota.push_back(m1);
    flota.push_back(m2);
    flota.push_back(m3);

    cout << "\nLista masini:" << endl;

    for (int j = 0; j < flota.size(); j++) {
        flota[j].afisare();
    }

    vector<Inchiriere> inchirieri;

    inchirieri.push_back(i1);
    inchirieri.push_back(i2);
    inchirieri.push_back(i4);

    float incasari = 0;
    int totalZile = 0;

    cout << "\nLista inchirieri:" << endl;

    for (int j = 0; j < inchirieri.size(); j++) {
        inchirieri[j].afisare();
        incasari += inchirieri[j].calculeazaCost();
        totalZile += inchirieri[j].getNrZile();
    }

    cout << "Numar masini: " << flota.size() << endl;
    cout << "Total zile: " << totalZile << endl;
    cout << "Total incasari: " << incasari << " lei" << endl;

    salveazaText(flota, inchirieri);
    citesteText();

    salveazaBinar(inchirieri);
    citesteBinar();

    return 0;
}