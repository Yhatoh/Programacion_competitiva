t = int(input())

i = 0
while(i < t):
	s = list(input())
	
	#print(s)

	j = 0
	while(j < len(s)):
		if(s[j] == "9"):
			s[j] = "8"
			h = j + 1
			while(h < len(s) and s[h] == "9"):
				s[h] = "8"
				h += 1
			s.insert(h, ")")
			s.insert(j, "(")
		j += 1
	#print(s)

	j = 0
	toFind = "8"
	while(j < len(s) and toFind != "0"):
		if(s[j] == toFind):
			s[j] = str(int(toFind) - 1)
			h = j + 1
			while(h < len(s) and (s[h] == toFind or s[h] == "(" or s[h] == ")")):
				if(s[h] == toFind):
					s[h] = str(int(toFind) - 1)
				h += 1
			s.insert(h, ")")
			s.insert(j, "(")
		j += 1
		if(len(s) == j):
			toFind = str(int(toFind) - 1)
			j = 0
	#print(s)

	cantParentesis = 0
	string = ""

	j = 0
	while(j < len(s)):
		if(s[j] == "("):
			cantParentesis += 1
			string += "("
		elif(s[j] == ")"):
			cantParentesis -= 1
			string += ")"
		else:
			string += str(cantParentesis)
		j += 1

	print("Case #" + str(i + 1) + ": " + string)
	i += 1