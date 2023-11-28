import heapq
# grid of square regions; values 1 to 9
# fracture line is between top edge and the bottom edge; that minimizes the strength
# up, down, left, right, and diagonal -> from top to bottom
while True:
    def isValid(i, j, h, w):
        return 0 <= i < h and 0 <= j < w
    
    h, w = map(int, input().split())

    if h == 0 and w == 0:
        break
    
    grid =  [list(map(int, list(input()))) for _ in range(h)]
    
    def dijstra_block_crusher(grid, h, w, pq, ans_prev, ans_weights):
        moves = [(1, 1), (1, 0), (1, -1), (0, 1), (0, -1), (-1, 1), (-1, 0), (-1, -1)]
        while pq:
            weight, i, j = heapq.heappop(pq)
            for m in moves:
                ni, nj = i + m[0], j + m[1]
                if isValid(ni, nj, h, w):
                      new_weight = weight + grid[ni][nj]
                      if new_weight < ans_weights[ni][nj]:
                            heapq.heappush(pq, (new_weight, ni, nj))
                            ans_weights[ni][nj] = new_weight
                            ans_prev[ni][nj] = (i, j)

    # add the first row to the pq
    pq = []
    ans_weights = [[float('inf')]*w for _ in range(h)]
    ans_prev = [[None]*w for _ in range(h)]

    for i in range(w):
        heapq.heappush(pq, (grid[0][i], 0, i))
        ans_weights[0][i] = grid[0][i]

    dijstra_block_crusher(grid, h, w, pq, ans_prev, ans_weights) 
    

    # Find the smallest weight in the last row
    curr = (h-1, ans_weights[h-1].index(min(ans_weights[h-1])))
    
    # make fracture
    while True:
        assert curr is not None
        i, j = curr
        if i == 0:
            grid[i][j] = -1
            break
        curr = ans_prev[i][j]
        grid[i][j] = -1

    for row in grid:
        for val in row:
            print(" " if val == -1 else val, end="")
        print()
