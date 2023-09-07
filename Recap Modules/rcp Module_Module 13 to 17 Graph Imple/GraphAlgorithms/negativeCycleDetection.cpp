#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
class Edge
{
    public:
        int u, v, w;
        Edge(int u, int v, int w)
        {
            this->u = u;
            this->v = v;
            this->w = w;
        }
};
vector<Edge> EdgeList;
vector<int> dist(N, INF);
int n, m;
bool isCycleExists()
{
    for(int i = 1; i <= n - 1; i++)
    {
        for(auto ed : EdgeList)
        {
            int a = ed.u;
            int b = ed.v;
            int w = ed.w;
            if(dist[a] + w < dist[b]) //relaxation Section
            {
                return true;
                dist[b] = dist[a] + w;
            }
        }
    }
    return false;
}
void bellmanFord(int src)
{
    dist[src] = 0;
    for(int i = 1; i <= n - 1; i++)
    {
        for(auto ed : EdgeList)
        {
            int a = ed.u;
            int b = ed.v;
            int w = ed.w;
            if(dist[a] + w < dist[b])
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
        EdgeList.push_back(eg);
    }
    bellmanFord(1); // O(n * e)
    // for(int  i= 1; i <= n; i++)
    // {
    //     cout << "The Dist of Node-> " << i << " : " << dist[i] << endl;
    // }
    if(isCycleExists()) cout << "Cycle Detected" << endl;
    else cout << "No Cycle Detected" << endl;
    return 0;
}


/*

4
4
1 2 5
2 3 2
3 4 -2
1 4 1

*/