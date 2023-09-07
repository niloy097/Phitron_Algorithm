#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
vector<pair<int,int>> graph[N];
vector<int> dist(N, INT_MAX);
void dijkstra(int src) //O(n * m)
{
    queue<int> qu;
    dist[src] = 0;
    qu.push(src);
    while(!qu.empty())
    {
        int parent = qu.front();
        qu.pop();
        for(auto childPr : graph[parent])
        {
            int child = childPr.first;
            int weight = childPr.second;
            if(dist[parent] + weight < dist[child])
            {
                dist[child] = dist[parent] + weight;
                qu.push(child);
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
        int u, v,w ;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    dijkstra(1);
    for(int i = 1; i <= n; i++)
    {
        cout << "Dist of  Node " << i << " " << dist[i] << endl;
    }
    return 0;
}