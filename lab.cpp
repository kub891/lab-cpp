#include <iostream>
using namespace std;

class Zespolona{
private:
    float re;
    float im;
public:
    static int ile;
    Zespolona(float re = 0, float im = 0): re(re), im(im){ile++;}
    ~Zespolona(){ile--;}
    Zespolona operator+ (Zespolona & z) {
        return Zespolona(re+z.re, im+z.im);
    }
    Zespolona operator+ (int liczba){
        return Zespolona(re+liczba, im);
    }
    Zespolona operator+= (Zespolona &z){
        return Zespolona(re+z.re, im+z.im);
    }
    bool operator== (Zespolona & z){
        return (re == z.re) && (im == z.im);
    }
    Zespolona operator! (){
        return Zespolona(re, -im);
    }
    friend Zespolona operator*(float scalar, const Zespolona &z) {
        return Zespolona(scalar * z.re, scalar * z.im);
    }
    friend Zespolona operator+(float scalar, const Zespolona &z) {
        return Zespolona(scalar + z.re, z.im);
    }
    friend ostream& operator<<(ostream& os, Zespolona &z);
    Zespolona operator/ (Zespolona & z){
        float mianownik = z.re * z.re + z.im * z.im;
        float r = (re * z.re + im * z.im) / mianownik;
        float i = (im * z.re - re * z.im) / mianownik;
        return Zespolona(r, i);
    }
    void wypisz(){
        if(re > 0 && im == 0){
            cout << re << endl;
        }
        if(re == 0 && im > 0){
            cout << im << "i" << endl;
        }
        if(re > 0 && im > 0){
            cout << re << "+" << im << "i" << endl;
        }
        if(re > 0 && im < 0){
            cout << re << im << "i" << endl;
        }
        if(re == 0 && im == 0){
            cout << 0 << endl;
        }
    }
    static void ileobiektow();

};

class Licznik{
public:
    static int ile;
    Licznik(){
        ile++;
    }
    ~Licznik(){
        ile--;
    }
};

ostream& operator<< (ostream& os, Zespolona &z)
{
    if(z.re > 0 && z.im == 0){
        os << z.re << endl;
    }
    if(z.re == 0 && z.im > 0){
        os << z.im << "i" << endl;
    }
    if(z.re > 0 && z.im > 0){
        os << z.re << "+" << z.im << "i" << endl;
    }
    if(z.re > 0 && z.im < 0){
        os << z.re << z.im << "i" << endl;
    }
    if(z.re == 0 && z.im == 0){
        os << 0 << endl;
    }
    return os;
}
int Zespolona::ile = 0;
int Licznik::ile = 0;

void Zespolona::ileobiektow(){
    if(Zespolona::ile >= 3){
        cout << "obecnie mamy duzo obiektow" << endl;
    }
    if(Zespolona::ile >= 1 && Zespolona::ile <=2){
        cout << "obecnie mamy nieduzo obiektow" << endl;
    }
    if(Zespolona::ile == 0){
        cout << "obecnie mamy brak obiektow" << endl;
    }
}

int main(){
    Zespolona z1(2,3), z2(1,4),z3; z3=(z1/z2)+z2;
    Zespolona::ileobiektow();
    cout << z3;
    z3=z1+4;
    if(z1==z2)
    z3+=z1;
    else
    z3=!z1;
    cout << z3;
    z3 = 2.5 * z1;
    cout << z3;
    z3 = 2 + z1;
    cout << z3;

    Licznik* l1 = new Licznik();
    cout << "licznik: " << Licznik::ile << endl;
    Licznik l2;
    cout << "licznik: " << Licznik::ile << endl;
    Licznik l3;
    cout << "licznik: " << Licznik::ile << endl;
    delete l1;
    cout << "licznik: " << Licznik::ile << endl;
    }
