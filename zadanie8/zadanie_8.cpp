// list::cbegin/cend
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void przeszukaj(int startowy, vector<int> &gotowy_graf,vector<int> *graf, queue<int> kolejka);

int main ()
{
	int macierz_sasiedztwa[12][12] = { 
		                              {0,0,1,0,0,0,0,1,1,0,1,0},
									  {1,0,1,0,0,0,1,0,0,0,0,0},
									  {0,1,0,1,0,0,0,1,0,0,0,1},
									  {0,0,1,0,0,1,0,0,0,1,0,0},
									  {0,0,1,0,0,0,1,0,0,0,0,0},
									  {1,0,0,0,1,0,0,0,1,0,0,1},
									  {0,1,0,1,0,0,0,0,0,0,1,0},
									  {0,0,1,0,1,0,0,0,0,1,0,0},
									  {1,1,0,0,0,1,0,0,0,1,0,1},
									  {0,1,0,1,0,0,1,0,0,0,1,0},
									  {0,0,1,0,1,0,1,1,0,0,0,1},
									  {0,0,1,0,1,0,0,0,0,1,0,0}
	                                 };




  vector<int> * graf;

  queue<int> kolejka;

  graf = new vector<int> [12];

     for(int i = 0; i < 12; i++){
		 for(int j = 0; j < 12; j++){
			 if(macierz_sasiedztwa[i][j] == 1){
               graf[i].push_back(j);              // Wskazujemy dla kolejnych wierzcho³ków graf[i], i nal¿y 0...12 wierzcho³ki wchodz¹ce do danego wierzcho³ka i
			 }                                    // np. dla wierzcho³ka 0 (graf[0]) wektor bedzie zawiera³ wierzcholki 2,7,8,10
		 }
		
	 }
 

  vector<int> gotowy_graf;

  int wierzcholek_startowy = 0;   // wierzcholek od ktorego zaczynamy


    kolejka.push(wierzcholek_startowy);
	cout<<"Dodano do kolejki: "<<kolejka.back();
	cout<<"\n";
	gotowy_graf.push_back(wierzcholek_startowy);
    przeszukaj(wierzcholek_startowy,gotowy_graf,graf, kolejka);

	cout<<"\nWynik programu: \n";
  	  for(vector<int>::iterator ik = gotowy_graf.begin(); ik != gotowy_graf.end(); ik++){
		  cout<<*ik<<" ";
	  }

  getchar();
  return 0;
}


void przeszukaj(int startowy, vector<int> &gotowy_graf,vector<int> *graf, queue<int> kolejka){
	
	static int blad = 0;
 
  for(vector<int>::iterator it = graf[startowy].begin(); it != graf[startowy].end(); it++){

	  for(vector<int>::iterator ik = gotowy_graf.begin(); ik != gotowy_graf.end(); ik++){
		  if(*ik == *it){
			  blad = 1;
		  }
	  }

	  if(blad == 0){
	  kolejka.push(*it);
	  cout<<"Dodano do kolejki: "<<kolejka.back();
	  cout<<"\n";
	  gotowy_graf.push_back(*it);
	  }
	blad = 0;
  }

  cout<<"Usunieto z kolejki: "<<kolejka.front();
  cout<<"\n";
  kolejka.pop();
                             
    if(!kolejka.empty()){
       przeszukaj(kolejka.front(), gotowy_graf, graf, kolejka);
    }
  

}