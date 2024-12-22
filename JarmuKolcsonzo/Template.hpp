#pragma once
#define TEMPLATE_HPP
#include <string>
#include <iostream>
#include <limits> //hibakezeleshez kellett

//Amiatt hoztam oket letre, hogy kezelje azokat az eseteket, amikor
//nem a tipusnak megfelelo ertek kerult megadasra
class Template
{
    public:
        Template();

        //azert static meg igy nem a peldanoykhoz tartoznak, hanem az osztalyok hasznalhatjak
        //pldanyositas nelkul
        template <typename T>
        static T BemenetEllenorzes(std::string& uzenet);

};

