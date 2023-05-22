n = int(input())
nums = input()

suma = 0
i = 0
flag = 1
prev = 0
while i < len(nums):
	if flag == 1:
		if int(nums[i]) > prev:
			suma += int(nums[i])
			prev = int(nums[i])
			i += 1
		else:
			flag = 2
	elif flag == 2:
		if(int(nums[i] + nums[i + 1]) > prev):
			suma += int(nums[i] + nums[i + 1])
			prev = int(nums[i] + nums[i + 1]) 
			i+=2 
		else:
			flag = 3
	else:
		suma += 100
		i+=3

print(int(n * (n + 1) / 2) - suma)
