#include "Template.hpp"



Template::Template()
{
    //ctor
}


template <typename T>
T Template::BemenetEllenorzes(std::string & uzenet)
{
    T ertek;
    while (true) {
        std::cout << uzenet;
        std::cin >> ertek;

        //ellenorzi a program hogy az olvasasi muvelet sikertelen-e
        if (std::cin.fail())
        {
            // toroljuk a hibaallapotot, hogy ne ragadjon be a program
            //segit elkerulni a vegtelen ciklust
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "HIBA! Kerlek helyes ertekeket adj meg" << std::endl;
        }
        else
        {

            //ha nem teszem ide a kiuritest, akkor nem tud tovabblepni a program helyes ertek megadasakor
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }
    return ertek;
}

template <>
int Template::BemenetEllenorzes(std::string & uzenet)
{
    int ertek;
    while (true) {
        std::cout << uzenet;
        std::cin >> ertek;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "HIBA! Kerlek a meghatarozott ertekekkel dolgozz\n" << std::endl;
        }
        else if (ertek < 0)
        {
            std::cout << "HIBA! Negativ szammal nem dolgozhatsz!\n" << std::endl;
            std::cin.clear();
        }
        else
        {

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }
    return ertek;
}

template <>
double Template::BemenetEllenorzes(std::string & uzenet)
{
    double ertek;
    while (true) {
        std::cout << uzenet;
        std::cin >> ertek;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "HIBA! Kerlek double ertekekkel dolgozz\n" << std::endl;
        }
        else if (ertek < 0)
        {
            std::cout << "HIBA! Negativ szammal nem dolgozhatsz!\n" << std::endl;
            std::cin.clear();
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }
    return ertek;
}

template <>
bool Template::BemenetEllenorzes(std::string & uzenet)
{
    std::string input;
    bool ertek;
    while (true) {
        std::cout << uzenet;
        std::cin >> input;
        if (input == "1")
        {
            ertek = true;
            break;
        }
        else if (input == "0")
        {
            ertek = false;
            break;
        }
        else
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "HIBA! Kerlek 0(Nem) vagy 1(Igen) opciokat valaszd." << std::endl;
        }
    }
    return ertek;
}



