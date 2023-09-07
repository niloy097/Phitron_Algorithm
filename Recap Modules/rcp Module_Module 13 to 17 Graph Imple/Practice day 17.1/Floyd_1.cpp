#include<bits/stdc++.h>
using namespace std;
const int N = 101;
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
void printDist()
{
    for(int i = 1; i <= n; i++)
    {
        for(int  j = 1; j <= n ; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << "\n";
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
    floydWarshall();
    printDist();
    return 0;
}