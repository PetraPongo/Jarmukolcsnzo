#include "Szemelygepkocsi.hpp"


using namespace std;

Szemelygepkocsi::Szemelygepkocsi(string rendszam, int napi_ar, int km_ar, bool elerheto):
    Jarmu(rendszam, napi_ar, km_ar, elerheto){}

string Szemelygepkocsi::getTipus()
{
    string tipus = "Szemelygepkocsi";
    return tipus;
}

int Szemelygepkocsi::Berleti_dij()
{
    int nap;
    double km;
    string uzenet;

    uzenet = "Add meg a megkezdett napok szamat: ";
    nap = Template::BemenetEllenorzes<int>(uzenet);
    uzenet = "Add meg a megtett km-t: ";
    km = Template::BemenetEllenorzes<double>(uzenet);

    return ((napi_ar_m * nap) + (km_ar_m * km ));
}

int Szemelygepkocsi::Alap_ar()
{
    //költségtartománynál alap értékekkel számolok
    int nap = 1;
    int km = 1;
    return ((napi_ar_m * nap) + (km_ar_m * km ));
}

ostream& operator<<(ostream &os, Szemelygepkocsi &a)
{
    a.Jarmu_reszletei(os);
    return os;
}
Szemelygepkocsi::~Szemelygepkocsi(){}
