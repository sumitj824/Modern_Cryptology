#include <bits/stdc++.h>
using namespace std;

//this code is used to find the value of y and z
int32_t main()
{   
    // 2021y + 9189z =1
    int y,z;
    for(y=1;y<1000000;y++)
    {   
        if((2021*y-1)%9189==0)
        {
            cout<<"Found  :\n";
            break;
        }
    }
    
    z=(1-2021*y)/9189;
    

    cout<<"y = "<< y<<endl;
    cout<<"z = "<< z<<endl;
}
