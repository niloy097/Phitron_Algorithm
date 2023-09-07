#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e3 + 5;
vector<string> graph;
int visited[N][N];
int level[N][N];
int n , m;
vector<pii> direction = 
{make_pair(0, -1), make_pair(0, 1), 
 make_pair(-1, 0), make_pair(1, 0)};
bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
void bfs(int si, int sj)
{
    queue<pii> qu;
    qu.push(make_pair(si, sj));
    visited[si][sj] = true;
    level[si][sj] = 0;

    while(!qu.empty())
    {
        pii parent = qu.front();
        int i = parent.first;
        int j = parent.second; 
        qu.pop();

        for(auto d : direction)
        {
            int ni = i + d.first;
            int nj = j + d.second;

            if(isValid(ni, nj) && !visited[ni][nj] && graph[ni][nj] != 'x')
            {
                qu.push(make_pair(ni, nj));
                visited[ni][nj] = true;
                level[ni][nj] = level[i][j] + 1;
            }

        }

        
    }
}
int main()
{
    int si, sj, di, dj;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        for(int j = 0; j < m; j++)
        {
            if(x[j] == 's')
                si = i, sj = j;
            if(x[j] == 'e')
                di = i, dj = j;
        }
        graph.push_back(x);
    }
    
    bfs(si, sj);

    if(visited[di][dj])
    {
        cout << level[di][dj] << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}