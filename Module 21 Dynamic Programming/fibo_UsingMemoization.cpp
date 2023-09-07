#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 7;
ll save[N];
ll fibo(ll n) // O(n)
{
    if(n == 0 or n == 1) return 1;
    if(save[n] != -1)
    {
        return save[n];
    }
    ll ans1 = fibo(n-1);
    ll ans2 = fibo(n-2);
    save[n] = ans1 + ans2;
    return save[n];
}
void settt(int n)
{
    for(int  i= 0; i <= n; i++)
    {
        save[i] = -1;
    }
}
int main()
{
    ll n;
    cin >> n;
    settt(n);
    cout << fibo(n) << "\n";
    return 0;
}