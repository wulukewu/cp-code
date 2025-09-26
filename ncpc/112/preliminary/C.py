now = int(input())
n,m = map(int,input().split())
alls = [" " for i in range(m)]
for i in range(m):
    s = str(input())
    alls[i] = s
    # print(i,s)
for i in range(m):
    move = False
    if(now != n):
        # print(2*now-1,alls[i][2*now-1])
        if(alls[i][2*now-1] == "_"):
            now += 1
            move = True
    if(not move and now != 1):
        if(alls[i][2*now-3] == "_"):
            now -= 1
            move = True
print(now)