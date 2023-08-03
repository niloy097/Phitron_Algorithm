#include<bits/stdc++.h>
using namespace std;
int isExists(vector<int>& v, int key)
{
    int low = 0;
    int high = v.size() - 1;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        if(key == v[mid])
        {
            return mid;
        }
        else if(key > v[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}
int main()
{


    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    int key;
    cin >> key;

    if(isExists(v, key) == -1) cout << "Not Found" << endl;
    else cout << isExists(v, key) << endl;
    return 0;
}