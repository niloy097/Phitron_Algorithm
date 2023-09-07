#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pa;
const int N = 1e3 + 7;
char graph[N][N];
bool visited[N][N];
int dist[N][N];
int n, m;
vector<pa> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
void bfs(int si, int sj)
{
    queue<pa> qu;
    qu.push({si, sj});
    dist[si][sj] = 0;
    visited[si][sj] = true;
    while(!qu.empty())
    {
        pa parent = qu.front();
        qu.pop();
        int pi = parent.first;
        int pj = parent.second;
        for(auto childPr : direction)
        {
            int ci = pi + childPr.first;
            int cj = pj + childPr.second;
            if(isValid(ci, cj) && !visited[ci][cj])
            {
                visited[ci][cj] = true;
                qu.push({ci, cj});
                dist[ci][cj] = dist[pi][pj] + 1;
            }

        }


    }
}
int main()
{
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
        }
    }
    int si, sj;
    cin >> si >> sj;
    bfs(si, sj);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}