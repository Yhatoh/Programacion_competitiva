t = int(input())

while(t > 0):
	num = input().split(" ")	
	a = num[0]
	b = num[1]

	if(int(a) < 10 and int(b) >= 10):
		sum1 = int(a) + int(b)
		
		sum2 = int(b[1]) + int(b[0] + a[0])
		sum3 = int(b[0]) + int(a[0] + b[1])

		sum4 = -1
		sum5 = -1
	else:
		if(int(b) < 10 and int(a) >= 10):
			sum1 = int(a) + int(b)
			
			sum2 = int(a[1]) + int(a[0] + b[0])
			sum3 = int(a[0]) + int(b[0] + a[1])

			sum4 = -1
			sum5 = -1
		else:
			if(int(a) < 10 and int(b) < 10):
				sum1 = int(a) + int(b)
				sum2 = -1
				sum3 = -1
				sum4 = -1
				sum5 = -1
			else:
				sum1 = int(a) + int(b)

				sum2 = int(b[0] + a[1]) + int(a[0] + b[1])

				sum3 = int(a[0] + b[1]) + int(b[0] + a[1])
				sum4 = int(a[0] + b[0]) + int(a[1] + b[1])
				sum5 = int(b[1] + a[1]) + int(b[0] + a[0])

	if(sum1 >= sum2):
		if(sum1 >= sum3):
			if(sum1 >= sum4):
				if(sum1 >= sum5):
					print(sum1)
				else:
					print(sum5)
			else:
				if(sum4 >= sum5):
					print(sum4)
				else:
					print(sum5)
		else:
			if(sum3 >= sum4):
				if(sum3 >= sum5):
					print(sum3)
				else:
					print(sum5)
			else:
				if(sum4 >= sum5):
					print(sum4)
				else:
					print(sum5)
	else:
		if(sum2 >= sum3):
			if(sum2 >= sum4):
				if(sum2 >= sum5):
					print(sum2)
				else:
					print(sum5)
			else:
				if(sum4 >= sum5):
					print(sum4)
				else:
					print(sum5)
		else:
			if(sum3 >= sum4):
				if(sum3 >= sum5):
					print(sum3)
				else:
					print(sum5)
			else:
				if(sum4 >= sum5):
					print(sum4)
				else:
					print(sum5)
	t -= 1
