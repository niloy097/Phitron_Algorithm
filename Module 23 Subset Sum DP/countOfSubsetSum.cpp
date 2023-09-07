// //Top Down
// #include<bits/stdc++.h>
// #define edl "\n"
// using namespace std;
// int dp[1005][1005];
// int subsetSum(int* arr, int n, int sum)
// {
//     if(n == 0)
//     {
//         if(sum == 0) return 1;
//         else return 0;
//         // return sum == 0; shortcut
//     }
//     if(dp[n][sum] != -1) return dp[n][sum];
    
//     if(arr[n - 1] <= sum) // if the currect element in the range of sum
//     { // ex: if the sum = 7 and arr[n - 1] = 5 then this condition is True
//         int op1 = subsetSum(arr, n - 1, sum - arr[n - 1]);//including
//         int op2 = subsetSum(arr, n - 1, sum);//excluding
//         return dp[n][sum] = op1 + op2;
//     }
//     else
//     {
//         int op2 = subsetSum(arr, n - 1, sum);//excluding
//         return dp[n][sum] = op2;
//     }
// }
// int sum;
// void printMatirx(int n, int s)
// {
//     for(int i = 0; i <= n; i++)
//     {
//         for(int j = 0; j <=sum; j++)
//         {
//             cout << dp[i][j] << " ";
//         }
//         cout << edl;
//     }
// }
// int main()
// {
//     int n;
//     cin >> n;
//     int arr[n];
//     for(int  i = 0; i < n; i++)
//     {
//         cin>> arr[i];
//     }
    
//     cin >> sum;
//     for(int i = 0; i <= n; i++)
//     {
//         for(int j = 0; j <=sum; j++)
//         {
//             dp[i][j] = -1;
//         }
//     }
//     cout << subsetSum(arr, n, sum) << edl;
//     printMatirx(n, sum);
//     return 0;
// }


//Bottom Up Approach
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
    int dp[n+1][s+1];
    dp[0][0] = 1;
    for(int i = 1; i <= s; i++)
    {
        dp[0][i] = 0;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= s; j++) // here j = sums(1 to s)
        {
            if(arr[i - 1] <= j)
            {
                int op1 = dp[i - 1][j - arr[i - 1]];
                int op2 = dp[i - 1][j];
                dp[i][j] = op1 + op2;
            }
            else
            {
                int op2 = dp[i - 1][j];
                dp[i][j] = op2;
            }
        }
    }
    cout << dp[n][s] << endl;
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0;j <=s; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}