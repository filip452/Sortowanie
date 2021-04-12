//Zrodla: https://eduinf.waw.pl/inf/alg/003_sort/0017.php
#include <algorithm>

template<class szab>
void kopcuj(szab *tab,int rozmiar, int i)
{
    int max=i;
    int lewy=2*i+1;
    int prawy=2*i+2;

    if(lewy<rozmiar && tab[lewy]>tab[max])
        max=lewy;

    if(prawy<rozmiar && tab[prawy]>tab[max])
        max=prawy;

    if(max!=i)
    {
        std::swap(tab[i],tab[max]);

        kopcuj(tab,rozmiar,max);
    }
}

template<class szab>
void kopcowanie(szab* tab,int rozmiar)
{
    for(int i=rozmiar/2-1;i>=0;i--)     //buduje kopiec
        kopcuj(tab,rozmiar,i);

    for(int i=rozmiar-1;i>0;i--)
    {
        std::swap(tab[0],tab[i]);

        kopcuj(tab,i,0);
    }
}
