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
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, marks;
        cin >> n >> marks;
        int a[n];
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int s = 1000 - marks;
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= s; j++)
            {
                dp[i][j] = -1;
            }
        }
        subsetSum(a, n, s) ? cout << "YES" << edl : cout << "NO" << edl;
        
    }
    return 0;
}
