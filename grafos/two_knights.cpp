#include <bits/stdc++.h>  
using namespace std; 
int posicion(int k)
{
    long total= (k*k)*((k*k)-1)/2;
    long ataque=4*(k-1)*(k-2);
    return total-ataque;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cout<<posicion(i)<<endl;
    }

    return 0;
}