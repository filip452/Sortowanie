#include <algorithm>

template<class szab>
void sortuj(szab *tab,int rozmiar, int i)
{
    int max=i;
    int lewy=2*i+1;
    int prawy=2*i+2;

    if(lewy<rozmiar && tab[lewy]>tab[max])      //sprawdza czy lewy jest maksymalny
        max=lewy;

    if(prawy<rozmiar && tab[prawy]>tab[max])    //sprawdza czy prawy jest maksymalny
        max=prawy;

    if(max!=i)                                  //jeœli i maksymalny sie amienil
    {
        std::swap(tab[i],tab[max]);             //zamien go

        sortuj(tab,rozmiar,max);                //sortuj jeszcze raz
    }
}

template<class szab>
void kopcowanie(szab* tab,int rozmiar)
{
    for(int i=rozmiar/2-1;i>=0;i--)     //buduje kopiec
        sortuj(tab,rozmiar,i);

    for(int i=rozmiar-1;i>0;i--)        //rozbiera kopiec
    {
        std::swap(tab[0],tab[i]);

        sortuj(tab,i,0);
    }
}
