t = int(input())

h = 0
while(t > h):
	n = int(input())

	matriz = []
	col = []
	row = []
	cols = []
	rows = []
	i = 0
	while i < n:
		lista = list(map(int, input().split(" ")))
		matriz.append(lista)
		i += 1
		cols.append(0)
		rows.append(0)
		col.append([])
		row.append([])


	i = 0

	trace = 0

	while i < n:
		j = 0
		while j < n:
			if(i == j):
				trace += matriz[i][j]

			if(cols[j] == 0 and matriz[i][j] not in col[j]):
				col[j].append(matriz[i][j])
			elif(matriz[i][j] in col[j]):
				cols[j] = 1
			if(rows[i] == 0 and matriz[i][j] not in row[i]):
				row[i].append(matriz[i][j])
			elif(matriz[i][j] in row[i]):
				rows[i] = 1
			j += 1
		i += 1

	i = 0

	r = 0
	c = 0
	while i < n:
		r += rows[i]
		c += cols[i]
		i += 1

	h += 1
	print("Case #" + str(h) + ": " + str(trace) + " " + str(r) + " " + str(c))