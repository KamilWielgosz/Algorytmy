#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
void sortuj(vector<int> &vec);
int funkcja_f(int tablica[10][10], int zbiornik[]);
int funkcja_F(int *wsk);
int main(){

	ifstream czyt_macierz;

	czyt_macierz.open("nieposortowane.txt");

	if(!czyt_macierz.good()){
		cout<<"Blad podczas proby otwarcia pliku nieposortowane";
	    getchar();
		return EXIT_FAILURE;
	}


	string element;
	vector<int> wektor_liczb;
	int wynik = 0;
	int znak = 0;
	int minus = 1;
	while(!czyt_macierz.eof()){

		czyt_macierz>>element;


		 if(element[0] == '-'){
			 znak = 1;
			 minus = -1;
		 } else {
			 znak = 0;
		 }
		for(znak; znak < element.size(); znak++){
			wynik = wynik*10 + (element[znak] - '0');
		}

		wektor_liczb.push_back(minus*wynik);
		wynik = 0;
		znak = 0;
		minus = 1;
	}

	czyt_macierz.close();

	sortuj(wektor_liczb);



	ofstream posort;

	posort.open("posort.txt");

	if(!posort.good()){
		cout<<"Blad podczas otwierania pliku posort\n";
		return EXIT_SUCCESS;
	}

	int tab[10][10];
	int elem = 0;

	   for(int i = 0; i < 10; i++){
		   for(int j = 0; j < 10; j++){
			   tab[i][j] = wektor_liczb.at(elem++);
			   posort<<tab[i][j]<<" ";
		   }
		  
		   posort<<"\n";
	   }
    
	   posort<<"\n";
	   int zbiornik[9];
	   posort<<"\nWartosc funkcji F: ";
	   posort<<funkcja_f(tab, zbiornik);
	   
	   posort<<"\nWartosc funkcji f: \n";

	   for(int i = 0; i < 9; i++){
		   posort<<zbiornik[i]<<" ";
	   }

	   posort<<"\nindeksy oraz wartoœci elementów z cyframi 33 na koñcu\n";
	   for(int i = 0; i < wektor_liczb.size(); i++){

		   if((wektor_liczb.at(i) % 100) == 33){
			   posort<<"tablica["<<i<<"]"<<" = "<< wektor_liczb.at(i)<<"\n";
		   }

	   }

    posort.close();
	cout<<"Program zostal wykonany pomyslnie";
	getchar();
	return EXIT_SUCCESS;
}



void sortuj(vector<int> &vec){

	int p = 1;
  for(int j = vec.size() - 1; j > 0; j--)
  {
    p = 1;
    for(int i = 0; i < j; i++)
      if(vec.at(i) > vec.at(i+1))
      {
        swap(vec.at(i), vec.at(i+1));
        p = 0;
      }
    if(p) break;
  }
}


int funkcja_f(int tablica[10][10], int zbiornik[]){

        int tab[10];
        int * wsk_tab;

        int suma = 0;

        for (int i = 1; i < 10; i++){

                for (int j = 0; j < i; j++){
                        suma = suma + tablica[i][j];
                }

                tab[i - 1] = suma;
				zbiornik[i-1] = tab[i-1];
                suma = 0;
        }
		wsk_tab = &tab[0];
        return funkcja_F(wsk_tab);
}

int funkcja_F(int *wska){
        int ilosc = 0;

        for (int i = 0; i < 9; i++){
                ilosc = ilosc + *(wska + i);
        }

        return ilosc;
}

