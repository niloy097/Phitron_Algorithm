#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100];
bool visited[100];
void dfs(int parent)
{
    visited[parent] = true;
    for(int child : adj[parent])
    {
        if(!visited[child])
        {
            dfs(child);
        }
    }
}
void bfs(int src)
{
    queue<int> qu;
    qu.push(src);
    visited[src] = true;
    while(!qu.empty())
    {
        int parent = qu.front();
        qu.pop();
        for(int child : adj[parent])
        {   
            if(!visited[child])
            {
                qu.push(child);
                visited[child] = true;
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i< m; i++)
    {
        int u, v;
        cin>> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> cc;
    for(int i = 1; i<=n; i++)
    {
        if(!visited[i])
        {
            cc.push_back(visited[i]);
            bfs(i);
        }
    }
    cout << "Number of Components: " << cc.size() << endl;
    return 0;
}