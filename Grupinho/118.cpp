#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int A, B, T, N, M;

    cin >> N >> M;
    vector<int> grafo[N+1];

    while(M--)
    {
        cin >> T >> A >> B;

        if(T == 0)
        {
            /*for(int i=0; i<grafo[A].size(); i++)
            {
                int v = grafo[A][i];

                if(B == v)
                    printf("1\n");
                else
                    printf("0\n");
            }*/
            if(find(grafo[A].begin(),grafo[A].end(),B) != grafo[A].end())
                printf("0\n");
            else
                printf("1\n");
        }
        else if(T == 1)
        {
            grafo[A].push_back(B);
            grafo[B].push_back(A);
        }
    }

    return 0;
}
