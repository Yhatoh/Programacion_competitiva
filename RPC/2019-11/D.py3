
n, k = list(map(int, input().split()))

s2 = 0.0
for i in list(range(k)):
    s1 = 0.0
    for j in list(range(1, n + 1)):
        s1 += j if j > s2 else s2
    s1 = s1 / n
    s2 = s1

print("{:0.8f}".format(s1))
