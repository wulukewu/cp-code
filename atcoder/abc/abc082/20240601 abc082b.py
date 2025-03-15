import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

s = input()
t = input()
arr = {'a':1, 'b':2, 'c':3, 'd':4, 'e':5, 'f':6, 'g':7, 'h':8, 'i':9, 'j':10, 'k':11, 'l':12, 'm':13, 'n':14, 'o':15, 'p':16, 'q':17, 'r':18, 's':19, 't':20, 'u':21, 'v':22, 'w':23, 'x':24, 'y':25, 'z':26}

S = []
T = []
for i in s:
    S.append(arr[i])
for i in t:
    T.append(arr[i])

S.sort()
T.sort()

det = False
not_skip = True
while len(S) > 0 and len(T) > 0:
    # print(S, T)
    if S[0] < T[-1]:
        det = True
        break
    elif S[0] > T[-1]:
        det = False
        not_skip = False
        break
    else:
        S.pop(0)
        T.pop(-1)
    
    # if len(S) == 0:
    #     if len(T) > 0:

if not_skip:
    if len(S) == 0 and len(T) > 0:
        det = True


if det:
    print('Yes')
else:
    print('No')