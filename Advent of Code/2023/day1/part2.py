import sys

ans = 0

map = {
    "one": "1",
    "two": "2",
    "three": "3",
    "four": "4",
    "five": "5",
    "six": "6",
    "seven": "7",
    "eight": "8",
    "nine": "9"
}

for line in sys.stdin:
    for long, short in map.items():
        line = line.replace(long, long + short + long)
    line = "".join(c for c in line if c.isdigit())
    ans += int(line[0] + line[-1])

print(ans)