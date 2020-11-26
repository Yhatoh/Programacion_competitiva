a, b, c = list(map(int, input().split(" ")))

cant = 0
for i in range(a, b + 1):
	if i % 10 == c:
		cant += 1
	i = int(i / 10)
	if i % 10 == c:
		cant += 1
	i = int(i / 10)
	if i % 10 == c:
		cant += 1
	i = int(i / 10)
	if i % 10 == c:
		cant += 1

print(cant)