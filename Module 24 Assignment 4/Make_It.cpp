#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 1e5 + 7;
ll dp[N];
bool recursion(ll src, ll target)
{
    if(src == target) return true;
    else if(src > target) return false;
    if(dp[src] != -1) return dp[src];
    bool op1 = recursion(src + 3, target);
    bool op2 = recursion(src * 2, target);
    return dp[src] = op1 or op2;
}

void sett(int n)
{
    for(int i = 0; i <= n; i++)
    {
        dp[i] = -1;
    }
}
void solveT()
{
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        sett(n);
        if(n == 1) cout << "YES" << endl;
        else
        {
            if (recursion(1, n))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}
int main()
{
    solveT();
    return 0;
}