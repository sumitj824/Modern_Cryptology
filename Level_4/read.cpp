#include <bits/stdc++.h>
#define INT  unsigned int

using namespace std;

//to read terminal screen output
int main()
{
    string s;
    int x=100; // number of pairs 
    ofstream out;
    out.open("cipher_pair.txt",ios::app);
    int i;
    for(i=0;i<10;i++)getline(cin,s);
    
    for(i=0;i<=4*x;i++)
    {
        cin>>s;
    }
    for(i=12;i<=69;i++)getline(cin,s);

    for(i=0;i<2*x;i++)
    {
        for(int j=70;j<=79;j++) getline(cin,s);
        out<<s;
        for(int j=80;j<=84;j++) getline(cin,s);
    }
    out.close();

}