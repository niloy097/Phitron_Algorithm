#include<bits/stdc++.h>
using namespace std;
const long long  N = 1e3 + 7;
const long long  INF = 1e18 + 7;
long long  dist[N][N];
long long  n, m;
void distInit()
{
    for(long long  i = 1; i <= n; i++)
    {
        for(long long  j = 1; j <= n; j++)
        {
            if(i != j) dist[i][j] = INF;
        }
    }
}
void printDist()
{
    for(long long  i = 1; i <= n; i++)
    {
        for(long long  j = 1; j <= n; j++)
        {
            if(dist[i][j] == INF) cout << 'X' << " ";
            else cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}
void floydWarshall()
{
    for(long long  k = 1; k <= n; k++) //For Node allowance
    {
        for(long long  i = 1; i <= n; i++)
        {                              
            for(long long   j= 1; j <= n; j++)
            {
                if(dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}
int  main()
{
    cin >> n >> m;
    distInit();
    while(m--)
    {
        long long  u, v, w;
        cin >> u >> v >> w;
        if(dist[u][v] < w) continue;
        dist[u][v] = w;
        
    }
    // printDist(); cout << endl;
    floydWarshall();
    long long  q;
    cin >> q;
    while(q--)
    {
        long long  src, desti;
        cin >> src >> desti;
        if(dist[src][desti] != INF) cout << dist[src][desti] << endl;
        else cout << -1 << endl;
    }
    // printDist();
    return 0;
}