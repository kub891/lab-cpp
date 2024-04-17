#include <iostream>
#include <string>
using namespace std;

class KontoBankowe {
protected:
    string numer;
    double saldo;
    int debet;

public:
    KontoBankowe() {
        numer = "<Nie podano numeru konta>";
        saldo = 0.00;
        debet = 0;
    }

    KontoBankowe(string numer, double saldo, int debet) {
        this->numer = numer;
        this->saldo = saldo;
        this->debet = debet;
    }

    void sprawdzStan() {
        cout << "Numer konta: " << numer << ", Saldo: " << saldo << ", Debet: " << debet << endl;
    }

    void wyplac(double ile) {
        saldo -= ile;
        cout << "Wyplacono: " << ile << "Nowy stan konta to: " << saldo << endl;
    }

    void zmianaDebetu(int nowyDebet) {
        debet = nowyDebet;
        cout << "Nowy debet: " << debet << endl;
    }

    string nr_konta() {
        return numer;
    }

    double ssaldo() {
        return saldo;
    }

    void przelew(KontoBankowe& cel, double ile) {
        if (saldo >= ile) {
            saldo -= ile;
            cel.saldo += ile;
            cout << "Przelew wykonany. Nowe saldo na koncie: " << saldo << endl;
        } else {
            cout << "Nie wystarczajace srodki na koncie" << endl;
        }
    }
};


class Klient : public KontoBankowe {
protected:
    string pesel;
    string imie_nazwisko;
public:
    Klient() {
        pesel = "Brak danych";
        imie_nazwisko = "Brak danych";
    }
    Klient(string pesel, string imie_nazwisko, KontoBankowe konto) : KontoBankowe(konto) {
        this->pesel = pesel;
        this->imie_nazwisko = imie_nazwisko;
    }
    void wypisz() {
        cout << "Pesel: " << pesel << ", Imie i nazwisko: " << imie_nazwisko << endl;
        sprawdzStan();
    }
    bool czyUjemneSaldo() {
        return ssaldo() < 0;
    }
};

int main() {
    int liczbaKlientow = 3;
    Klient klienci[liczbaKlientow] = {
        Klient("032131254", "Marek marek", KontoBankowe("2137", 1569.69, 0)),
        Klient("378283777", "Marcin marcin", KontoBankowe("3210", 500.00, 0)),
        Klient("654321098", "Anna anna", KontoBankowe("4567", -200.00, 0))
    };


    klienci[0].przelew(klienci[1], 100.00);

    cout << "Stan konta dla kazdego klienta:" << endl;
    for (int i = 0; i < liczbaKlientow; ++i) {
        cout << "Klient " << i + 1 << ": ";
        klienci[i].wypisz();
    }

    cout << "\nKlienci z ujemnym saldo: " << endl;
    for (int i = 0; i < liczbaKlientow; ++i) {
        if (klienci[i].czyUjemneSaldo()) {
            cout << "Klient " << i + 1 << ": ";
            klienci[i].wypisz();
        }
    }
}
