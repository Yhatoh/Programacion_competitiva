min_changes = 1000000
min_num = ""
def backtrack(number, pos, changes):
	global min_changes
	global min_num 
	if pos == len(number):
		return

	for i in range(10):
		if pos == 0 and i == 0:
			continue 
		aux = list(number)
		aux[pos] = str(i)
		num_aux = "".join(aux)
		if int(num_aux) % 7 == 0:
			if changes + 1 < min_changes:
				min_changes = changes + 1
				min_num = num_aux
		backtrack(num_aux, pos + 1, changes + 1)

	if int(number) % 7 == 0:
		if changes < min_changes:
			min_changes = changes
			min_num = number
	backtrack(number, pos + 1, changes)



t = int(input())
while t > 0:
	n = input()
	backtrack(n, 0, 0)
	print(min_num)
	min_changes = 1000000
	min_num = ""
	t -= 1