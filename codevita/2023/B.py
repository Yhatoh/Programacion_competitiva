def toggle(binary):
    res = ""
    for bit in binary:
        if bit == "0":
            res += "1"
        else:
            res += "0"
    return res

nums = list(map(int, input().split(" ")))
a_rahul, b_rahul = list(input().split(" "))
a_rupesh, b_rupesh = list(input().split(" "))

k = int(input())

sum_rahul = 0
sum_rupesh = 0

turn = "rupesh"
while len(nums) > 0:
    if turn == "rahul":
        turn = "rupesh"
    else:
        turn = "rahul"

    maxi_i = nums.index(max(nums))
    left = max(0, maxi_i - k)
    right = min(len(nums) - 1, maxi_i + k)

    if turn == "rahul":
        sum_rahul += sum(nums[left:right+1])
    else:
        sum_rupesh += sum(nums[left:right+1])
    nums = nums[0:left] + nums[right + 1: len(nums)]

if sum_rahul > sum_rupesh:
    a_rahul = toggle(a_rahul)
    b_rupesh = toggle(b_rupesh)
else:
    a_rupesh = toggle(a_rupesh)
    b_rahul = toggle(b_rahul)

xor_rahul = int(a_rahul, 2) ^ int(b_rahul, 2)
xor_rupesh = int(a_rupesh, 2) ^ int(b_rupesh, 2)
if xor_rahul > xor_rupesh:
    print("Rahul", end="")
elif xor_rahul < xor_rupesh:
    print("Rupesh", end="")
else:
    print("both", end="")
