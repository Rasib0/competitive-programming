n = int(input("Enter the number of queens: "))

# For a given position we check if the column or diagonals are safe

col = [False]*n
diag1 = [False]*(2*n-1)
diag2 = [False]*(2*n-1)

count = 0


def nqueens(row):
    global count

    if row == n:
        count = count + 1
    else:
        for column in range(n):
            if col[column] or diag1[row + column] or diag2[n - 1 - column + row]:
                continue
            col[column] = diag1[row + column] = diag2[n - 1 - column + row] = True
            nqueens(row + 1)
            col[column] = diag1[row + column] = diag2[n - 1 - column + row] = False


nqueens(0)

print(count)
