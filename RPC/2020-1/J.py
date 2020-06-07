l = input().split(" ")

n = int(l[0])
c = int(l[1])

song = []

horas = 0
minutos = 0
segundos = 0

i = 0
while(i < n):
	line = input().split(":")

	minutos += int(line[0])
	segundos += int(line[1])

	i+=1
segundos = segundos - c * (n - 1)

horas += int(minutos / 60)
minutos = minutos - (minutos - minutos % 60)
minutos += int(segundos / 60)
segundos = segundos - (segundos - segundos % 60)

string_h = str(horas)
if(horas < 10):
	string_h = "0" + string_h

string_m = str(minutos)
if(minutos < 10):
	string_m = "0" + string_m

string_s = str(segundos)
if(segundos < 10):
	string_s = "0" + string_s

print(string_h + ":" + string_m + ":" + string_s)
