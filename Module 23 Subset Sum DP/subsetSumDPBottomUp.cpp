#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int  i = 0; i < n; i++)
    {
        cin>> arr[i];
    }
    int s;
    cin >> s;
    bool dp[n+1][s+1];
    dp[0][0] = true;
    for(int i = 1; i <= s; i++)
    {
        dp[0][i] = false;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= s; j++) // here j = sums(1 to s)
        {
            if(arr[i - 1] <= j)
            {
                bool op1 = dp[i - 1][j - arr[i - 1]];
                bool op2 = dp[i - 1][j];
                dp[i][j] = op1 or op2;
            }
            else
            {
                bool op2 = dp[i - 1][j];
                dp[i][j] = op2;
            }
        }
    }
    if(dp[n][s]) cout << "YES" << endl;
    else cout << "NO" << endl;
    for(int i = 0; i  <= n; i++)
    {
        for(int j = 0; j <= s; j++)
        {
            if(dp[i][j]) cout << 'T' << " ";
            else cout << 'F' << " ";
        }
        cout << endl;
    }
    return 0;
}

//my version
/*

//Subset Sum Bottom Up cpp
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
    int a[n];
    inRange(i, 0, n) cin >> a[i];
    int s;
    cin >> s;
    bool dp[n+1][s+1];
    dp[0][0] = true;
    inRange(i, 1, s+1) dp[0][i] = false;
    inRange(i, 1, n+1)
    {
        inRange(j, 0, s+1)
        {
            if(a[i -1] <= j)
            {
                bool op1 = dp[i - 1][j - a[i - 1]];
                bool op2 = dp[i - 1][j];
                dp[i][j] = op1 or op2;
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    if(dp[n][s]) YES << el;
    else NO << el;
    inRange(i, 0, n+1)
    {
        inRange(j, 0, s+1)
        {
            if(dp[i][j]) cout << "T" << " ";
            else cout << "F" << " ";
            // cout << dp[i][j] << " ";
        }
        cout << el;
    }
}   
int main()
{
    solve();
    return 0;
}


*/