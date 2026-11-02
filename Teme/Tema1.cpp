#include <iostream>
#include <string>
using namespace std;

class Copac {
private:
    string nume;
    static int nrCopaci;
    const int id;
    int* inaltime;

public:
    Copac() : id(1) {
        nume = "Tei";
        inaltime = new int(300);
        nrCopaci++;
    }

    Copac(string numeCopac) : id(2) {
        nume = numeCopac;
        inaltime = new int(250);
        nrCopaci++;
    }

    Copac(string numeCopac, int idCopac, int inaltimeCopac) : id(idCopac) {
        nume = numeCopac;
        inaltime = new int(inaltimeCopac);
        nrCopaci++;
    }

    ~Copac() {
        delete inaltime;
        nrCopaci--;
    }

    void afisare() {
        cout << "Copac: " << nume
            << ", id = " << id
            << ", inaltime = " << *inaltime << " cm\n";
    }
};

int Copac::nrCopaci = 0;


class Banca {
private:
    string material;
    static int nrBanci;
    const int id;
    int* nrLocuri;

public:
    Banca() : id(1) {
        material = "Lemn";
        nrLocuri = new int(3);
        nrBanci++;
    }

    Banca(string mat) : id(2) {
        material = mat;
        nrLocuri = new int(4);
        nrBanci++;
    }

    Banca(string mat, int idBanca, int locuri) : id(idBanca) {
        material = mat;
        nrLocuri = new int(locuri);
        nrBanci++;
    }

    ~Banca() {
        delete nrLocuri;
        nrBanci--;
    }

    void afisare() {
        cout << "Banca: " << material
            << ", id = " << id
            << ", locuri = " << *nrLocuri << "\n";
    }
};

int Banca::nrBanci = 0;


class Alee {
private:
    string nume;
    static int nrAlei;
    const int id;
    int* lungime;

public:
    Alee() : id(1) {
        nume = "Aleea Centrala";
        lungime = new int(100);
        nrAlei++;
    }

    Alee(string numeAlee) : id(2) {
        nume = numeAlee;
        lungime = new int(80);
        nrAlei++;
    }

    Alee(string numeAlee, int idAlee, int lungimeAlee) : id(idAlee) {
        nume = numeAlee;
        lungime = new int(lungimeAlee);
        nrAlei++;
    }

    ~Alee() {
        delete lungime;
        nrAlei--;
    }

    void afisare() {
        cout << "Alee: " << nume
            << ", id = " << id
            << ", lungime = " << *lungime << " m\n";
    }
};

int Alee::nrAlei = 0;


int main() {
    cout << "Test parc\n\n";

    Copac c1;
    Copac c2("Stejar");
    Copac c3("Molid", 10, 420);

    c1.afisare();
    c2.afisare();
    c3.afisare();

    cout << "\nBanci:\n";

    Banca b1;
    Banca b2("Metal");
    Banca b3("Plastic", 5, 2);

    b1.afisare();
    b2.afisare();
    b3.afisare();

    cout << "\nAlei:\n";

    Alee a1;
    Alee a2("Aleea Copiilor");
    Alee a3("Aleea Lac", 7, 250);

    a1.afisare();
    a2.afisare();
    a3.afisare();

    return 0;
}