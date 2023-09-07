#include<bits/stdc++.h>
using namespace std;
vector<int> graph[1001];
vector<bool> visited(1001);
vector<int> l;
int cnt = 0;
void dfs(int parent)
{
    visited[parent] = true;
    cnt++;
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
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 0; i <= 1000; i++)
    {
        if(!visited[i])
        {
            dfs(i);
            l.push_back(cnt);
            cnt = 0;
        }
    }
    sort(l.begin(), l.end());
    for(int val : l)
    {
        if(val > 1) cout << val << " ";
    }
    return 0;
}

