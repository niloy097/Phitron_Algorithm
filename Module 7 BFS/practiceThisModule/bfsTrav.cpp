//BFS
#include<bits/stdc++.h>
using namespace std;
vector<int> adjList[100];
bool visited[100];
void bfs(int src)
{
    queue<int> qu;
    qu.push(src);
    visited[src] = true;
    while(!qu.empty())
    {
        int parent = qu.front();
        qu.pop();
        cout << parent << " "; //Traversal
        for(int child : adjList[parent])
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
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    bfs(1);
    return 0;
}