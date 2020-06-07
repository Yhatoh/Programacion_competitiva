y = input()
x = input().split()

def numero(a):
    if a != "(" and a != ")":
        return int(a)
    return a

l = list(map(numero, x))
s = []
o = True

for t in l:
    if t == ")":
        acc = 0 if o else 1
        while s[-1] != "(":
            acc = acc + s.pop() if o else acc * s.pop()
            acc %= (10**9 + 7)
        s.pop()
        s.append(acc)
        o = not o
    else:
        if t == "(":
            o = not o
        s.append(t)

print(sum(s) % (10**9 + 7))
