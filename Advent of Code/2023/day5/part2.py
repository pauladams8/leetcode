import sys, re, math

def merge(intervals):
    intervals.sort()
    merged = []
    for interval in intervals:
        if not merged or merged[-1][1] < interval[0]:
            merged.append(interval)
        else:
            merged[-1][1] = max(merged[-1][1], interval[1])
    return merged

ans = math.inf
seeds = [int(x) for x in sys.stdin.readline().strip().replace("seeds: ", "").split()]
seeds = merge([[start, start + length] for start, length in zip(seeds[::2], seeds[1::2])])
maps = [[[int(num) for num in line.split()] for line in map.split("\n") if line.strip()] for map in re.split(r".*map:", sys.stdin.read()) if map.strip()]
for map in maps:
    soil = []
    for dest, src, length in map:
        remaining_seeds = []
        for start, end in seeds:
            if start < src + length and end > src:
                soil.append([dest + max(start, src) - src, dest + min(end, src + length) - src])
                if start < src:
                    remaining_seeds.append([start, src])
                if end > src + length:
                    remaining_seeds.append([src + length, end])
            else:
                remaining_seeds.append([start, end])
        seeds = remaining_seeds
    seeds = merge(soil + seeds)
print(seeds[0][0])