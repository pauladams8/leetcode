from math import prod

def prime_factors(n):
  f = 2
  while f**2 <= n:
    if n%f == 0:
      yield f
      n /= f
    else:
      f += 1

def solve():
    n = int(input())
    return str(prod(set(prime_factors(n))))

while True:
  try:
    print(solve())
  except KeyboardInterrupt:
    break