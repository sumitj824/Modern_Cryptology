#include <bits/stdc++.h>
#define INT  unsigned int

using namespace std;

//to read terminal screen output
int main()
{
    string s;
    int x=128; // number of inputs 
    ofstream out;
    out.open("cipher.txt",ios::app);
    int i;
    for(i=0;i<14;i++)getline(cin,s);
    
    for(i=0;i<2*x;i++)
    {
        cin>>s;
    }
    for(i=415;i<=543;i++)getline(cin,s);

    for(i=0;i<x;i++)
    {
        for(int j=70;j<=79;j++) getline(cin,s);
        out<<s;
        for(int j=80;j<=84;j++) getline(cin,s);
    }
    out.close();

}