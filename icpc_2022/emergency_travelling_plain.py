test_cases = int(input())

for i in range(test_cases):
    number_of_cities = int(input())
    aerial_routes_num = int(input())

    aerial_routes = {}
    for i in range(0, number_of_cities - 1):
        aerial_routes.update({i: [i + 1]})

    for i in range(aerial_routes_num):
        k, e = map(int, input().split())
        aerial_routes[k].append(e)

    def dfs(days, counter, root, min_days):
        print(f"days: {days}, counter: {counter}, root: {root}")

        if counter == 6:
            counter = 0
            if all([neigh_of_n > root for neigh_of_n in aerial_routes[root]]):
                return float("inf")
            else:
                days += 1

        if root == number_of_cities - 1:
            return days

        for neighbor in aerial_routes[root]:
            temp = float("inf")

            # road
            if neighbor == root + 1:
                counter += 1
                # we can't stop at roat that has a neighbor that is smaller than it
                if neighbor == number_of_cities - 1:
                    return days
                temp = dfs(days, counter + 1, neighbor, min_days)
            # aerial
            else:
                temp = dfs(days + 1, counter, neighbor, min_days)
            min_days = min(temp, min_days)

        return min_days

    print(dfs(0, 0, 0, float("inf")))
    # will choice the first element only 6 times in a row or increment day
    # can't increment day on a node that points back, so kill this branch
    # choosing an aerial route updates day by one
