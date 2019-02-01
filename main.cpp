//POP_2016_12_12_projekt_1_Laskowski_Maciej_EIT_3_165650
//Code::Blocks 16.01
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

struct Labirynt
{
    int gracz_x;
    int gracz_y;
    int wymiar_x;
    int wymiar_y;
};

void rysuj(int *labirynt, int x, int y, int ogr, int gracz_x, int gracz_y);
void przesun(int *labirynt, string polecenia, int &x, int &y, int wiersz, bool &wyjscie);
void instrukcje();
int main()
{
    int map1[9][15] = {201, 205, 205, 187, 0, 0, 201, 205, 205, 205, 205, 205, 205, 205, 187,
                       186, 88, 0, 200, 205, 205, 188, 0, 0, 0, 0, 0, 0, 0, 186,
                       186, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 186,
                       200, 205, 205, 205, 187, 0, 0, 0, 0, 0, 0, 0, 0, 0, 186,
                       0, 0, 0, 0, 186, 0, 0, 0, 201, 205, 187, 0, 0, 0, 186,
                       201, 205, 205, 205, 188, 0, 0, 0, 186, 0, 186, 0, 0, 0, 186,
                       186, 0, 0, 0, 0, 0, 0, 0, 186, 0, 186, 0, 0, 0, 186,
                       186, 0, 0, 0, 0, 0, 0, 0, 186, 0, 186, 0, 0, 0, 186,
                       200, 205, 205, 205, 205, 205, 205, 205, 188, 0, 200, 205, 87, 205, 188
                      };
    int map2[29][29]= {0,0,0,0,0,0,0,201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187,0,0,
                       0,0,0,0,0,0,0,186,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,186,0,0,
                       0,0,0,0,0,0,0,186,0,205,205,205,205,203,205,205,205,205,205,205,205,187,0,186,0,0,
                       0,0,0,0,0,0,0,186,0,0,0,0,0,186,0,0,0,0,0,0,0,186,0,186,0,0,
                       0,0,0,0,0,0,0,200,205,205,205,187,0,186,0,0,0,0,0,0,0,186,0,186,0,0,
                       0,0,0,0,0,0,0,0,0,0,0,186,0,186,0,0,0,0,0,0,0,186,0,186,0,0,
                       201,205,205,205,187,201,205,205,205,205,205,188,0,200,203,205,205,205,205,205,187,186,0,186,0,0,
                       186,88,0,0,186,87,0,0,0,0,0,0,0,0,186,0,0,0,0,0,186,186,0,186,0,0,
                       186,0,201,205,188,200,205,205,205,205,205,205,205,205,202,205,187,0,0,0,186,186,0,186,0,0,
                       186,0,186,0,0,0,0,0,0,0,201,205,205,205,205,205,188,0,0,0,186,186,0,186,0,0,
                       186,0,200,205,205,205,205,205,205,205,185,0,0,0,0,0,0,0,0,0,200,188,0,186,0,0,
                       186,0,0,0,0,0,0,0,0,0,186,0,0,0,0,0,0,0,0,0,0,0,0,186,0,0,
                       186,0,0,201,205,205,205,187,0,0,186,0,0,201,205,205,187,0,0,0,201,205,205,188,0,0,
                       186,0,0,186,0,0,0,186,0,0,186,0,0,186,0,0,186,0,0,0,186,0,0,0,0,0,
                       186,0,0,186,0,0,0,186,0,0,186,0,0,186,0,0,186,0,0,0,200,205,205,205,205,187,
                       204,205,205,188,0,0,0,186,0,0,186,0,0,200,205,205,188,0,0,0,0,0,0,0,0,186,
                       186,0,0,0,0,0,0,0,0,0,186,0,0,0,0,0,0,0,201,205,205,205,205,187,0,186,
                       186,0,0,0,0,0,0,0,0,0,186,0,0,0,0,0,0,0,186,0,0,0,0,186,0,186,
                       200,205,205,205,187,0,186,0,0,0,200,203,205,187,0,0,186,0,186,0,0,0,0,186,0,186,
                       0,0,0,0,186,0,186,0,0,0,0,186,0,186,0,201,188,0,186,0,0,0,0,186,0,186,
                       0,0,0,0,186,0,200,205,205,205,205,188,0,200,205,188,0,0,186,0,0,0,0,186,0,186,
                       0,0,0,0,186,0,0,0,0,0,0,0,0,0,0,0,0,0,200,203,205,205,187,186,0,186,
                       0,0,0,0,186,0,0,201,205,205,205,205,205,187,0,205,205,205,205,188,0,0,186,200,205,188,
                       0,0,0,0,200,205,205,188,0,0,0,0,0,186,0,0,0,0,0,0,0,0,186,0,0,0,
                       0,0,0,0,0,0,0,0,0,0,0,0,0,186,0,0,201,205,205,187,0,201,188,0,0,0,
                       0,0,0,0,0,0,0,0,0,0,0,0,0,186,0,0,186,0,0,186,0,186,0,0,0,0,
                       0,0,0,0,0,0,0,0,0,0,0,0,0,186,0,0,186,0,0,186,0,186,0,0,0,0,
                       0,0,0,0,0,0,0,0,0,0,0,0,0,186,0,0,186,0,0,186,0,186,0,0,0,0,
                       0,0,0,0,0,0,0,0,0,0,0,0,0,200,205,205,188,0,0,200,205,188,0,0,0,0,0
                      };
    int map3[15][42]= {201,205,205,205,187,0,0,0,0,0,201,205,205,205,205,205,187,0,0,0,0,0,0,0,0,0,201,205,187,0,0,0,0,0,0,0,0,0,0,0,0,0,
                       186,88,0,0,186,0,0,0,0,0,186,0,0,0,0,0,186,0,0,0,0,0,0,0,0,0,186,0,186,0,0,0,0,0,0,0,0,0,0,0,0,0,
                       186,0,0,0,186,0,0,0,0,0,186,0,0,0,0,0,186,0,0,0,0,0,0,0,0,0,186,0,186,0,0,0,0,0,0,0,0,0,0,0,0,0,
                       186,0,0,0,200,205,205,205,205,205,188,0,0,0,0,0,200,205,205,205,205,205,205,205,205,205,185,0,200,205,205,205,205,205,205,205,205,205,205,205,205,187,
                       186,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,186,0,0,0,0,0,0,0,0,0,0,0,0,0,0,87,
                       186,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,201,205,205,205,205,205,205,205,205,205,185,0,201,205,205,205,205,205,205,205,205,205,205,205,205,188,
                       200,205,205,205,205,205,205,205,205,187,0,0,0,0,0,0,186,0,0,0,0,0,0,0,0,0,186,0,186,0,0,0,0,0,0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,0,0,186,0,0,0,0,0,201,188,0,0,0,0,0,0,0,0,0,186,0,186,0,0,0,0,0,0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,0,0,186,0,0,0,0,0,186,0,0,0,0,0,0,0,0,0,0,186,0,200,205,205,205,205,205,205,205,187,0,0,0,0,0,
                       201,205,205,205,205,205,205,205,205,188,0,0,0,0,0,186,0,0,0,0,0,0,0,0,0,0,186,0,0,0,0,0,0,0,0,0,186,0,0,0,0,0,
                       186,0,0,0,0,0,0,0,0,0,0,0,0,0,201,188,0,0,0,0,0,0,0,0,0,0,186,0,201,205,205,205,205,205,205,205,188,0,0,0,0,0,
                       200,205,205,205,205,205,205,205,205,205,205,187,0,0,186,0,0,0,0,0,0,0,0,0,0,0,186,0,186,0,0,0,0,0,0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,0,0,0,0,186,0,0,200,205,205,205,205,205,205,205,205,205,205,205,188,0,186,0,0,0,0,0,0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,0,0,0,0,186,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,186,0,0,0,0,0,0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,0,0,0,0,200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188,0,0,0,0,0,0,0,0,0,0,0,0,0
                      };

    Labirynt labirynt1;
    labirynt1.gracz_x = 1;
    labirynt1.gracz_y = 1;
    labirynt1.wymiar_x = 15;
    labirynt1.wymiar_y = 9;

    Labirynt labirynt2;
    labirynt2.gracz_x = 1;
    labirynt2.gracz_y = 7;
    labirynt2.wymiar_x = 26;
    labirynt2.wymiar_y = 29;

    Labirynt labirynt3;
    labirynt3.gracz_x = 1;
    labirynt3.gracz_y = 1;
    labirynt3.wymiar_x = 42;
    labirynt3.wymiar_y = 15;


    int wybor_lab;
    int wybor_menu;
    string polecenia;
    int ogranicznik;
    bool wybrany = false;
    bool wyjscie = false;
    bool zakonczono = false;

    Labirynt* lab;
    int* map;
    while(!zakonczono)
    {
        cout<< endl << "\t\t\t\t\t Symulator labiryntu 2016" << endl << endl;
        cout<<"MENU"<<endl<<endl;
        cout<<"1. Start gry"<<endl<<"2. Jak grac?"<<endl<<"3. Wyjdz z gry"<<endl<<endl;
        cout<<"> ";
        cin>> wybor_menu;

        switch(wybor_menu)
        {
        case 1:
            system("cls");
            while(!wybrany)
            {
                cout << "wybierz labirynt (1-3): " << endl;
                cin >> wybor_lab;

                system("cls");

                if(wybor_lab==1)
                {
                    lab = &labirynt1;
                    map = &**map1;
                    wybrany = true;
                }
                else if(wybor_lab==2)
                {
                    lab = &labirynt2;
                    map = &**map2;
                    wybrany = true;
                }
                else if(wybor_lab==3)
                {
                    lab = &labirynt3;
                    map = &**map3;
                    wybrany = true;
                }
                else
                    cout << "Nie ma takiego labiryntu, sprobuj wybrac inny" <<endl<<endl;
            }
            wybrany=false;
            while(!wybrany)
            {
                cout << "wybierz ogranicznik widocznosci: " << endl;
                cin >> ogranicznik;
                system("cls");
                if(ogranicznik>lab->wymiar_x)
                {
                    cout<<"Wybrano wartosc wieksza niz rozmiar labiryntu. Ustawiono maksymalny ogranicznik"<<endl;
                    wybrany=true;
                }
                else if(ogranicznik<=lab->wymiar_x)
                    wybrany=true;

                else
                    cout<<"Nieprawidlowa wartosc"<<endl;
            }

            cout << "Wpisz ? aby uzyskac pomoc"<<endl;
            do
            {
                rysuj(map, lab->wymiar_x, lab->wymiar_y, ogranicznik, lab->gracz_x, lab->gracz_y);
                cout << "Gdzie chcesz isc?" << endl;
                cin >> polecenia;
                system("cls");
                przesun(map, polecenia, lab->gracz_x, lab->gracz_y, lab->wymiar_x, wyjscie);
            }
            while(!wyjscie);

            break;
        case 2:
            instrukcje();
            system("pause");
            break;
        case 3:
            zakonczono=true;
            break;
        default:
            cout<<"Nieznane polecenie.. :("<<endl<<"sprobuj wpisac 2 by uzyskac pomoc."<<endl;
            system("pause");
        }
        system("cls");
    }
    return 0;

}

void rysuj(int *labirynt, int x, int y, int ogr, int gracz_x, int gracz_y)
{
    int ogr_x = gracz_x + ogr;
    int ogr_x2 = gracz_x - ogr;
    int ogr_y = gracz_y + ogr;
    int ogr_y2 = gracz_y - ogr;

    if(ogr>x) ogr_x=x;
    if(ogr_x2<0) ogr_x2=0;
    if(ogr_y>y) ogr_y=y;
    if(ogr_y2<0) ogr_y2=0;

    for(int i=ogr_y2; i<ogr_y; i++)
    {
        for(int j=ogr_x2; j<ogr_x; j++)
            cout<< static_cast<char>((labirynt[i*x+j]));
        cout<<endl;
    }
}

void przesun(int *labirynt, string polecenia, int &x, int &y, int wiersz, bool &wyjscie)
{
    int licznik = 0;
    for(int i=0; i<polecenia.length(); i++)
    {
        if(polecenia[i]==101  && labirynt[y*wiersz+x+1]==0) //e
        {
            labirynt[y*wiersz+x+1] = 88;
            labirynt[y*wiersz+x] = 0;
            x++;
            licznik++;
        }
        else if(polecenia[i]==101  && labirynt[y*wiersz+x+1]==87)
        {
            cout << "Dotarles do wyjscia!" << endl;
            wyjscie=true;
            licznik++;
            break;
        }
        else if(polecenia[i]==119  && labirynt[y*wiersz+x-1]==0) //w
        {
            labirynt[y*wiersz+x-1] = 88;
            labirynt[y*wiersz+x] = 0;
            x--;
            licznik++;
        }
        else if(polecenia[i]==119  && labirynt[y*wiersz+x-1]==87)
        {
            cout << "Dotarles do wyjscia!" << endl;
            wyjscie=true;
            licznik++;
            break;
        }
        else if(polecenia[i]==110  && labirynt[y*wiersz+x-wiersz]==0) //n
        {
            labirynt[y*wiersz+x-wiersz] = 88;
            labirynt[y*wiersz+x] = 0;
            y--;
            licznik++;
        }
        else if(polecenia[i]==110  && labirynt[y*wiersz+x-wiersz]==87)
        {
            cout << "Dotarles do wyjscia!" << endl;
            wyjscie=true;
            licznik++;
            break;
        }
        else if(polecenia[i]==115  && labirynt[y*wiersz+x+wiersz]==0) //s
        {
            labirynt[y*wiersz+x+wiersz] = 88;
            labirynt[y*wiersz+x] = 0;
            y++;
            licznik++;
        }
        else if(polecenia[i]==115  && labirynt[y*wiersz+x+wiersz]==87)
        {
            cout << "Dotarles do wyjscia!" << endl;
            wyjscie=true;
            licznik++;
            break;
        }
        else if(polecenia[0]==63)
            instrukcje();
        else if(polecenia[0]==33)
            wyjscie=true;
        else
        {
            cout << "Nie mozesz isc w kierunku: " << polecenia[i] << endl;;
            cout << "Blad w poleceniu nr: " << i+1 <<endl;
            break;
        }
    }
    cout << "Liczba poprawnie wykonanych polecen: " << licznik << endl;
}

void instrukcje()
{
    cout<<endl<<"Gra polega na znalezieniu wyjscia z labiryntu."<<endl
    <<"Gracz oznaczony znakiem X porusza sie po calej planszy za pomoca wpisywanych komend."<<endl
    <<"Utrudnieniem jest ogranicznik widocznosci, ktory mozna dowolnie zdefiniowac na poczatku gry."<<endl<<endl;
    cout<<endl<<"Do poruszania sie po labirynie uzywaj pierwszych liter slow kierunkow geograficznych w jezyku angielskim."<<endl
        <<"n - north(polnoc)"<<endl<<"e - east(wschod)"<<endl<<"s - south(poludnie)"<<endl<<"w - west(zachod)"<<endl;
    cout<<endl<<"Aby wyswietlic pomoc - wpisz znak: ?"<<endl<<"Aby zakonczyc gre - wpisz znak: !"<<endl;
}
