n = int(input())
while(n != -1):
	pal = input().strip()
	l = []
	for x in pal:
		l.append(x)
	res = input().strip()
	cont = 0
	intentos = []
	for x in res:
		if(x not in intentos):			
			intentos.append(x)
			if(x in l):
				while(x in l):
					l.remove(x)
			else:
				cont+=1
		if(l == []):
			break
		elif(cont == 7):
			break
	print("Round " + str(n))
	if(l == []):
		print("You win.")
	elif(cont >= 7):
		print("You lose.")
	else:
		print("You chickened out.")
	n = int(input())