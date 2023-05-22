n = int(input())


price = input().split("$")[1]
inte, deci = list(map(int, price.split(".")))

bank_inte = inte
bank_deci = deci

days = 0
while(n > 0):
	price = input().split("$")[1]
	inte, deci = list(map(int, price.split(".")))

	bank_inte += inte

	bank_deci += deci

	#print(bank_deci, bank_inte, deci, inte)
	if(bank_deci >= 100):
		bank_inte += int(bank_deci / 100)
		bank_deci = bank_deci % 100
	#print(bank_deci, bank_inte, deci, inte)
	if(bank_deci != 0):
		days += 1

	n -= 1

print(days)