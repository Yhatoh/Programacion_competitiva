n = int(input())
recipes = dict()
pre_cal = dict()

for _ in range(n):
    line = input()
    key, values = line.split("=")
    if key not in recipes.keys():
        recipes[key] = []
        pre_cal[key] = []
    recipes[key].append(values.split("+"))
    pre_cal[key].append(-1)

potion = input()

def fun(node, recipes): 
    if node not in recipes.keys():
        return 0

    min_cost = 1000000000
    for i in range(len(recipes[node])):
        if pre_cal[node][i] != -1:
            min_cost = min(min_cost, pre_cal[node][i]);
        else:
            cost = len(recipes[node][i]) - 1
            for item in recipes[node][i]:
                if item in recipes.keys():
                    cost += fun(item, recipes)
            min_cost = min(cost, min_cost)
            pre_cal[node][i] = cost

    return min_cost

print(fun(potion, recipes), end="")
