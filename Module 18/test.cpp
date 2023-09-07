#include<bits/stdc++.h>
using namespace std;
int prnt[] = {-1, 2, 3, -1, -1, 3, -1, 6, 6};
int absRoot(int node)
{
    while(prnt[node] != -1)
    {
        node = prnt[node];
    }
    return node;
}
bool Find(int a, int b)
{
    int x = absRoot(a);
    int y = absRoot(b);
    return  x == y;
}
int main()
{
    cout << Find(6, 8) << endl;
    return 0;
}