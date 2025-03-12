import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

S = input()
arr = []
add = True

for i in range(len(S)):
    if S[i] == '|':
        if add:
            add = False
        else:
            add = True
    elif add:
        arr.append(S[i])

ans = ''.join(arr)
print(ans)