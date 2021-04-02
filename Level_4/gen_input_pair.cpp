
#include <bits/stdc++.h>
#define INT  unsigned int

using namespace std;


void pack8(INT *packed, INT *binary)
{
  register INT i, j, k;
  
  for (i=0; i<8; i++) {
    k = 0;
    for (j=0; j<8;j++) k  = (k<<1)+ *binary++;
    *packed++ = k;
  }
}

INT INV_IP[] = {
  40, 8, 48, 16, 56, 24, 64, 32,
  39, 7, 47, 15, 55, 23, 63, 31,
  38, 6, 46, 14, 54, 22, 62, 30,
  37, 5, 45, 13, 53, 21, 61, 29,
  36, 4, 44, 12, 52, 20, 60, 28, 
  35, 3, 43, 11, 51, 19, 59, 27, 
  34, 2, 42, 10, 50, 18, 58, 26, 
  33, 1, 41, 9, 49, 17, 57, 25
  };

int main()
{
  int x =100; //number of input pair
  srand(time(0));
  ofstream output;
  output.open("overall_input.txt",ios::app);
  INT a[64],LRa[64];
  INT b[64],LRb[64];
  // 1st characteristic
  // INT xorValue[]={0,1,0,0, 0,0,0,0, 0,0,0,0, 1,0,0,0, 0,0,0,0, 0,0,0,0,  0,0,0,0,  0,0,0,0, 0,0,0,0,   0,1,0,0,  0,0,0,0, 0,0,0,0, 0,0,0,0,  0,0,0,0,  0,0,0,0, 0,0,0,0};
  
  // 2nd characteristic
  INT xorValue[]={0,0,0,0, 0,0,0,0, 0,0,1,0, 0,0,0,0, 0,0,0,0, 0,0,0,0,  0,0,0,0,  1,0,0,0, 0,0,0,0,   0,0,0,0,  0,0,0,0, 0,0,0,0, 0,0,0,0,  0,1,0,0,  0,0,0,0, 0,0,0,0};
  
  for(int j=0;j<x;j++)
  {
    for (int i = 0; i < 64; i++)
    {
      a[i]=rand()%2;
      b[i]=(a[i]^xorValue[i]);
    }

    for (int i =0; i<64; i++)
    {
      LRa[i] = a[INV_IP[i] -1];
      LRb[i] = b[INV_IP[i] -1];
    }
    string s(16,'x');
    INT out[8];
    pack8(out,LRa);
    for(int i=0;i<8;i++)
    {
      s[2*i]=char((out[i]>>4)+'f');
      s[2*i+1]=char((out[i]&(15))+'f');
    }
    cout<<s<<endl;
    output<<s<<endl;

    pack8(out,LRb);
    for(int i=0;i<8;i++)
    {
      s[2*i]=char((out[i]>>4)+'f');
      s[2*i+1]=char((out[i]&(15))+'f');
    }
    cout<<s<<endl; 
    output<<s<<endl;

  }
  output.close();

}