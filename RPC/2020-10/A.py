n = int(input())

dicc = {}
i = 0
while(i < n):
	fecha = input()
	if fecha not in dicc.keys():
		dicc[fecha] = 0
	dicc[fecha] += 1
	i += 1

print(len(dicc.keys()))