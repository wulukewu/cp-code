n = int(input())
nn = n

# t = 0
visit = []
ans = False
while True:
    x = 0
    for i in str(nn):
        j = int(i)
        x += j ** 2
    nn = x
    # print(x)

    if x in visit:
        break
    else:
        visit.append(x)

    if x == 1:
        ans = True
        break
    elif x == n:
        break
    # t += 1
    # if t>10: break

if ans:
    print('HAPPY')
else:
    print('UNHAPPY')