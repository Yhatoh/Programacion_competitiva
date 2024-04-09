t = int(input())
for _ in range(t):
    hour, minutes = input().split(":")
    hour = int(hour)
    time = "PM"
    if hour < 12:
        time = "AM"
        if hour == 0:
            hour = "12"
        else:
            if hour < 10:
                hour = "0" + str(hour)
            else:
                hour = str(hour)
    else:
        if hour == 12:
            hour = "12"
        else:
            hour = hour - 12
            if hour < 10:
                hour = "0" + str(hour)
            else:
                hour = str(hour)
    print(hour + ":" + minutes + " " + time)
