#pragma once
#define TEHERAUTO_HPP

#include <Jarmu.hpp>
#include <iostream>
#include <string>

using namespace std;

class Teherauto : public Jarmu
{
    public:
        Teherauto(string rendszam, int napi_ar, int km_ar, bool elerheto, int tonna_egysegar);
        void Jarmu_reszletei(ostream &os);
        void MentesCSV(ostream &os);
        int Berleti_dij();
        int Alap_ar();

        string getTipus();
        int GetTonnaAr();

        void setTonnaAr(int tonna);

        ~Teherauto();

        //osztalyon kivuli fuggvenyek hozzaferhetnek igy a privat tagokhoz
        //egyedi console-ra kiiratast tesz lehetove
        friend ostream& operator<<(ostream &os, Teherauto &t);

    private:
        int tonna_egysegar_m;
};
