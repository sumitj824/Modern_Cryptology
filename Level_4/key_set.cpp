#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("schedulekey.txt","r",stdin);
    freopen("key_set.txt","w",stdout);
    
    int block[48] = { 1,0,1,1,0,1, 1,1,0,0,1,1,  -1,-1,-1,-1,-1,-1, 0,0,0,1,1,1, 0,1,0,0,0,0,  0,1,1,1,1,0, 0,0,1,1,0,0, 1,1,0,1,1,0};
    
    int perm[48];
    for(int i=0;i<48;i++)
    {
        cin>>perm[i];
    }
            
     
    int arr[48];
    for(int i=0;i<48;i++) arr[i]=block[i];
    

    int key[64];
    for(int i=0;i<64;i++)key[i]=-1;
    for(int i=0;i<48;i++)
    {
        
        key[perm[i]-1]=arr[i];
    }
    for(int i=7;i<64;i+=8){
        key[i]=67;
    }

    for(int i=0;i<64;i++)
    {
        cout<<key[i]<<" ";
    }
    cout<<endl;


}