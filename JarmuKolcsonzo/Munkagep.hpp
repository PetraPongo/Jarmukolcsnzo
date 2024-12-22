#pragma once
#define MUNKAGEP_HPP

#include <Jarmu.hpp>
#include <iostream>
#include <string>


using namespace std;

class Munkagep : public Jarmu
{
    public:
        Munkagep(string rendszam, int munkanap_egysegar, bool elerheto, int tonna_egysegara);
        void Jarmu_reszletei(ostream &os);
        void MentesCSV(ostream &os);
        int Berleti_dij();
        int Alap_ar();

        string getTipus();
        int GetTonnaAr();

        void setTonnaAr(int tonna);

        ~Munkagep();

        //azert kell friend hogy az ostream a privat valtozohoz is hozzaferjen
        //osztalyon kivuli fuggvenyek hozzaferhetnek igy a privat tagokhoz
        //egyedi console-ra kiiratast tesz lehetove
        friend ostream& operator<<(ostream &os, Munkagep &m);

    private:
        int tonna_egysegar_m;
};
