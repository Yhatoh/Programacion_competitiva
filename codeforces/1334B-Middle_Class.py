t = int(input())
while(t > 0):
	n, x = list(map(int, input().split(" ")))

	savings = list(map(int, input().split(" ")))

	savings.sort()
	savings.reverse()

	numbers = 0
	suma = 0

	for nums in savings:
		numbers += 1
		suma += nums
		if(suma / numbers < x):
			numbers -= 1
			break

	print(numbers)
	t -= 1