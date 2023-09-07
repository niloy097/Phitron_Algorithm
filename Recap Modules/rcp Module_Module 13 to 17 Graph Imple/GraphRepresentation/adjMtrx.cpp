#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
int graph[N][N];
int main()
{
    int n, m;
    cin >> n >> m;
    while(m--)
    {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1; //for directed graph
        graph[v][u] = 1;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <=n; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}