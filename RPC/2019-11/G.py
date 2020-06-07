i = input()

r = input().strip().split(" ")
c = input().strip().split(" ")

r.sort()
c.sort()

i = 0
a = 2
while(i < len(r) or i < len(c)):
	if(r[i] != c[i]):
		print("impossible")
		break
	i+=1

if(i == len(r) or i == len(c)):
	print("possible")