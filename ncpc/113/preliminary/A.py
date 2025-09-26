while(True):
    y1,y2,x1,x2 = map(int,input().split())
    if(y1 == 0 and y2 == 0 and x1 == 0 and x2 == 0):
        break
    print(x1,y1,x2+1,y2+1)