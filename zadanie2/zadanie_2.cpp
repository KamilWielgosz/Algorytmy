#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void posortuj(vector<int> &vect);
void funkcja_f(int tab[10][10],int wyniki[]);
int funkcja_F(int tabl[]);
int main(){

	ifstream macierz_2;

	vector<int> vec_nieposort;
	string liczba_str;
	int liczba_dec = 0;

	macierz_2.open("macierz_2.txt");

	if(!macierz_2.good()){

		cout<<"Blad podczas proby otwarcia pliku macierz_2.txt\n";
		getchar();
		return EXIT_FAILURE;
	}

	while(!macierz_2.eof()){
		macierz_2>>liczba_str;

		for(int i = 0; i < liczba_str.size(); i++){

			liczba_dec = liczba_dec*10 + (liczba_str[i] - '0');
		}
		vec_nieposort.push_back(liczba_dec);

		liczba_dec = 0;
	}
	macierz_2.close();

	posortuj(vec_nieposort);


	int tab[10][10];
	int k = 0;
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			tab[i][j] = vec_nieposort.at(k++);
		}
	}

	int wyniki[10] = {10};

	funkcja_f(tab, wyniki);

	ofstream posort_2;

	posort_2.open("posort_2.txt");

	if(!posort_2.good()){
		cout<<"Blad podczas proby otwarcia pliku posort_2.txt\n";
		getchar();
		return EXIT_FAILURE;
	}

	   for(int i = 0; i < 10; i++){

		   for(int j = 0; j < 9; j++){
			   if((tab[i][j]/10) == 0){
			   posort_2<<tab[i][j]<<"   ";
			   } else if((tab[i][j]/10) < 10){
               posort_2<<tab[i][j]<<"  ";
			   } else if((tab[i][j]/10) >= 10){
			   posort_2<<tab[i][j]<<" ";
			   }
		   }
		   posort_2<<tab[i][9];
		   posort_2<<"\n";
	   }
	  
	   posort_2<<"Wartosc funkcji f(a) (suma elementów ka¿dego wiersza pod diagonal¹ dodatkow¹) to:\n";
	   for(int i = 0; wyniki[i] != 0; i++){
		   posort_2<<wyniki[i]<<" ";
	   }

	   posort_2<<"\nWartosc funkcji F(f(a)): "<<funkcja_F(wyniki)<<"\n";

       posort_2<<"Indeksy oraz wartoœci elementów z krotnoci¹ 11:\n";

	      for(int i = 0; i < 10; i++){

			  for(int j = 0; j < 10; j++){
				  if((tab[i][j] % 11) == 0){
					  posort_2<<"tablica["<<i<<"]["<<j<<"] = "<<tab[i][j]<<"\n";
				  }
			  }

		  }



	posort_2.close();

	cout<<"Program zostal wykonany pomyslnie\n";
	getchar();
	return EXIT_SUCCESS;
}


void posortuj(vector<int> &vect){

	int pmin = 0;
	int i = 0;
	int j = 0;
	 for(j = 0; j < vect.size() - 1; j++)
     {
    pmin = j;
       for(i = j + 1; i < vect.size(); i++)
	   {
         if(vect.at(i)< vect.at(pmin)){			 
			 pmin = i;
		 }
      swap(vect.at(pmin), vect.at(j));
      }
	 }
}




void funkcja_f(int tab[10][10],int wyniki[]){

	int suma = 0;

	for(int i = 1; i < 10; i++){

		for(int j = 0; j < i; j++){			
			suma = suma + tab[i][j];
		}

		wyniki[i-1] = suma;
		suma = 0;
	}
}

int funkcja_F(int tabl[]){
	int dodaj = 0;
	for(int i = 0; i < 10; i++){
		dodaj = dodaj + tabl[i];
	}
	return dodaj;
}