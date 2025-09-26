while(True):
    n = int(input())
    if(n == 0):
        break
    coes = [[] for i in range(n)]
    print()
    print(f"n = {n}")
    
    for i in range(n):
        nums = list(map(str,input().split()))
        if(nums[0][0] != "-"):
            a = "+" + nums[0]
        else:
            a = nums[0]
        if(nums[1][0] != "-"):
            b = "+" + nums[1]
        else:
            b = nums[1]
        c = nums[2]
        print(f" {a} X1 {b} X2 = {c}")
        if("/" in nums[0]):
            p1,q1 = map(int,nums[0].split("/"))
        else:
            p1 = int(nums[0])
            q1 = 1
        if("/" in nums[1]):
            p2,q2 = map(int,nums[1].split("/"))
        else:
            p2 = int(nums[1])
            q2 = 1
        if("/" in nums[2]):
            p3,q3 = map(int,nums[2].split("/"))
        else:
            p3 = int(nums[2])
            q3 = 1
        # print(p1,q1,p2,q2,p3,q3)
        coes[i] = [p1*q2*q3 , p2*q1*q3 , p3*q2*q1]
        # print(coes[i])
        # if(coes[i][0] == 0):

        # if(coes[i][1] == 0):

        # if(i >= 1):
        #     if(coes[i][0])




    print()
    # if(n == 1):
    #     if(nums[0][0] == 0 and nums[0][1] == 0):
    #         if(nums[0][2] == 0):
    #             print("infinite many solutions")