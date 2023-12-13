from math import sqrt

ans = 1
time = [int(t) for t in input().replace("Time:", "").split()]
distance = [int(d) for d in input().replace("Distance:", "").split()]
for time, record in zip(time, distance):
    discriminant = sqrt(time ** 2 - 4 * record)
    left, right = int((time - discriminant + 2) // 2), int((time + discriminant) // 2)
    ans *= right - left + (1 if (time + discriminant) % 2 else -1)
print(ans)