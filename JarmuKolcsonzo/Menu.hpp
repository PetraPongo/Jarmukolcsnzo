#pragma once
#define MENU_HPP
#include "Autopark.hpp"
#include "Template.hpp"
#include <iostream>
#include <limits> //hibakezeleshez kellett


class Menu
{
    public:
        Menu();
        void exec();
        void JarmuFelvetele();
        void JarmuListazasa();
        void JarmuKeresese();
        void JarmuMuveletek();
        void JarmuElerhetoSzuro();
        void JarmuKategoriakSzuro();
        void JarmuKoltsegtartomanySzuro();
        void FajlbaMentes();
        void FajlbolBetoltes();

        ~Menu();
    private:
        //letrehozom az autopark peldanyat
        Autopark autopark;
};
