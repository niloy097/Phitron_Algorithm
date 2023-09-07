//Error in code
#include<bits/stdc++.h>
#define edl "\n"
using namespace std;
int dp[1005][1005];
bool subsetSum(int* arr, int n, int sum)
{
    if(n == 0)
    {
        if(sum == 0) return true;
        else return false;
        // return sum == 0; shortcut
    }
    if(dp[n][sum] != -1) return dp[n][sum];
    
    if(arr[n - 1] <= sum) // if the currect element in the range of sum
    { // ex: if the sum = 7 and arr[n - 1] = 5 then this condition is True
        bool op1 = subsetSum(arr, n - 1, sum - arr[n - 1]);//including
        bool op2 = subsetSum(arr, n - 1, sum);//excluding
        return dp[n][sum] = op1 or op2;
    }
    else
    {
        bool op2 = subsetSum(arr, n - 1, sum);//excluding
        return dp[n][sum] = op2;
    }
}
int sum;
void printMatirx(int n, int s)
{
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <=sum; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << edl;
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int  i = 0; i < n; i++)
    {
        cin>> arr[i];
    }
    
    cin >> sum;
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <=sum; j++)
        {
            dp[i][j] = -1;
        }
    }
    subsetSum(arr, n, sum) ? cout << "YES" << edl : cout << "NO" << edl;
    cout << edl;
    printMatirx(n, sum);
    return 0;
}


//My Version
/*


#include<bits/stdc++.h>
using namespace std;
#define inRange(i, a, n) for(int i = a; i < n; i++)
#define inRanger(i, a, n) for(int i = n - 1; i >= a; i--)
#define pb push_back
#define el cout << "\n"
#define eL "\n"
#define OR ||
#define AND &&
#define T true 
#define F false 
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
int dp[1005][1005];
bool subSetSum(int n, int* a, int s)
{
    //base case
    if(n == 0)
    {
        if(s == 0) return T;
        else return F;
    }
    if(dp[n][s] != -1) return dp[n][s];
    if(a[n-1] <= s)
    {
        bool op1 = subSetSum(n-1, a, s - a[n-1]);
        bool op2 = subSetSum(n-1, a, s);
        return dp[n][s] = op1 OR op2;
    }
    else
    {
        return dp[n][s] = subSetSum(n-1, a, s);
    }
}
void solveT()
{
    int t;
    cin >> t;
    while(t--)
    {
        
    }
}
void init(int n, int s)
{
    inRange(i, 0, n+1)
    {
        inRange(j, 0, s+1)
        {
            dp[i][j] = -1;
        }
    }
}
void printDP(int n, int s)
{
    inRange(i, 0, n+1)
    {
        inRange(j, 0, s+1)
        {
            cout << dp[i][j] << " ";
        }
        el;
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
    init(n, s);
    if(subSetSum(n,a,s)) YES << eL;
    else NO << eL;
    printDP(n, s);
}
int main()
{
    solve();
    return 0;
}

*/