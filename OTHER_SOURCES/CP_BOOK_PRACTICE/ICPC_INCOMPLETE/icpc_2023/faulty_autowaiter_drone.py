# Function to find the seat that the Circular AutoWaiter will pick up last
def find_last_seat(p):
    # Initialize a list to represent the seats
    seats = list(range(1, p + 1))
    skip = 1  # Initial skip count

    # Repeat the process until there is only one seat left
    while len(seats) > 1:
        # Create a new list to store the seats that are not skipped
        new_seats = []
        for i in range(len(seats)):
            if i % skip == 0:
                new_seats.append(seats[i])
        seats = new_seats
        skip += 1  # Increment the skip count

    return seats[0]


# Read the number of test cases
n = int(input())
results = []

# Process each test case
for _ in range(n):
    p = int(input())
    last_seat = find_last_seat(p)
    results.append(last_seat)

# Output the results
for seat in results:
    print(seat)
