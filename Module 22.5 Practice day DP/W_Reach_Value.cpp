#include<bits/stdc++.h>
using namespace std;
#define inRange(i, a, n) for(int i = a; i < n; i++)
#define inRanger(i, a, n) for(int i = n - 1; i >= a; i--)
#define pb push_back
#define el "\n"
#define yes cout << "yes" << el
#define no cout << "no" << el
#define YES cout << "YES" << el
#define NO cout << "NO" << el
#define srtV(vec) sort(vec.begin(), vec.end())
#define srtA(arr, n) sort(arr, arr+n)
#define srtrA(arr, n) sort(arr, arr+n, greater<int>())
#define srtrV(vec) sort(vec.begin(), vec.end(), greater<int>())
typedef pair<int, int> pr;
typedef long long ll;
typedef vector<int> vt;
bool recursion(ll n)
{
    if(n == 1) return true;
    if(n == 0) return false;
    bool op1 = recursion(n/10);
    bool op2 = recursion(n/20);
    return op1 || op2;
}
void solveT()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        if(n == 1) YES;
        else if(n < 10) NO;
        else if(n % 10 != 0 && n % 20 != 0) NO;
        else
        {
            if (recursion(n))
                YES;
            else
                NO;
        }
    }
}
void solve()
{
 
}
int main()
{
    solveT();
    return 0;
}