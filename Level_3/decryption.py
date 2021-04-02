
 
#  This code was used to do modular calculation
#  required for decryption


def modInverse(a, m):
     return power(a, m - 2, m)
 
# To compute x^y under modulo m

def power(x, y, m):
 
    if (y == 0):
        return 1
 
    p = power(x, y // 2, m) % m
    p = (p * p) % m
 
    if(y % 2 == 0):
        return p
    else:
        return ((x * p) % m)
 

 
 
 
# Driver Code
p = 19807040628566084398385987581  #mod
y1= 11226815350263531814963336315
y2= 9190548667900274300830391220
y3= 4138652629655613570819000497
 
# Function call
a=(y2*modInverse(y1, p))%p #g^2021 = y2 * y1^-1
b=(y3*modInverse(y1, p))%p #g^9189 = y3 * y1^ -1

g= (power(a,632,p)*modInverse(power(b,139,p),p))%p

x= (y1*modInverse(power(g,324,p), p))%p   #password

print(g)
print(x)
