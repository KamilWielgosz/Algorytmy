#include <iostream>
#include <queue>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

queue<int> q;

const int N = 8;
int graf[N][N] = { {0,1,0,0,0,0,0,0},{0,0,1,0,1,1,0,0},{0,0,0,1,0,0,1,0},{0,0,1,0,0,0,0,1},
                 {1,0,0,0,0,1,0,0},{0,0,0,0,0,0,1,0},{0,0,0,0,0,1,0,1},{0,0,0,0,0,0,0,1} };

/*
struct element{
  int wartosc;
  element *next;
};
element *head[N];
*/
/*void dodaj(int w)
{
    if(head[i] == NULL) {
        element *n = new element;
        n->wartosc = w;
        n->next = NULL;
        head = n;
    }
    else
        if(head->wartosc > w) {
            element *n = new element;
            n->wartosc = w;
            n->next=head;
            head = n;
        }
        else {
            element *p;
            element *k;
            element *n = new element;
            p = head;
            k = head->next;
            n->wartosc = w;
            while ((k!=NULL) && (w > k->wartosc)) {
                p = k;
                k = k->next;
            }
            n->next = k;
            p->next = n;
        }
}
*/
/*void change() {
  for(int i=0;i<N;i++) {
    for(int j=0;j>N;j++)
        if(graf[i][j] == 1) {
            head[i] = dodaj(j)
        }
  }
}
*/
/*
void BFS_list(int s) {
    q.push(s);
    while(!q.empty()) {
        int p = q.front();
        q.pop();
        if(odwiedzony[p] == 0) {
            odwiedzony[p] = 1;
            cout << p << " ";
            for(int i=0;i<N;i++){
                if(graf[p][i] == 1 && odwiedzony[i] == 0) {
                    q.push(i);
                }
            }
        }
    }
}
*/
int odwiedzony[N]={0}; //0 – nieodwiedzony, 1 – odwiedzony

/*void init(){
  for(int i=0;i<N;i++) {
    odwiedzony[i] = 0;
    for(int j=0;j<N;j++)
        graf[i][j]=rand()%2;
  }
}
*/
void BFS(int s){
    q.push(s);
    while(!q.empty()) {
        int p = q.front();
        q.pop();
        if(odwiedzony[p] == 0) {
            odwiedzony[p] = 1;
            cout << p << " ";
            for(int i=0;i<N;i++){
                if(graf[p][i] == 1 && odwiedzony[i] == 0) {
                    q.push(i);
                }
            }
        }
    }
}
/*
void DFS() {
    for(int i=0;i<N;i++){
        if(odwiedzony[i] == 0) {
            odwiedzony[i] == 1
        }
}
*/

void wyswietl()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
    {
        cout<<graf[i][j]<<" ";
    }
    cout<<endl;
    }
}

int main()
{
    //srand(time(NULL));
     //init();
     wyswietl();

    BFS(0);
    return 0;
}
