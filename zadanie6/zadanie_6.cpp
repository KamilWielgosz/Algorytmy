#include <iostream>
#include <ctime>

using namespace std;

	int const n = 5;
	int P[] = {0, 1, 2, 3, 4, 5};

void reverse(int m){ //odwroceenie ciagu P[0],..,P[m] , tablica P jest globalna

	int i = 1;
	int j = m;
	  while(i < j){
		  swap(P[i], P[j]);
		  i = i + 1;
		  j = j - 1;
	  }

} // koniec reverse

void antylex(int m){ // tablica P jest globalna

	if(m == 1){
		for(int k = 1; k <= n; k++){
			cout<<P[k]<<" ";
		}
		cout<<endl;
	} else {
		for(int i = 1; i <= m; i++){
			antylex(m-1);
			if(i < m){
				swap(P[i], P[m]);
				reverse(m-1);
			}
		}
	}	
} // koniec antylex

int main(){
	clock_t start = clock();

		antylex(n);





	cout<<"Program zosta³ wykonany pomyslnie\n";
	cout<<"Czas wykonywanie programu: "<<clock() - start<<" ms";
	getchar();
	return EXIT_SUCCESS;
}