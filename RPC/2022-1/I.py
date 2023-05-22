def parser(inp, types):
	max_num = (24 if types == 0 else 60)	
	possible_times = []
	if(inp == "*"):
		for i in range(max_num):
			possible_times.append(i)
	else:
		inp = inp.split(",")
		for time in inp:
			if("-" in time):
				l, h = list(map(int, time.split("-")))
				for i in range(l, h + 1):
					possible_times.append(i)
			else:
				possible_times.append(int(time))
	return possible_times


n = int(input())
count = 0
jobs = 0
triple_grid = []
for i in range(24):
	triple_grid.append([])
	for j in range(60):
		triple_grid[i].append([])
		for k in range(60):
			triple_grid[i][j].append(False)

while(n > 0):
	hours, minutes, seconds = input().split(" ")

	possible_hours = parser(hours, 0)
	possible_minutes = parser(minutes, 1)
	possible_seconds = parser(seconds, 1)


	for h in possible_hours:
		for m in possible_minutes:
			for s in possible_seconds:
				triple_grid[h][m][s] = True


	jobs += len(possible_hours) * len(possible_minutes) * len(possible_seconds)
	n -= 1

for i in range(24):
	for j in range(60):
		for k in range(60):
			if(triple_grid[i][j][k]):
				count += 1
print(count, jobs)