template<class szab>
bool sort(szab* tab,int rozmiar)
{
    for(int i=1;i<rozmiar;i++)
        if(tab[i]<tab[i-1])
            return 0;
    return 1;
}
