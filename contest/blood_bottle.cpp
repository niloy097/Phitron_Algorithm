#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
        vector<int> v;
        int cnt = 0;
        for(int i = 0; i < str.size(); i++)
        {
            if(str[i] == '1')
            {
                cnt++;
            }
            else
            {
                if(cnt != 0) 
                {
                    v.push_back(cnt);
                    cnt=0;
                }
            }
        }

        if(cnt != 0) v.push_back(cnt);
        if(v.size() == 0) v.push_back(0);
        sort(v.begin(), v.end(), greater<int>());
        long long int sum = 0;
        for(int i = 0; i < v.size(); i++)
        {
            if(i % 2 == 0) sum += v[i];
        }
        cout<< sum <<endl;
    }
    return 0;
}