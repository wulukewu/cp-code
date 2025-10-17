# def prem(x):
#     if x == n:
#         # print((brr, crr))
#         arr.append((brr.copy(), crr.copy()))
#         return

#     brr.append(x)
#     prem(x+1)
#     brr.pop()
#     crr.append(x)
#     prem(x+1)
#     crr.pop()

# def pail(brr):
#     b = ''.join(s[i] for i in brr)
#     # print(b)
#     return b == b[::-1]

# def ince(crr):
#     return all(s[crr[i]]<=s[crr[i+1]] for i in range(len(crr)-1))
    

# t = int(input())

# for tt in range(t):
#     n = int(input())
#     s = input()

#     arr = []
#     brr = []
#     crr = []
#     prem(0)

#     no_ans = True
#     for brr, crr in arr:
#         # print(brr, crr)
#         if pail(brr) and ince(crr):
#             print(len(crr))
#             print(' '.join(str(i+1) for i in crr))
#             no_ans = False
#             break
    
#     if no_ans:
#         print(-1)

def solve():
    global found
    def dfs(x):
        global found
        if found:
            return
        if x==n:
            if pail(brr) and ince(crr):
                print(len(crr))
                print(' '.join(str(i+1) for i in crr))
                found = True
            return
        
        brr.append(x)
        dfs(x+1)
        brr.pop()
        if found: return

        crr.append(x)
        dfs(x+1)
        crr.pop()

    def pail(brr):
        b = ''.join(s[i] for i in brr)
        return b == b[::-1]
    
    def ince(crr):
        return all(s[crr[i]] <= s[crr[i+1]] for i in range(len(crr)-1))
    
    n = int(input())
    s = input()
    brr, crr = [], []
    found = False
    dfs(0)
    if not found:
        print(-1)

t = int(input())
for _ in range(t):
    solve()