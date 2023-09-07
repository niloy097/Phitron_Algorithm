#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
const int INF = 1e9 + 7;
int dist[N][N];
int n, m;
void distInit()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i != j) dist[i][j] = INF;
        }
    }
}
void printDist()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(dist[i][j] == INF) cout << 'X' << " ";
            else cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}
void floydWarshall()
{
    for(int k = 1; k <= n; k++) //For Node allowance
    {
        for(int i = 1; i <= n; i++)
        {                              
            for(int  j= 1; j <= n; j++)
            {
                if(dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    distInit();
    while(m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
    }
    cout << "Before Floyd Warshall" << endl;
    printDist();
    floydWarshall();
    printf("\n\n");
    cout << "After Floyd Warshall" << endl;
    printDist();
    return 0;
}