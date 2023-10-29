import sys

def whowins(board):
    # Check rows, columns, and diagonals for a win
    for i in range(3):
        if board[i][0] == board[i][1] == board[i][2] and board[i][0] != '_':
            return board[i][0]
        if board[0][i] == board[1][i] == board[2][i] and board[0][i] != '_':
            return board[0][i]
    if board[0][0] == board[1][1] == board[2][2] and board[0][0] != '_':
        return board[0][0]
    if board[0][2] == board[1][1] == board[2][0] and board[0][2] != '_':
        return board[0][2]
  
    return 'No winner'

inputs = sys.stdin.read().splitlines()
# Create the board
board = [list(filter(lambda x: x != ' ', line)) for line in inputs]

winner = whowins(board)
if winner == 'X':
    print('Johan', end=' ')
elif winner == 'O':
    print('Abdullah', end=' ')
else:
    print('ingen', end=' ')

print('har vunnit')



