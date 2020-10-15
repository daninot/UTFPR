#include <bits/stdc++.h>

using namespace std;        //temq usar isso

int main()
{
    cin>>N; //le
    cout<<n; //imprime
    cout<<"Olá Mundo\n";   // == cout<<"Olá Mundo"<<endl;

    vector<int>vetor;       //criando um vetor do tipo int
    vector<int>vetor(N,7);      //criei um vetor de tamanho N (q eu vou ler) com todos os valores 7
    vector<string>frase;    //um vetor de string

    for(int i=0; i<N; i++)
    {
        int X;
        scanf("%d",&X);
        vetor.push_back(X);     //insere valores em um vetor
    }
    vetor.size();       //vê o tamanho do vetor
    vector.erase();     //apaga um índice do vetor

    reverse(vetor.begin(),vetor.end()); //inverte os valores do vetor
    sort(vetor.begin(),vetor.end());
    0;
}

//para compilar
//g++ treinamento.c -o treinamento
