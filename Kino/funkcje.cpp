#include "funkcje.hpp"
// Konstruktory i Destruktor klasy Film
Film::Film(int nr, const std::string nazwa, int dzien, int miesiac, int rok, int cena)
{
    this->nr = nr;
    this->nazwa = nazwa;
    this->dzien = dzien;
    this->miesiac = miesiac;
    this->rok = rok;
    this->cena = cena;
    this->miejscap = 20;
    this->miejscaz = 30;
    this->miejscav = 10;
}

Film::Film()
{
    this->miejscap = 20;
    this->miejscaz = 30;
    this->miejscav = 10;
};

Film::~Film(){};

// Pobiera elementy prywatne klasy
int Film::getNr() const
{
    return nr;
}

std::string Film::getNazwa() const
{
    return nazwa;
}

int Film::getDzien() const
{
    return dzien;
}

int Film::getMiesiac() const
{
    return miesiac;
}

int Film::getRok() const
{
    return rok;
}
int Film::getCena() const
{
    return cena;
}

// Ustawia elementy prywatne klasy
void Film::SetNr(int nr)
{
    this->nr = nr;
}
void Film::SetNazwa(std::string nazwa)
{
    this->nazwa = nazwa;
}
void Film::SetCena(int cena)
{
    this->cena = cena;
}
void Film::SetDzien(int dzien)
{
    this->dzien = dzien;
}
void Film::SetMiesiac(int miesiac)
{
    this->miesiac = miesiac;
}
void Film::SetRok(int rok)
{
    this->rok = rok;
}

Repertuar::Repertuar()
{
    this->tab = new Film[10];
}

// Wczytuje filmy z pliku
void Repertuar::wczytaj()
{

    std::ifstream plik("filmy.txt");
    if (!plik.is_open())
    {
        std::cout << "Nie udalo sie otworzyc/utworzyc pliku wejsciowego" << std::endl;
        return;
    }
    Film f;
    std::string linijka;
    int nrl = 0;
    while (std::getline(plik, linijka))
    {
        switch (nrl % 6)
        {
        case 0:
            f.SetNr(stoi(linijka));
            break;
        case 1:
            f.SetNazwa(linijka);
            break;
        case 2:
            f.SetCena(stoi(linijka));
            break;
        case 3:
            f.SetDzien(stoi(linijka));
            break;
        case 4:
            f.SetMiesiac(stoi(linijka));
            break;
        case 5:
            f.SetRok(stoi(linijka));

            this->pb(f);

            break;
        default:
            std::cout << "Blad" << std::endl;
            break;
        }
        nrl++;
    }

    if (nrl % 6 != 0)
    {
        std::cout << "Ostatni film w pliku wejsciowym nie jest w pelni zapisany" << std::endl;
    }

    plik.close();
}

// Zapisuje Filmy do pliku
void Repertuar::zapis()
{
    std::ofstream plik("filmy.txt");
    if (!plik.is_open())
    {
        std::cout << "Nie udalo sie otworzyc/utworzyc pliku wyjsciowego" << std::endl;
        return;
    }

    for (unsigned int i = 0; i < rozmiar; i++)
    {
        plik << tab[i].getNr() << std::endl;
        plik << tab[i].getNazwa() << std::endl;
        plik << tab[i].getCena() << std::endl;
        plik << tab[i].getDzien() << std::endl;
        plik << tab[i].getMiesiac() << std::endl;
        plik << tab[i].getRok() << std::endl;
    }

    plik.close();
}

// Wypisuje Film
void Film::wypisz()
{
    std::cout << "Nr: " << this->nr << std::endl;
    std::cout << "Nazwa: " << this->nazwa << std::endl;
    std::cout << "Cena Przedni: " << cena * 0.75 << std::endl;
    std::cout << "Cena Zwykly: " << cena << std::endl;
    std::cout << "Cena Vip: " << cena * 1.5 << std::endl;
    std::cout << "Data emisji: " << this->dzien << "." << this->miesiac << "." << this->rok << std::endl;
    std::cout << std::endl;
}

// Powieksza tablice zawierajaca filmy
void Repertuar::powieksz()
{
    this->pojemnosc *= 2;

    Film *ntab = new Film[pojemnosc];

    for (unsigned int i = 0; i < rozmiar; i++)
        ntab[i] = tab[i];

    delete[] tab;
    tab = ntab;
}

// Wsadza film do tablicy
void Repertuar::pb(Film a)
{
    if (pojemnosc <= rozmiar)
        this->powieksz();

    tab[this->rozmiar++] = a;
}

// Pozwala na używanie operatora []
Film &Repertuar::operator[](unsigned int index)
{
    return tab[index];
}
// Pobiera cenę
float Repertuar::cena(int wybor)
{
    return tab[wybor - 1].getCena();
}

// Wypisuje wszystkie filmy
void Repertuar::print()
{
    for (unsigned int i = 0; i < this->rozmiar; i++)
    {
        tab[i].wypisz();
    }
    std::cout << std::endl;
}

// Konstruktor i destruktor BiletPrzedni
BiletPrzedni::BiletPrzedni(float cenap)
{
    this->cena = cenap;
}
BiletPrzedni::~BiletPrzedni(){};

// Konstruktor i destruktor BiletZwykly
BiletZwykly::BiletZwykly(float cenaz)
{
    this->cena = cenaz;
}
BiletZwykly::~BiletZwykly(){};

// Konstruktor i destruktor BiletVip
BiletVip::BiletVip(float cenav)
{
    this->cena = cenav;
}
BiletVip::~BiletVip(){};

// Wczytuje ilosc zajętych miejsc oraz wypisuje ilosc wolnych miejsc na dany film
void Film::Miejsca(int wyborf)
{
    std::ifstream plik1("Bprzedni.txt");
    if (!plik1)
    {
        std::cout << "Nie można otworzyć pliku." << std::endl;
    }
    std::string linia1;
    int iloscWierszy1 = 0;
    while (getline(plik1, linia1))
    {
        std::istringstream stream(linia1);
        std::string pierwszeSlowo;
        if (stream >> pierwszeSlowo)
        {
            if (wyborf == stoi(pierwszeSlowo))
            {
                iloscWierszy1++;
            }
        }
    }
    miejscap = miejscap - iloscWierszy1;
    if(miejscap < 1){
        std::cout << "Nie można otworzyć pliku." << std::endl;
    }
    plik1.close();

    std::ifstream plik2("Bzwykly.txt");
    if (!plik2)
    {
        std::cout << "Nie można otworzyć pliku." << std::endl;
    }
    std::string linia2;
    int iloscWierszy2 = 0;
    while (getline(plik2, linia2))
    {
        std::istringstream stream(linia2);
        std::string pierwszeSlowo;
        if (stream >> pierwszeSlowo)
        {
            if (wyborf == stoi(pierwszeSlowo))
            {
                iloscWierszy2++;
            }
        }
    }
    miejscaz = miejscaz - iloscWierszy2;
    plik2.close();

    std::ifstream plik3("Bvip.txt");
    if (!plik3)
    {
        std::cout << "Nie można otworzyć pliku." << std::endl;
    }
    std::string linia3;
    int iloscWierszy3 = 0;
    while (getline(plik3, linia3))
    {
        std::istringstream stream(linia3);
        std::string pierwszeSlowo;
        if (stream >> pierwszeSlowo)
        {
            if (wyborf == stoi(pierwszeSlowo))
            {
                iloscWierszy3++;
            }
        }
    }
    miejscav = miejscav - iloscWierszy3;
    plik3.close();

    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << "Jaki bilet chcialbys zarezerwowac? " << std::endl;
    std::cout << "1. Bilet Przedni (zostało " << miejscap << " miejsc) - Najtanszy (bez przekasek) " << std::endl;
    std::cout << "2. Bilet Zwykly (zostało " << miejscaz << " miejsc) - Przecietny (popcorn/nachosy)" << std::endl;
    std::cout << "3. Bilet Vip (zostało " << miejscav << " miejsc) - Najdrozszy (pizza/sushi/wino)" << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;
}

// Wybór przekąsek BiletPrzedni (Polimorfizm)
void BiletPrzedni::przekaski()
{
    std::cout << "Niestety ten bilet nie pozwala na dobranie przekasek, zapraszamy do sklepiku" << std::endl;
}

// Rezerwuje BiletPrzedni (Polimorfizm)
void BiletPrzedni::rezerwacja(Film seans, int miejsca)
{
    int ilosc = 1;
    std::cout << "Ile biletow chcesz zakupic" << std::endl;
    std::cin >> ilosc;
    if(ilosc > miejsca){
        std::cout << "Brak tylu wolnych miejsc" << std::endl;
    }
    else{
    std::cout << "Bilety beda kosztowac: " << cena * ilosc << std::endl;

    std::ofstream plik("Bprzedni.txt", std::ios::app);
    if (!plik.is_open())
    {
        std::cout << "Nie udalo sie otworzyc/utworzyc pliku wyjsciowego" << std::endl;
        return;
    }
    for (int i = ilosc; i > 0; i--)
    {
        plik << seans.getNr() << " " << seans.getNazwa() << std::endl;
    }

    plik.close();}
}

// Wybór przekąsek BiletZwykly (Polimorfizm)
void BiletZwykly::przekaski()
{
    int wyborz;
    int wyjsciez = 0;
    std::cout << "Jaka przekaske chcialbys dobrac: " << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << "1. Popcorn" << std::endl;
    std::cout << "2. Nachosy" << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;
    while (wyjsciez == 0)
    {
        std::cin >> wyborz;
        switch (wyborz)
        {
        case 1:
        {
            wyjsciez++;
            std::cout << "Wybrales Popcorn" << std::endl;
            break;
        }
        case 2:
        {
            wyjsciez++;
            std::cout << "Wybrales Nachosy" << std::endl;
            break;
        }
        default:
        {
            std::cout << "Wpisz poprawną cyfre od 1 - 2" << std::endl;
            break;
        }
        }
    }
}

// Rezerwuje BiletZwykly (Polimorfizm)
void BiletZwykly::rezerwacja(Film seans, int miejsca)
{
    unsigned int ilosc = 1;
    std::cout << "Ile biletow chcesz zakupic" << std::endl;
    std::cin >> ilosc;
    if(ilosc > miejsca){
        std::cout << "Brak tylu wolnych miejsc" << std::endl;
    }
    else{
    std::cout << "Bilety beda kosztowac: " << cena * ilosc << std::endl;

    std::ofstream plik("Bzwykly.txt", std::ios::app);
    if (!plik.is_open())
    {
        std::cout << "Nie udalo sie otworzyc/utworzyc pliku wyjsciowego" << std::endl;
        return;
    }
    for (int i = ilosc; i > 0; i--)
    {
        plik << seans.getNr() << " " << seans.getNazwa() << std::endl;
    }

    plik.close();}
}

// Wybór przekąsek BiletVip (Polimorfizm)
void BiletVip::przekaski()
{
    int wyborv;
    int wyjsciev = 0;
    std::cout << "Jaka przekaske chciabys dobrac: " << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << "1. Wino + Sushi" << std::endl;
    std::cout << "2. Pizza + Cola" << std::endl;
    std::cout << "3. Burger + Fanta" << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;
    while (wyjsciev == 0)
    {
        std::cin >> wyborv;
        switch (wyborv)
        {
        case 1:
        {
            wyjsciev++;
            std::cout << " Wybrales Wino + Sushi" << std::endl;
            break;
        }
        case 2:
        {
            wyjsciev++;
            std::cout << "Wybrales Pizza + Cola" << std::endl;
            break;
        }
        case 3:
        {
            wyjsciev++;
            std::cout << "Wybrales Burger + Fanta" << std::endl;
            break;
        }
        default:
        {
            std::cout << "Wpisz poprawną cyfre od 1 - 3" << std::endl;
            break;
        }
        }
    }
}

// Rezerwuje BiletVip (Polimorfizm)
void BiletVip::rezerwacja(Film seans, int miejsca)
{
    int ilosc = 1;
    std::cout << "Ile biletow chcesz zakupic" << std::endl;
    std::cin >> ilosc;
    if(ilosc > miejsca){
        std::cout << "Brak tylu wolnych miejsc" << std::endl;
    }
    else{
    std::cout << "Bilety beda kosztowac: " << cena * ilosc << std::endl;

    std::ofstream plik("Bvip.txt", std::ios::app);
    if (!plik.is_open())
    {
        std::cout << "Nie udalo sie otworzyc/utworzyc pliku wyjsciowego" << std::endl;
        return;
    }
    for (int i = ilosc; i > 0; i--)
    {
        plik << seans.getNr() << " " << seans.getNazwa() << std::endl;
    }
    plik.close();}
}