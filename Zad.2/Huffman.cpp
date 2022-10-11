#include <iostream>
#include <string>
#include <list>

using namespace std;

struct wierzcholek {
    char znak;
    int czestosc;
    wierzcholek* lewy = nullptr;
    wierzcholek* prawy = nullptr;
};

struct kod {
    char znak;
    string slowo_kodowe;
};

int zlicz_znaki(string wiadomosc, int* tablica_zliczen) {
    for (int i = 0; i <= 255; ++i) {
        tablica_zliczen[i] = 0;
    }
    for (int i = 0; i < wiadomosc.length(); ++i) {
        ++tablica_zliczen[wiadomosc[i]];
    }
    int liczba = 0;
    for (int i = 0; i <= 255; ++i) {
        if (tablica_zliczen[i] > 0) {
            ++liczba;
        }
    }
    return liczba;
}

bool funkcja_porownujaca(wierzcholek* w1, wierzcholek* w2) {
    return w1->czestosc > w2->czestosc;
}

void utworz_ksiazke_kodowa(wierzcholek* drzewo_kodowe, kod* ksiazka_kodowa, string dotychczasowy_kod = "") {
    static int i = 0;
    if (drzewo_kodowe->lewy == nullptr && drzewo_kodowe->prawy == nullptr) {
        ksiazka_kodowa[i].znak = drzewo_kodowe->znak;
        ksiazka_kodowa[i].slowo_kodowe = dotychczasowy_kod;
        ++i;
    }
    else {
        utworz_ksiazke_kodowa(drzewo_kodowe->lewy, ksiazka_kodowa, dotychczasowy_kod + "0");
        utworz_ksiazke_kodowa(drzewo_kodowe->prawy, ksiazka_kodowa, dotychczasowy_kod + "1");
    }
}

string znajdz_slowo_kodowe(char znak, kod* ksiazka_kodowa, int dlugosc_ksiazki_kodowej) {
    for (int i = 0; i < dlugosc_ksiazki_kodowej; ++i) {
        if (ksiazka_kodowa[i].znak == znak) {
            return ksiazka_kodowa[i].slowo_kodowe;
        }
    }
}

string zakoduj_wiadomosc(string wiadomosc, kod* ksiazka_kodowa, int dlugosc_ksiazki_kodowej) {
    string zakodowana_wiadomosc = "";
    for (int i = 0; i < wiadomosc.length(); ++i) {
        zakodowana_wiadomosc += znajdz_slowo_kodowe(wiadomosc[i], ksiazka_kodowa, dlugosc_ksiazki_kodowej);
    }
    return zakodowana_wiadomosc;
}

void zwolnij_pamiec(wierzcholek* drzewo_kodowe) {
    if (drzewo_kodowe->lewy != nullptr && drzewo_kodowe->prawy != nullptr) {
        zwolnij_pamiec(drzewo_kodowe->lewy);
        zwolnij_pamiec(drzewo_kodowe->prawy);
    }
    delete drzewo_kodowe;
}

string odkodujWiadomosc(string zakodowanaWiadomosc, wierzcholek* drzewo_kodowe) {
    string odkodowanaWiadomosc = "";
    wierzcholek* aktualny_wierzcholek = drzewo_kodowe;
    for (int i = 0; i < zakodowanaWiadomosc.length(); ++i) {
        if (aktualny_wierzcholek->lewy == nullptr && aktualny_wierzcholek->prawy == nullptr) {
            odkodowanaWiadomosc += aktualny_wierzcholek->znak;
            aktualny_wierzcholek = drzewo_kodowe;
        }
        if (zakodowanaWiadomosc[i] == '0') {
            aktualny_wierzcholek = aktualny_wierzcholek->lewy;
        }
        else {
            aktualny_wierzcholek = aktualny_wierzcholek->prawy;
        }
    }
    odkodowanaWiadomosc += aktualny_wierzcholek->znak;
    return odkodowanaWiadomosc;
}

int main() {
    int tablica_zliczen[256];
    string wiadomosc;
    
    cout<<"Podaj ciag znakow do zakodowania: ";
    cin>>wiadomosc;

    int liczba_znakow = zlicz_znaki(wiadomosc, tablica_zliczen);

    cout << endl;
    for (int i = 0; i < wiadomosc.length(); ++i) {
        char znak = wiadomosc[i];
        cout << znak << ": " << tablica_zliczen[znak] << endl;
    }

    list<wierzcholek*> lista_wierzcholkow;
    int j = 0;
    for (int i = 0; i <= 255; ++i) {
        if (tablica_zliczen[i] > 0) {
            lista_wierzcholkow.push_back(new wierzcholek());
            lista_wierzcholkow.back()->znak = i;
            lista_wierzcholkow.back()->czestosc = tablica_zliczen[i];
            ++j;
            if (j == liczba_znakow) {
                break;
            }
        }
    }

    lista_wierzcholkow.sort(funkcja_porownujaca);

    while (lista_wierzcholkow.size() > 1) {
       
        wierzcholek* w1 = lista_wierzcholkow.back();
        lista_wierzcholkow.pop_back();
        wierzcholek* w2 = lista_wierzcholkow.back();
        lista_wierzcholkow.pop_back();

        
        wierzcholek* w3 = new wierzcholek();
        w3->czestosc = w1->czestosc + w2->czestosc;
        w3->lewy = w1;
        w3->prawy = w2;

    
        lista_wierzcholkow.push_back(w3);
        lista_wierzcholkow.sort(funkcja_porownujaca);
    }

   
    wierzcholek* drzewo_kodowe = lista_wierzcholkow.back();

    
    kod* ksiazka_kodowa = new kod[liczba_znakow];
    utworz_ksiazke_kodowa(drzewo_kodowe, ksiazka_kodowa);


    cout << "--------" << endl;
    for (int i = 0; i < liczba_znakow; ++i) {
        cout << ksiazka_kodowa[i].znak << ": " << ksiazka_kodowa[i].slowo_kodowe << endl;
    }

    string zakodowana_wiadomosc = zakoduj_wiadomosc(wiadomosc, ksiazka_kodowa, liczba_znakow);
    
 cout << "--------" << endl;
 
    
    cout << "Zakodowana wiadomosc:" << endl;
    cout << zakodowana_wiadomosc << endl;

    
    string odkodowana_wiadomosc = odkodujWiadomosc(zakodowana_wiadomosc, drzewo_kodowe);
    
    zwolnij_pamiec(drzewo_kodowe);
    delete[] ksiazka_kodowa;

    return 0;
}
