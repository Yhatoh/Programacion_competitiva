from math import sqrt

def is_prime(n):
    prime_flag = 0
      
    if(n > 1):
        for i in range(2, int(sqrt(n)) + 1):
            if (n % i == 0):
                prime_flag = 1
                break
        if (prime_flag == 0):
            return True
        else:
            return False
    else:
        return False

lines = []
while True:
    try:
        s=input()
        lines.append(s)
    except:
        break
#print(lines)
possible_nums = []
for line in lines:
    new_s = ""
    for c in line:
        if(c == " " or c == "\r" or c == "\t"):
            if(new_s != ""):
                possible_nums.append(new_s)
                new_s = ""
        else:
            new_s += c
    if(new_s != ""):
        possible_nums.append(new_s)

booli = 0
#(possible_nums)
if(len(possible_nums) == 3):
    correct_nums = 0
    which_one = 1
    save_first = 0
    save_sec = 0
    for s in possible_nums:
        try:
            if("." in s or "+" in s or s[0] == "0"):
                break
            else:
                num = int(s)
                if(num < 0):
                    break

                if(which_one == 1):
                    if(num % 2 == 0 and num > 3 and num <= 1000000000):
                        correct_nums += 1
                        which_one += 1
                        save_first = num
                    else:
                        which_one = -1
                elif(which_one == 2):
                    if(is_prime(num)):
                        which_one += 1
                        save_sec = num
                elif(which_one == 3):
                    if(is_prime(num)):
                        if(save_sec + num == save_first):
                            booli = 1
            if(which_one == -1):
                break
        except:
            break

print(booli)