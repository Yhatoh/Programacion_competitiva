t = int(input())

i = 0
while(i < t):
	n = int(input())

	a = list(map(int, input().split(" ")))
	b = list(map(int, input().split(" ")))
	c = list(map(int, input().split(" ")))
	
	sol = []

	sol.append(a[0])

	j = 1
	while(j < n):
		if(sol[j - 1] != a[j % n]):
			sol.append(a[j])
		elif(sol[j - 1] != b[j % n]):
			sol.append(b[j])
		elif(sol[j - 1] != c[j % n]):
			sol.append(c[j])
		
		j+= 1

	booli = 1
	for j in range(n):
		if(sol[j] == sol[(j + 1) % n]):
			booli = 0
			break

	if(booli):
		print(" ".join(list(map(str,sol))))
	else:
		sol = []

		sol.append(b[0])

		j = 1
		while(j < n):
			if(sol[j - 1] != a[j % n]):
				sol.append(a[j])
			elif(sol[j - 1] != b[j % n]):
				sol.append(b[j])
			elif(sol[j - 1] != c[j % n]):
				sol.append(c[j])
			
			j+= 1

		booli = 1
		for j in range(n):
			if(sol[j] == sol[(j + 1) % n]):
				booli = 0
				break

		if(booli):
			print(" ".join(list(map(str,sol))))
		else:
			sol = []

			sol.append(c[0])

			j = 1
			while(j < n):
				if(sol[j - 1] != a[j % n]):
					sol.append(a[j])
				elif(sol[j - 1] != b[j % n]):
					sol.append(b[j])
				elif(sol[j - 1] != c[j % n]):
					sol.append(c[j])
				
				j+= 1

			booli = 1
			for j in range(n):
				if(sol[j] == sol[(j + 1) % n]):
					booli = 0
					break
			print(" ".join(list(map(str,sol))))
	i += 1