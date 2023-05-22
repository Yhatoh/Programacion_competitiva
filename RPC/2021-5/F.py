n, k = list(map(int, input().split(" ")))

actual = 0
for i in range(k):
	actual += int(input())

print((actual - 3 * (n - k)) / n, (actual + 3 * (n - k)) / n)

