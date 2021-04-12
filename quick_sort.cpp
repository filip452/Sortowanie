#include <algorithm>

template<class szab>
void quick_sort(szab *tab,int lewy,int prawy)
{
    if(prawy<=lewy) return;                      //wskazniki sie przecinaja

    int nowy_lewy=lewy-1,nowy_prawy=prawy+1;
    int el_os=tab[(lewy+prawy)/2];               //ustaw element osiowy na œrodku tablicy

    while(el_os>tab[++nowy_lewy]);           //znajdz pierwszy element do zamiany
    while(el_os<tab[--nowy_prawy]);          //znajdz drugi elemnt do zamiany

    while(nowy_lewy<=nowy_prawy)
    {
        std::swap(tab[nowy_lewy],tab[nowy_prawy]);   //sortuj do przeciecia sie wskaznikow

        while(el_os>tab[++nowy_lewy]);
        while(el_os<tab[--nowy_prawy]);
    }

    if(nowy_prawy>lewy);
        quick_sort<szab>(tab,lewy,nowy_prawy); //sortuj pierwsza podtablice
    if(nowy_lewy<prawy);
        quick_sort<szab>(tab,nowy_lewy,prawy); //sortuj druga podtablice
}
