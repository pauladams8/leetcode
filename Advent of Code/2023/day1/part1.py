import sys

ans = 0

for line in sys.stdin:
    line = "".join(c for c in line if c.isdigit())
    ans += int(line[0] + line[-1])

print(ans)