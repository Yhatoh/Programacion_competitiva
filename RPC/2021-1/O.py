t = int(input())

while(t > 0):
	p, e = list(map(int, input().split(" ")))
	p -= e
	print("YES" if p >= 10 else "NO")
	t -= 1