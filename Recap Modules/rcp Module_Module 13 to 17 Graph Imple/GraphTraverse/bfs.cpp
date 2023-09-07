#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
vector<int> graph[N];
vector<bool> visited(N);
vector<int> level(N);
void bfs(int src)
{
    queue<int> qu;
    visited[src] = true;
    qu.push(src);
    while(!qu.empty())
    {
        int parent = qu.front();
        qu.pop();

        for(auto& child : graph[parent])
        {
            if(!visited[child])
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
    while(m--)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bfs(1);
    cout << level[4] << endl;
    return 0;
}