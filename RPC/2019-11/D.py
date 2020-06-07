i = input().strip().split(" ")

n = int(i[0])
k = int(i[1])

esperanza = 0

i = 1
while(i <= n):
	esperanza+=(i*1/n)**k
	i+=1

print(esperanza)