def recursive(n, k, a, prices, profit, acum, result):
    max_i = profit.index(max(profit))
    max_profit = profit[max_i]
    max_price = price[max_i]
    for _ in range(int(k)):
        if a > acum and a >= acum + max_price:
            acum += max_price
            result += (max_price * max_profit) / 100
        else:
            print(int(result))
            return
    profit.pop(max_i)
    price.pop(max_i)
    recursive(n, k, a, prices, profit, acum, result);

n, k, a = list(map(int, input.split(" ")))
prices = list(map(int, input.split(" ")))
profit = list(map(int, input.split(" ")))


recursive(n, k, a, prices, profit, 0, 0);