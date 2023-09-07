#include<bits/stdc++.h>
using namespace std;
const int N = 105;
const int INF = 1e7 + 7;
int graph[N][N];
int n;
void floydWarshall()
{
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}
int findMaxFromDist()
{
    int mx = INT_MIN;
    for(int i = 1; i <= n; i++)
    {
        for(int  j = 1; j <= n ; j++)
        {
            if(graph[i][j] == -1) continue;
            mx = max(mx, graph[i][j]);
        }
        
    }

    return mx;
}
void changeInput()
{
    for(int i = 1; i <= n; i++)
    {
        for(int  j = 1; j <= n ; j++)
        {
            if(graph[i][j] == -1)
            {
                graph[i][j] = INF;
            }

        }
        
    }
}
void modify()
{
    for(int i = 1; i <= n; i++)
    {
        for(int  j = 1; j <= n ; j++)
        {
            if(graph[i][j] == INF)
            {
                graph[i][j] = -1;
            }

        }
        
    }
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> graph[i][j];
        }
    }
    changeInput();
    floydWarshall();
    modify();
    cout << findMaxFromDist() << endl;
    // printmat();
    return 0;
}