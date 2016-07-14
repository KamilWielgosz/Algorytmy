#include <iostream>
#include <stdlib.h>
using namespace std;
const int N=8;
int d[]={100,100,100,100,100,100,100,100};
int p[]={-1,100,100,100,100,100,100,100};
int od[]={0,0,0,0,0,0,0,0};
int graf[N][N]={0,2,5,0,0,0,0,15,
                0,0,0,10,0,0,8,0,
                0,0,0,0,11,0,0,0,
                0,0,0,0,0,7,0,0,
                0,0,0,0,0,4,0,0,
                0,0,0,0,4,0,0,6,
                0,0,0,2,0,0,0,1,
                15,0,0,0,0,0,0,0};

void relax(int u, int v)
{
    if(d[v]>d[u]+graf[u][v])
    {
        d[v]=d[u]+graf[u][v];
        p[v]=u;
    }
}
int minQ()
{
    int mini=1000,ki;
    for(int i=0; i<N; ++i)
    {
        if((mini>d[i])&&od[i]!=1)
        {
            mini=d[i];
            ki=i;
        }
    }
    d[ki]=mini;
    od[ki]=1;
    return ki;
}
void dijkstra(int s)
{
    int mini,kj,u;
    d[s]=0;
    for(int i=0;i<N;++i)
    {
        u=minQ();
        for(int j=0;j<N;++j)
        {
            if(graf[u][j]>0)
            {
                relax(u,j);
            }
        }
    }
}

void wypisz()
{
    for(int i=0;i<N;++i)
    {
        cout<<d[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<N;++i)
    {
        cout<<p[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int s;
    cout<<"Podaj wezel poczatkowy"<<endl;
    cin>>s;
    dijkstra(s);
    wypisz();
    system("pause");
    return 0;
}