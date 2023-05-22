s = input()

letters = set()

for letter in s:
	letters.add(letter)

print(1 if len(letters) == len(s) else 0)