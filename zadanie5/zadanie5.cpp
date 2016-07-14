#include <iostream>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <ctime>

using namespace std;

int d[10];

void sortowanie_szybkie(int lewy, int prawy)
{
  int i,j,piwot;

  i = (lewy + prawy) / 2;
  piwot = d[i]; d[i] = d[prawy];
  for(j = i = lewy; i < prawy; i++)
  if(d[i] > piwot)
  {
    swap(d[i], d[j]);
    j++;
  }
  d[prawy] = d[j]; d[j] = piwot;
  if(lewy < j - 1)  sortowanie_szybkie(lewy, j - 1);
  if(j + 1 < prawy) sortowanie_szybkie(j + 1, prawy);
}

int main(){
	clock_t start = clock();
	int tablica[10][10];

	srand(time(NULL));

	for(int i = 0; i < 10; i++){

	    for(int j = 0; j < 10; j++){
			tablica[i][j] = rand() % 100;
		}

	}


	ofstream plik_zad_5;

	plik_zad_5.open("plik_zad_5.txt");

	if(!plik_zad_5.good()){
		cout<<"Blad przy probie otwarcia pliku plik_zad_5.txt\n";
		getchar();
		return EXIT_FAILURE;
	}

	    for(int i = 0; i < 10; i++){

			for(int j = 0; j < 10; j++){
				plik_zad_5<<setw(5)<<tablica[i][j];
			}
			plik_zad_5<<"\n";
		}

	plik_zad_5.close();


	for(int i = 0; i < 10; i++){

		for(int j = 0; j < 10; j++){
			d[j] = tablica[j][i];
		}

		sortowanie_szybkie(0, 9);

		for(int k = 0; k < 10; k++){
			tablica[k][i] = d[k];
		}

	}

	fstream plik_zad_5_zapis;

	plik_zad_5_zapis.open("plik_zad_5.txt", std::ios::app);

	if(!plik_zad_5_zapis.good()){
		cout<<"Blad podczas drugiego zapisu do pliku \n";
		getchar();
		return EXIT_FAILURE;
	}

	plik_zad_5_zapis<<"\n\n\n\n";
	      for(int i = 0; i < 10; i++){

			  for(int j = 0; j < 10; j++){
				  plik_zad_5_zapis<<setw(5)<<tablica[i][j];
			  }
			  plik_zad_5_zapis<<"\n";
		  }
	

	plik_zad_5_zapis.close();
	printf( "Czas wykonywania: %lu ms\n", clock() - start );
    cout<<"Program zostal wykonany pomyslnie";
	getchar();
	return EXIT_SUCCESS;
}