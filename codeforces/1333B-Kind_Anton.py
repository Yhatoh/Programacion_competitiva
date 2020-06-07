t = int(input())

while(t > 0):
	n = int(input())
	a = list(map(int, input().split(" ")))
	b = list(map(int, input().split(" ")))
	
	i = 0
	pos_add = n + 1
	pos_sub = n + 1
	while(i < n):
		if(a[i] == 1 and pos_add == n + 1):
			pos_add = i
		elif(a[i] == -1 and pos_sub == n + 1):
			pos_sub = i
		i += 1

	i = 0
	boola = 1
	while(i < n):
		if(a[i] < b[i] and i <= pos_add):
			boola = 0
			break
		elif(a[i] > b[i] and i <= pos_sub):
			boola = 0
			break
		i+=1

	if(boola):
		print("YES")
	else:
		print("NO")
	t -= 1