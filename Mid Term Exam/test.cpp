#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v;
    while(true)
    {
        int x;
        cin >> x;
        if(x == -1) break;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    for(int val : v) cout << val << " ";
    cout << endl << v.size() << endl;
    return 0;
}