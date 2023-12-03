import sys, math

ans = 0
adj = ((-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1))
grid = [list(line) for line in sys.stdin.read().split("\n")]
for i in range(len(grid)):
    for j in range(len(grid[i])):
        if grid[i][j] == "*":
            nums = []
            for di, dj in adj:
                ii, jj = i + di, j + dj
                if 0 <= ii < len(grid) and 0 <= jj < len(grid[ii]) and grid[ii][jj].isdigit():
                    num = grid[ii][jj]
                    grid[ii][jj] = "."
                    jjj = jj - 1
                    while jjj >= 0 and grid[ii][jjj].isdigit():
                        num = grid[ii][jjj] + num
                        grid[ii][jjj] = "."
                        jjj -= 1
                    jjj = jj + 1
                    while jjj < len(grid[ii]) and grid[ii][jjj].isdigit():
                        num += grid[ii][jjj]
                        grid[ii][jjj] = "."
                        jjj += 1
                    nums.append(int(num))
            if len(nums) == 2:
                ans += math.prod(nums)
print(ans)