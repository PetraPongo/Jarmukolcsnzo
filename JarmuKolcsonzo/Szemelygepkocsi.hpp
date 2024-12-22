#pragma once
#define SZEMELYGEPKOCSI_HPP

#include <Jarmu.hpp>
#include <iostream>
#include <string>

using namespace std;

class Szemelygepkocsi : public Jarmu
{
    public:
        Szemelygepkocsi(string rendszam, int napi_ar, int km_ar, bool elerheto);
        int Berleti_dij();
        int Alap_ar();
        string getTipus();

        ~Szemelygepkocsi();

        //osztalyon kivuli fuggvenyek hozzaferhetnek igy a privat tagokhoz
        //egyedi console-ra kiiratast tesz lehetove
        friend ostream& operator<<(ostream &os, Szemelygepkocsi &a);
};

