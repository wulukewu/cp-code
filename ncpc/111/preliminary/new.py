t = int(input())

while(t>0):
    t -= 1
    n = int(input())
    nums = [[] for i in range(n)]
    for i in range(n):
        nums[i] = list(map(int,input().split()))
    r1,c1,r2,c2 = map(int,input().split())
    small = nums[r1-1][c1-1]
    big = nums[r2-1][c2-1]
    ans = 0
    for i in nums:
        for j in i:
            if(big <= j):
                #print(f"end at {j}")
                break
            elif(small < j):
                #print(f"add for {j}")
                ans += 1
#for i in nums:
#		for j in i:
#			  print(i)
#	for j in i:
#			  
#     		  if(big < j):
#      	          break
#             elif(small < j):
#                 ans += 1
    print(ans)
