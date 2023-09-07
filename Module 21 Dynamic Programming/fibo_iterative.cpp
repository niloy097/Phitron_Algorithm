#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n;
    cin >> n;
    ll a[n+1];
    a[0] = 1;
    a[1] = 1;
    for(int i = 2; i <= n; i++) //O(n)
    {
        a[i] = a[i-1] + a[i-2];
    }
    cout << a[n] << "\n";
    return 0;
}