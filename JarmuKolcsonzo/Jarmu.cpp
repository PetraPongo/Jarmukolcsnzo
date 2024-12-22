#include "Jarmu.hpp"


using namespace std;

Jarmu::Jarmu(string rendszam, int napi_ar, int km_ar, bool elerheto)
   :rendszam_m(rendszam), napi_ar_m(napi_ar), km_ar_m(km_ar), elerheto_m(elerheto){}


string Jarmu::GetRendszam()
{
    return rendszam_m;
}

int Jarmu::GetNapiAr()
{
    return napi_ar_m;
}

int Jarmu::GetKmAr()
{
    return km_ar_m;
}

bool Jarmu::Elerheto()
{
    return elerheto_m;
}

void Jarmu::setElerheto(bool elerheto)
{
    elerheto_m = elerheto;
}

void Jarmu::setRendszam(string& uj_rendszam)
{
    this->rendszam_m = uj_rendszam;
}

void Jarmu::setNapiAr(int napi)
{
    this->napi_ar_m = napi;
}

void Jarmu::setKmAr(int km)
{
    this->km_ar_m = km;
}

void Jarmu::Jarmu_reszletei(ostream &os)
{
    os << "Tipus\t\t" << "\tRendszam\t" << "Napi ar\t\t" << "Km ar\t\t" << "Alap ar\t\t" << "Elerheto-e\n" << endl;
    os << getTipus() << "\t\t";
    os << GetRendszam() << "\t\t";
    os << GetNapiAr() << " HUF/nap" << "\t";
    os << GetKmAr() << " HUF/km" << "\t";
    os << Alap_ar() << " HUF" << "\t";
    os <<(Elerheto() ? "Igen" : "Nem") << "\n\n" << endl;
}

void Jarmu::MentesCSV(ostream &os)
{
    os << getTipus() << ",";
    os << GetRendszam() << ",";
    os << GetNapiAr() << ",";
    os << GetKmAr() << ",";
    os << Alap_ar() << ",";
    os << (Elerheto() ? "Igen" : "Nem") << "\n";
}

ostream& operator<<(ostream &os, Jarmu &v)
{
    v.Jarmu_reszletei(os);
    return os;
}
Jarmu::~Jarmu(){}
