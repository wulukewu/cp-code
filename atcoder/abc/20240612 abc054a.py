import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

a, b = map(int, input().split())

if a == b:
    print('Draw')
else:
    if a == 1:
        print('Alice')
    elif b == 1:
        print('Bob')
    else:
        if a > b:
            print('Alice')
        else:
            print('Bob')