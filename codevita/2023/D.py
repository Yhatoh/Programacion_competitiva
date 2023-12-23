nums = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
oper = ["add", "sub", "mul", "rem", "pow"]

def fun(oper, num1, num2):
    if oper == "add":
        return num1 + num2
    if oper == "sub":
        return num1 - num2
    if oper == "mul":
        return num1 * num2
    if oper == "rem":
        return num1 % num2
    if oper == "pow":
        return num1 ** num2
    if oper == "div":
        return int(num1 / num2)

splitted = input().split(" ")
len_s = len(splitted)
i = 0
stack = []
correct_word = True
while i < len_s:
    if splitted[i] in oper:
        stack.append(splitted[i])
    else:
        part = splitted[i].split("c")
        real_num = ""
        for num in part:
            if num in nums:
                real_num += str(nums.index(num))
            else:
                correct_word = False
                break
        if not correct_word:
            break
        real_num = int(real_num)
        stack.append(real_num)
    if not correct_word:
        break
    i += 1

#print("stack:", stack)
correct_expr = True
if correct_word:
    new_stack = []
    i = 0
    len_stack = len(stack)
    while i < len_stack:
        if stack[i] in oper:
            new_stack.append(stack[i])
        else:
            if len(new_stack) >= 1:
                new_stack.append(stack[i])
            else:
                new_stack.append(stack[i])
                break
        #print("NEW BF:", new_stack)
        while len(new_stack) >= 3:
            nl = len(new_stack)
            if type(new_stack[nl - 1]) == int and type(new_stack[nl - 2]) == int and type(new_stack[nl - 3]) == str:
                mini_res = fun(new_stack[nl - 3], new_stack[nl - 2], new_stack[nl - 1])
                new_stack.pop()
                new_stack.pop()
                new_stack.pop()
                new_stack.append(mini_res)
            else:
                break
        #print("NEW AF:", new_stack)
        i += 1
    if i == len_stack and len(new_stack) == 3:
        if type(new_stack[2]) == int and type(new_stack[1]) == int:
            if type(new_stack[0]) == str:
                mini_res = fun(new_stack[0],new_stack[2],new_stack[1])
                new_stack.pop()
                new_stack.pop()
                new_stack.pop()
                new_stack.append(mini_res)
    if i != len_stack or len(new_stack) > 1:
        correct_expr = False
if not correct_word:
    print("expression evaluation stopped invalid words present", end="")
elif not correct_expr:
    print("expression is not complete or invalid", end="")
else:
    print(new_stack[0], end="")
