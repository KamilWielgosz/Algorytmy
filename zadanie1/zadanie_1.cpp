#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;
void posortuj(vector<int> &vect);
void funkcja_f(int tab[10][10], int wyniki[]);
int funkcja_F(int tab[]);
int main(){


	ifstream nie_posort;

	nie_posort.open("nie_posort.txt");

	if(!nie_posort.good()){
		cout<<"Blad podczas otwierania pliku nie_posort\n";
		getchar();
		return EXIT_FAILURE;
	}

	string liczba;
	vector <int> macierz_sort;
	int wynik = 0;
	int minus = 1;

	while(!nie_posort.eof()){

		nie_posort>>liczba;
		for(int i = 0; i < liczba.size(); i++){

			if(liczba[i] == '-'){
				minus = -1;
				i++;
			}

			wynik = wynik*10 + (liczba[i] - '0');

		}
		macierz_sort.push_back(minus*wynik);
		wynik = 0;
		minus = 1;
	}
	nie_posort.close();


	posortuj(macierz_sort);


	int tab[10][10];
	int ik = 0;
	for(int k = 0; k<10; k++){

		for(int j = 0; j < 10; j++){
			tab[k][j] = macierz_sort.at(ik++);
		}
	}
	

	int wyniki[10] = {0};
	ofstream posort;

	posort.open("posort.txt");

	if(!posort.good()){
		cout<<"Blad podczas otwierania pliku posort.txt\n";
		getchar();
		return EXIT_FAILURE;
	}

	for(int i = 0; i < 10; i++){

		for(int k = 0; k < 10; k++){
			if(tab[i][k] > 0) {

				if((tab[i][k] / 10) > 0){
					posort<<tab[i][k]<<"  ";
				} else {
					posort<<tab[i][k]<<"   ";
				}

			} else {

				if((tab[i][k] / 10) < 0){
					posort<<tab[i][k]<<" ";
				} else {
					posort<<tab[i][k]<<"  ";
				}
			}
		}

		posort<<"\n";
	}

	funkcja_f(tab,wyniki);

	posort<<"\nWartosci funkcji f(a) to:\n";

	for(int i = 0; wyniki[i] != 0; i++){
		posort<<wyniki[i]<<" ";
	}


	posort<<"\nWartosc funkcji F(f(a)) to: \n";

	posort<<funkcja_F(wyniki);

	posort<<"\Indeksy oraz wartoœci elementów z cyfr¹ 3 na koñcu\n";
    for(int i = 0; i < 10; i++){

		for(int j = 0; j < 10; j++){
			if((tab[i][j] % 10) == 3){
				posort<<"tablica["<<i<<"]["<<j<<"] = "<<tab[i][j]<<"\n";
			}
		}
	}

	posort.close();




	cout<<"\nProgram zostal wykonany pomyslnie";
	getchar();
	return EXIT_SUCCESS;;

}

void posortuj(vector<int> &vect){

	int pom, j;

	for(int i = 1; i < vect.size(); i++){

		pom = vect.at(i);
		j = i-1;

		while(j>=0 && vect.at(j) < pom){

			vect.at(j+1) = vect.at(j);
			--j;
		}

		vect.at(j+1) = pom;
	}
}

void funkcja_f(int tab[10][10], int wyniki[]){

	int najmniejsza = 0;

	for(int i = 1; i < 10; i++){

		najmniejsza = tab[i][0];

		for(int j = 1; j < i; j++){
			if(tab[i][j] < najmniejsza){
				najmniejsza = tab[i][j];
			}
		}


		wyniki[i-1] = najmniejsza;

	}
}

int funkcja_F(int tab[]){
	int dodaw = 0;
	cout<<dodaw;

	for(int i = 0; i < 10; i++){
		dodaw = dodaw + tab[i];
	}

	return dodaw;
}