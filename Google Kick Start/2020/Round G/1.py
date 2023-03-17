def solve():
    s = input().strip()
    kick = 0
    lucky = 0
    for i in range(len(s)):
        if s[i:i+4] == 'KICK':
            kick += 1
        if s[i:i+5] == 'START':
            lucky += kick
    return lucky

t = int(input())
for c in range(1, t+1):
    print(f'Case #{c}: {solve()}')