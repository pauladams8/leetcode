import collections

def solution(src, dest):
    q = collections.deque()
    seen = [False for _ in range(64)]
    q.append(src)
    seen[src] = True
    moves = 0
    while q:
        n = len(q)
        for _ in range(n):
            square = q.popleft()
            if square == dest:
                return moves
            i, j = square // 8, square % 8
            adj = ((2, 1), (2, -1), (1, -2), (-1, -2),
                    (-2, -1), (-2, 1), (-1, 2), (1, 2))
            for di, dj in adj:
                ii, jj = i + di, j + dj
                if 0 <= ii < 8 and 0 <= jj < 8:
                    new_square = ii * 8 + jj
                    if not seen[new_square]:
                        q.append(new_square)
                        seen[new_square] = True
        moves += 1
    return -1
