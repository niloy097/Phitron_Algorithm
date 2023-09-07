#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int parent[N];
int prntLvl[N];
void sett(int n)
{
    for(int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        prntLvl[i] = 0;
    }
}
int find(int node) // we can find leader by using this fucntion
{
    while(parent[node] != -1)
    {
        node = parent[node];
    }
    return node;
}
void unionn(int a, int b)
{
    int leaderA = find(a);
    int leaderB = find(b);

    if(leaderA != leaderB)
    {   
        //Union by Rank
        if(prntLvl[leaderA] > prntLvl[leaderB])
        {
            //A leader
            parent[leaderB] = leaderA;

        }
        else if(prntLvl[leaderA] < prntLvl[leaderB])
        {
            //B can be leader
            parent[leaderA] = leaderB;
         
        }
        else
        {
            //if the level is same anyone both can be leader
            parent[leaderB] = leaderA;
            prntLvl[leaderA]++;

        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    sett(n);
    while(m--)
    {
        int u, v;
        cin >> u >> v;
        unionn(u, v);
    }
    map<int, bool>mp;
    for(int i = 1; i <= n; i++)
    {
        int ldr = find(i);
        mp[ldr] = true;
    }
    vector<int> v;
    for(pair<int, bool> p : mp)
    {
        v.push_back(p.first);
    }
    cout << v.size() -1<< "\n" ;
    for(int i= 0; i < v.size() -1; i++)
    {
        cout << v[i] << " " << v[i + 1] << endl;
    }
    return 0;
}