from sage.all import *


def coppersmith_howgrave_univariate(pol, modulus, beta, mm, tt, XX):
    """
    Coppersmith revisited by Howgrave-Graham
    
    finds a solution if:
    * b|modulus, b >= modulus^beta , 0 < beta <= 1
    * |x| < XX
    """
    #
    # init
    #
    dd = pol.degree()
    nn = dd * mm + tt

    #
    # checks
    #
    if not 0 < beta <= 1:
        raise ValueError("beta should belongs in (0, 1]")

    if not pol.is_monic():
        raise ArithmeticError("Polynomial must be monic.")

    #
    # calculate bounds and display them
    #
    """
    * we want to find g(x) such that ||g(xX)|| <= b^m / sqrt(n)

    * we know LLL will give us a short vector v such that:
    ||v|| <= 2^((n - 1)/4) * det(L)^(1/n)

    * we will use that vector as a coefficient vector for our g(x)
    
    * so we want to satisfy:
    2^((n - 1)/4) * det(L)^(1/n) < N^(beta*m) / sqrt(n)
    
    so we can obtain ||v|| < N^(beta*m) / sqrt(n) <= b^m / sqrt(n)
    (it's important to use N because we might not know b)
    """
    #
    # Coppersmith revisited algo for univariate
    #

    # change ring of pol and x
    polZ = pol.change_ring(ZZ)
    x = polZ.parent().gen()

    # compute polynomials
    gg = []
    for ii in range(mm):
        for jj in range(dd):
            gg.append((x * XX)**jj * modulus**(mm - ii) * polZ(x * XX)**ii)
    for ii in range(tt):
        gg.append((x * XX)**ii * polZ(x * XX)**mm)
    
    # construct lattice B
    BB = Matrix(ZZ, nn)

    for ii in range(nn):
        for jj in range(ii+1):
            BB[ii, jj] = gg[ii][jj]


    # LLL
    BB = BB.LLL()

    # transform shortest vector in polynomial    
    new_pol = 0
    for ii in range(nn):
        new_pol += x**ii * BB[0, ii] / XX**ii

    # factor polynomial
    potential_roots = new_pol.roots()
    # print "potential roots:", potential_roots

    # test roots
    roots = []
    for root in potential_roots:
        if root[0].is_integer():
            result = polZ(ZZ(root[0]))
            if gcd(modulus, result) >= modulus^beta:
                roots.append(ZZ(root[0]))

    # 
    return roots


################################################################
################################################################


N = 84364443735725034864402554533826279174703893439763343343863260342756678609216895093779263028809246505955647572176682669445270008816481771701417554768871285020442403001649254405058303439906229201909599348669565697534331652019516409514800265887388539283381053937433496994442146419682027649079704982600857517093
e = 5
c = 23701787746829110396789094907319830305538180376427283226295906585301889543996533410539381779684366880970896279018807100530176651625086988655210858554133345906272561027798171440923147960165094891980452757852685707020289384698322665347609905744582248157246932007978339129630067022987966706955482598869800151693



def break_RSA(x_str):
    x_binary = ''.join(['{0:08b}'.format(ord(y)) for y in x_str])
    for i in range(0,208,4):
        P.<m> = PolynomialRing(Zmod(N)) #, implementation='NTL')
        pol = ((int(x_binary,2)<<i)+m)^e - c
        dd = pol.degree()
        # Tweak those
        beta = 1                                # b = N
        epsilon = beta / 7                      # <= beta / 7
        mm = ceil(beta**2 / (dd * epsilon))     # optimized value
        tt = floor(dd * mm * ((1/beta) - 1))    # optimized value
        XX = ceil(N**((beta**2/dd) - epsilon))  # optimized value

        # Coppersmith
        roots = coppersmith_howgrave_univariate(pol, N, beta, mm, tt, XX)

        # output
        n=0
        if roots:
            print("Root is :")
            print("\nIn decimal :",str(roots))
            print("\nIn hexadecimal :",hex(roots[0]))
            
if __name__ == "__main__":
    S = [
    # "Astralis: This door has RSA encryption with exponent 5 and the password is:",
    # "Astralis: This door has RSA encryption with exponent 5 and the password is",
    # " Astralis: This door has RSA encryption with exponent 5 and the password is:",
    # "  Astralis: This door has RSA encryption with exponent 5 and the password is:",
    # "  Astralis: This door has RSA encryption with exponent 5 and the password is:  ",
    # "Astralis: This door has RSA encryption with exponent 5 and the password is ",
    # "Astralis: This door has RSA encryption with exponent 5 and the password is  ",
    # "astralis: this door has rsa encryption with exponent 5 and the password is:",
    # "Astralis",
    # "CS641A: Modern Cryptology",
    # "cs641a: modern cryptology",
    # "cs641a",
    # "CS641A",
    # "You reach a chamber that has five exits, numbered one through five. Exit numbered five is closed with a panel next to it. Remaining are open",
    # "You reach a chamber that has five exits, numbered one through five. Exit numbered five is closed with a panel next to it. Remaining are open.",
    # "59 6f 75 20 73 65 65 20 61 20 47 6f 6c 64 2d 42 75 67 20 69 6e 20 6f 6e 65 20 63 6f 72 6e 65 72 2e 20 49 74 20 69 73 20 74 68 65 20 6b 65 79 20 74 6f 20 61 20 74 72 65 61 73 75 72 65 20 66 6f",
    "You see a Gold-Bug in one corner. It is the key to a treasure found by"
    ]
    #In above list of text we get solution for last text. i.e. last one is correct padding

    for i in S:
        break_RSA(i)



