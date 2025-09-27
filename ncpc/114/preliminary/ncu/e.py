n = int(input())
city = [[] for i in range(n)]
dis = 0

for i in range(n):
	city[i] = list(map(int,input().split()))

for i in range(n):
	d_all = 0
	for k in range(2):
		for j in range(n):
			if(i != j):

				d1 = (city[i][2*k] - city[j][0])**2 + (city[i][2*k+1] - city[j][1])**2
				#print((city[i][2*k] - city[j][0])**2 , (city[i][2*k+1] - city[j][1])**2)
				d2 = (city[i][2*k] - city[j][2])**2 + (city[i][2*k+1] - city[j][3])**2
				#print(city[i][2*k] - city[j][2] , city[i][2*k+1] - city[j][3])
				d_all = max(d_all,min(d1,d2))

		if(i == 0):
			dis = d_all
		else:
			dis = min(dis,d_all)
	
print(dis)
