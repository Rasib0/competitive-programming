import sys
lines = sys.stdin.read().splitlines()
board = [list(filter(lambda x: x != ' ', line)) for line in lines]

winner = 'Tie'

for i in range(3):
    if board[i][0] == board[i][1] == board[i][2] != '_':
        winner = board[i][0]
    if board[0][i] == board[1][i] == board[2][i] != '_':
        winner = board[0][i]

if board[0][0] == board[1][1] == board[2][2] != '_':
    winner = board[0][0]
if board[0][2] == board[1][1] == board[2][0] != '_':
    winner = board[0][2]

if winner == 'X':
    print("Johan har vunnit")
elif winner == 'O':
    print("Abdullah har vunnit")
else:
    print("ingen har vunnit")


