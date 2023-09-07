#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pa;
// void printSorted(vector<pair<int, int>> pp)
// {
//     priority_queue<pa, vector<pa>, greater<pa>>pq;
//     for(int i = 0; i < pp.size(); i++)
//     {
//         pq.push({pp[i].first, pp[i].second});
//     }
//     while (!pq.empty())
//     {
//         cout << pq.top().first << " " << pq.top().second << endl;
//         pq.pop();
//     }
// }
int main()
{
    int n;
    cin >> n;
    vector<pa> v;
    while(n--)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    for(auto &x : v)
    {
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}