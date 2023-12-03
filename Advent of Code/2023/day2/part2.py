import sys, re, collections, math

def power(game):
    shows = game.split(";")
    max_cubes = collections.defaultdict(lambda: 0)
    for show in shows:
        cubes = show.split(",")
        for cube in cubes:
            cnt, name = re.search(r"(\d+) (red|green|blue)", cube).groups()
            cnt = int(cnt)
            max_cubes[name] = max(max_cubes[name], cnt)
    return math.prod(max_cubes.values())

ans = 0
for game in sys.stdin:
    _, game = game.split(":")
    ans += power(game)
print(ans)