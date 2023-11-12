#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <string>

// Klasa Film
class Film
{
private:
  int nr;
  std::string nazwa;
  int dzien;
  int miesiac;
  int rok;
  int cena;

public:
  int miejscap;
  int miejscaz;
  int miejscav;

  // Konstruktory i Destruktor
  Film(int nr, std::string nazwa, int dzien, int miesiac, int rok, int cena);
  Film();
  ~Film();
  
  // Pobieranie elementów
  int getNr() const;
  std::string getNazwa() const;
  int getDzien() const;
  int getMiesiac() const;
  int getRok() const;
  int getCena() const;

  // Ustawianie elementów
  void SetNr(int nr);
  void SetNazwa(std::string nazwa);
  void SetCena(int cena);
  void SetDzien(int dzien);
  void SetMiesiac(int miesiac);
  void SetRok(int rok);

  // Wypisuje film
  void wypisz();

  // Działania na miejscach
  void Miejsca(int wyborf);
};

// Klasa Repertuar zawierająca filmy
class Repertuar
{

public:
  Film *tab;
  unsigned int rozmiar = 0;
  unsigned int pojemnosc = 10;
  Repertuar();
 
  // Zapisuje i wczytuje Filmy
  void zapis();
  void wczytaj();

  // Działania na cenie seansu
  float cena(int wybor);

  // Działania na tablicy
  void powieksz();
  void pb(Film a);
  void print();
  Film &operator[](unsigned int index);
};

// Klasa abstrakcyjna Bilet
class Bilet
{
protected:
  float cena;

public:
  virtual ~Bilet() {}
  // Metody virtalne
  virtual void przekaski() = 0;
  virtual void rezerwacja(Film seans, int miejsca) = 0;
};

// Klasa BiletPrzedni dziedziczy po klasie abstarkcyjnej Bilet
class BiletPrzedni : public Bilet
{
public:
  // Konstruktor i Destruktor
  BiletPrzedni(float cenap);
  ~BiletPrzedni();

  // Dzialania na przekaskach
  virtual void przekaski();

  // Dzialania na rezerwacjach
  virtual void rezerwacja(Film seans, int miejsca);
};

// Klasa BiletZwykly dziedziczy po klasie abstarkcyjnej Bilet
class BiletZwykly : public Bilet
{
public:
  // Konstruktor i Destruktor
  BiletZwykly(float cenaz);
  ~BiletZwykly();

  // Dzialania na przekaskach
  virtual void przekaski();

  // Dzialania na rezerwacjach
  virtual void rezerwacja(Film seans, int miejsca);
};

// Klasa BiletVip dziedziczy po klasie abstarkcyjnej Bilet
class BiletVip : public Bilet
{
public:
  // Konstruktor i Destruktor
  BiletVip(float cenav);
  ~BiletVip();

  // Dzialania na przekaskach
  virtual void przekaski();

  // Dzialania na rezerwacjach
  virtual void rezerwacja(Film seans, int miejsca);
};