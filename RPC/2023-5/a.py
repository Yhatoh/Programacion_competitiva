n = int(input())
i = 1
flag = True
prev_x = -1
prev_y = -1
error = -1
win = False
while i <= n:
    x, y = list(map(int, input().split("-")))
    if (x + y) % 4 == 1 or (x + y) % 4 == 2:
        aux = x
        x = y
        y = aux


    if (prev_x != x or prev_y != y):
        if x > 11 or y > 11 or win or (x == y and y == 11):
            error = i
            flag = False
            break

        if prev_x > x or prev_y > y:
            error = i
            flag = False
            break

    if x == 11 or y == 11:
        win = True

    prev_x = x
    prev_y = y
    i += 1

if flag:
    print("ok")
else:
    print("error", error)
