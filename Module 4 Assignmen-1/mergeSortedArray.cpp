#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>& v1, vector<int>& v2, vector<int>& result)
{
    v1.push_back(INT_MIN);
    v2.push_back(INT_MIN);
    int lp = 0, rp = 0;
    for(int i = 0; i < (v1.size() + v2.size()) - 2 ; i++)
    {
        if(v1[lp] >= v2[rp])
        {
            result.push_back(v1[lp]);
            lp++;
        }
        else
        {
            result.push_back(v2[rp]);
            rp++;
        }
    }
}
int main()
{


    int n;
    cin >> n;
    vector<int> result;
    vector<int> v;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int m;
    cin >> m;
    vector<int> w;
    for(int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        w.push_back(x);
    }
    merge(v, w, result);
    for(int val : result) cout << val << " ";
    cout << endl;
    return 0;
}