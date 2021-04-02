#include<bits/stdc++.h>

#define BYTE  unsigned int
#define INT unsigned int
using namespace std;




INT S[8][64]=
{
  14, 4, 13, 1, 2, 15, 11, 8, 3 , 10, 6, 12, 5, 9, 0, 7,
  0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
  4, 1 , 14, 8, 13, 6, 2, 11, 15, 12, 9, 7,3, 10, 5, 0,
  15, 12, 8,2,4, 9, 1,7 , 5, 11, 3, 14, 10, 0, 6, 13 ,
  
  15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0,5, 10,
  3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
  0, 14, 7, 11, 10, 4, 13, 1, 5, 8,12, 6, 9, 3, 2, 15,
  13, 8, 10, 1, 3, 15, 4, 2,11,6, 7, 12, 0,5, 14, 9,
  
  10, 0, 9,14,6,3,15,5, 1, 13, 12, 7, 11, 4,2,8,
  13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
  13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12,5, 10, 14, 7,
  1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12,
  
  7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
  13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
  10, 6, 9, 0, 12, 11, 7, 13, 15, 1 , 3, 14, 5, 2, 8, 4, 
  3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14,
  
  
  2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9, 
  14, 11,2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6, 
  4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14, 
  11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3, 
  
  
  
  12, 1, 10, 15, 9, 2, 6,8, 0, 13, 3, 4, 14, 7, 5, 11, 
  10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8, 
  9, 14, 15, 5, 2,8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6, 
  4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13, 
  
  4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
  13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
  1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2, 
  6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12,
  
  13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12,7, 
  1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2, 
  7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8, 
  2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11 };




/* PERMUTED CHOICE  PC1 */
INT PC1[] = {
  57, 49, 41, 33, 25, 17, 9,
  1, 58, 50, 42, 34, 26, 18,
  10,  2, 59, 51, 43, 35, 27,
  19, 11,  3, 60, 52, 44, 36,
  63, 55, 47, 39, 31, 23, 15, 
  7, 62, 54, 46, 38, 30, 22, 
  14,  6, 61, 53, 45, 37, 29, 
  21, 13,  5, 28, 20, 12,  4
};

/* Shedule og the left shifts for C and D blocks 
unsigned short shifts[] = {
        2, 13, 13 }; 
*/
unsigned short shifts[] = {
1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1
};

/* PERMUTED CHOICE 2 (PC@) */

INT PC2[] = {
  14, 17, 11, 24,  1, 5, 
  3, 28 ,15,  6, 21, 10, 
  23, 19, 12,  4, 26, 8, 
  16,  7, 27, 20, 13, 2, 
  41, 52, 31, 37, 47, 55, 
  30, 40, 51, 45, 33, 48, 
  44, 49, 39, 56, 34, 53, 
  46, 42, 50, 36, 29, 32
};



/* INITIAL PERMUTATION (IP) */

INT IP[] = {
  58,50,42, 34,26,18,10,2,
  60,52,44,36,28,20,12,4,
  62,54, 46, 38, 30, 22, 14,6,
  64, 56, 48, 40,32,24, 16, 8,
  57, 49, 41, 33,25,17, 9,1,
  59, 51,43,35,27,19,11,3,
  61,53,45,37,29,21,13, 5,
  63,55, 47,39,31,23,15,7
};

/* INVERSE PERMUTATION (IP-1) */

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



/* REVERSE PERMUTATION (RFP) */

INT RFP[] = {
  8,40,16,48,24,56,32,64,
  7, 39,15,47,23,55,31,63,
  6,38,14,46,22,54,30,62,
  5,37,13,45, 21,53,29,61,
  4,36,12,44,20,52,28,60,
  3, 35, 11,43,19,51,27,59,
  2, 34, 10, 42,18, 50,26,58,
  1,33,9,41, 17, 49, 25,57
};

/* E BIT_SELECTION TABLE */


int INV_RFP[]= {
 57,49,41,33,25,17,9,1,
 59,51,43,35,27,19,11,3,
 61,53,45,37,29,21,13,5,
 63,55,47,39,31,23,15,7,
 58,50,42,34,26,18,10,2,
 60,52,44,36,28,20,12,4,
 62,54,46,38,30,22,14,6,
 64,56,48,40,32,24,16,8
};


INT E[] = {
  32, 1, 2, 3, 4, 5,
  4, 5,6, 7, 8, 9,
  8, 9, 10, 11, 12, 13,
  12, 13, 14, 15, 16, 17, 
  16, 17, 18, 19, 20, 21, 
  20, 21, 22, 23, 24, 25, 
  24, 25, 26, 27, 28, 29,
  28, 29, 30, 31, 32, 1
};


/* PERMUTATION FUNCTION P */
INT P[] = {
  16, 7, 20, 21, 
  29, 12, 28, 17,
  1, 15, 23, 26,
  5, 18, 31,10,
  2, 8, 24, 14,
  32, 27, 3, 9,
  19, 13, 30, 6,
  22, 11, 4, 25,
};


/* Inverse of P */
INT INV_P[] = {
	9, 17, 23, 31,
	13, 28, 2, 18,
	24, 16, 30, 6,
	26, 20, 10, 1,
	8, 14, 25, 3,
	4, 29, 11, 19,
	32, 12, 22, 7,
	5, 27, 15, 21,
};




/********************************************************************
 *UNPACK8()  Unpack 8 bytes at 8bits/byte into 64 bytes at 1 bit/byte
 ********************************************************************/

void unpack8(BYTE *packed, BYTE *binary)
{
  register INT i, j, k;
  
  for (i=0; i<8; i++) {
    k = *packed++;
    for (j=0; j<8;j++) *binary++ = (k>>(7-j))&(01) ;
  }
}


/********************************************************************
 *PACK8() Pack 64 bytes at 1 bits/byte into 8 bytes at 8 bit/byte
 ********************************************************************/

void pack8(BYTE *packed, BYTE *binary)
{
  register INT i, j, k;
  
  for (i=0; i<8; i++) {
    k = 0;
    for (j=0; j<8;j++) k  = (k<<1)+ *binary++;
    *packed++ = k;
  }
}


/* Key Scedule of 16 498-bit subkey generated from 64-bit key */

BYTE KS[16][48];


void set_the_key(INT sw1, BYTE *key, INT r)    /* type of cryption 0= encryption, 1= decryption */
{
  register INT i, j, k, t1, t2;
  // static BYTE key[64];
  static BYTE CD[56];
  
  
  // /* Unpack KEY from 8 bits/byte into 1 bit/byte */
  // unpack8(pkey, key);
  // /* printf(" key in 56 bits....\n"); */
  // /* permute unpacked key with PC1 to generate C and D*/
  for (i=0; i<56; i++) {
    CD[i] = key[PC1[i] -1];
    /* printf("%d", CD[i]); */
  }
  
  /* Rotate and permute C and D to generate 16 subkeys */
  for ( i=0; i<r; i++) { /**--*/
    /* Rotate C and D */
    for (j =0; j <shifts[i]; j++) {
      t1 = CD[0];
      t2 = CD[28];
      for ( k=0; k<27; k++) {
	CD[k] = CD[k+1];
	CD[k+28] = CD[k+29];
      }
      CD[27] = t1;
      CD[55] = t2;
    }
    /* Set the order of subkeys for type of encryption */
    j = sw1 ? r-1-i :i ;   /**--*/
    
    /* Permute C and D with PC2 to generate KS[i] */
    for (k=0; k< 48 ; k++)  KS[j][k] = CD[PC2[k] -1];
  }

  // for(k=0;k<48;k++)cout<<KS[5][k]<<" ";
  // cout<<endl;

  
  return;
  
}



/****************************************************************
		       DES
****************************************************************/



/* packed 64 bit Input block */   /* packed 64 bit output block */  /* number of rounds */

void des(BYTE *in,BYTE *out, INT r, char flag)                              
{
  register INT i, j, k, t;
  static BYTE block[64]; /* unpacked 64-bit input/output block */
  static BYTE LR[64], f[32], preS[48];

  
  unpack8(in, block);
  
  /* Permute unpacked input block with IP to generate L and R */
  /*
    printf("\nThe block after the initial permutation IP \n");
  */
  for (j =0; j<64 ; j++)
  {
          LR[j] = block[IP[j] -1];
          /*printf("%d", LR[j]);*/
  }

  /* Perform r rounds */
  /*
  printf(" In des 3rd round expandes block is \n");
  */

  for (i=0; i<r; i++)
  {  
    /* expand R to 48 bits with E and XOR  with ith subkey */
    // cout<<"\nRound "<<i<<"\nKey:\n";
    for( j=0; j<48; j++) {
      preS[j] = LR[E[j] +31]^KS[i][j];
    
      //  cout<<KS[i][j]<<" ";
    
    }




	  /* Map 8 6-bit blocks into 8 4-bit bolcks using S-boxes */
	  for (j=0; j<8; j++) {
	    /* Compute index t into jth s box */
	    k= 6*j;
	    t= preS[k];
	    t = (t<<1) | preS[k+5];     
	    t = (t<<1)| preS[k+1];      
	    t = (t<<1)| preS[k+2];
	    t = (t<<1)| preS[k+3];
	    t = (t<<1)| preS[k+4];
	    /* fetch t th entry fron jth sbox */
	    t = S[j][t];
	    /* generate 4-bit block from s-box entry */
	    k= 4*j;
	    f[k] = (t>>3)&1;
	    f[k+1] = (t >> 2) & 1;
	    f[k+2] = (t >> 1) & 1;
	    f[k+3] = t &1;
	    
	  }


	  
	  
	  for (j=0; j <32; j++) 
    {
      /* Copy R */
      t = LR[j+32];
      /* Permute Permute f w/ P and XOR w/ L to generate new R*/
      if (flag == 'N')
          LR[j+32] = LR[j]^f[P[j] -1];
      else
          LR[j+32] = LR[j]^f[INV_P[j] -1];
      /*LR[j+32] = LR[j]^f[j];*/
      /* copy original R to new L */
      LR[j] =t;
	  }
	  
  }
  /*
	printf( "\n\n I am in Des , block before final RFP permute\n");
	for(i=0; i<64; i++)
	printf( "%d", LR[i]);
  */
  /* Permute L and R with reverse IP-1 to generate output block*/
  for (j=0; j < 64; j++) block [j] = LR[RFP[j]-1];
	
  /* Pack data into 8 bits per byte */
	
  pack8(out, block);
  /*
	  out[9] = '\0';
  */
}


vector<map<INT,INT>> res(8);


void get(string a,INT *in)
{ 
  int i;
  INT arr[16];
  for( i=0;i<16;i++)   arr[i]=a[i]-'f';
  for( i=0;i<16;i+=2)  in[i/2]=(arr[i]<<4)|(arr[i+1]);
}

//! Decrypt  6 round DES
void decrypt6(string a, string ca,string b, string cb)
{
  INT in1[8],in2[8];
  INT inblock1[64],inblock2[64];
  INT outblock1[64],outblock2[64];
  // INT LRa_0[64],LRb_0[64];
  INT LRa_4[64],LRb_4[64];
  INT out1[8],out2[8];
  INT i,j,k,t;
  //input 1   
  // get(a,in1);
  // unpack8(in1,inblock1);

  // //input 2
  // get(b,in2);
  // unpack8(in2,inblock2);

  //cipher  1
  get(ca,out1);
  unpack8(out1,outblock1);
 

  //cipher 2
  get(cb,out2);
  unpack8(out2,outblock2);
  

  // // initial permutation
  // for (j =0; j<64; j++)
  // {
  //   LRa_0[j] = inblock1[IP[j] -1];
  //   LRb_0[j] = inblock2[IP[j] -1];

  // }



  //inverse RFP  

  for (j =0; j<64; j++)
  {
    LRa_4[j] = outblock1[INV_RFP[j] -1];
    LRb_4[j] = outblock2[INV_RFP[j] -1];
  }

 
  // let say l5 =r2
  //1st characteristic
  INT xorR2[32]={0,0,0,0, 0,1,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0,  0,0,0,0,  0,0,0,0};  
  //2nd characteristic
  // INT xorR2[32]={0,0,0,0, 0,0,0,0, 0,0,1,0, 0,0,0,0, 0,0,0,0, 0,0,0,0,  0,0,0,0,  1,0,0,0};  


  INT xorOutput_P[32];

  for(i=0;i<32;i++)
  {
    xorOutput_P[i]=(xorR2[i]^LRa_4[i+32]^LRb_4[i+32]);
  } 
  INT xorOutput_S[32]; 

  
  for(i=0;i<32;i++)
  {
    xorOutput_S[i]=xorOutput_P[INV_P[i] -1];
  }

  INT xorInput_S[48],Ea_Output[48],Eb_Output[48];

  for( j=0; j<48; j++)
  {
    Ea_Output[j] =LRa_4[E[j]-1];
    Eb_Output[j]=LRb_4[E[j]-1];
    xorInput_S[j]=(Ea_Output[j]^Eb_Output[j]);
  }


  for( i=0;i<8;i++) 
  {
    k=6*i;
    INT inXor=0,outXor=0,alpha=0;  // inXor=Beta  outXor=gamma
    
    for(j=0;j<6;j++)inXor=(inXor<<1)|xorInput_S[6*i+j];
    for(j=0;j<4;j++)outXor=(outXor<<1)|xorOutput_S[4*i+j];
    for(j=0;j<6;j++)alpha=(alpha<<1)|Ea_Output[6*i+j];
    for(j=0;j<64;j++)
    { 
      INT a1=j;
      INT a2=j^inXor;
      
      INT x1=(16*(2*(a1/32)+a1%2)) + (a1/2)%16;
      INT x2=(16*(2*(a2/32)+a2%2))+(a2/2)%16;
      if((S[i][x1]^S[i][x2])==outXor)
      {
        res[i][alpha^j]++;
      }
    }
  }


}



void find_the_key()
{
  freopen("key_set.txt","r",stdin);
  string plain="kkkkkkkkkkkkkkkk";
  string cipher="fjumkpimsmtmnoui";

  int key[64];
  for(int i=0;i<64;i++)cin>>key[i];
  
  for(int i=0;i<(1<<14);i++)
  {
 
    int arr[64];
    for(int j=0;j<64;j++) arr[j]=key[j];
    int bit[14]={};
    bitset<14> bit1(i);
    for(int j=0;j<14;j++)
    {
      bit[j]=bit1.test(13-j);
    }

    int k=0;
    for(int j=0;j<64;j++)
    {
      if(arr[j]==-1)arr[j]=bit[k++];
    }

    INT pkey[64];
    for(int j=0;j<64;j++) pkey[j]=arr[j];
    
    set_the_key(0,pkey,6);

    INT in1[8],in2[8];
    get(plain,in1);

    INT out[8];
    char c='N';
    des(in1,out,6,c);
    get(cipher,in2);
    int flag=1;
    for(int k=0;k<8;k++)
    {
      if(in2[k]!=out[k])flag=0;
    }
    if(flag){
        for(int k=0;k<64;k++)cout<<pkey[k]<<" ";
        cout<<endl;
    }

  }
}


void find_the_answer()
{
  INT key[64]={0,0, 1, 1, 1, 0, 0, 67, 1, 1, 1, 1, 0, 1, 0, 67, 1, 1, 0, 0, 1, 0, 1, 67, 1, 1, 1, 1, 1, 0, 1, 67, 0, 1, 1, 0, 1, 0, 0, 67, 1, 0, 1, 0, 0, 1, 0, 67, 1, 1, 1, 0, 1, 1, 0, 67, 0, 0, 0, 0, 1, 0, 0, 67};
  set_the_key(1,key,6);

  string a="iojnqqsuqsnoqlfl";
  string b="rjkuukpmstouosuu";
  INT in[8],out[8];
  get(a,in);
  des(in,out,6,'N');
  for(int i=0;i<8;i++)
  {
    cout<<char(out[i])<<" ";
  }
  cout<<"\n";
  get(b,in);
  des(in,out,6,'N');
  for(int i=0;i<8;i++)
  {
    cout<<char(out[i])<<" ";
  }
  cout<<"\n";
}


void find_the_Round6_Key()
{
  int x=10000; //number of input pairs
  vector< vector<string>> v(x,vector<string>(4));
  ifstream f;
  f.open("overall_input.txt");
  for(int i=0;i<x;i++)
  {
    f>>v[i][0];
    f>>v[i][2];
  }
  f.close();
  f.open("cipher_pair.txt");
   for(int i=0;i<x;i++)
  {
    f>>v[i][1];
    f>>v[i][3];
  }
  f.close();

  for(int i=0;i<x;i++)  
  {
    decrypt6(v[i][0],v[i][1],v[i][2],v[i][3]);
  }
  for(int i=0;i<8;i++)
  {
      INT mx1=0,mx2=0,key1=0,key2=0;
      for(auto p:res[i])
      {
        if(p.second>mx1)
        {
          mx2=mx1;key2=key1;

          mx1=p.second;key1=p.first;
        }
        else if(p.second > mx2)
        {
           mx2=p.second;key2=p.first;
        }
      }

      cout<<"Key "<<i+1<<" :"<<key1<<"  freq: "<<mx1<<"   ,  "<< key2<<"  freq: "<<mx2<<endl;
  }
  
}


int main()
{ 
  
  
  // find_the_round6_key();
  find_the_key();
  // find_the_answer();

}


