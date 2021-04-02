
# Substitution Cipher

## Commands used in the game 
<pre>
Reaching the cipher text was straightforward using following commands-  
 climb -> read ->  enter -> read
</pre>


## Analysis



```
In the given encrypted text, we can see repetition of some patterns (e.g mey) and frequency of some letters like y, m is much
more than normal text which clearly indicates substitution cipher scheme is used for encryption. We first ran the frequency
analysis on the alphabets and found ‘y’ and ‘m’ to be the two most frequently occurring letters.

Cipher Text 	Frequency	No. of occurrences 
y 		       13.95		36 
m 		       10.85		28 

Hence, we replaced ‘y’ with ‘e’ and ‘m’ with ‘t’, as the frequency of these characters was closest to the frequency of ‘e’
and ‘t’ respectively.

1) Then patterns such as 't_e' at the start of some sentences made it easy to guess that 'e' maps to 'h' such that
the pattern "t_e" gives the word "the".
	
2) Then after carefully observing the last sentence of the entire text, which was “th????the?”, we know the third
letter cannot be 'e', as 'y' is already mapped to 'e'. Hence we looked for 4 letter words starting with th.
And "this" was the best match as it makes the sentence "this is the_".

3) Now, the second sentence(in encrypted text) starts with 'P' and the second character in the decrypted text was 'S'.
By pairing of letters, we can say ‘P’ maps to either ‘A’ or ‘U’. We moved on with the choice of ‘A’.

4) The first sentence ends with "the?a?es". Searching for words with patterns similar to "?a?es", we found the word "caves"
which was quite relatable to the assignment, so we made substitutions('i' → 'c' and 'b' → 'v').

5) Now words like "chamber" in the first sentence and "can" in the second sentence seemed quite easy to observe and on making
corresponding substitutions, it was easy to come up with suitable substitutions for other alphabets as well.

6) On reading the decrypted message we found the password is tyRgU03diqq. 

The decrypted message says that the cipher was a simple substitution cipher, but with  digits shifted by 8 places. But here
the same encryption was applied for 8 as well, therefore 8 is not the actual number in the plaintext. Let’s assume d is the
actual digit in plaintext, then after encryption it will get shifted by d, and the number in cipher text will be 2d mod 10.
As , 2d mod 10 = 8 ,which means d = 4 or 9.Then, trying these 2 possibilities our  final password  can be  tyRgU69diqq or
tyRgU14diqq. tyRgU69diqq is the correct choice.


```




## Mapping Used in Encryption


<pre>
For a given encryption algorithm E, Plaintext space P and cipher text space C. We can say the following :
E maps P→ C
 and let decryption algorithm is D then 
D maps C → P

For the current level P: [a-z, A-Z, 0-9] and C:[a-z, A-Z, 0-9]. 
Encryption Scheme used is as follows : 
	{ e→y, t→m, s→a, i→w, h→e, o→g, r→s, a→p, n→h, c→i, m→j, b→o, u→n, f→t, d→u, g→r, l→k, w→v, p→f, y→x, q→d
	, v→b , 0→4, 1→5, 2→6, 3→7, 4→8, 5→9, 6→0, 7→1, 8→2, 9→3 }

In the above mapping we have not written the mapping of capital letters as it is similar to the mapping
of small letters.

</pre>

