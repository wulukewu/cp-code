def solve():
    n = int(input())
 
    if n == 1:
        print(2)
        return
    
    if n == 2:
        print(3)
        return

    first = 2  
    second = 3
    
    for i in range(3, n + 1):
        target = first + second
        first = second
        second = target
    
    print(target)

solve()