//Zrodla: https://binarnie.pl/sortowanie-przez-scalanie/
template<class szab>
void scal(szab* tab, int lewy, int srodek, int prawy)
{
	int lewaRoz=srodek-lewy+1;
	int prawaRoz=prawy-srodek;

	int* lewaTab=new int[lewaRoz];        //stworz tablice pomocnicze
	int* prawaTab=new int[prawaRoz];

	for(int i=0;i<lewaRoz;i++)         //przekopiuj dane do tablic pomocniczych
		lewaTab[i]=tab[lewy+i];
	for(int i=0;i<prawaRoz;i++)
		prawaTab[i]=tab[srodek+1+i];

	int lewyI=0,prawyI=0,obecny;

	for(obecny=lewy;lewyI<lewaRoz && prawyI<prawaRoz;obecny++)  //scalanie tablic
	{
		if (lewaTab[lewyI]<=prawaTab[prawyI])
			tab[obecny]=lewaTab[lewyI++];
		else
			tab[obecny]=prawaTab[prawyI++];
	}

	while(lewyI<lewaRoz)                    //dolacza pozostale elemnty z pierwszej tablicy
		tab[obecny++]=lewaTab[lewyI++];

	while(prawyI<prawaRoz)                  //dolacza pozostale elemnty z drugiej tablicy
		tab[obecny++]=prawaTab[prawyI++];

	delete[] lewaTab;
	delete[] prawaTab;
}

template<class szab>
void scalSort(szab* tab, int lewy, int prawy) {
	if(prawy == lewy) return;

		int srodek=(lewy+prawy)/2;
		scalSort<szab>(tab,lewy,srodek);         //sortuj pierwsza podtablice
		scalSort<szab>(tab,srodek+1,prawy);      //sortuj druga podtablice
		scal(tab,lewy,srodek,prawy);        //scal obie podtablice
}
