//*************************************************
// KOLOKWIUM PRAKTYCZNE: 1
// DATA: 3.12.2015
// IMIÊ NAZWISKO:  Kamil Wielgosz
// GRUPA LABORATORYJNA:          L1
// ZESTAW ZADAÑ: 1B
//*************************************************

#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

/*
//Zadanie 1 - nie pamietam ;/
const int N = 10;
int dane[N];



void init1(){ //inicjalizacja tablicy do zadania 1

 for(int i=0; i<N;i++)   {
    dane[i]=rand()%10;
 }

}
void sortuj(){

}
void drukuj(){

}
void zadanie1(){
    init1(); drukuj(); sortuj(); drukuj();
    }

*/





//Zadanie 2
struct element{
     char wart;
     element *next;
 };
element *head=NULL;


void dodaj(char z){

element *n = new element;

n->wart = z;
n->next = head;

head = n;

}


void drukujL(){

    element *n;

    n = head;

   while(n != NULL){

    cout<<n->wart<<"\n";

    n = n->next;
   }


}



void usun(){

   element *n;
   element *pom;

   n = head;

   while(n != NULL){

      pom = head;

      head = n->next;

      n = n->next;

      delete pom;
   }


}




void zadanie2(){

cout<<"\nWpisuje dane do listy\n";
dodaj('d'); dodaj('j'); dodaj('l');
dodaj('h'); dodaj('a'); dodaj('a'); dodaj('k'); dodaj('k');

cout<<"\nDrukuje elementy listy\n";
drukujL();

cout<<"\nUsuwam elementy z listy\n";

usun();

cout<<"\nDrukuje elementy listy\n";

drukujL();
              }


int main(int argc, char *argv[]){

// cout<<"Zadanie 1"<<endl;    zadanie1();
 cout<<"Zadanie 2"<<endl;    zadanie2();



 system("PAUSE");
 return EXIT_SUCCESS;
}
