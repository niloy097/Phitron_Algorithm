#include <bits/stdc++.h>
using namespace std;
const int N = 10e5 + 1;
vector<int> graph[N];
vector<bool> visited(N);
vector<int> level(N);
void dfs(int parent)
{
    visited[parent] = true;
    for(int child : graph[parent])
    {
        if(!visited[child])
        {
            dfs(child);
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
    }
    int q;
    cin >> q;
    dfs(q);
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        if(visited[i] == true) cnt ++;
    }
    cout << cnt - 1 << endl;
    return 0;
}