casos = int(input())
i = 0
while(i < casos):
	dicc = {}
	linea = input()
	lista = [linea[0]]
	dicc[linea[0]] = 0
	pos = 1
	while(lista != []):
		if(lista[len(lista)-1] == linea[pos]):
			lista.remove(linea[pos])
			pos += 1
		else:
			dicc[lista[len(lista)-1]] += 1
			lista.append(linea[pos])
			dicc[linea[pos]] = 1
			pos += 1
	l = []
	for x,y in dicc.items():
		l.append((x,y))
	l.sort()
	print("Case " + str(i+1))
	for x in l:
		print(x[0] + " = " + str(x[1]))
	i += 1