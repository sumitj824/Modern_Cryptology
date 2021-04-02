#include <bits/stdc++.h>
using namespace std;

// This Code is  to remove whitespace and punctuation
// and then to split into pairs of two letters

int main()
{   
    char c;
    int cnt=0;
    while (cin>>c)
    {
        if(c>='A' && c<='Z')
        {
            cout<<c;
            cnt++;
            if(cnt%2==0)cout<<" ";
        }
    }
    cout<<endl;
}
