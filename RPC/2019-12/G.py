
def divycon(line,i,j,itera):
	if(i == j):
		return [i,j]

	maxizq = divycon(line,i,int((i+j)/2),itera+1)
	maxder = divycon(line,int((i+j)/2)+1,j,itera+1)
	print(itera)
	print(maxizq,maxder,i,j)

	if(maxder == None):
		return maxizq
	elif(maxizq == None):
		return maxder


	dicc = {}


	if(maxder[0] == maxizq[1]+1 and (maxizq[1]-maxizq[0] > 0 or maxder[1]-maxder[0] > 0)):
		i = maxder[0]
		while(i <= maxder[1]):
			if(line[i] not in dicc.keys()):
				dicc[i] = 0
			dicc[i]+=1
			i+=1
		i = maxizq[0]
		while(i <= maxizq[1]):
			if(line[i] not in dicc.keys()):
				dicc[line[i]] = 0
			dicc[line[i]]+=1
			i+=1
		impar = 0
		no = 0
		for x,y in dicc.items():
			if(y%2 == 1 and impar == 0):
				impar = 1
			elif(y%2 == 1 and impar == 1):
				no = 1
				break
		if(no == 1):
			if(maxizq[1]-maxizq[0] < maxder[1]-maxder[0]):
				return maxder
			else:
				return maxizq
		else:
			return [maxizq[0],maxder[1]]
	else:
		k = 0
		while(k < len(line)):
			if(line[k] not in dicc.keys()):
				dicc[line[k]] = 0
			dicc[line[k]]+=1
			k+=1
		impar = 0
		no = 0
		for x,y in dicc.items():
			if(y%2 == 1 and impar == 0):
				impar = 1
			elif(y%2 == 1 and impar == 1):
				no = 1
				break
		if(no == 1):
			return maxizq
		else:
			return [i,j]

xd = input()
line = input()
itera = 0
maxi = divycon(line,0,len(line)-1,itera)
print(maxi)
print(maxi[1]-maxi[0]+1)
