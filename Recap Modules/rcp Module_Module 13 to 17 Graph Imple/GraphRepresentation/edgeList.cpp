#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> eL;
int main()
{
    int n, m;
    cin >> n >> m;
    while(m--)
    {
        int u, v;
        cin >> u >> v;
        eL.push_back({u,v});
    }
    for(auto pr : eL)
    {
        cout << pr.first << " " << pr.second << endl;
    }
    cout << endl;
    return 0;
}