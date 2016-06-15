#include<iostream>
#include <stdlib.h>
#include <ctime>
#include <string>
using namespace std;

int const meret = 9;

int veletlen (){
    int a = rand () % 10;
    return a;
}

void palya (int n0, int n1, int n2 ,int n3, int n4, int n5,int n6, int n7, int n8){
    cout << endl;
    cout << " ------- " << endl;
    cout << " " << "|" << n0 << "|" << n1 << "|" << n2 << "|" << endl;
    cout << " ------- " << endl;
    cout << " " << "|" << n3 << "|" << n4 << "|" << n5 << "|" << endl;
    cout << " ------- " << endl;
    cout << " " << "|" << n6 << "|" << n7 << "|" << n8 << "|" << endl;
    cout << " ------- " << endl;
    cout << endl;
}

int ertekeles (int eredmeny[]){
    int osszesitett = 0;
    if (eredmeny [0] == eredmeny [1] && eredmeny [0] == eredmeny [2]){
    cout << "On nyert a felso sorban" << endl;
    osszesitett += (eredmeny[0]+1);
    }
    if (eredmeny [3] == eredmeny [4] && eredmeny [3] == eredmeny [5]){
    cout << "On nyert a kozepso sorban" << endl;
    osszesitett += (eredmeny[3]+1);
    }
    if (eredmeny [6] == eredmeny [7] && eredmeny [6] == eredmeny [8]){
    cout << "On nyert az also sorban" << endl;
    osszesitett += (eredmeny[6]+1);
    }
    if (eredmeny [0] == eredmeny [3] && eredmeny [0] == eredmeny [6]){
    cout << "On nyert az elso oszlopban" << endl;
    osszesitett += (eredmeny[0]+1);
    }
    if (eredmeny [1] == eredmeny [4] && eredmeny [1] == eredmeny [7]){
    cout << "On nyert a masodik oszlopban" << endl;
    osszesitett += (eredmeny[1]+1);
    }
    if (eredmeny [2] == eredmeny [5] && eredmeny [2] == eredmeny [8]){
    cout << "On nyert a harmadik oszlopban" << endl;
    osszesitett += (eredmeny[2]+1);
    }
    if (eredmeny [0] == eredmeny [4] && eredmeny [0] == eredmeny [8]){
    cout << "On atlosan nyert" << endl;
    osszesitett += (eredmeny[0]+1);
    }
    if (eredmeny [2] == eredmeny [4] && eredmeny [2] == eredmeny [6]){
    cout << "On atlosan nyert" << endl;
    osszesitett += (eredmeny[2]+1);
    }
    if (osszesitett == 0){
    cout << "Ebben a korben on vesztett" << endl;
    }
    return osszesitett;
}

int sorsolas (){
    cout << "Ez a jatek egy sorsolassal kezdodik" << endl;
    cout << "Azt sorsoljuk ki, melyik kategoriaba tartozol" << endl;
    cout << "6 kulombozo kategoria van, kategoriankent egyre tobb tokevel indulsz" << endl;
    cout << "A sorsolas a jatek elejen tortenik" << endl;
    cout << "Ahogy valtozik a toked ugy valtozik a kategoriad is" << endl;
    cout << "A cel, hogy elerd az 5.000.000.$" << endl;
    cout << "Hogyha elerted, akkor a kaszino tulaj csodbe ment es tied lett a kaszino" << endl;
    cout << "Mindezt felkaru rablo segitsegevel teheted meg." << endl;
    cout << "jo jatekot kivanok, lassuk a sorsolast" << endl;
    int a;
    do{
    a = rand () % 7;
    } while (a == 0);
    //kocka animacio
    cout << "EEEEsss az on kategoriaja : " << a << endl;
    return a;
}

int rablo (int t_tarcsa1[],int t_tarcsa2[],int t_tarcsa3 []){
    int p_eredmeny [meret];
    for (int i = 0;i < 9;i++){
        p_eredmeny [i] = veletlen();
    }
    palya (t_tarcsa1[p_eredmeny [0]],t_tarcsa2[p_eredmeny [1]],t_tarcsa3[p_eredmeny [2]],t_tarcsa1[p_eredmeny [3]],t_tarcsa2[p_eredmeny [4]],t_tarcsa3[p_eredmeny [5]],t_tarcsa1[p_eredmeny [6]],t_tarcsa2[p_eredmeny [7]],t_tarcsa3[p_eredmeny [8]]);
    int vegeredmeny = ertekeles(p_eredmeny);
    return vegeredmeny;
}

int kezdes (int foszam){
    cout << endl;
   if (foszam == 1){
   cout << "Az on foglalkozasa: keregeto" << endl;
   cout << "jelenlegi tokeje : 500$" << endl;
   return 500;
   }
   if (foszam == 2){
   cout << "Az on foglalkozasa: utcasepro" << endl;
   cout << "jelenlegi tokeje : 3000$" << endl;
   return 3000;
   }
   if (foszam == 3){
   cout << "Az on foglalkozasa: pizzafutar" << endl;
   cout << "jelenlegi tokeje : 6000$" << endl;
   return 6000;
   }
   if (foszam == 4){
   cout << "Az on foglalkozasa: bortonigazgato" << endl;
   cout << "jelenlegi tokeje : 10000$" << endl;
   return 10000;
   }
   if (foszam == 5){
   cout << "Az on foglalkozasa: plasztikaisebesz" << endl;
   cout << "jelenlegi tokeje : 14000$" << endl;
   return 14000;
   }
   if (foszam == 6){
   cout << "Az on foglalkozasa: politikus" << endl;
   cout << "jelenlegi tokeje : 20000$" << endl;
   return 20000;
   }
}

int tetkivalasztas (){
    cout << endl;
    cout << "Adja meg mekkora tettel akar jatszani" << endl;
    cout << "1-8 ig nyomhat egy szamot a kivalasztashoz.(utana enter)" << endl;
    cout << "1 = 50, 2 = 100, 3 = 200, 4 = 500, 5 = 1000, 6 = 2000, 7 = 5000, 8 = 10000." << endl;
    int a = 0;
    for (int i = 0; i < 10;){
        cin >> a;
        if (a>0 && a<9){
        i = 10;
        }else{
        cout << "A megadott szam nem 1es 8 kozott van" << endl;
        }
    }
    if (a == 1){
    a = 50;
    }else if (a == 2){
    a = 100;
    }else if (a == 3){
    a = 200;
    }else if (a == 4){
    a = 500;
    }else if (a == 5){
    a = 1000;
    }else if (a == 6){
    a = 2000;
    }else if (a == 7){
    a = 5000;
    }else{
    a = 10000;
    }
    return a;
}

int kiegyenlites (int penz){
    if (penz > 5000000){
        penz = 5000000;
    }
    return penz;
}

struct targy {
    string nev;
    string valasztas;
    string tkiir;
    string fkiir;
    bool van;
    int ertek;
    int karrier;
    char betujel;
};

int main (){
    srand(time(NULL));
    int foszam = sorsolas();
    int penz = kezdes(foszam);
    int tet = tetkivalasztas();
    int t_tarcsa1 [] = {0,1,2,3,4,5,6,7,8,9};
    int t_tarcsa2 [] = {0,1,2,3,4,5,6,7,8,9};
    int t_tarcsa3 [] = {0,1,2,3,4,5,6,7,8,9};
    int vegeredmeny;
    char kar;
    int nyeremeny;
    targy tabla[6][8] ={
                        {
                            {"Wc","Nyomd meg a w a wc kitakaritasahoz","A kaszino tulaj megengedi hogy keress egy kis plusz penzt wc takaritassal.","Mar tiszta a wc.",true,100,1,'w'}, // [0][0]
                            {"Wc","Nyomd meg a w a wc kitakaritasahoz","A kaszino tulaj megengedi hogy keress egy kis plusz penzt wc takaritassal.","Mar tiszta a wc.",true,100,1,'w'}  // [0][1]
                        },
                        {
                           {"Wc","Nyomd meg a w a wc kitakaritasahoz","A kaszino tulaj megengedi hogy keress egy kis plusz penzt wc takaritassal.","Mar tiszta a wc.",true,150,2,'w'} // [1][0]
                        }
                      };
    bool vege = false;
    int lesz = 0;
    bool marha = false;
    int vpenz = 20000;
    int vpenzsz = 0;
    bool maffialehuz = false;
    char eladas;
    do{
        do{
            cout << "nyomjon egy szamot es egy entert a kar meghuzasahoz" << endl;
            cout << "ha at akarja allitani a tetet nyomja megy a t billentyut.(utana enter)" << endl;
            cin >> kar;
            if (kar == 't'){
                tet = tetkivalasztas();
            }
            if (tet > penz){
                cout << "Tul magas a tet, nincs eleg penze." << endl;
            }else{
                penz -= tet;
                vegeredmeny = rablo(t_tarcsa1,t_tarcsa2,t_tarcsa3);
                nyeremeny = (vegeredmeny*2*tet);
                cout << "Az on nyeremenye: " << nyeremeny << endl;
                penz += nyeremeny;
                cout << "Jelenlegi tet: " << tet << endl;
                cout << "Jelenlegi penze: " << penz << "$" << endl;
                /*if (maffia == false){
                    vpenzsz++;
                    if (penz > vpenz){
                        if (vpenzsz == 20){
                            cout << "Nem volt bolcs dolog felvenni a maffiatol." << endl << "Most eljottek beszedni a vedelmi penzt." << endl;
                            penz -= vpenz;
                            vpenzsz = 0;
                        }
                    }else if (maffialehuz == false){
                        cout << "Nincs eleg penzed fizetni a maffianak. Eltorik a jobb karodat es kiegyenlitettenek veszik a szamlat." << endl;
                        cout << "Ha eddig volt hazad mostmar nincs." << endl;
                        if (haz == true){
                        haz = false;
                        lesz +=1;
                        }
                        maffialehuz = true;
                        maffia = NULL;
                    }
                }*/
            }
            penz = kiegyenlites(penz);
        }while (penz != 0 && penz != 5000000);
        if (penz == 0){
            cout << "Elfogyott a penze, a kovetkezo lehetosegek kozul valaszthat: " << endl;
            cout << tabla [foszam][0].valasztas << endl;
            /*cout <<  << endl;
            cout <<  << endl;
            cout <<  << endl;
            cout <<  << endl;
            cout <<  << endl;*/
            do{
                    do{
                    marha = false;
                    cin >> eladas;
                    if (eladas != 'w' && eladas != 'o' && eladas != 'a' && eladas != 'h' && eladas != 'm'){
                        cout << "Rossz betut adott meg a kovetkezo betuk kozul valaszthat : w,o,a,h,m." << endl;
                    }
                }while (eladas != 'w' && eladas != 'o' && eladas != 'a' && eladas != 'h' && eladas != 'm');

                if (lesz == 5 && penz == 0){
                    vege = true;
                }
                }while (marha != false);
                cout << "Jelenlegi penzed: " << penz << endl;
                cout << "tet: " << tet << endl;
        }
    }while (penz != 5000000 && vege != true);
    if (vege == true){
        cout << "Eljatszottad minden vagyonodat, minden ertekedet, barhonnan kezdted mostmar koldus vagy :(" << endl;
    }
    if (penz == 5000000){
        cout << "Gratulalunk kifosztottad a kszino tulajdonosat tied lett a kaszino." << endl;
        cout << "De mivel a tulaj is benne volt a maffiaba igy most 2 kes all ki a hatadbol. :(" << endl;
    }
    char n;
    cout << "nyomjon meg egy e betut es egy entert ahhoz hogy befejezze a jatekot." << endl;
    do{
        if (n == 'e'){
        cin >> n;
        return 0;
        }
    }while (n != 'e');
}
