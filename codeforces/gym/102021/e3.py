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

m = 20000000
prime = [True for _ in range(m)]
prime[0] = False
prime[1] = False
for i in range(2, m):
    if not prime[i]: continue
    j = 2*i
    while j<m:
        prime[j] = False
        j += i


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
    p = a // g
    q = b // g
    # print(p, q)

    if q==1:
        if p==1:
            print("2 2")
        else:
            print('impossible')
        continue

    det = True
    for k in [p, q]:
        # det = det and is_prime(k)
        det = det and prime[k]
    # for k in [p, q]:
    #     i = 2
    #     while i*i<=k:
    #         if k%i==0:
    #             prime = False
    #             break
    #         i += 1

    if not det:
        print('impossible')
        continue

    if swap:
        p, q = q, p
    print(p, q)
    
    # print('---')