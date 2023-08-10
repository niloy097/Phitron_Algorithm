//depth of graph

#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 3;
vector<int> adj[N];
bool visited[N];
int depth[N];
int height[N];
void dfs(int parent)
{
    visited[parent] = true;
    cout << "Visited Node : " << parent << endl;
    for(int child : adj[parent])
    {
        if(!visited[child])
        {
            depth[child] = depth[parent] + 1;
            dfs(child);
            height[parent] = max(height[parent], height[child] + 1);
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
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    dfs(1);
    /*for(int i = 1; i <= n; i++)
    {
        cout << "List-> " << i << " : "; 
        for(int val : adj[i]) cout << val << ",";
        cout << endl;
    }*/
    for(int i = 1; i <= n; i++)
    {
        cout << "dpt  of Node- " << i << " : " << depth[i] << endl;
    }
    cout << "************************\n";
    for(int i = 1; i <= n; i++)
    {
        cout << "ht  of Node- " << i << " : " << height[i] << endl;
    }
    return 0;
}