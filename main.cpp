#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <cmath>
#include <chrono>
#include "quick_sort.cpp"
#include "scalanie.cpp"
#include "kopcowanie.cpp"
#include "czy_sort.cpp"

using namespace std;

int main(){

    srand(time(NULL));

    int *tab;
    int rozmiar;
    float procent;
    bool czy_sort=1;

    int ROZ[5]={10000,50000,100000,500000,1000000};
    float PROC[8]={0,0.25,0.5,0.75,0.95,0.99,0.997,1};

    ofstream czasy("Qsort.txt");
    //ofstream czasy("Ssort.txt");
    //ofstream czasy("Ksort.txt");
    for(int P=0;P<8;P++)
    {
        procent=PROC[P];
        czasy<<"Czas sortowania tablicy posortowanej w "<<procent*100<<"%:\n";

        for(int R=0;R<5;R++)
        {
            rozmiar=ROZ[R];
            tab=new int[rozmiar];
            czasy<<"  O wymiarach "<<rozmiar<<":\n";

            float czas=0;

            for(int j=0;j<100;j++)                          //sortuje 100 tablic
            {
                if(procent==0)
                    for(int i=0;i<rozmiar;i++)              //losuje wszystkie elementy
                    {
                        tab[i]=(rand()%rozmiar)+1;
                    }
                else
                    if(procent==1)                           //sortuje elementy malejaco
                        for(int i=0;i<rozmiar;i++)
                    {
                        tab[i]=rozmiar-i;
                    }
                    else
                    {
                        for(int i=0;i<procent*rozmiar;i++)   //sortuje n elemntow
                        {
                            tab[i]=i;
                        }
                        for(int i=procent*rozmiar;i<rozmiar;i++)    //losuje pozostale elementy
                        {
                            tab[i]=(rand()%rozmiar)+1+procent*100;
                        }
                    }

                auto t_start=std::chrono::high_resolution_clock::now();              //uruchom zegar
                quick_sort(tab,0,rozmiar-1);
                //scalSort(tab,0,rozmiar-1);
                //kopcowanie(tab,rozmiar);
                auto t_koniec=std::chrono::high_resolution_clock::now();             //zatrzymaj zegar
                czas+=std::chrono::duration<double,std::milli>(t_koniec-t_start).count();
                if(!sort(tab,rozmiar))
                    czasy<<"Blad!\nNie posortowana tablica.\n";
            }

            delete[] tab;
            czasy<<"  "<<czas/100<<"s\n";
        }
    }
    czasy.close();

    return 0;
}
