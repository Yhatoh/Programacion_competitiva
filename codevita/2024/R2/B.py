n = int(input())

reorder = []

per_person = dict()
time_per_person = dict()

for _ in range(n):
    id, act, loc, time = input().split(" ")
    time = time.split(":")
    pm = time[1][2:4] == "PM"
    time2 = int(time[1][0:2])
    if time[0] == "12" and pm:
        time2 += 12 * 60
    elif pm:
        time2 += int(time[0]) * 60 + 12 * 60
    elif time[0] != "12":
        time2 += int(time[0]) * 60

    reorder.append([act, loc, id, time2])
    time_per_person[id] = 0
    per_person[id] = dict()

reorder.sort()
for act, loc, id, time2 in reorder:
    if act == "enters" and "room" in loc:
        if loc not in per_person[id].keys():
            per_person[id][loc] = []
        if 0 in per_person[id][loc]:
            per_person[id][loc].append(0)
            per_person[id][loc].append(0)
            per_person[id][loc].append(0)
            per_person[id][loc].append(0)
        per_person[id][loc].append(0)
        time_per_person[id] -= time2
    elif "room" in loc:
        if loc not in per_person[id].keys():
            per_person[id][loc] = []
        if 1 in per_person[id][loc]:
            per_person[id][loc].append(1)
            per_person[id][loc].append(1)
            per_person[id][loc].append(1)
            per_person[id][loc].append(1)
        per_person[id][loc].append(1)
        time_per_person[id] += time2

res = []
for x, y in time_per_person.items():
    res.append([y, x])

res.sort()
least = res[0][0]

super_flag = True
flag = False
id2 = input()

sus = []

for id, x in per_person.items():
    for _, f in x.items():
        if len(f) != 2:
            if not (id in sus):
                sus.append(id)

if len(sus) != 0:
    super_flag = False
for time, id in res:
    if time == least and id == id2:
        flag = True
    elif time != least:
        break

if not super_flag:
    print("Cannot be determined", end="")
elif flag:
    print("Yes", end="")
else:
    print("No", end="")
