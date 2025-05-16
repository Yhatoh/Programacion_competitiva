from copy import deepcopy

n, t = list(map(int, input().split(" ")))

base = [[0 for _ in range(n)] for _ in range(n)]
back = [[0 for _ in range(n)] for _ in range(n)]
top = [[0 for _ in range(n)] for _ in range(n)]
front = [[0 for _ in range(n)] for _ in range(n)]
left = [[0 for _ in range(n)] for _ in range(n)]
right = [[0 for _ in range(n)] for _ in range(n)]

## base
#for i in range(n):
#    cs = input().split(" ")
#    for l in range(n):
#        base[n - i - 1][l] = cs[l]
#
#
## back
#
#for i in range(n):
#    cs = input().split(" ")
#    for l in range(n):
#        back[i][n - l - 1] = cs[l]
#
#
## top
#
#for i in range(n):
#    cs = input().split(" ")
#    for l in range(n):
#        top[n - i - 1][l] = cs[l]
#
#
## front
#
#for i in range(n):
#    cs = input().split(" ")
#    for l in range(n):
#        front[n - i - 1][l] = cs[l]
#
#
## left
#
#for i in range(n):
#    cs = input().split(" ")
#    for l in range(n):
#        left[i][l] = cs[l]
#
#
## right
#
#for i in range(n):
#    cs = input().split(" ")
#    for l in range(n):
#        right[n - i - 1][n - l - 1] = cs[l]

# base
for i in range(n):
    cs = input().split(" ")
    for l in range(n):
        base[i][l] = cs[l]


# back

for i in range(n):
    cs = input().split(" ")
    for l in range(n):
        back[i][l] = cs[l]


# top

for i in range(n):
    cs = input().split(" ")
    for l in range(n):
        top[i][l] = cs[l]


# front

for i in range(n):
    cs = input().split(" ")
    for l in range(n):
        front[i][l] = cs[l]


# left

for i in range(n):
    cs = input().split(" ")
    for l in range(n):
        left[i][l] = cs[l]


# right

for i in range(n):
    cs = input().split(" ")
    for l in range(n):
        right[i][l] = cs[l]

print("base")
for x in base:
    print(x)
print("back")
for x in back:
    print(x)
print("top")
for x in top:
    print(x)
print("front")
for x in front:
    print(x)
print("left")
for x in left:
    print(x)
print("right")
for x in right:
    print(x)

def rot_right(l):
    return list(map(list, list(zip(*l[::-1]))))

def rot_left(l):
    return list(map(list, list(zip(*l))[::-1]))

for _ in range(t):
    rule = input()

    base_ = deepcopy(base)
    back_ = deepcopy(back)
    top_ = deepcopy(top)
    front_ = deepcopy(front)
    left_ = deepcopy(left)
    right_ = deepcopy(right)

    if rule == "turn left":
        left = front_
        back = left_
        right = back_
        front = right_

        top = rot_right(top_)
        base = rot_left(base_)
    elif rule == "turn right":
        right = front_
        back = right_
        left = back_
        front = left_

        top = rot_left(top_)
        base = rot_right(base_)
    elif rule == "rotate front":
        base = front_[::-1]
        back = base_
        top = back_[::-1]
        front = top_

        left = rot_right(left_)
        right = rot_left(right_)
    elif rule == "rotate back":
        top = front_
        back = top_[::-1]
        base = back_
        front = base_[::-1]

        left = rot_left(left_)
        right = rot_right(right_)
    elif rule == "rotate left":
        left = rot_left(top_)
        base = rot_left(left_)
        right = rot_left(base_)
        top = rot_left(right_)

        front = rot_left(front_)
        back = rot_right(back_)
    else:
        right = rot_right(top_)
        base = rot_right(right_)
        left = rot_right(base_)
        top = rot_right(left_)
        front = rot_right(front_)
        back = rot_left(back_)


print()
print("base")
for x in base:
    print(x)
print("back")
for x in back:
    print(x)
print("top")
for x in top:
    print(x)
print("front")
for x in front:
    print(x)
print("left")
for x in left:
    print(x)
print("right")
for x in right:
    print(x)
side, x, y = input().split(" ")

x = int(x)
y = int(y)

x -= 1
y -= 1

if side == "top":
    print(top[n - x - 1][y])
if side == "left":
    print(left[x][y])
if side == "right":
    print(right[n - x - 1][n - y - 1])
if side == "base":
    print(base[n - x - 1][y])
if side == "back":
    print(back[x][n - y - 1])
if side == "front":
    print(front[n - x - 1][y])
