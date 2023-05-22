n = int(input())
s = input()
s = [i for i in s]
s2 = [i for i in s]
l = len(s)
for i in range(len(s)):
    if s[i] == "1":
        if i + 1 < l:
            s2[i + 1] = "1"
        if i + 2 < l:
            s2[i + 2] = "1"

ans = 0
for i in range(l):
    if s2[i] == "1":
        ans += 1
print(ans)

