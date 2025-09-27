n = int(input())
nums = list(map(int,input().split()))

nums.sort()
c = 1
ans = 0
for i in range(n):
	c = c * (n-i) // (i+1)
	add = (nums[i] * c) % 998244353
	ans += add
	ans = ans % 998244353
print(ans)
