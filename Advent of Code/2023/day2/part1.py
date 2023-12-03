import sys, re

max = {
    "red": 12,
    "green": 13,
    "blue": 14
}

def is_game_possible(game):
    shows = game.split(";")
    for show in shows:
        cubes = show.split(",")
        for cube in cubes:
            cnt, name = re.search(r"(\d+) (red|green|blue)", cube).groups()
            cnt = int(cnt)
            if cnt > max[name]:
                return False
    return True

ans = 0
for game in sys.stdin:
    id, game = game.split(":")
    id = int(re.search(r"Game (\d+)", id)[1])
    if is_game_possible(game):
        ans += id
print(ans)