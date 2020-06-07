s = int(input())

holes = []
while(s > 0):
	holes.append(list(map(int, input().split(" "))))
	s -= 1


c = int(input())
passed = 0
while(c > 0):
	u, v = list(map(int, input().split(" ")))
	for x in holes:
		passed += 1
		if(u <= x[0] and v >= x[1]):
			break
	c -= 1
print(passed)