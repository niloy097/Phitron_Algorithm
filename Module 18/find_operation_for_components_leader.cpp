#include<bits/stdc++.h>
using namespace std;
int parent[8] = {-1, -1, 1, 1, 6, 4, -1, 1};
int find(int node) // we can find leader by using this fucntion
{
    while(parent[node] != -1)
    {
        node = parent[node];
    }
    return node;
}
int main()
{
    cout << find(5) << endl;
    return 0;
}


//Self Analysis
/*

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


*/