i = input()

meow = ["meow","me","eo","ow"]
meow_3 = ["mow","mew","meo","eow"]
meow_1 = ["m","e","o","w"]
meow_2 = ["me","eo","ow","mw","mo","ew"]


if(meow[0] in i):
	print(0)
else:
	a = 0
	d = 0
	while(d < 4):
		if(meow_3[d] in i):
			a = 1
			d = 5
		d+=1
	if(a == 1):
		print(1)
	else:
		a = 0
		d = 0
		while(d < 6):
			if(meow_2[d] in i):
				a = 1
				d = 5
			d+=1	
		if(a == 1):
			print(2)
		else:
			if("m" not in i and "e" not in i and "o" not in i and "w" not in i):
				print(4)
			else:
				_1 = i.find("m")
				_2 = i.find("e")
				_3 = i.find("o")
				_4 = i.find("w")
				

				if(_1 == -1 and _2 == -1 and _3 == -1):
					print(3)
				elif(_4 == -1 and _2 == -1 and _3 == -1): 
					print(3)
				elif(_4 == -1 and _1 == -1 and _3 == -1):
					print(3)
				elif(_4 == -1 and _2 == -1 and _1 == -1):
					print(3)
				else:
					if(_1 == -1 and _2 == -1):
						print(3)
					elif(_1 == -1 and _4 == -1):
						print(3)
					elif(_3 == -1 and _4 == -1):
						print(3)
					else:							
						if(_1 == -1):
							if(_2-_3 == 1 and _3-_4 == -1):
								print(2)
							elif(_3-_4 == 1 and _2-_3 == -1):
								print(2)
							else:
								print(3)
						elif(_2 == -1):
							if(_1-_3 == 1 and _3-_4 == -1):
								print(2)
							elif(_3-_4 == 1 and _1-_3 == -1):
								print(2)
							else:
								print(3)
						elif(_3 == -1):
							if(_1-_2 == 1 and _2-_4 == -1):
								print(2)
							elif(_2-_4 == 1 and _1-_2 == -1):
								print(2)
							else:
								print(3)
						else:
							pritn(3)