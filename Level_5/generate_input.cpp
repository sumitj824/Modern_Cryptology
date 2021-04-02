
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int x =128; //number of input 
  srand(time(0));
  string s;
  int j; //block number [1,...,7,8]

  //for first 16 char

  // s="ffffffffffffffff"; j=1;    
  // s="mjffffffffffffff"; j=2;    
  // s="mjmkffffffffffff"; j=3;    
  // s="mjmkmhffffffffff"; j=4;    
  // s="mjmkmhmjffffffff"; j=5;    
  // s="mjmkmhmjljffffff"; j=6;    
  // s="mjmkmhmjljmmffff"; j=7;   
  // s="mjmkmhmjljmmltff"; j=8;   

  // for  second 16 char
  // s="ffffffffffffffff"; j=1;    
  // s="lkffffffffffffff"; j=2;    
  // s="lkmpffffffffffff"; j=3;    
  // s="lkmpifffffffffff"; j=4;    
  // s="lkmpififffffffff"; j=5;    
  // s="lkmpifififffffff"; j=6;    
  // s="lkmpififififffff"; j=7;   
  s="lkmpifififififff"; j=8;    


  for(int i=0;i<=127;i++)
  {
    
    s[2*j-2]='f'+ i/16;
    s[2*j-1]='f' + (i%16);
    cout<<s<<endl;
  }

}