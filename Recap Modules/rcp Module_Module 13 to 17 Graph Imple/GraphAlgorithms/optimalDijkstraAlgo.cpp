#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pr;
const int N = 1e5 + 7;
vector<pr> graph[N];
vector<bool> visited(N, false);
vector<int> dist(N, INT_MAX);
void dijkstra(int src)
{
    priority_queue<pr, vector<pr>, greater<pr>>pq;
    dist[src] = 0;
    pq.push({dist[src], src});
    while(!pq.empty())
    {
        int parent = pq.top().second;
        pq.pop();
        visited[parent] = true;
        for(auto childPr : graph[parent])
        {
            int child = childPr.first;
            int weight = childPr.second;

            // if(!visited[child])
            // {
            //     if(dist[parent] + weight < dist[child])
            //     {
            //         dist[child]  =  dist[parent] + weight;
            //         pq.push({dist[child], child});
            //     }
            // }
            if(!visited[child])
            {
                dist[child] = min(dist[child], dist[parent] + weight);
                pq.push({dist[child], child});
                
            }
        }
    }
}
int main()
{
    int n,  m;
    cin >> n>> m;
    while(m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    dijkstra(1);
    for(int i = 1; i <= n; i++)
    {
        cout << "Distanceee of Node " << i << " " << dist[i] << endl;
    }
    return 0;
}