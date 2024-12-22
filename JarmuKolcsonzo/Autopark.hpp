#pragma once
#define AUTOPARK_HPP

#include "Jarmu.hpp"
#include "Szemelygepkocsi.hpp"
#include "Buszok.hpp"
#include "Teherauto.hpp"
#include "Munkagep.hpp"
#include "Template.hpp"
#include <iostream>
#include <vector> //dinamikus tomb miatt
#include <fstream> //filekezeles
#include <sstream> //filebol olvasas
#include <string>



class Autopark
{
    public:
        Autopark();
        void Jarmu_felvetele();
        void Jarmu_listazasa();
        void Jarmu_kereses(std::string rendszam);
        void Koltseg_szamitas(std::string rendszam);
        void Jarmu_muveletek(std::string rendszam);
        void Jarmu_elerheto_szuro();
        void Jarmu_kategoriak_szuro();
        void Jarmu_koltsegtartomany_szuro();

        void Fajlba_mentes(int valasztas);
        void Mentes_kocsi();
        void Mentes_busz();
        void Mentes_teherauto();
        void Mentes_munkagep();
        void Mentes_minden();

        void Fajlbol_betoltes(string file);

        ~Autopark();


    private:
        std::vector<Jarmu*> jarmulista; //dinamikus meretu tomb
};

