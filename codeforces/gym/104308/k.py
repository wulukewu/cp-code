t = int(input())
while(t):
    t -= 1
    n = int(input())
    sma = [" " for i in range(n)]
    for i in range(n):
        sma[i] = str(input())
    big = str(input())

    # print(sma)
    # print(big)
    # print(len(big))

    ok = True
    ans = 1
    while(len(big) > 0 and ok):
        ok = False
        for i in sma:
            if(big.count(i) != 0):
                # print(big,i,big.count(i))
                ok = True
                ans += big.count(i)
                big = big.replace(i,"")
        # print(ans,big)
    if(not ok):
        print("No")
    else:
        print("Yes")
        print(ans)