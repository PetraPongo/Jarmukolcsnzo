#include "Menu.hpp"


using namespace std;

Menu::Menu(){}

void Menu::exec()
{
    int valasztas;
    do
        {

            cout << "-----------------------" << endl;
            cout << "| Autokolcsonzo Menu  |" << endl;
            cout << "-----------------------" << endl;
            cout << "1. Jarmu felvetele" << endl;
            cout << "2. Jarmupark listazasa" << endl;
            cout << "3. Jarmu keresese rendszam alapjan" << endl;
            cout << "4. Jarmu muveletek" << endl;
            cout << "5. Elerheto jarmuvek listaja" << endl;
            cout << "6. Szures jarmu tipus szerint" << endl;
            cout << "7. Szures koltsegtartomany alapjan" << endl;
            cout << "8. Fajlba mentes" << endl;
            cout << "9. Fajlbol betoltes" << endl;
            cout << "\n0. Kilepes" << endl;
            string uzenet = "Valasszon menupontot: ";
            valasztas = Template::BemenetEllenorzes<int>(uzenet);


            switch(valasztas)
                {
                case 1:
                    JarmuFelvetele();
                    break;

                case 2:
                    JarmuListazasa();
                    break;

                case 3:
                    JarmuKeresese();
                    break;

                case 4:
                    JarmuMuveletek();
                    break;

                case 5:
                    JarmuElerhetoSzuro();
                    break;

                case 6:
                    JarmuKategoriakSzuro();
                    break;

                case 7:
                    JarmuKoltsegtartomanySzuro();
                    break;

                case 8:
                    FajlbaMentes();
                    break;

                case 9:
                    FajlbolBetoltes();
                    break;

                case 0:
                    cout << "Kilepes a programbol..." << endl;
                    break;

                default:
                    cout << "Ervenytelen valasztas!\n0-9 kozotti opciok kozul valassz\n" << endl;
                }

        }
    while(valasztas != 0);
}

void Menu::JarmuFelvetele()
{
    autopark.Jarmu_felvetele();
}

void Menu::JarmuListazasa()
{
    cout << "-------------------------" << endl;
    cout << "|   Jarmuvek listaja    |" << endl;
    cout << "-------------------------" << endl;
    cout << "\n";
    autopark.Jarmu_listazasa();
}

void Menu::JarmuKeresese()
{
    string rendszam;
    cout << "-----------------------------------" << endl;
    cout << "|  Add meg a keresendo rendszamot  |" << endl;
    cout << "-----------------------------------" << endl;
    cout << "rendszam: ";
    cin >> rendszam;
    cout << "-----------------------" << endl;
    autopark.Jarmu_kereses(rendszam);
}

void Menu::JarmuMuveletek()
{
    string rendszam;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "|  Add meg annak a jarmunek a rendszamat, amivel dolgozni szeretnel  |" << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "rendszam: ";
    cin >> rendszam;
    cout << "-----------------------" << endl;
    autopark.Jarmu_muveletek(rendszam);

}

void Menu::JarmuElerhetoSzuro()
{
    autopark.Jarmu_elerheto_szuro();
}

void Menu::JarmuKategoriakSzuro()
{
    autopark.Jarmu_kategoriak_szuro();
}

void Menu::JarmuKoltsegtartomanySzuro()
{
    autopark.Jarmu_koltsegtartomany_szuro();
}

void Menu::FajlbaMentes()
{
    int opcio;
    do
    {
        cout << "----------------------------------------------------" << endl;
        cout << "|   Valaszd ki melyik jarmutipust akarod menteni!   |" << endl;
        cout << "----------------------------------------------------" << endl;
        cout << "1. Szemelygepkocsi" << endl;
        cout << "2. Busz-kisbusz" << endl;
        cout << "3. Teherauto" << endl;
        cout << "4. Munkagep" << endl;
        cout << "5. Minden jarmu" << endl;
        cout << "\n0. Vissza" << endl;
        cout << "-----------------------" << endl;

        string uzenet = "Opcio: ";
        opcio = Template::BemenetEllenorzes<int>(uzenet);

        autopark.Fajlba_mentes(opcio);
    }while(opcio != 0);

}

void Menu::FajlbolBetoltes()
{
        string file;
        cout << "-------------------------------" << endl;
        cout << "|   Adatok fajlbol betoltese  |" << endl;
        cout << "-------------------------------" << endl;
        cout << "Add meg a file nevet" << endl;
        cout << "file: ";
        cin >> file;
        autopark.Fajlbol_betoltes(file);
}

Menu::~Menu()
{
    cout << "\nLegyen szep napod!\nDestruktor lefut..." << endl;
}
