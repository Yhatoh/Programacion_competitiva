n = int(input())
rs = list(map(int, input().split(" ")))

ans = 0
for i in range(len(rs)):
    for j in range(i):
        case = 0
        if rs[i] >= rs[j]:
            case = (rs[j] * (rs[j] - 1)) / 2
        else:
            case = (rs[i] * (rs[i] - 1)) / 2 + (rs[j] - rs[i]) * rs[i]
        ans += case / (rs[i] * rs[j])
ans = round(ans, 10)
print("{:.6f}".format(ans))
