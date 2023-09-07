#include<bits/stdc++.h>
using namespace std;
int parent[1000];
int prntLvl[1000];
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
        int leaderA = find(u);
        int leaderB = find(v);
        if(leaderA == leaderB)
        {
            cout << "Cycle Detected in between  "<< u <<" " << v << endl;
        }
        else
            unionn(u, v);
    }
    return 0;
}