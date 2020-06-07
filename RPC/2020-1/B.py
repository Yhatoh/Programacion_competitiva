line = input()
dicc = {}

for i in line:
	if i not in dicc.keys():
		dicc[i] = 0
	dicc[i] += 1

l = []
for x,y in dicc.items():
	l.append((y,x))

l.sort()
pos = 0
i = l[0][0]
h = 0
lista = [""]
while(h < i):
	lista[0] += l[0][1]
	h+=1
j = 0
for x,y in l:
	if(j == 0):
		j = 1
	else:
		if(i == x):
			h = 0
			while(h < i):
				lista[pos] += y
				h+=1
		else:
			pos+=1
			lista.append("")
			i = x
			h = 0
			while(h < i):
				lista[pos] += y
				h+=1
			
lista.reverse()
string = ""
for x in lista:
	string = string + x
print(string)
