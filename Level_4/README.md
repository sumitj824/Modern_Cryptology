# Breaking 6 Round DES using 3 round characteristics

## Commands used in the game
<pre> 
Started from level 4 and entered following command :
go -> dive -> dive -> back -> pull -> back -> back -> go -> wave -> exit

After that we Start the game and entered following command in level 4:
read -> password

</pre>
## Analysis

<pre>

To decrypt the password which was encrypted using 4 round , 6 round or 10
round DES. We started by assuming it to be a 4 round DES, but we didn’t get the
expected results, hence it can be concluded that it is not a 4 round DES. Afterwards we
tried assuming it to be a 6 round DES.


It was given that two letters were for one byte and DES has a block size of 64
bits or 8 bytes so 16 letters represented 1 block size. As letters in output
belongs to {f, g, ..., u} which corresponds to only 16 letters  so we thought that
input also consists of only these letters, as 16 letters could be represented by
four bits and each letter was mapped to a number from 0 to 15 (i.e., ‘f’ was mapped
to 0 and ‘u’ was mapped to 15). So now we have converted our input to a 64 bit
string of 0s and 1s.


To find the key of 6-round DES ,we used following  two different characteristics :

1. Consider the 3-round characteristic :

(40080000,04000000 , 1/4 ,04000000,00000000, 1, 00000000,04000000, 1/4 ,04000000,40080000)

(^  is  xor operator)
Since R3^R3’= 40080000 (hex) = 0100 0000 0000 1000 0000 0000 0000 0000, 
E(R3)^E(R3’) = 001000 000000 000001 010000 000000 000000 000000 000000
So, Xor of input to S-box in Round 4 = E(R3)^E(R3’)
We can see that the xor of input corresponding to S-box S2,S5,S6,S7,S8 is zero so 
the xor of output of these S-boxes will also be zero. 

We know R6 and R6’,
Xor of output of Permutation in Round 6 = (R6^L5)^(R6’ ^ L5’)
So, Xor of output of S-boxes in Round 6 
 = Inverse_Perm((R6^R6’)^(L5 ^ L5’))
  = Inverse_Perm(R6^R6’) ^ Inverse_Perm(L5^L5’)
 = Inverse_Perm(R6^R6’) ^ Inverse_Perm(R4^R4’)
 = Inverse_Perm(R6^R6’) ^ (Inverse_Perm(R4)^Inverse_Perm(R4’))
 = Inverse_Perm(R6^R6’) ^ (S(R4)^S(R4’) ) [Inverse permutation is a linear function]

Here, S(R4) is the output of S-boxes corresponding to round 4. Similarly for S(R4’).

As we know ,S(R4)^S(R4’) for  S-box S2,S5,S6,S7,S8 is zero in round 4 we can find xor 
of the output of S-boxes S2,S5,S6,S7,S8 in Round 6 using this characteristic. 

Also ,we know R5=L6 and R5’=L6’ we can find the output of expansion in Round 6 
corresponding to both pairs , so we can find the Xor of input to the S-boxes in Round 6.

Now, we know xor of input to S-boxes and xor of output of S-box S2,S5,S6,S7,S8. So we can
find K2,K5,K6,K7,K8 (where Round 6 key, K = (K1, K2, ...., K8)) using this characteristic
(using methods discussed in class). 


2. Consider another 3-round characteristic :

(00200008,00000400 , 1/4 ,00000400,00000000, 1, 00000000,00000400, 1/4 ,00000400,00200008)


Since R3^R3’= (00200008)16 = 0000 0000 0010 0000 0000 0000 0000 1000, 
E(R3)^E(R3’) = 000000 000000 001000 000000 000000 000000 000001 010000
So, Xor of input to S-box in Round 4 = E(R3)^E(R3’)
We can see that the xor of input corresponding to S-box S1,S2,S4,S5,S6 is zero so the xor of 
output of these S-boxes will also be zero. 

As shown for the previous characteristic, using the same analysis we can find XOR of input of 
S-boxes and XOR of output of S-box S1,S2,S4,S5,S6 in round 6. So,we can find K1,K2,K4,K5,K6 
(where Round 6 key, K = (K1, K2, ...., K8)) using this characteristic (using methods discussed
 in class). 

For first characteristic, we get expected output with probability 1/16. So to find the K2,K5,K6,
K7,K8 we generated 5000 input pairs having xor 40080000 04000000 (after initial permutation) and
 corresponding ciphers using script.sh .In script.sh firstly we are generating input pairs having
  xor 40080000 04000000 using gen_input_pair.cpp and then corresponding ciphers are generated 
  using input.cpp and read.cpp . So script.sh will output overall_input.txt and cipher.txt . 

Then find_the_Round6_Key function in code.cpp finds K2,K5,K6,K7,K8 as discussed in the first 
characteristic. In find_the_Round6_Key function, we take an input pair a, b and corresponding 
cipher texts ca, cb. After converting these strings of 16 letters to 64 bits (using the process
discussed above) we apply inverse RFP on ca, cb to find LRa_6 (cipher block corresponding to ca)
and LRb_6. Now we know R6 and R6’ and Xor of Input is 40080000 04000000 . Using the first 
characteristic we find the Xor of input to the S-boxes and xor of output of S-box S2,S5,S6,S7,S8
in Round 6. We did the same thing discussed to find the set of possible values of keys K2,K5,K6,K7,
K8. For 5000 pairs we find the most occurring value. So we get ,

K2 = 51, K5 = 16, K6 = 30, K7 = 12, K8 = 54

Similarly for second characteristic , we generate input pairs having xor 
0020000800000400(after initial permutation). After following similar procedure as above, we get 

K1 = 45, K2 = 51, K4 = 7, K5 = 16, K6 = 30

Now we know, K1, K2, K4, K5, K6, K7, K8, i.e., for key K (key for round 6), we have 42 bits out of 
48 bits (we don’t know K3).

So for Final_K (overall key for this DES), we can find  42 bits out of 56 bits.

The key_schedule.cpp gives us the knowledge how the bits were permuted giving output in scheduledkey.txt.

Using key_set.cpp we mapped the bit of key K(key for round 6) to Final_K giving output in key_set.txt


The Final_K is: 
x01110xyx111010y1xx0101yx11x101yx11xx00y10x0010y11x0110yx000x00y 





Here x=-1 , means the values we don't know ,we need to find them
y is a dummy bit ,As we know every 8th bit is used to store the xor of another 7 bit. 
Hence its value is never referred to in our code. In our code we had represented x 
with -1 and y with 67

So we know 42 bits out of 56 bits of Final_k . Now to find the remaining 14 bits in  
find_the_key function in code.cpp, we apply bruteforce over all 2^14 combinations.

Given input : kkkkkkkkkkkkkkkk   
Given output : fjumkpimsmtmnoui 
Final Key :  0011100y1111010y1100101y1111101y0110100y1010010y1110110y0000100y
finding each y by taking xor of 7 bits preceding them. We have,


Final Key :  0011100111110101110010101111101001101001101001011110110100001001

Then we run find_th_answer function in code.cpp and find the plaintext corresponding
 to each 16 blocks of given password using the Final key.

Encrypted password : iojnqqsuqsnoqlflrjkuukpmstouosuu
Decrypted password :{112,115,117,116,105,117,100,103,104,114, 48, 48, 48, 48, 48, 48}


As the number lies between 48 and 127 we thought that these could be ASCII codes.
We converted this numbers into characters , we get 
psutiudghr000000

We tried this but this was not the password. So, we thought 0 was just to pad.
So using "psutiudghr" as a password, we cleared the level.

</pre>

