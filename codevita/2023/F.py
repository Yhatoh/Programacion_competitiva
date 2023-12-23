permuts = [('P', 'S', 'D', 'H'), ('P', 'S', 'H', 'D'), ('P', 'D', 'S', 'H'), ('P', 'D', 'H', 'S'), ('P', 'H', 'S', 'D'), ('P', 'H', 'D', 'S'), ('S', 'P', 'D', 'H'), ('S', 'P', 'H', 'D'), ('S', 'D', 'P', 'H'), ('S', 'D', 'H', 'P'), ('S', 'H', 'P', 'D'), ('S', 'H', 'D', 'P'), ('D', 'P', 'S', 'H'), ('D', 'P', 'H', 'S'), ('D', 'S', 'P', 'H'), ('D', 'S', 'H', 'P'), ('D', 'H', 'P', 'S'), ('D', 'H', 'S', 'P'), ('H', 'P', 'S', 'D'), ('H', 'P', 'D', 'S'), ('H', 'S', 'P', 'D'), ('H', 'S', 'D', 'P'), ('H', 'D', 'P', 'S'), ('H', 'D', 'S', 'P')]

n = int(input())
row = input().split(" ")

best = 100000000000000
for f, s, t, q in permuts:
    backup = row.copy()
    ans = 0
    i = 0
    while i < len(backup):
        if backup[i] == f:
            if i > 0:
                ans += 1
            backup.pop(i)
        i += 1
    i = 0
    while i < len(backup):
        if backup[i] == s:
            if i > 0:
                ans += 1
            backup.pop(i)
        i += 1
    i = 0
    while i < len(backup):
        if backup[i] == t:
            if i > 0:
                ans += 1
            backup.pop(i)
        i += 1
    i = 0
    while i < len(backup):
        if backup[i] == q:
            if i > 0:
                ans += 1
            backup.pop(i)
        else:
            i += 1
    if best > ans:
        best = ans

print(best, end="")
