from itertools import count

def solve():
    s = input().strip().upper()
    digits = {
        'ONE': 1,
        'TWO': 2,
        'THREE': 3,
        'FOUR': 4,
        'FIVE': 5,
        'SIX': 6,
        'SEVEN': 7,
        'EIGHT': 8,
        'NINE': 9
    }
    for k, v in digits.items():
        try:
            i = 0
            for c in k:
                i = s[i:].index(c)
            return str(v)
        except ValueError:
            continue
    return 'NO'

for c in count(start=1):
    try:
        print(f'Case #{c}: {solve()}')
    except KeyboardInterrupt:
        break