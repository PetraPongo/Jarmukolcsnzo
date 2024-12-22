#pragma once
#define JARMU_HPP

#include <string>
#include <iostream>
#include <fstream> //fájlbaírás és fájlból olvasás miatt
#include <vector>
#include "Template.hpp"
using namespace std;

class Jarmu
{
    public:
        Jarmu(string rendszam, int napi_ar, int km_ar, bool elerheto);



        string GetRendszam();
        int GetNapiAr();
        int GetKmAr();

        void setRendszam(string& rendszam);
        void setNapiAr(int napi);
        void setKmAr(int km);

        void setElerheto(bool elerheto);
        bool Elerheto();

        //azért kellett ez a megoldás, mivel a gyerek osztályok nem tudták felülírni a sima ostream-et
        //virtual pedig nem hasznalhato ostreambol
        //így mindig a jarmu tipusra írta ki az adatokat
        virtual void Jarmu_reszletei(ostream &os);
        virtual void MentesCSV(ostream &os);
        virtual string getTipus() =0;
        virtual int Berleti_dij() =0;
        virtual int Alap_ar() =0;

        virtual ~Jarmu();


    protected:
        string rendszam_m;
        string tipus_m;
        int napi_ar_m;
        int km_ar_m;
        int alap_ar_m;
        bool elerheto_m;
};

ostream& operator<<(ostream &os, Jarmu &v);
