wc, hc, ws, hs = list(map(int, input().split(" ")))

if(ws + 2 <= wc and hs + 2 <= hc):
	print(1)
else:
	print(0)