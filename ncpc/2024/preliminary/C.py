while True:
    n = int(input())
    if n == 0: break

    for i in range(100):
        if n % 2 == 0:
            n = n / 2
        else:
            n = 3*n + 1
        
        if n == 1:
            break
    
    print(int(n))

