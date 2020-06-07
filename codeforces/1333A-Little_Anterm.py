t = int(input())

while(t > 0):
	n,m = list(map(int, input().split(" ")))
	l = []
	
	i = 0
	while(i < n):
		l.append([])
		j = 0
		while(j < m):
			if(i % 2 == 0 and j % 2 == 1):
				l[i].append("W")
			elif(i % 2 == 1 and j % 2 == 0):
				l[i].append("W")
			else:
				l[i].append("B")
			j += 1
		i += 1

	if(m % 2 == 0):
		l[0][m - 1] = "B"
	elif(m % 2 == 1 and n % 2 == 0):
		l[1][m - 1] = "B"
	i = 0
	while(i < n):
		s = "".join(l[i])
		print(s)
		i += 1
	
	t -= 1 