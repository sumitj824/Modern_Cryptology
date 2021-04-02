#include<bits/stdc++.h>
using namespace std;

void find_the_answer()
{
  string s="mjmkmhmjljmmltltlkmpifififififif";
  for(int i=0;i<16;i++)
  {
    int x= 16*(s[2*i]-'f') + (s[2*i+1]-'f');
    // cout<<x<<" ";
    cout<<char(x)<<" ";
  }

}


int main()
{ 
  find_the_answer();

}
