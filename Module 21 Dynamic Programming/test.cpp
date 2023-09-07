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
const int N = 1e5 + 7;
void solveT()
{
    int t;
    cin >> t;
    while(t--)
    {
        
    }
}
void solve()
{
    int n;
    cin >> n;
    int arr[n+1];
    int dp[n+1];
    for(int i = 1; i <= n; i++) 
    {
        cin >> arr[i];
    }
    dp[1] = 0;
    dp[2] = abs(arr[2] - arr[1]);
    for(int i = 3; i <= n; i++)
    {
        int op1 = dp[i - 2] + abs(arr[i] - arr[i - 2]);
        int op2 = dp[i - 1] + abs(arr[i] - arr[i - 1]);
        dp[i] = min(op1, op2);
    }
    cout << dp[n] << endl;
    
}
int main()
{
    solve();
    return 0;
}