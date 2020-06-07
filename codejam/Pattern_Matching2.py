t = int(input())
h = 0
while(t > h):
	n = int(input())


	suffixMasLargo = ""
	prefixMasLargo = ""
	lenPrefixMasLargo = 0
	lenSuffixMasLargo = 0
	sufix = []
	prefix = []
	stringPos = ""
	while(n > 0):
		pattern = input()
		i = 0
		toAppend = []
		j = 0
		while(j < len(pattern)):
			if(pattern[j] == "*"):
				toAppend.append(pattern[i:j])
				i = j + 1
				j = j + 1
			else:
				j += 1
		if(i < j):
			prefix.append(pattern[i:j])
		toAppend.append(pattern[i:j])
		sufix.append(toAppend[0])

		if(len(prefix) != 0):
			if(len(prefix[len(prefix) - 1]) > lenPrefixMasLargo):
				lenPrefixMasLargo = len(prefix[len(prefix) - 1])
				prefixMasLargo = prefix[len(prefix) - 1]
		if(len(sufix[len(sufix) - 1]) > lenSuffixMasLargo):
			lenSuffixMasLargo = len(sufix[len(sufix) - 1])
			suffixMasLargo = sufix[len(sufix) - 1]


		stringPos += "".join(toAppend[1:len(toAppend) - 1])
		n -= 1

	
	
	bol = 1
	for x in sufix:
		i = 0
		while(i < len(x)):
			if(x[i] != suffixMasLargo[i]):
				bol = 0
				break
			i += 1
		if(bol == 0):
			break
	if(bol):
		for y in prefix:
			i = 1
			while(i <= len(y)):
				if(y[len(y) - i] != prefixMasLargo[len(prefixMasLargo) - i]):
					bol = 0
					break
				i += 1
			if(bol == 0):
				break
		if(bol):
			print("Case #" + str(h + 1) + ": " + suffixMasLargo + stringPos + prefixMasLargo)
		else:
			print("Case #" + str(h + 1) + ": *") 
	else:
		print("Case #" + str(h + 1) + ": *") 

	h +=1