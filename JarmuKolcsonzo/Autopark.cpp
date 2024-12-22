#include "Autopark.hpp"
#include "Buszok.hpp"
#include "Teherauto.hpp"
#include "Munkagep.hpp"
#include <algorithm> //a remove_if miatt kell


using namespace std;

Autopark::Autopark(){}


void Autopark::Jarmu_felvetele()
{
    int opcio;

    do
    {
        cout << "----------------------------------------------------" << endl;
        cout << "| Valassz jarmu tipust az alabbi lehetosegek kozul! |" << endl;
        cout << "----------------------------------------------------" << endl;
        cout << "1. Szemelygepkocsi" << endl;
        cout << "2. Busz-kisbusz" << endl;
        cout << "3. Teherauto" << endl;
        cout << "4. Munkagep" << endl;
        cout << "\n0. Vissza" << endl;
        string uzenet = "Opcio: ";
        //ellenorzom a beviteli erteket a template segitsegevel
        opcio = Template::BemenetEllenorzes<int>(uzenet);
        cout << "-----------------------" << endl;

        if (opcio < 0 || opcio > 4)
            {
                cout << "HIBA!\nRossz opciot adtal meg! 0-4 kozott valassz" << endl;
            }
    } while (opcio < 0 || opcio > 4);

    string rendszam;
    int napi_ar;
    int km_ar;
    bool elerheto;

    switch(opcio)
    {
    case 1:
        {
            cout << "Add meg a rendszamot: ";
            cin >> rendszam;

            string napi = "Add meg a napi arat: ";
            napi_ar = Template::BemenetEllenorzes<int>(napi);
            string km = "Add meg a kilometer arat: ";
            km_ar = Template::BemenetEllenorzes<int>(km);
            string allapot = "Elerheto a jarmu? (1: Igen, 0:Nem) -> Kerlek 1-el vagy 0-val valaszolj\n: ";
            elerheto = Template::BemenetEllenorzes<bool>(allapot);

            //hozzaadok egy uj kocsi peldanyt a jarmulista dinamikus tombomhoz
            jarmulista.push_back(new Szemelygepkocsi(rendszam, napi_ar, km_ar, elerheto));
            cout << "\nSikeres felvetel!" << endl;
            break;
        }
    case 2:
        {
            int biztositas_dij;
            cout << "Add meg a rendszamot: ";
            cin >> rendszam;


            string napi = "Add meg a napi arat: ";
            napi_ar = Template::BemenetEllenorzes<int>(napi);
            string km = "Add meg a kilometer arat: ";
            km_ar = Template::BemenetEllenorzes<int>(km);
            string biztositas = "Add meg a szemelyenkenti biztositas dijat: ";
            biztositas_dij = Template::BemenetEllenorzes<int>(biztositas);
            string allapot = "Elerheto a jarmu? (1: Igen, 0:Nem) -> Kerlek 1-el vagy 0-val valaszolj\n: ";
            elerheto = Template::BemenetEllenorzes<bool>(allapot);

            jarmulista.push_back(new Buszok(rendszam, napi_ar, km_ar, elerheto, biztositas_dij));
            cout << "\nSikeres felvetel!" << endl;
            break;
        }
    case 3:
        {
            int tonna_egysegar;
            cout << "Add meg a rendszamot: ";
            cin >> rendszam;


            string napi = "Add meg a napi arat: ";
            napi_ar = Template::BemenetEllenorzes<int>(napi);
            string km = "Add meg a kilometer arat: ";
            km_ar = Template::BemenetEllenorzes<int>(km);
            string tonna = "Add meg a tonna egysegarat: ";
            tonna_egysegar = Template::BemenetEllenorzes<int>(tonna);
            string allapot = "Elerheto a jarmu? (1: Igen, 0:Nem) -> Kerlek 1-el vagy 0-val valaszolj\n: ";
            elerheto = Template::BemenetEllenorzes<bool>(allapot);

            jarmulista.push_back(new Teherauto(rendszam, napi_ar, km_ar, elerheto, tonna_egysegar));
            cout << "\nSikeres felvetel!" << endl;
            break;
        }
    case 4:
        {
            int munkanap_egysegar, tonna_egysegar;
            cout << "Add meg a rendszamot: ";
            cin >> rendszam;

            string munkanap = "Add meg a munkanap egysegarat: ";
            munkanap_egysegar = Template::BemenetEllenorzes<int>(munkanap);
            string tonna = "Add meg a tonna egysegarat: ";
            tonna_egysegar = Template::BemenetEllenorzes<int>(tonna);
            string allapot = "Elerheto a jarmu? (1: Igen, 0:Nem) -> Kerlek 1-el vagy 0-val valaszolj\n: ";
            elerheto = Template::BemenetEllenorzes<bool>(allapot);

            jarmulista.push_back(new Munkagep(rendszam, munkanap_egysegar, elerheto, tonna_egysegar));
            cout << "\nSikeres felvetel!" << endl;
            break;
        }
    case 0:
        {
            cout << "Vissza..." << endl;
            break;
        }
    default:
            cout << "HIBA! Rossz opciot adtal meg!" << endl;
    }

}

void Autopark::Jarmu_listazasa()
{
    //megnezem ures-e a jarmulista
    if(jarmulista.empty())
    {
        cout << "Nem talalhato jelenleg egy jarmu sem.\n" << endl;
    }
    else
    {
        for(Jarmu* jarmuptr : jarmulista)
        {
            cout << "-----------------------------------------------------------------------------------------------------------\n\n" << endl;
            cout << *jarmuptr << endl;
            cout << "-----------------------------------------------------------------------------------------------------------" << endl;
        }
    }

}

void Autopark::Jarmu_kereses(string rendszam)
{
    //jarmutipusu ptr-t veszek fel ami vegig megy a lista adatain
    for(Jarmu* jarmuptr : jarmulista)
    {
        //ptr-el meghivom az eljarast
        if (jarmuptr->GetRendszam() == rendszam)
        {
            cout << "Talalat! Jarmu adatai:\n" << endl;
            cout << *jarmuptr << endl;
            return;
        }
    }
    cout << "Sajnos nincs ilyen rendszammal rendelkezo jarmu az autoparkban" << endl;

}

void Autopark::Koltseg_szamitas(string rendszam)
{
    for(Jarmu* jarmuptr : jarmulista)
    {
        if(jarmuptr->GetRendszam() == rendszam)
        {
            //castolom az eredmenyt int tipusura, mivel double ertek is van a szamitasban
            int berlet_dij = static_cast<int>(jarmuptr->Berleti_dij());
            cout << "Berleti dij: " << berlet_dij << "HUF" << endl;
        }
    }
    cout << "Nincs ilyen rendszammal rendelkezo jarmu!" << endl;
}

void Autopark::Jarmu_muveletek(string rendszam)
{

    Jarmu* kivalasztott_jarmuptr = nullptr;

    for(Jarmu* jarmuptr : jarmulista)
    {
        if(jarmuptr->GetRendszam() == rendszam)
        {
            kivalasztott_jarmuptr = jarmuptr;
            break;
        }
    }

    //ha a rendszam nem volt megtalalhato akkor hibat fog dobni az else agban, mivel
    //a ptr erteke nullptr marad
    if(kivalasztott_jarmuptr != nullptr)
    {
        int muvelet;
        do
        {
            cout << "------------------------" << endl;
            cout << "|   Jarmu muveletek:    |" << endl;
            cout << "------------------------" << endl;
            cout << "rendszam: " << kivalasztott_jarmuptr->GetRendszam() << endl;
            cout << "\n1. Arajalnlat adasa" << endl;
            cout << "2. Kiadas" << endl;
            cout << "3. Visszavetel" << endl;
            cout << "4. Torles az autoparkbol" << endl;
            cout << "5. Rendszam szerkesztese" << endl;
            cout << "6. Napi ar/munkanap egysegar szerkesztese" << endl;
            cout << "7. Km ar szerkesztese" << endl;
            cout << "8. Szemely biztositasi dij szerkesztese" << endl;
            cout << "9. Tonna ar szereksztese" << endl;
            cout << "\n10. Masik jarmu valasztasa" << endl;
            cout << "\n0. Vissza" << endl;
            string uzenet = "Opcio: ";
            muvelet = Template::BemenetEllenorzes<int>(uzenet);
            cout << "\n-----------------------" << endl;

            switch(muvelet)
            {
            case 1:
                cout << "Arajanlat: \n" << endl;
                cout << static_cast<int>(kivalasztott_jarmuptr->Berleti_dij()) << " HUF" << endl;
                break;
            case 2:
                if(kivalasztott_jarmuptr->Elerheto())
                {
                    cout << "Jarmu kiadasa" << endl;
                    int dij = static_cast<int>(kivalasztott_jarmuptr->Berleti_dij());

                    cout << "\nA berles dija: " << dij << " HUF" << endl;
                    string uzenet;
                    uzenet = "Biztos kiadod? (1: Igen, 0:Nem) -> Kerlek 1-el vagy 0-val valaszolj\n";
                    bool kiadas;
                    kiadas = Template::BemenetEllenorzes<bool>(uzenet);
                    if(kiadas == true)
                    {
                        cout << "Siker!\nJarmu kiadva." << endl;
                        kivalasztott_jarmuptr->setElerheto(false);
                    }
                    else
                    {
                        cout << "Jarmu kiadas visszavonasa." << endl;
                    }
                }
                else
                {
                    cout << "HIBA!\nA kivalasztott jarmu sajnos mar ki van adva\n";
                }
                break;
            case 3:
                //ptr-el meghivom az eljarast
                if(!kivalasztott_jarmuptr->Elerheto())
                {
                    cout << "Jarmu sikeresen visszaveve!" << endl;
                    kivalasztott_jarmuptr->setElerheto(true);
                    }
                else
                {
                    cout << "HIBA!\nA jarmu elerheto volt." << endl;
                }
                break;
            case 4:
                cout << "Jarmu torlese..." << endl;
                // A remove_if eltavolitja a torlesre szant jarmuvet
                jarmulista.erase(remove_if(jarmulista.begin(), jarmulista.end(),
                                [rendszam](Jarmu* jptr)
                                {
                                    if (jptr->GetRendszam() == rendszam) {
                                        delete jptr; // Memoriat felszabaditjuk
                                        return true;
                                    }
                                    return false;
                                }),
                    jarmulista.end());
                cout << "Jarmu sikeresen torolve!" << endl;
                return; // fuggveny kilepes
            case 5:
                //adat bekeres miatt kellett {}-ba tennem, enelkul nem futott le a program
                {
                    string uj_rendszam;
                    cout << "\nAdd meg az uj rendszamot" << endl;
                    cout << "rendszam: ";
                    cin >> uj_rendszam;

                    kivalasztott_jarmuptr->setRendszam(uj_rendszam);
                    cout << "Uj rendszam sikeresen beallitva!" << endl;
                    break;
                }
            case 6:
                {
                    int nap;
                    cout << "Add meg az uj napi/munkanap arat" << endl;
                    string uzenet = "napi/munkanap ar: ";
                    nap = Template::BemenetEllenorzes<int>(uzenet);

                    kivalasztott_jarmuptr->setNapiAr(nap);
                    cout << "Uj napi/munkanap ar sikeresen beallitva!" << endl;
                    break;
                }
            case 7:
                {
                    int km;
                    cout << "Add meg az uj km arat" << endl;
                    string uzenet = "km ar: ";
                    km = Template::BemenetEllenorzes<int>(uzenet);

                    kivalasztott_jarmuptr->setKmAr(km);
                    cout << "Uj km ar sikeresen beallitva!" << endl;
                    break;
                }
            case 8:
                {
                    //ellenorzom, hogy a kivalasztott jarmu busz tipusu-e mert, ha nem akkor
                    //nem szabad hogy lefusson ez a valasztas
                    Buszok* buszptr = dynamic_cast<Buszok*>(kivalasztott_jarmuptr);
                    if(buszptr)
                    {
                        int szemely;
                        cout << "Add meg az uj szemely biztositas arat" <<endl;
                        string uzenet = "szemelybiztositas ar: ";
                        szemely = Template::BemenetEllenorzes<int>(uzenet);

                        buszptr->setSzemelybiztositas(szemely);
                        cout << "Uj szemelybiztositas ar sikeresen beallitva!" << endl;
                    }
                    else
                    {
                        cout << "HIBA!\nAz altalad kivalasztott jarmu nem Busz-kisbusz" << endl;
                    }
                    break;
                }
            case 9:
                {
                    //ellenorzom, hogy a kivalasztott jarmu teherauto vagy munkagep tipusu-e mert, ha nem akkor
                    //nem szabad hogy lefusson ez a valasztas
                    Teherauto* teherautoptr = dynamic_cast<Teherauto*>(kivalasztott_jarmuptr);
                    Munkagep* munkagepptr = dynamic_cast<Munkagep*>(kivalasztott_jarmuptr);
                    if (teherautoptr || munkagepptr)
                    {
                        int tonna;
                        cout << "Add meg az uj tonna egysegarat" << endl;
                        string uzenet = "tonna: ";
                        tonna = Template::BemenetEllenorzes<int>(uzenet);

                        if(teherautoptr)
                        {
                            teherautoptr->setTonnaAr(tonna);
                            cout << "Uj tonna egysegar sikeresen beallitva!" << endl;
                        }
                        else if(munkagepptr)
                        {
                            munkagepptr->setTonnaAr(tonna);
                            cout << "Uj tonna egysegar sikeresen beallitva!" << endl;
                        }
                    }
                    else
                    {
                        cout << "HIBA!\nAz altalad kivalasztott jarmu nem Teherauto vagy Munkagep" << endl;
                    }
                    break;
                }
            case 10:
                {
                    string masik;
                    cout << "Add meg a masik jarmu rendszamat" << endl;
                    cout << "rendszam: ";
                    cin >> masik;
                    for(Jarmu* jarmuptr : jarmulista)
                    {
                        if(jarmuptr->GetRendszam() == masik)
                        {
                            kivalasztott_jarmuptr = jarmuptr;
                            break;
                        }
                    }
                    if(kivalasztott_jarmuptr != nullptr)
                    {
                        cout << "Masik jarmu sikeresen kivalasztva!\n" << endl;
                    }
                    else
                    {
                        cout << "HIBA!\nNincs jarmu a megadott rendszammal!" << endl;
                    }
                    break;
                }
            case 0:
                cout << "Vissza..." << endl;
                break;
            default:
                cout << "HIBA!\nNincs ilyen muvelet.\nValassz ujra: " << endl;
            }
        }while (muvelet != 0);
    }
    else
    {
        cout << "HIBA!\nNincs jarmu a megadott rendszammal!" << endl;
    }

}

void Autopark::Jarmu_elerheto_szuro()
{
    cout << "-----------------------------" << endl;
    cout << "| Elerheto jarmuvek listaja: |" << endl;
    cout << "-----------------------------" << endl;
    for(Jarmu *jarmuptr : jarmulista)
    {
        if(jarmuptr->Elerheto())
        {
            cout << "-----------------------------------------------------------------------------------------------------------\n\n" << endl;
            cout << *jarmuptr << endl;
            cout << "-----------------------------------------------------------------------------------------------------------" << endl;
        }
    }
}

void Autopark::Jarmu_kategoriak_szuro()
{
    int kategoria;
    bool Vissza = false;

    do
    {
        cout << "-----------------------" << endl;
        cout << "|   Kategoria szuro:  |" << endl;
        cout << "-----------------------" << endl;
        cout << "1. Szemelygepkocsi" << endl;
        cout << "2. Busz-kisbusz" << endl;
        cout << "3. Teherauto" << endl;
        cout << "4. Munkagep" << endl;
        cout << "\n0. Vissza" << endl;
        cout << "Valasztas: ";

        try
        {
            cin >> kategoria;
            cout << "\n" << endl;
            // c++ beepitett muvelet kezeloje
            if (cin.fail() || kategoria < 0 || kategoria > 4)
            {
                throw runtime_error("HIBA!\n0-4 kozott valassz.\n");
            }
            else if(kategoria == 0)
            {
                Vissza = true; //Vissza a fomenube
            }
            else
            {
                for (Jarmu* jarmuptr : jarmulista)
                {
                    string tipus = jarmuptr->getTipus();
                    if (kategoria == 1 && tipus == "Szemelygepkocsi")
                    {
                        cout << "-----------------------------------------------------------------------------------------------------------\n\n" << endl;
                        cout << *jarmuptr << endl;
                        cout << "-----------------------------------------------------------------------------------------------------------" << endl;
                    }
                    else if (kategoria == 2 && tipus == "Busz-kisbusz")
                    {
                        cout << "-----------------------------------------------------------------------------------------------------------\n\n" << endl;
                        cout << *jarmuptr << endl;
                        cout << "-----------------------------------------------------------------------------------------------------------" << endl;
                    }
                    else if (kategoria == 3 && tipus == "Teherauto")
                    {
                        cout << "-----------------------------------------------------------------------------------------------------------\n\n" << endl;
                        cout << *jarmuptr << endl;
                        cout << "-----------------------------------------------------------------------------------------------------------" << endl;
                    }
                    else if (kategoria == 4 && tipus == "Munkagep")
                    {
                        cout << "-----------------------------------------------------------------------------------------------------------\n\n" << endl;
                        cout << *jarmuptr << endl;
                        cout << "-----------------------------------------------------------------------------------------------------------" << endl;
                    }

                }
            }

        }
        catch (const exception& e)
        {
            cerr << "HIBA: " << e.what() << endl;
            cin.clear(); // torli a hibas bemenetet a bemeneti pufferbol
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // figyelmem kivul hagyja a sortorest
        }

    }while(!Vissza);

}

void Autopark::Jarmu_koltsegtartomany_szuro()
{
    int also_hatar, felso_hatar;
    cout << "---------------------------" << endl;
    cout << "| Koltsegtartomany szuro: |" << endl;
    cout << "---------------------------" << endl;

    do
    {
        string uzenetalso = "Add meg az also hatart: ";
        also_hatar = Template::BemenetEllenorzes<int>(uzenetalso);
        string uzenetfelso = "Add meg a felso hatart: ";
        felso_hatar = Template::BemenetEllenorzes<int>(uzenetfelso);

        if (also_hatar > felso_hatar)
        {
            cout << "HIBA! Az also hatar nem lehet nagyobb, mint a felso" << endl;
        }
        else
        {
            bool talalat = false;

            cout << "\nMegadott tartomanyban benne levo jarmuvek:\n" << endl;
            for (Jarmu* jarmuptr : jarmulista)
            {
                //alap arat hasznalom a koltsegtartomany szuresehez
                int berleti_dij = static_cast<int>(jarmuptr->Alap_ar());
                if (berleti_dij >= also_hatar && berleti_dij <= felso_hatar)
                {
                    cout << "-----------------------------------------------------------------------------------------------------------\n\n" << endl;
                    cout << *jarmuptr << endl;
                    cout << "-----------------------------------------------------------------------------------------------------------" << endl;
                    talalat = true;
                }
            }

            if (!talalat)
            {
                cout << "Egy megfelelo jarmu sincsen a megadott tartomanyban" << endl;
            }
        }

    } while (also_hatar > felso_hatar);

}

void Autopark::Fajlba_mentes(int valasztas)
{
    switch(valasztas)
    {
    case 1:
        Mentes_kocsi();
        break;
    case 2:
        Mentes_busz();
        break;
    case 3:
        Mentes_teherauto();
        break;
    case 4:
        Mentes_munkagep();
        break;
    case 5:
        Mentes_minden();
        break;
    case 0:
        break;
    default:
        cout << "HIBA! 1-5 kozott valassz" << endl;
    }

}

void Autopark::Mentes_kocsi()
{
    ofstream file("kocsi.csv");
    if (file.is_open())
    {
        file << "Tipus,Rendszam,Napi ar (HUF/nap),Km ar (HUF/km),Alap ar (HUF),Elerheto-e\n";
        for (Jarmu* jarmuptr : jarmulista)
        {
            //itt megyek biztosra, hogy a peldany biztos az e ami nekem kell
            if (dynamic_cast<Szemelygepkocsi*>(jarmuptr))
            {
                jarmuptr->MentesCSV(file);
            }
        }
        cout << "Sikeres mentes!" << endl;
        file.close();
    } else {
        cerr << "HIBA tortent a fajlba iras soran..." << endl;
    }
}

void Autopark::Mentes_busz()
{
    ofstream file("buszok.csv");
    if (file.is_open())
    {
        file << "Tipus,Rendszam,Napi ar (HUF/nap),Km ar(HUF/km,Biztositas dij (HUF/fo),Alap ar,Elerheto-e\n";
        for (Jarmu* jarmuptr : jarmulista)
        {
            //itt megyek biztosra, hogy a peldany biztos az e ami nekem kell
            if (dynamic_cast<Buszok*>(jarmuptr))
            {
                jarmuptr->MentesCSV(file);
            }
        }
        cout << "Sikeres mentes!" << endl;
        file.close();
    } else {
        cerr << "HIBA tortent a fajlba iras soran..." << endl;
    }
}

void Autopark::Mentes_teherauto()
{
    ofstream file("teherauto.csv");
    if (file.is_open())
    {
        file << "Tipus,Rendszam,Napi ar (HUF/nap),Km ar(HUF/km,Tonna egysegar (HUF/t),Alap ar,Elerheto-e\n";
        for (Jarmu* jarmuptr : jarmulista)
        {
            //itt megyek biztosra, hogy a peldany biztos az e ami nekem kell
            if (dynamic_cast<Teherauto*>(jarmuptr))
            {
                jarmuptr->MentesCSV(file);
            }
        }
        cout << "Sikeres mentes!" << endl;
        file.close();
    } else {
        cerr << "HIBA tortent a fajlba iras soran..." << endl;
    }
}

void Autopark::Mentes_munkagep()
{
    ofstream file("munkagep.csv");
    if (file.is_open())
    {
        file << "Tipus,Rendszam,Munkanap egysegar (HUF/nap),Tonna egysegar (HUF/t),Alap ar,Elerheto-e\n";
        for (Jarmu* jarmuptr : jarmulista)
        {
            //itt megyek biztosra, hogy a peldany biztos az e ami nekem kell
            if (dynamic_cast<Munkagep*>(jarmuptr))
            {
                jarmuptr->MentesCSV(file);
            }
        }
        cout << "Sikeres mentes!" << endl;
        file.close();
    } else {
        cerr << "HIBA tortent a fajlba iras soran..." << endl;
    }
}

void Autopark::Mentes_minden()
{
    ofstream file("autopark.txt");
    if (file.is_open())
    {
        for (Jarmu* jarmuptr : jarmulista)
        {
            file << *jarmuptr << endl;
        }
        cout << "Sikeres mentes!" << endl;
        file.close();
    }
    else
    {
        cerr << "HIBA tortent a fajlba iras soran..." << endl;
    }
}

void Autopark::Fajlbol_betoltes(string file)
{
    ifstream olvas(file);
    int hiba = 0;

    //ellenorizzuk megnyithato-e a file
    if(!olvas.is_open())
    {
        cout << "Hiba a file megnyitasakor!" << endl;
        return;
    }

    //fejlecet nem akarok kezelni, mert nem teljesen egyseges a kulon osztalyoknak, ezert nem tettem bele a probabetoltes.csv-be
    string sor;

    while(getline(olvas, sor))
    {
        stringstream s(sor);
        string tipus, rendszam, elerheto;
        int napi_ar, km_ar, biztositas_ar, tonna_ar;
        bool elerheto_j;

        Jarmu* jarmuptr = nullptr;

        //c++ fuggveny szoveges bemenethez
        //karakterlancba olvas be addig amig , -vel nem talalkozik
        getline(s, tipus, ',');
        getline(s, rendszam, ',');

        if (tipus == "Szemelygepkocsi")
        {
            s >> napi_ar; s.ignore(); //vesszot figyelmen kivul hagyjuk
            s >> km_ar; s.ignore();
            getline(s, elerheto, ',');
            elerheto_j = (elerheto == "Igen"); //egy bool valtozoba lementem, hogy elerheto-e a jarmu
            jarmuptr = new Szemelygepkocsi(rendszam, napi_ar, km_ar, elerheto_j);
        }
        else if (tipus == "Busz-kisbusz")
        {
            s >> napi_ar; s.ignore(); //vesszot figyelmen kivul hagyjuk
            s >> km_ar; s.ignore();
            s >> biztositas_ar; s.ignore();
            getline(s, elerheto, ',');
            elerheto_j = (elerheto == "Igen");
            jarmuptr = new Buszok(rendszam, napi_ar, km_ar, elerheto_j, biztositas_ar);
        }
        else if (tipus == "Teherauto")
        {
            s >> napi_ar; s.ignore(); //vesszot figyelmen kivul hagyjuk
            s >> km_ar; s.ignore();
            s >> tonna_ar; s.ignore();
            getline(s, elerheto, ',');
            elerheto_j = (elerheto == "Igen");
            jarmuptr = new Teherauto(rendszam, napi_ar, km_ar, elerheto_j, tonna_ar);
        }
        else if (tipus == "Munkagep")
        {
            s >> napi_ar; s.ignore(); //vesszot figyelmen kivul hagyjuk
            s >> tonna_ar; s.ignore();
            getline(s, elerheto, ',');
            elerheto_j = (elerheto == "Igen");
            jarmuptr = new Munkagep(rendszam, napi_ar, elerheto_j, tonna_ar);
        }
        else {
            cout << "HIBA! A(z)" << tipus << " tipusu jarmu nem ismert tipus" << endl;
            ++hiba;
            continue; // Folytatjuk az adatok beolvasasat, hatha van meg jo
        }

        if(jarmuptr)
        {
            //jarmulistahoz hozzaadom a peldanyokat a ptr-bol
            jarmulista.push_back(jarmuptr);
        }
    }

    olvas.close();
    cout << "-----------------------" << endl;
    cout << "|  Sikeres betoltes!  |" << endl;
    cout << "-----------------------" << endl;
    cout << "\nHibas rekordok szama: " << hiba << endl;
    cout << "\n" << endl;

}

Autopark::~Autopark(){}
