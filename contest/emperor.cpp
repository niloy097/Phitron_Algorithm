//https://cses.fi/problemset/task/1675/
#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pr;
typedef pair<int,pr> dp; // u, v
const int N = 1e5 + 7;
vector<pr> graph[N];
vector<bool> visited(N);
vector<dp> edgeList;
int cnt = 0;
void prims(int src, int n)
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
        cnt++;
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
    int saved = m;
    while(m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    prims(1, n);
    edgeList.erase(edgeList.begin());
    long long int sum = 0;
    int x = 0;
    for(dp list : edgeList)
    {
        sum += (long long)(list.first);
        x++;
    }
    if(cnt == n)
    {
        cout<< saved - x << " " << sum << endl;
    }
    else
    {
        cout << "Not Possible" << endl;
    }
    return 0;
}