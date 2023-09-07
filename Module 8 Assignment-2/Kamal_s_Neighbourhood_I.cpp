#include <bits/stdc++.h>
using namespace std;
const int N = 10e5 + 1;
vector<int> graph[N];
vector<bool> visited(N);
vector<int> level(N);
void bfs(int src)
{
    queue<int> qu;
    visited[src] = true;
    qu.push(src);
    while (!qu.empty())
    {
        int parent = qu.front();
        qu.pop();
        for (int child : graph[parent])
        {
            if (!visited[child])
            {
                qu.push(child);
                visited[child] = true;
                level[child] = level[parent] + 1;
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int q;
    cin >> q;
    bfs(q);
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        if(level[i] == 1) cnt++;
    }
    cout << cnt << endl;
    return 0;
}