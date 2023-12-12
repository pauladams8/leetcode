import sys, re, math

ans = math.inf
seeds = [int(x) for x in sys.stdin.readline().strip().replace("seeds: ", "").split()]
maps = [[[int(num) for num in line.split()] for line in map.split("\n") if line.strip()] for map in re.split(r".*map:", sys.stdin.read()) if map.strip()]
for seed in seeds:
    for map in maps:
        for dest, src, length in map:
            if src <= seed < src + length:
                seed = dest + seed - src
                break
    ans = min(ans, seed)
print(ans)