#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pr;
typedef pair<int,pr> dp; // u, v
const int N = 1e5 + 7;
vector<pr> graph[N];
vector<bool> visited(N);
vector<dp> edgeList;
void prims(int src)
{
    priority_queue<dp, vector<dp>, greater<dp>> pq;
    pq.push({0,{src, src}}); // w, u, v pair in this form
    while(!pq.empty())
    {
        dp parent = pq.top();
        pq.pop();
        int w = parent.first; //coast
        int u = parent.second.first;
        int v = parent.second.second;
        if(visited[v]) continue;
        visited[v] = true;
        edgeList.push_back({w,{u, v}});
        for(pr childPr : graph[v]) // here parent is v
        {
            if(!visited[childPr.first])
            {
                pq.push({childPr.second,{v, childPr.first}});
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
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    prims(1);
    edgeList.erase(edgeList.begin());
    for(dp list : edgeList)
    {
        cout << list.second.first << " " <<
        list.second.second << " " << list.first << endl;
    }
    return 0;
}