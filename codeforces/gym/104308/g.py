t = int(input())

change = ["z","x","c","v","b","n","m"]
while(t):
    t -= 1
    s = str(input())
    for i in change:
        if(i in s):
            s = s.replace(i,"")
    print(s)