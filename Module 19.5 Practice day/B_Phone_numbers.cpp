#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(s.size() % 2 == 0)
    {
        int cnt = 0;
        for(int i = 0; i < s.size(); i++)
        {
            cout << s[i];
            cnt++;
            if(cnt == 2 && i != s.size()-1)
            {
                cout <<'-';
                cnt = 0;
            }
        }
    }
    else
    {
        int cnt = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(i == (s.size()- 3))
            {
                cout << s[i] << s[i+1] << s[i+2];
                break;
            }
            cout << s[i];
            cnt++;
            if(cnt == 2)
            {
                cout <<'-';
                cnt = 0;
            }
        }
    }
    return 0;
}