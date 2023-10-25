def knapsack(w, p, prev, size, sum):
    if size < 0:
        return 0, []
    if size == 0:
        return sum, []

    max = 0
    selected_items = []

    for i in range(len(w)):
        temp_profit, temp_items = knapsack(w, p, prev, size - w[i], sum + p[i])

        if temp_profit > max:
            max = temp_profit
            selected_items = temp_items + [i]

    return max, selected_items

if __name__ == "__main__":
    print("Hi World")
    w = [5, 4, 2]
    p = [1, 1, 3]
    prev = []
    maxi, items = knapsack(w, p, prev, 15, 0)
    print(maxi)
    
    print("backtrack: ")
    print([ w[i] for i in items ])

