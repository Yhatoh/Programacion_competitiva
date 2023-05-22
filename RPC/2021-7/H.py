s, n = list(map(int, input().split(" ")))

ln = []
ly = []
for i in range(n):
	d, t = input().strip().split(" ")
	d = int(d)
	if t == 'y':
		ly.append([d, t])
	else:
		ln.append([d, t])


ln.sort()
ly.sort()
print(ln)
print(ly)

iteration = 0
while 1:
	for i in range(s):
		if ly != []:
			if ly[0][0] - iteration == 1:
				ly.pop(0)
				continue
			elif ln[0][0] - iteration == 1:
				ln.pop(0)
				continue
			else:
				timePaper = ly[0][0]
				count = 1
				tamano = len(ly)
				while tamano > count:
					if ly[count][0] == timePaper - iteration:
						count += 1
					else:
						break

				cont2 = 0
				tamano2 = len(ln)
				while tamano2 > cont2:
					if ln[cont2][0] < timePaper - iteration - count:
						cont2 += 1
					else:
						break
				if cont2 / s < timePaper:
					ly.pop(0)
				else:
					ln.pop(0)
		else:
			ln.pop(0)
			continue

	if ly == [] and ln == []:
		break
	iterions += 1

if(flag):
	print("Yes")
else:
	print("No")