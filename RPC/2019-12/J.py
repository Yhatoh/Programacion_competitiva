n = int(input())

i = 0
points = []
while(i < n):
	x,y = map(int,input().split(" "))
	points.append([x,y])
	i+=1
i = 0
vector = []
while(i < n):
	j = i+1
	while(j < n):
		vector.append([points[i][0]-points[j][0],points[i][1]-points[j][1]])
		j+=1
	i+=1

i = 0
cont = 0;
while(i < 2*n):
	j=i+1
	while(j < 2*n):

		if(vector[i][0]!=0 and vector[j][0]!=0 and vector[i][1]!=0 and vector[j][1]!=0 and vector[i][0]/vector[j][0] == vector[i][1]/vector[j][1]):
			print(i,j)
			cont+=1
		j+=1
	i+=1
print(vector)
print(cont)