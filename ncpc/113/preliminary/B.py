def gcd(x, y): # x>y
    if x<y: x, y = y, x
    if y == 1:
        return 1
    if x % y == 0:
        return y
    else:
        return gcd(y, x%y)


while True:
    pq = input()
    if pq=='0': break

    p, q = map(int, pq.split('/'))
    g = gcd(p, q)
    p //= g
    q //= g
    a = p // q
    p -= q * a
    # print(a, p, q)

    if p == 0:
        print(a)
    elif a == 0:
        l = max(len(str(p)), len(str(q)))
        print(f"{' '*(l-len(str(p)))}{p}")
        print(f"{'-'*l}")
        print(f"{' '*(l-len(str(q)))}{q}")
    else:
        l = len(str(a)) + max(len(str(p)), len(str(q)))
        # print(l)
        print(f"{' '*(l-len(str(p)))}{p}")
        print(f"{a}{'-'*(l-len(str(a)))}")
        print(f"{' '*(l-len(str(q)))}{q}")
    print()

    