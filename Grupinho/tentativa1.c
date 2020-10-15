#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin>>N;
    vector<int>vet;

    for(int i=0; i<N; i++)
    {
        int X;
        cin>>X;
        vet.push_back(X);
    }
    int tamanho = vet.size();
    cout<<"tamanho = "<<tamanho<<endl;  //endl == \n
    //cout<<"tamanho = "<<tamanho<<"\n";
    for(int i=(N-1); i>=0; i--)
    {
        cout<<vet[i]<<endl;
    }

    return 0;
}
