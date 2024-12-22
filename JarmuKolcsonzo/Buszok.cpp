#include "Buszok.hpp"


using namespace std;

Buszok::Buszok(string rendszam, int napi_ar, int km_ar, bool elerheto, int biztositas_dij)
    :Jarmu(rendszam, napi_ar, km_ar, elerheto), biztositas_dij_m(biztositas_dij){}


string Buszok::getTipus()
{
    string tipus = "Busz-kisbusz";
    return tipus;
}

int Buszok::GetBiztositasDij()
{
    return biztositas_dij_m;
}

void Buszok::setSzemelybiztositas(int szemely)
{
    this->biztositas_dij_m = szemely;
}

int Buszok::Berleti_dij()
{
    double km;
    int nap, ossz_szemely;
    string uzenet;

    uzenet = "Add meg a megtett km-t: ";
    km = Template::BemenetEllenorzes<double>(uzenet);
    uzenet = "Add meg a megkezdett napok szamat: ";
    nap = Template::BemenetEllenorzes<int>(uzenet);
    uzenet = "Add meg hany szemely utazik a buszon: ";
    ossz_szemely = Template::BemenetEllenorzes<int>(uzenet);

    return ((napi_ar_m * nap) + (km_ar_m * km ) + (biztositas_dij_m * ossz_szemely));
}

void Buszok::Jarmu_reszletei(ostream &os)
{
    os << "Tipus\t\t" << "Rendszam\t" << "Napi ar\t\t" << "Km ar\t\t" << "Biztositas dij\t" <<"Alap ar\t\t" << "Elerheto-e\n" << endl;
    os << getTipus() << "\t";
    os << GetRendszam() << "\t";
    os << GetNapiAr() << " HUF/nap " << "\t";
    os << GetKmAr() << " HUF/km " << "\t";
    os << GetBiztositasDij() << " HUF/fo " << "\t";
    os << Alap_ar() << " HUF " << "\t";
    os <<(Elerheto() ? "Igen" : "Nem") << "\n\n" << endl;
}

void Buszok::MentesCSV(ostream &os)
{
    os << getTipus() << ",";
    os << GetRendszam() << ",";
    os << GetNapiAr() << ",";
    os << GetKmAr() << ",";
    os << GetBiztositasDij() << ",";
    os << Alap_ar() << ",";
    os << (Elerheto() ? "Igen" : "Nem") << "\n";
}

int Buszok::Alap_ar()
{
    //költségtartománynál alap értékekkel számolok
    int nap = 1;
    int km = 1;
    int ossz_szemely = 1;
    return ((napi_ar_m * nap) + (km_ar_m * km ) + (biztositas_dij_m * ossz_szemely));
}

ostream& operator<<(ostream &os, Buszok &b)
{
    b.Jarmu_reszletei(os);
    return os;
}


Buszok::~Buszok(){}
