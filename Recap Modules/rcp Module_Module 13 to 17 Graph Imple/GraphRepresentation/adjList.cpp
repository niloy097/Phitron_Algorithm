#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
vector<int> graph[N];
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
    for(int i = 1; i <= n; i++)
    {
        cout << "Index " << i << " : ";
        for(auto u : graph[i]) cout << u  << " ";
        //for(int j = 0; j < graph[i].size(); j++)
        cout << endl;
    }
    return 0;
}