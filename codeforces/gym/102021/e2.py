def gcd(a, b):
    if a<b:
        a, b = b, a
    if a%b==0:
        return b
    return gcd(b, a%b)

def is_prime(k):
    if k<2: return False
    if k==2: return True
    if k%2==0: return False
    i = 3
    while i*i<=k:
        if k%i==0:
            return False
        i += 2
    return True

n = int(input())
for q in range(n):
    swap = False
    a, b = map(float, input().split(' '))
    if a<b:
        a, b = b, a
        swap = True
    # a *= 1e5
    # b *= 1e5
    a = round(a*1e5)
    b = round(b*1e5)
    # print(a, b, swap)
    g = gcd(a, b)
    # print(g)
    # a /= g
    # b /= g
    p = int(a/g)
    q = int(b/g)
    # print(p, q)

    if q==1:
        if p==1:
            print("2 2")
        else:
            print('impossible')
        continue

    prime = True
    for k in [p, q]:
        prime = prime and is_prime(k)
    # for k in [p, q]:
    #     i = 2
    #     while i*i<=k:
    #         if k%i==0:
    #             prime = False
    #             break
    #         i += 1

    if not prime:
        print('impossible')
        continue

    if swap:
        p, q = q, p
    print(p, q)
    
    # print('---')