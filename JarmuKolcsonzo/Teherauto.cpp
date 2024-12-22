#include "Teherauto.hpp"


using namespace std;

Teherauto::Teherauto(string rendszam, int napi_ar, int km_ar, bool elerheto, int tonna_egysegar)
    :Jarmu(rendszam, napi_ar, km_ar, elerheto), tonna_egysegar_m(tonna_egysegar){}


void Teherauto::Jarmu_reszletei(ostream &os)
{

    os << "Tipus\t\t" << "Rendszam\t" << "Napi ar\t\t" << "Km ar\t\t" << "Tonna egysegar\t" <<"Alap ar\t\t" << "Elerheto-e\n" << endl;
    os << getTipus() << "\t";
    os << GetRendszam() << "\t\t";
    os << GetNapiAr() << " HUF/nap " << "\t";
    os << GetKmAr() << " HUF/km " << "\t";
    os << GetTonnaAr() << " HUF/t " << "\t";
    os << Alap_ar() << " HUF " << "\t";
    os <<(Elerheto() ? "Igen" : "Nem") << "\n\n" << endl;
}

void Teherauto::MentesCSV(ostream &os)
{
    os << getTipus() << ",";
    os << GetRendszam() << ",";
    os << GetNapiAr() << ",";
    os << GetKmAr() << ",";
    os << GetTonnaAr() << ",";
    os << Alap_ar() << ",";
    os <<(Elerheto() ? "Igen" : "Nem") << "\n";
}

string Teherauto::getTipus()
{
    string tipus = "Teherauto";
    return tipus;
}

int Teherauto::GetTonnaAr()
{
    return tonna_egysegar_m;
}

void Teherauto::setTonnaAr(int tonna)
{
    this->tonna_egysegar_m = tonna;
}

int Teherauto::Berleti_dij()
{
    double km, tonna_osszesen;
    int nap;
    string uzenet;

    uzenet = "Add meg a megtett km-t: ";
    km = Template::BemenetEllenorzes<double>(uzenet);
    uzenet = "Add meg a megkezdett napok szamat: ";
    nap = Template::BemenetEllenorzes<int>(uzenet);
    uzenet = "Add meg az osszesen szallitott tonnat: ";
    tonna_osszesen = Template::BemenetEllenorzes<double>(uzenet);

    return ((napi_ar_m * nap) + (km_ar_m * km ) + (tonna_egysegar_m * tonna_osszesen));
}

int Teherauto::Alap_ar()
{
    int nap = 1;
    int km = 1;
    int tonna_osszesen =1;

    return ((napi_ar_m * nap) + (km_ar_m * km ) + (tonna_egysegar_m * tonna_osszesen));
}

ostream& operator<<(ostream &os, Teherauto &t)
{
    t.Jarmu_reszletei(os);
    return os;
}

Teherauto::~Teherauto(){}
