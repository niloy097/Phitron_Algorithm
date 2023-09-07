#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 + 7;
const int INF = 1e7 + 5;
class Edge{
    public:
        int u, v, w;
        Edge(int u, int v, int w)
        {
            this->u = u;
            this->v = v;
            this->w = w;
        }
};
vector<Edge> edgeList;
vector<int> dist(N, INF);
int n, m;
void bellmanFord(int src)
{
    dist[src] = 0;

    for(int i = 1; i <= n - 1; i++)
    {
        for(auto eg : edgeList)
        {
            int a = eg.u;
            int b = eg.v;
            int w = eg.w;
            if(dist[a] != INF && dist[a] + w < dist[b])
            {
                dist[b] = dist[a] + w;
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    while(m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        Edge eg(u, v, w);
        edgeList.push_back(eg);
    }
    bellmanFord(1);
    for(int i = 1; i <= n; i++) 
    {
        if(dist[i] == INF) cout << 30000 << " ";
        else cout << dist[i] << " ";
    }
    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;
// typedef pair<int, int> pii;
// const int N = 1e2 + 7;
// const int INF = 1e7+7;
// int dist[N];
// vector<pii> graph[N];
// vector<pair<pii,int>> listOfEdges;
// int n, m;
// void bellmanFord(int src)
// {   
//     for(int i = 1; i <= n; i++)
//     {
//         dist[i] = INF;
//     }
//     dist[src] = 0;

//     for(int  i = 1; i < n; i++) //n - 1 times 
//     {
//         //all edges relaxation
//         for(int u = 1; u <= n; u++) // for traversing all node
//         {
//             for(pii vpair : graph[u]) // accessing every nodes adjList
//             {
//                 int v = vpair.first;
//                 int w = vpair.second;

//                 if(dist[u] != INF && dist[v] > dist[u] + w)
//                 {
//                     dist[v] = dist[u] + w;
//                 }
//             }
//         }
//         /*for(auto edge : listOfEdges)
//         {
//             int u = edge.first.first;
//             int v = edge.first.second;
//             int w = edge.second;

//             if(dist[u] != INF && dist[v] > dist[u] + 1)
//             {
//                 dist[v] = dist[u] + w;
//             }
//         }*/
//     }
// }
// int main()
// {
//     cin >> n >> m;
//     while(m--)
//     {
//         int u, v, w;
//         cin >> u >> v >> w;
//         graph[u].push_back({v, w}); //adh list
//         // listOfEdges.push_back({{u, v}, w});
//     }
//     bellmanFord(1); //O(Edges * vertex)

//     for(int  i = 1; i <= n; i++)
//     {
//         if(dist[i] == INF) cout << 30000 << " ";
//         else cout << dist[i] << " ";
//     }
//     return 0;
// }
/*

7
10
1 2 6
1 3 5
1 4 5
2 5 -1
3 2 -2
3 5 1
4 3 -2
4 6 -1
5 7 3
6 7 3


4
5
1 2 4
1 3 5
3 4 3
4 2 -10
2 3 2
Dis of 1 0
Dis of 2 -22
Dis of 3 -15
Dis of 4 -12

Di of 1 0
Di of 2 6
Di of 3 5
Di of 4 5
Di of 5 5
Di of 6 4
Di of 7 7

*/