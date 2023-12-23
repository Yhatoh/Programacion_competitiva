n = int(input())

nums = list(map(int, input().split(" ")))

mood = 0
ans = ""
for i in range(n):
    mood = mood / 2.0
    mood = mood + nums[i]
    if(i <= 90):
        if(mood > 0):
            ans += "+"
        elif(mood < 0):
            ans += "-"
        else:
            ans += "0"
    else:
        if(mood > 0):
            ans += "+"
        else:
            ans += "-"


print(ans)
