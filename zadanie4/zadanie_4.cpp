#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
void sortuj(vector<int> &wek);
int *funkcja_f(int tab[10][10], int tab_wynik[9]);
int funkcja_F(int *wsk);
int main(){

	ifstream macierz_nie;

	macierz_nie.open("macierz_nie.txt");

	if(!macierz_nie.good()){
		cout<<"Blad przy probie otwarcia pliku macierz_nie.txt\n";
		getchar();
		return EXIT_FAILURE;
	}

	vector<int> wek_jed;
	string element;
	int liczba_kon = 0;
	int minus = 1;
	int iter = 0;
	while(!macierz_nie.eof()){
		macierz_nie>>element;

		   if(element[0] == '-'){
			   iter++;
			   minus = -1;
		   }
		   
		   for(iter; iter < element.size(); iter++){
			   liczba_kon = liczba_kon * 10 + (element[iter] - '0');
		   }
		   iter = 0;

		   wek_jed.push_back(liczba_kon*minus);
		   liczba_kon = 0;
		   minus = 1;
	} 

	macierz_nie.close();

	sortuj(wek_jed);

	int tab[10][10];
	int el_wek = 0;
	int tab_wyniki[9];

	int *wsk_tab_wyniki;

	wsk_tab_wyniki = &tab_wyniki[0];

	ofstream posort;

	posort.open("posort.txt");

	if(!posort.good()){
		cout<<"Blad podczas proby otwarcia pliku posort.txt\n";
		getchar();
		return EXIT_FAILURE;
	}

	 for(int i = 0; i < 10; i++){
		  for(int j = 0; j < 10; j++){
			  tab[i][j] = wek_jed.at(el_wek++);
			  posort<<tab[i][j]<<" ";
		  }
		  posort<<"\n";
	  }

	 posort<<"\nfi(aij) – iloczyn elementów ka¿dego wiersza pod diagonal¹ dodatkow¹: \n";

	 funkcja_f(tab,wsk_tab_wyniki);

	 for(int i = 0; i < 9; i++){
		 posort<<tab_wyniki[i]<<" ";
	 }
	 posort<<"\n\nF(fi(aij))=sumafi(aij)\n";
	 posort<<funkcja_F(funkcja_f(tab,wsk_tab_wyniki))<<"\n";


	 posort<<"\nKolumna 4 przedstawiona w systemie 7-kowym\n";

	 vector<int> wek_buf;
	 int literka = 0;
	 int znak_minus = 1;
	 for(int i = 0; i < 10; i++){
		 literka = tab[i][3];

		 if(literka < 0){
			 literka = literka*(-1);
			 znak_minus = 1;
		 } else {
			 znak_minus = 0;
		 }

		 while(literka != 0){
			 wek_buf.push_back(literka%7);
			 literka = literka / 7;
		 }

		 posort<<"tablica[3]["<<i<<"] = ";

		 if(znak_minus == 1){
			 posort<<"1";
		 } else {
			 posort<<"0";
		 }

		 for(int j = wek_buf.size() - 1; j >= 0; j--){
			 posort<<wek_buf.at(j);
		 }
		 posort<<"\n";
		 wek_buf.erase(wek_buf.begin(), wek_buf.end());

		 literka = 0;
	 }

	 float zmien_float = 2.552;

	 posort<<"\n";
	 posort<<zmien_float;

	posort.close();

	cout<<"Program zostal wykonany pomyslnie";
	getchar();
	return EXIT_SUCCESS;
}


void sortuj(vector<int> &wek){
	int h,j,i,x;
	
  for(h = 1; h < wek.size(); h = 3 * h + 1);
  h /= 9;
  if(!h) h++; // istotne dla ma³ych N, dla wiêkszych mo¿na pomin¹æ!

// Sortujemy

  while(h)
  {
    for(j = wek.size() - h - 1; j >= 0; j--)
    {
      x = wek.at(j);
      i = j + h;
      while((i < wek.size()) && (x > wek.at(i)))
      {
        wek.at(i - h) = wek.at(i);
        i += h;
      }
      wek.at(i - h) = x;
    }
    h /= 3;
  }
} // koniec funkcji sortuj

int *funkcja_f(int tab[10][10], int *wsk_wynik){

	      int iloczyn = 1;

        for (int i = 1; i < 10; i++){

                for (int j = 0; j < i; j++){
                        iloczyn = iloczyn*tab[i][j];
                }
                wsk_wynik[i - 1] = iloczyn;
                iloczyn = 1;
        }


		return wsk_wynik;
}

int funkcja_F(int *wsk){

	int suma = 0;
	
	for(int i = 0; i < 9; i++){
		suma = suma+ *(wsk+i);
	}

	return suma;
}