import math

def get_radios(x1, y1, x2, y2):
    return math.ceil(math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2))

def get_area(pi, r):
    return math.ceil(pi * r * r)

pi = 3.14159265358979323846

cx, cy = list(map(int, input().split(" ")))
x, y = list(map(int, input().split(" ")))
wx, wy = list(map(int, input().split(" ")))

r_real = get_radios(cx, cy, x, y)
r_fake = get_radios(cx, cy, wx, wy)

area_real = get_area(pi, r_real)
area_fake = get_area(pi, r_fake)

if area_real == area_fake:
    print(-1, end="")
elif area_real > area_fake:
    print("Krishna", int((area_real - area_fake) * 20), end="")
else:
    diff = area_fake - area_real
    area_1 = math.ceil(math.sqrt(diff))
    area_2 = math.floor(math.sqrt(diff))
    area_1 *= area_1
    area_2 *= area_2
    if area_1 - diff > diff - area_2:
        area_1 = area_2

    if area_1 == diff:
        print(-1, end="")
    elif area_1 > diff:
        print("Krishna", int((area_1 - diff)) * 20, end="")
    else:
        print("Shiva", int((diff - area_1)) * 20, end="")
