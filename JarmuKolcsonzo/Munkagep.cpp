#include "Munkagep.hpp"

using namespace std;

Munkagep::Munkagep(string rendszam, int munkanap_egysegar, bool elerheto, int tonna_egysegara)
    :Jarmu(rendszam, munkanap_egysegar, 0, elerheto), tonna_egysegar_m(tonna_egysegara){}

void Munkagep::Jarmu_reszletei(ostream &os)
{
    os << "Tipus\t\t" << "Rendszam\t" << "Munkanap egysegar\t" << "Tonna egysegar\t" <<"Alap ar\t\t" << "Elerheto-e\n" << endl;
    os << getTipus() << "\t";
    os << GetRendszam() << "\t\t";
    os << GetNapiAr() << " HUF/nap " << "\t\t";
    os << GetTonnaAr() << " HUF/t " << "\t";
    os << Alap_ar() << " HUF " << "\t";
    os <<(Elerheto() ? "Igen" : "Nem") << "\n\n" << endl;
}

void Munkagep::MentesCSV(ostream &os)
{
    os << getTipus() << ",";
    os << GetRendszam() << ",";
    os << GetNapiAr() << ",";
    os << GetTonnaAr() << ",";
    os << Alap_ar() << ",";
    os <<(Elerheto() ? "Igen" : "Nem") << "\n";
}

string Munkagep::getTipus()
{
    string tipus = "Munkagep";
    return tipus;
}

int Munkagep::GetTonnaAr()
{
    return tonna_egysegar_m;
}

void Munkagep::setTonnaAr(int tonna)
{
    this->tonna_egysegar_m = tonna;
}

int Munkagep::Berleti_dij()
{
    int nap;
    double rakodott_tonna;
    string uzenet;

    uzenet = "Add meg a megkezdett napok szamat: ";
    nap = Template::BemenetEllenorzes<int>(uzenet);
    uzenet = "Add meg a rakodott tonnat: ";
    rakodott_tonna = Template::BemenetEllenorzes<double>(uzenet);

    return ((napi_ar_m * nap) + (tonna_egysegar_m * rakodott_tonna));
}

int Munkagep::Alap_ar()
{
    //költségtartománynál alap értékekkel számolok
    int nap = 1;
    int rakodott_tonna = 1;
    return ((napi_ar_m * nap) + (tonna_egysegar_m * rakodott_tonna));
}

ostream& operator<<(ostream &os, Munkagep &m)
{
    m.Jarmu_reszletei(os);
    return os;
}

Munkagep::~Munkagep(){}
