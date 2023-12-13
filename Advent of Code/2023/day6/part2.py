from math import sqrt

time = int("".join(c for c in input() if c.isdigit()))
record = int("".join(c for c in input() if c.isdigit()))
discriminant = sqrt(time ** 2 - 4 * record)
left, right = int((time - discriminant + 2) // 2), int((time + discriminant) // 2)
ans = right - left + (1 if (time + discriminant) % 2 else -1)
print(ans)