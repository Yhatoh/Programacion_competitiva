fn = input()
fn2 = input()

validExtension = 0

if fn2[-1] == "c" and fn2[-2] == ".":
	validExtension = 1
	fn2 = fn2.split(".c")[0]
elif fn2[-3] == "c" and fn2[-2] == "p" and fn2[-1] == "p" and fn2[-4] == ".":
	validExtension = 1
	fn2 = fn2.split(".cpp")[0]
elif fn2[-2] == "p" and fn2[-1] == "y" and fn2[-3] == ".":
	validExtension = 1
	fn2 = fn2.split(".py")[0]
elif fn2[-1] == "a" and fn2[-2] == "v" and fn2[-3] == "a" and fn2[-4] == "j" and fn2[-5] == ".":
	validExtension = 1
	fn2 = fn2.split(".java")[0]



if fn == fn2 and validExtension:
	r, d, e = list(map(int, input().split(" ")))
	if r == 0:
		if d >= e:
			c = int(input())
			i = 0
			lines = []
			while i < c:
				line = input()
				lines.append(line)
				i += 1
			t = int(input())
			if t == c:
				i = 0
				while i < t:
					line = input()
					if line != lines[i]:
						break
					i += 1

				if i == t:
					print("Correct")
				else:
					print("Wrong Answer")
			else:
				print("Wrong Answer")
		else:
			print("Time Limit Exceeded")
	else:
		print("Run-Time Error")
else:
	print("Compile Error")

