#include <iostream>
#include <vector>

using namespace std;

const int hossz = 9;

// tárolja a bábukat, kirajzolja a táblát.
class tabla {
    char helyek[hossz];
public:
    tabla();
    void valaszthato();
    void tablakiir ();
    bool lepes(int hova, char mit);
    char hely(int melyik);
};

tabla::tabla(){
    for (int i = 0; i < 9; i++){
        helyek[i] = ' ';
    }
}

void tabla::valaszthato () {
    for (int i = 9; i > 0; i-= 3){
            cout << "-------" << endl;
            cout << "|" << i-2 << "|" << i-1 << "|" << i << "|" << endl;
        }
        cout << "-------" << endl;
}

void tabla::tablakiir(){
    for (int i = 8; i > 0; i-= 3){
        cout << "-------" << endl;
        cout << "|" << helyek[i-2] << "|" << helyek [i-1] << "|" << helyek [i] << "|" << endl;
    }
    cout << "-------" << endl;
}

bool tabla::lepes(int hova, char mit) {
    if (hova < 0 || hova > 8) return false;
    if (helyek[hova] != ' ')
        return false;
    helyek[hova] = mit;
    return true;
}

char tabla::hely(int melyik) {
    if (melyik < 0 || melyik > 8) return ' ';
    return helyek[melyik];
}

// tárolja a két bábu jelét
struct babuk {
//public:
    char jatekos1;
    char jatekos2;
    babuk();

};

babuk::babuk () {
    jatekos1 = 'X';
    jatekos2 = 'O';
}

// lebonyolítja a játékot, betartatja a szabályokat.
class jatek {
    int hova;
    bool nyert;
    tabla t; // amikor létrejön a jatek osztály egy objektuma, akkor létrejön a t is. (jelen esetben paraméter nélküli konstruktor lefuttatásával)
    babuk bk;
    int kovi;
public:
    jatek();
    void lepes();
    bool nyeres ();
    void lefolytat();
};

jatek::jatek()/* : t(ydkfmsmdkf, dfsfd)*/ {
    kovi = 0;
}

void jatek::lepes (){
    int hova;
    bool jolepes;
    do {
        cout << "Adja meg hova szeretne lepni" << endl;
        cin >> hova;
        if (kovi % 2 == 0){
            jolepes = t.lepes(hova-1, bk.jatekos1);
    //        helyek[hova-1] = bk.jatekos1;
        }else{
            jolepes = t.lepes(hova-1, bk.jatekos2);
    //        helyek[hova-1] = bk.jatekos2;
        }
        if (!jolepes) {
            cout << "Huba van!" << endl;
        }
    } while (!jolepes);
    kovi++;
}

bool jatek::nyeres () {
    t.hely(4);
    if ((t.hely(0) == bk.jatekos1 && t.hely(1) == bk.jatekos1 && t.hely(2) == bk.jatekos1) ||
        (t.hely(0) == bk.jatekos2 && t.hely(1) == bk.jatekos2 && t.hely(2) == bk.jatekos2))
        return true;
    if (t.hely(3) == bk.jatekos1 && t.hely(4) == bk.jatekos1 && t.hely(5) == bk.jatekos1 ||
        t.hely(3) == bk.jatekos2 && t.hely(4) == bk.jatekos2 && t.hely(5) == bk.jatekos2)
        return true;
    if (t.hely(6) == bk.jatekos1 && t.hely(7) == bk.jatekos1 && t.hely(8) == bk.jatekos1 ||
        t.hely(6) == bk.jatekos2 && t.hely(7) == bk.jatekos2 && t.hely(8) == bk.jatekos2)
        return true;
    if (t.hely(1) == bk.jatekos1 && t.hely(4) == bk.jatekos1 && t.hely(7) == bk.jatekos1 ||
        t.hely(1) == bk.jatekos2 && t.hely(4) == bk.jatekos2 && t.hely(7) == bk.jatekos2)
        return true;
    if (t.hely(0) == bk.jatekos1 && t.hely(3) == bk.jatekos1 && t.hely(6) == bk.jatekos1 ||
        t.hely(0) == bk.jatekos2 && t.hely(3) == bk.jatekos2 && t.hely(6) == bk.jatekos2)
        return true;
    if (t.hely(2) == bk.jatekos1 && t.hely(5) == bk.jatekos1 && t.hely(8) == bk.jatekos1 ||
        t.hely(2) == bk.jatekos2 && t.hely(5) == bk.jatekos2 && t.hely(8) == bk.jatekos2)
        return true;
    if (t.hely(0) == bk.jatekos1 && t.hely(4) == bk.jatekos1 && t.hely(8) == bk.jatekos1 ||
        t.hely(0) == bk.jatekos2 && t.hely(4) == bk.jatekos2 && t.hely(8) == bk.jatekos2)
        return true;
    if (t.hely(6) == bk.jatekos1 && t.hely(4) == bk.jatekos1 && t.hely(2) == bk.jatekos1 ||
        t.hely(6) == bk.jatekos2 && t.hely(4) == bk.jatekos2 && t.hely(2) == bk.jatekos2)
        return true;
    return false;
}

//ő a vezérlő
void jatek::lefolytat (){

    cout << "ket tablat lat ez elson a szabad lehetosegek helyet szammal jeloltuk" << endl << "a masodikon azt lethatja hogy all jelenleg a palya" << endl << "adjon meg egy szamot hova szeretne lepni" << endl;
    do {
        t.valaszthato();
        t.tablakiir();
        lepes();
        if (kovi == 9){
        cout << "a jatek kimenetele dontetlen lett!" << endl;
        t.tablakiir();
        return;
        }
    }while (nyeres() == false);
    cout << "A jateknak vege a nyero allas: " << endl;
    t.tablakiir();
}

int main () {
    jatek j;
    j.lefolytat();
    return 0;
}
