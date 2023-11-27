def minimum_distance_to_cover_all_districts(N, distances):
    # Create a list of all districts
    districts = list(range(N))

    # Initialize the minimum total distance as infinity
    min_total_distance = float("inf")
    second_min_total_distance = float("inf")

    # Iterate through all possible permutations of districts
    from itertools import permutations

    for perm in permutations(districts):
        total_distance = 0

        is_valid_path = all(
            # check if the distance between two adjacent districts is <= 1000
            distances[perm[i]][perm[i + 1]] <= 1000
            for i in range(N - 1)
        )

        if not is_valid_path:
            continue

        for i in range(N - 1):
            total_distance += distances[perm[i]][perm[i + 1]]

        if total_distance < min_total_distance:
            second_min_total_distance = min_total_distance
            min_total_distance = total_distance

    return second_min_total_distance


# Read the number of test cases
num_test_cases = int(input())

results = []

for _ in range(num_test_cases):
    N = int(input())
    distances = []
    for _ in range(N):
        row = list(map(int, input().split()))
        distances.append(row)

    min_distance = minimum_distance_to_cover_all_districts(N, distances)
    results.append(min_distance)

# Print the results
for result in results:
    print(result)
