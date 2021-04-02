# Playfair Cipher

## Commands used in the game
<pre> 
Reaching the cipher text was straightforward using following commands-  
1. read

</pre>
## Analysis

<pre>

Firstly, we did Frequency analysis of cipher text and found that no letter has
a frequency percentage of more than 10%  ( a has highest 9.44 %). Such skewed
English text would be rare and an attempt at substitution cipher indeed quickly gets
stuck into contradictory swaps. Thus, substitution cipher can be eliminated. Since
permutation ciphers do not change the frequency, we can also eliminate permutation
ciphers. 


After writing the ‘go’ instead of ‘read’ command in level 2 we found a message
on our screen. After carefully reading the message of the Cave Man. We found 
following code and  message :


Code:
…   .    -.-.    ..-   .-.     ..      -    -.--

Message :
"You have been blessed, my child. Keep in mind that 
you must always believe in yourself and PLAY FAIR".


So, after reading the above message it was clear that the Playfair cipher is
used for encryption. We have mentioned the meaning of code and how we find the key
of Playfair cipher in Decryption algorithm.


</pre>


## Decryption Algorithm

<pre>

We used the Standard method to decrypt the Playfair cipher. Using following
steps we decrypt the ciphertext:

1)To decrypt the Playfair cipher we first need to find the key.

Finding the key :
In the message of Cave Man, there were some strange symbols on the boulder.
Cave Man mentioned that it appears like some code. These codes mainly used dot and 
dash. So, we google searched dash and dot code , discovering we found that these
codes are Morse Code. So,Using table of Morse Code we find the following alphabet
corresponding  to each code.


…   .    -.-.    ..-   .-.     ..      -    -.--
S    E   C     U    R      I      T    Y

So, the key used was “SECURITY” .

2) After finding the key ,we made the key square which is a 5 x 5 grid of
alphabets which act as a key for encrypting the plaintext. The initial alphabets  in the
key square are the key found above ,so following is key square we made :


		S  E   C   U  R
		I  T   Y   A  B
		D  F   G   H  K
		L  M   N   O  P
		Q  V   W   X  Z

3) Now, we remove all the whitespaces and punctuation from the ciphertext, since
they are not a part of the encryption, and can easily be replaced after decryption.

Then, we split it into pairs of two letters and for each pair using following
standard rule  we decrypted each pair : 

(i) If both letters are in the same row (in above key square) : Take the the
letter to the left of each one (going back to the rightmost if at the leftmost
position)


(ii) If both the letters are in the same column: Take the letter above each
one (going back to the bottom if at the top) 

(iii) If neither of the above rules is true: Form a rectangle with the two
letters and take the letters on the horizontal opposite corner of the rectangle


e.g  TR  ->  BE         ( using rule (iii)   )
       XY  ->  WA        (  using rule (iii)   )

Similarly , we decrypted for each pair and after that we aligned each word
similar to cipher text and inserted white spaces and punctuation.So, the Decrypted text
is :


BE WARY OF THE NEXT CHAMBER, THERE IS VERY LITTLE JOY THERE.
SPEAK OUT XTHE PASSWORD “OPEN_SESAME” TO GO THROUGH. MAY XYOU
HAVE THE STRENGTH FOR THE NEXT CHAMBER. TO FIND THE EXIT YOU
FIRST WILXL NEXED TO UTTER MAGIC WORDS THERE. 
</pre>