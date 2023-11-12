#include "funkcje.hpp"

int main(int argc, char* argv[])
{

    while (true)
    {
        int wybor;
        std::cout << "--------------------------------------------------------------" << std::endl;
        std::cout << "Witaj! Dostepne filmy:" << std::endl;
        std::cout << "Wpisz 1 jesli chcesz opuscic program" << std::endl;
        std::cout << "Wpisz 2, aby zobaczyc repertuar" << std::endl;
        std::cout << "--------------------------------------------------------------" << std::endl;
        std::cin >> wybor;
        while(std::cin.fail()){
            std::cout<<"Wpisz cyfre 1 lub 2"<<std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin>>wybor;
        }

        // Wyjscie z programu
        if (wybor == 1)
        {
            break;
        }

        // Wyswietlenie repertuaru
        else if (wybor == 2)
        {
            int wyborf;
            Repertuar biblioteka;

            // Wczytuje, zapisuje i wypisuje filmy
            biblioteka.wczytaj();
            biblioteka.zapis();
            biblioteka.print();

            std::cout << "--------------------------------------------------------------" << std::endl;
            std::cout << "Wybierz Film jaki chcesz zobaczyc:" << std::endl;
            std::cout << "--------------------------------------------------------------" << std::endl;
            std::cin >> wyborf;
            while(std::cin.fail()){
            std::cout<<"Wpisz cyfre"<<std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin>>wyborf;
        }

            int biletwybor;
            int wyjscie = 0;

            std::cout << "Wybrales film: " << std::endl;
            Film f = biblioteka[wyborf - 1];

            // Wypisuje wybrany film oraz ilosc dostepnych miejsc
            f.wypisz();
            f.Miejsca(wyborf);

            // Rezerwuje bilety
            Bilet *wsk;
            int miejsca = 0;
            while (wyjscie == 0)
            {
                std::cin >> biletwybor;
                while(std::cin.fail()){
                std::cout<<"Wpisz cyfre od 1 do 3"<<std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin>>biletwybor;
        }
                switch (biletwybor)
                {
                case 1:
                {
                    wyjscie++;
                    
                    std::cout << "Wybrales bilet Przedni" << std::endl;
                    float x = biblioteka.cena(wyborf) * 0.75;
                    miejsca = f.miejscap;
                    wsk = new BiletPrzedni(x);
                    break;
                }
                case 2:
                {
                    wyjscie++;
                    std::cout << "Wybrales bilet Zwykly" << std::endl;
                    float x = biblioteka.cena(wyborf);
                    miejsca = f.miejscaz;
                    wsk = new BiletZwykly(x);
                    break;
                }
                case 3:
                {
                    wyjscie++;
                    std::cout << "Wybrales bilet Vip" << std::endl;
                    float x = biblioteka.cena(wyborf) * 1.5;
                    miejsca = f.miejscav;
                    wsk = new BiletVip(x);
                    break;
                }
                default:
                {
                    std::cout << "Wpisz poprawna cyfre od 1 - 3" << std::endl;
                    break;
                }
                }
            }
            wsk->przekaski();
            wsk->rezerwacja(f, miejsca);

            // Usuwanie dynamicznie zaalokowanej pamięci
            delete wsk;
        }
        // Ochrona przed niewłasciwym wpisywaniem
        else
        {
            std::cout << "Nieprawidlowy wybor. Sprobuj ponownie." << std::endl;
        }
    }
    std::cout << "Do zobaczenia!" << std::endl;
    return 0;
}