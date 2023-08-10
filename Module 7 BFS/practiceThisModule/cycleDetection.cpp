#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100];
bool visited[100];
bool dfs(int parent, int pp = -1)
{
    bool isCycleExists = false;
    visited[parent] = true;
    for(int child : adj[parent])
    {
        if(child == pp) continue; // is neighbor == childs parent?
        if(visited[child]) return true;
        isCycleExists = isCycleExists || dfs(child, parent); // decession from whole graph
    }
    return isCycleExists;
}
int main()
{
    int n,  m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool isCycle = false;
    for(int i = 1; i <=n; i++)
    {
        if(visited[i]) continue;
        isCycle = isCycle || dfs(i);
    }
    isCycle ? cout << "Detected" : cout << "Not Detected";
    return 0;
}
