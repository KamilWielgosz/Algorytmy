#include <iostream>
#include <cstdlib>

using namespace std;

const int N = 12;
int kopiec[N]={15,12,11,10,61,15,5,3,7,2,9}; //przyk³adowy kopiec

void zanurzanie(int i){
    int wiekszy;
    int l = 2*i+1;
    int r = 2*i+2;
    if((l<=N) && (kopiec[l]>kopiec[i])) wiekszy = l;
    else wiekszy = i;
    if((r<=N) && (kopiec[r]>kopiec[wiekszy])) wiekszy = r;
    if(wiekszy != i) {
        int temp = kopiec[i];
        kopiec[i] = kopiec[wiekszy];
        kopiec[wiekszy] = temp;
        zanurzanie(wiekszy);
    }
}

void wynurzanie(int i){
    if(i>0) {
        int ojciec;
        if(i%2 == 0) ojciec = i/2 -1;
        else ojciec = i/2;
        if(kopiec[i]>kopiec[ojciec]) {
            int temp = kopiec[i];
            kopiec[i] = kopiec[ojciec];
            kopiec[ojciec] = temp;
            wynurzanie(ojciec);
        }
    }
}
int n =0;
void wsadzanie(int x) {
    if(n < N) {
        kopiec[n] = x;
        wynurzanie(n);
        n = n+1;
    }
}

int wyciaganie() {
    if(n==0) cout << "kopiec pusty" << endl;
    else {
        int temp = kopiec[0];
        kopiec[0] = kopiec[n];
        kopiec[n] = temp;
        n = n-1;
        zanurzanie(0);
        return kopiec[n];
    }
}

void drukuj() {
    for(int i=0;i<N;i++) {
        cout << kopiec[i] << " ";
    }
    cout << endl;
}

int main(){
int i = 4; // nale¿y zmieniæ wartoœæ wybranego wêz³a, tak aby w³asnoœæ kopca nie by³a zachowana
drukuj();
wsadzanie(70);
//zanurzanie(i); // wywo³anie dla wêz³a naruszaj¹cegow³asnoœæ kopca
wynurzanie(i);
drukuj();
int a = wyciaganie();
cout << a;
system("PAUSE");
}
