line = input().split(" ")
n = int(line[0])
p = int(line[1])

squares = ["INICIO"]

i = 0
while(i < n - 1):
	squares.append(input())

	i+=1
squares.append("FINAL")
posiciones = []
i = 0
while(i < p):
	posiciones.append(0)
	i+=1

c = int(input())

i = 0
cards = []
while(i < c):
	line = input().split(" ")
	cards.append((int(line[0]), line[1]))
	i += 1

i = 0
player = 0
while(1):
	card = cards[i][0]
	square = cards[i][1]
	if(card == 1):
		j = posiciones[player] + 1
		while(j < n):
			if(square == squares[j]):
				posiciones[player] = j
				break
			j += 1
		if(j == n):
			break
	elif(card == 2):
		j = posiciones[player] + 1
		find = 0
		while(find < 2 and j < n ):
			if(square == squares[j]):
				posiciones[player] = j
				find+=1
				if(find == 2):
					break
			j+=1
		if(j == n):
			break
	else:
		j = 1
		while(j < n):
			if(square == squares[j]):
				posiciones[player] = j
				break
			j += 1
	i = (i + 1) % c
	player = (player + 1) % p
print(player + 1)