#include<bits/stdc++.h>
using namespace std;
void merge(int l, int r, int mid, vector<int>& v)
{
    vector<int> L, R;
    for(int i = l; i <= mid; i++)
    {
        L.push_back(v[i]);
    }
    L.push_back(INT_MIN);
    for(int i = mid + 1; i <= r; i++)
    {
        R.push_back(v[i]);
    }
    R.push_back(INT_MIN);

    int lp = 0, rp = 0;
    for(int i = l; i <= r; i++)
    {
        if(L[lp] >= R[rp])
        {
            v[i] = L[lp];
            lp++;
        }
        else
        {
            v[i] = R[rp];
            rp++;
        }
    }
}
void mergeSort(int l, int r, vector<int>& v)
{
    if(l == r) return;
    int mid = (l + r) / 2;
    mergeSort(l, mid, v);
    mergeSort(mid + 1, r, v);
    merge(l, r, mid, v);
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

    mergeSort(0, v.size() - 1, v);

    for(int val : v) cout << val << " ";
    cout << endl;
    return 0;
}