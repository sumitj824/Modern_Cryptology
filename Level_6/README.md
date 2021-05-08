# RSA decryption

## Commands used in the game
<pre> 

To reach the cipher text, we used  the command in the following sequence :       
exit1 -> exit2 -> exit4 -> exit3 -> exit1 -> exit4 -> exit4 -> exit2 -> exit2
-> exit1 ->read                                                   
Explanation: Since on the first screen it was written that the exits are numbered
from 1 to 5 and exit 5 is closed. So, we started for all possible commands from exit1
to exit4. In the first screen after entering exit1 we move to the next screen, then 
in the second screen after entering exit1 we get to the same screen, so we enter exit2
and move to the next screen. Similarly entering any other command than exit 4 we weren’t
proceeding to a new screen other than the previous seen screen, So entering exit4 we moved to 
the next screen. Similarly we did this until we moved to the second last screen where entering
exit1 to exit4  , doesn’t make any progress. We entered the read command and found the message.
</pre>
## Analysis

<pre>
This level has RSA encryption, with a small exponent(i.e. 5 ). n and c are given in the 
problem statement. RSA encryption and decryption work as follows:
Encryption: c=m^e mod n
Decryption: m=c^d mod n

Obviously, we cannot straightway go for factoring n , because n is very large (i.e. 1023 bits).
Next, we could try to compute d , but as n couldn’t be factorized we cannot find phi(n) which 
means we cannot compute d efficiently.

Instead, since the exponent is very small (i.e. 5), we can use a low-exponent based 
attack(Coppersmith’s Attack).Now it may be possible that, to make the encryption more 
secure, since the public exponent is low , a padding may have been added to the plaintext 
before encryption. Before proceeding with the Coppersmith’s Attack ,we first need to check 
if any padding is used or not . This can be done by checking if c^(1/e) is integer or not.
 We computed the same and found that padding is added.


Let x be the padding , with the padding the equation becomes:
(x+M)^e = c mod n

In this equation e,c and n are known. We will try to guess x to find the padding. After that 
we used Coppersmith’s Attack to find the plaintext.


<strong>Coppersmith’s Theorem : </strong>

Let n be an integer and f be a polynomial. 
Given n and f,one can recover in polynomial time all x_0 such that f(x_0)= 0 mod n and 
x_0 < N^(1/delta).So ,we formed our problem as f(M)=(x+M)^e mod n. If M < n^(1/e) ,
we will find the plaintext as the root to this polynomial.For solving this polynomial
we used the code from open source github[1]. We modified the code as follows to compute
the polynomial modulo n:

We converted padding x to binary form x_binary.
The length of password M is unknown. But, from our assumption M < n^(1/e), 
M can’t be longer than 208 bits. So, the length of M can be guessed using brute force.
Thus, the final polynomial is pol= ((x_binary << length_M)+ M)^e-c
Using Coppersmith’s Theorem and LLL (Lattice reduction) for the above polynomial we can find the root. 

So, if we can find the padding we will be able to find the root.

<strong>Finding the padding : </strong>

Obviously, we cannot loop through all the possible paddings. So instead, we tried 
to use the sentence given in the problem statement, “Astralis: This door has … is:”
(and some simple variants) as the padding text. For each candidate padding text we 
tried to find the root using code.sage in which we follow the same step as in the 
above theorem.We tried following padding and some similar paddings but we were not
able to figure out the exact padding.

1.Astralis: This door has RSA encryption with exponent 5 and the password is:
2.Astralis: This door has RSA encryption with exponent 5 and the password is
3. Astralis: This door has RSA encryption with exponent 5 and the password is:
4.Astralis
5.CS641A: Modern Cryptology
6.cs641a: modern cryptology
7.You reach a chamber that has five exits, numbered one through five. Exit numbered 
five is closed with a panel next to it. Remaining are open

After that we opened the game hoping that there could be some hints related to padding.
We notice that while reaching the ciphertext we are getting some hexadecimal number on 
screen. We got following hexadecimal numbers corresponding to screen:

Screen 2 :59 6f 75 20 73 65 65 20
Screen 3 :61 20 47 6f 6c 64 2d 42
Screen 4 :75 67 20 69 6e 20 6f 6e
Screen 5 :65 20 63 6f 72 6e 65 72
Screen 6 :2e 20 49 74 20 69 73 20
Screen 7 :74 68 65 20 6b 65 79 20
Screen 8 :74 6f 20 61 20 74 72 65
Screen 9 :61 73 75 72 65 20 66 6f
Screen 10 :75 6e 64 20 62 79

We concatenated each number and tried this string as padding. But this doesn’t give any root. 
So,we thought to convert string of concatenated numbers to ASCII and got following text:
You see a Gold-Bug in one corner. It is the key to a treasure found by

After trying the above text as padding ,the obtained root is
595069740817087294497, which in hexadecimal is 20 42 40 68 75 62 41 6c 21. 
Now we converted each byte ( pair of hex) to its corresponding ASCII character to get 
the final password as B@hubAl! .



References :

[1] Link to github code: https://github.com/mimoo/RSA-and-LLL-attacks


</pre>


