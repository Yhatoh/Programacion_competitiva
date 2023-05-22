n = int(input())

outcomes = list(map(int, input().split(" ")))

booli = 0
for i in range(7, 0, -1):
	times = 0
	index = 0
	for j in range(0, n):
		if outcomes[j] == i:
			index = j
			times += 1

	if times == 1:
		booli = 1
		break

if booli:
	print(index + 1)
else:
	print("none")


