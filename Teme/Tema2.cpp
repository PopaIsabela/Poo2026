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

    virtual ~Masina() {
        nrMasini--;
    }

    virtual void afisare() const {
        cout << "Masina: " << marca << " " << model
            << ", ID: " << id
            << ", an: " << anFabricatie
            << ", pret pe zi: " << pretPeZi << " lei" << endl;
    }

    static void afisareNrMasini() {
        cout << "Numar obiecte Masina: " << nrMasini << endl;
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

    virtual float calculeazaCost(int zile) const {
        if (zile > 0)
            return zile * pretPeZi;
        return 0;
    }

    virtual string getTip() const {
        return "Masina normala";
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
        copie.setPretPeZi(copie.pretPeZi + pret);
        return copie;
    }

    Masina& operator+=(float pret) {
        setPretPeZi(pretPeZi + pret);
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

    virtual ~Client() = default;

    virtual void afisare() const {
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

    virtual float calculeazaPretFinal(float pret) const {
        return pret;
    }

    virtual string getTip() const {
        return "Client normal";
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
        copie.setNrZile(copie.nrZile + zile);
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

class MasinaElectrica : public Masina {
private:
    int autonomie;
    float capacitateBaterie;

public:
    MasinaElectrica() : Masina("Dacia", "Spring", 2023, 150, 5) {
        autonomie = 230;
        capacitateBaterie = 27;
    }

    MasinaElectrica(string marca, string model, int an,
        float pret, int id, int autonomie, float baterie)
        : Masina(marca, model, an, pret, id) {
        this->autonomie = autonomie;
        capacitateBaterie = baterie;
    }

    MasinaElectrica(const MasinaElectrica& m)
        : Masina(m) {
        autonomie = m.autonomie;
        capacitateBaterie = m.capacitateBaterie;
    }

    int getAutonomie() const {
        return autonomie;
    }

    float getCapacitateBaterie() const {
        return capacitateBaterie;
    }

    void setAutonomie(int autonomie) {
        if (autonomie > 0)
            this->autonomie = autonomie;
    }

    void setCapacitateBaterie(float baterie) {
        if (baterie > 0)
            capacitateBaterie = baterie;
    }

    void afisare() const override {
        Masina::afisare();

        cout << "Autonomie: " << autonomie << " km" << endl;
        cout << "Capacitate baterie: "
            << capacitateBaterie << " kWh" << endl;
    }

    float calculeazaCost(int zile) const override {
        return Masina::calculeazaCost(zile) * 0.95f;
    }

    string getTip() const override {
        return "Masina electrica";
    }
};

class ClientPremium : public Client {
private:
    float reducere;
    int nrInchirieri;

public:
    ClientPremium() : Client() {
        reducere = 10;
        nrInchirieri = 0;
    }

    ClientPremium(string nume, string telefon, int varsta,
        float reducere, int nrInchirieri)
        : Client(nume, telefon, varsta) {
        this->reducere = reducere;
        this->nrInchirieri = nrInchirieri;
    }

    ClientPremium(const ClientPremium& c)
        : Client(c) {
        reducere = c.reducere;
        nrInchirieri = c.nrInchirieri;
    }

    float getReducere() const {
        return reducere;
    }

    int getNrInchirieri() const {
        return nrInchirieri;
    }

    void setReducere(float reducere) {
        if (reducere >= 0 && reducere <= 100)
            this->reducere = reducere;
    }

    void setNrInchirieri(int nr) {
        if (nr >= 0)
            nrInchirieri = nr;
    }

    float calculeazaPretFinal(float pret) const override {
        return pret - pret * reducere / 100;
    }

    string getTip() const override {
        return "Client premium";
    }

    void afisare() const override {
        Client::afisare();

        cout << "Reducere: " << reducere << "%" << endl;
        cout << "Numar inchirieri: "
            << nrInchirieri << endl;
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

void raportFinal(const vector<Masina*>& masini,
    const vector<Client*>& clienti,
    const vector<Inchiriere>& inchirieri) {

    float incasari = 0;
    int totalZile = 0;
    int nrElectrice = 0;
    int nrPremium = 0;
    float totalPreturi = 0;

    for (Masina* m : masini) {
        totalPreturi += m->getPretPeZi();

        if (m->getTip() == "Masina electrica")
            nrElectrice++;
    }

    for (Client* c : clienti) {
        if (c->getTip() == "Client premium")
            nrPremium++;
    }

    for (const Inchiriere& i : inchirieri) {
        incasari += i.calculeazaCost();
        totalZile += i.getNrZile();
    }

    cout << "\nRaport final firma" << endl;
    cout << "------------------------" << endl;
    cout << "Total masini: " << masini.size() << endl;
    cout << "Masini electrice: " << nrElectrice << endl;
    cout << "Total clienti: " << clienti.size() << endl;
    cout << "Clienti premium: " << nrPremium << endl;
    cout << "Total inchirieri: " << inchirieri.size() << endl;
    cout << "Total zile inchiriate: " << totalZile << endl;
    cout << "Total incasari: " << incasari << " lei" << endl;

    if (!masini.empty()) {
        cout << "Pret mediu pe zi: "
            << totalPreturi / masini.size()
            << " lei" << endl;
    }

    if (!inchirieri.empty()) {
        cout << "Valoare medie inchiriere: "
            << incasari / inchirieri.size()
            << " lei" << endl;
    }
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

    for (const Masina& m : flota) {
        m.afisare();
    }

    vector<Inchiriere> inchirieri;

    inchirieri.push_back(i1);
    inchirieri.push_back(i4);

    cout << "\nLista inchirieri:" << endl;

    for (const Inchiriere& i : inchirieri) {
        i.afisare();
    }

    salveazaText(flota, inchirieri);
    citesteText();

    salveazaBinar(inchirieri);
    citesteBinar();

    MasinaElectrica me1;

    MasinaElectrica me2("Tesla", "Model 3",
        2024, 300, 4, 500, 75);

    cout << "\nMasini electrice:" << endl;

    me1.afisare();
    me2.afisare();

    MasinaElectrica me3 = me2;
    me3.setAutonomie(550);
    me3.afisare();

    ClientPremium cp1;

    ClientPremium cp2("Andrei Popescu",
        "0723456789", 30, 15, 8);

    cout << "\nClienti premium:" << endl;

    cp1.afisare();
    cp2.afisare();

    ClientPremium cp3 = cp2;
    cp3.setReducere(20);
    cp3.afisare();

    Masina* ptrMasina = &me2;
    Client* ptrClient = &cp2;

    cout << "\nTest upcasting:" << endl;

    ptrMasina->afisare();
    ptrClient->afisare();

    float cost = ptrMasina->calculeazaCost(5);
    float costFinal = ptrClient->calculeazaPretFinal(cost);

    cout << "Cost initial: " << cost << " lei" << endl;
    cout << "Cost final: " << costFinal << " lei" << endl;

    vector<Masina*> toateMasinile;

    toateMasinile.push_back(&m1);
    toateMasinile.push_back(&m2);
    toateMasinile.push_back(&m3);
    toateMasinile.push_back(&me1);
    toateMasinile.push_back(&me2);

    cout << "\nToate masinile:" << endl;

    for (Masina* m : toateMasinile) {
        cout << m->getTip() << endl;
        m->afisare();

        cout << "Cost pentru 3 zile: "
            << m->calculeazaCost(3)
            << " lei" << endl;
    }

    vector<Client*> totiClientii;

    totiClientii.push_back(&c1);
    totiClientii.push_back(&c2);
    totiClientii.push_back(&cp2);

    cout << "\nToti clientii:" << endl;

    for (Client* c : totiClientii) {
        cout << c->getTip() << endl;
        c->afisare();

        cout << "Pret final pentru 1000 lei: "
            << c->calculeazaPretFinal(1000)
            << " lei" << endl;
    }

    Inchiriere i5(3, 5, costFinal / 5);
    inchirieri.push_back(i5);

    salveazaText(flota, inchirieri);
    salveazaBinar(inchirieri);

    raportFinal(toateMasinile, totiClientii, inchirieri);

    return 0;
}