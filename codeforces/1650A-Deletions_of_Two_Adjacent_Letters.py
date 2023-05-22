t = int(input())
while t > 0:
	string = input()
	letter = input()
	valid = "NO"
	for i in range(len(string)):
		if string[i] == letter:
			if(i % 2 == 0 and (len(string) - (i + 1)) % 2 == 0):
				valid = "YES"
				break
	print(valid)
	t -= 1