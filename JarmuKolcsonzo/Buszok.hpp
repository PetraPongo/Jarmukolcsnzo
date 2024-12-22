#pragma once
#define BUSZOK_HPP

#include <Jarmu.hpp>
#include <iostream>
#include <string>

class Buszok : public Jarmu
{
    public:
        Buszok(string rendszam, int napi_ar, int km_ar, bool elerheto, int biztositas_dij);
        void Jarmu_reszletei(ostream &os);

        void MentesCSV(ostream &os);
        int Berleti_dij();
        int Alap_ar();

        string getTipus();
        int GetBiztositasDij();

        void setSzemelybiztositas(int szemely);

        ~Buszok();

        //osztalyon kivuli fuggvenyek hozzaferhetnek igy a privat tagokhoz
        //egyedi console-ra kiiratast tesz lehetove
        friend ostream& operator<<(ostream &os, Buszok &b);
    private:
        int biztositas_dij_m;
};

