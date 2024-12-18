def prime(p):

    if p<=1:
        return (-1)
    else:
        for k in range (2,p-1,1):
            

    




p = int(input("Enter the value of p: "))
q = int(input("Enter the value of q: "))

N = p*q

e = int(input("Enter the value of e: "))

#ed = 1 mod phi(N)

phi = (p-1)*(q-1)
d = pow(e, -1, phi)

print("The value of d is: ", d)
print("The value of N is: ", N)

PT = int(input("Enter the plain text: "))

CT = (PT**e)%N

print("The Cipher Text is: ", CT)

CT2 = int(input("Enter the CT value to decrypt: "))

PT2 = (CT2**d)%N

print("The PT value is: ", PT2)


