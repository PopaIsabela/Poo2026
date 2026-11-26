#include <iostream>
#include <string>
using namespace std;

class Destinatie {
private:
    string tara;
    string oras;
    int nrZile;
    float pret;
    static int nrDestinatii;
    const int id;

public:
    Destinatie() : tara("Romania"), oras("Brasov"),
        nrZile(3), pret(800), id(1) {
        nrDestinatii++;
    }

    Destinatie(string tara, string oras)
        : tara(tara), oras(oras),
        nrZile(5), pret(1500), id(2) {
        nrDestinatii++;
    }

    Destinatie(string tara, string oras, int zile,
        float pret, int idDestinatie)
        : tara(tara), oras(oras), nrZile(zile),
        pret(pret), id(idDestinatie) {
        nrDestinatii++;
    }

    void afisare() const {
        cout << "ID destinatie: " << id << endl;
        cout << "Tara: " << tara << endl;
        cout << "Oras: " << oras << endl;
        cout << "Numar zile: " << nrZile << endl;
        cout << "Pret: " << pret << " lei" << endl;
        cout << endl;
    }

    static void afisareNrDestinatii() {
        cout << "Numar destinatii: "
            << nrDestinatii << endl;
    }
};

int Destinatie::nrDestinatii = 0;

int main() {
    cout << "Agentie de turism" << endl;
    cout << endl;

    Destinatie d1;
    Destinatie d2("Italia", "Roma");
    Destinatie d3("Thailanda", "Bangkok", 7, 4500, 3);
    Destinatie d4("Japonia", "Tokyo", 10, 7500, 4);

    d1.afisare();
    d2.afisare();
    d3.afisare();
    d4.afisare();

    Destinatie::afisareNrDestinatii();

    return 0;
}