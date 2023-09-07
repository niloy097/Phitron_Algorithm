#include<bits/stdc++.h>
using namespace std;
#define inRange(i, a, n) for(int i = a; i < n; i++)
#define inRanger(i, a, n) for(int i = n - 1; i >= a; i--)
#define pb push_back
#define el "\n"
#define yes cout << "yes"
#define no cout << "no"
#define YES cout << "YES"
#define NO cout << "NO"
#define srtV(vec) sort(vec.begin(), vec.end())
#define srtA(arr, n) sort(arr, arr+n)
#define srtrA(arr, n) sort(arr, arr+n, greater<int>())
#define srtrV(vec) sort(vec.begin(), vec.end(), greater<int>())
typedef pair<int, int> pr;
typedef long long ll;
typedef vector<int> vt;
bool recursion(ll* arr, ll idx, ll n, ll sum, ll desti)
{
    if(idx == n - 1)
    {
        return sum == desti;
    }
    bool op1 = recursion(arr, idx + 1, n, sum + arr[idx + 1], desti);
    bool op2 = recursion(arr, idx + 1, n, sum - arr[idx + 1], desti);
    return  op1 || op2;
}
void solveT()
{
    ll t;
    cin >> t;
    while(t--)
    {
        
    }
}
void solve()
{
    ll n, desti;
    cin >> n >> desti;
    ll arr[n];
    inRange(i, 0, n) cin >> arr[i];
    // inRange(i, 0, n) cout << arr[i] << " ";
    // cout << el;
    if(recursion(arr, 0, n, arr[0], desti)) YES;
    else NO;
}
int main()
{
    solve();
    return 0;
}