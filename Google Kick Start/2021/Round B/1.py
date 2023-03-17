def solve():
  n = int(input())
  s = input().strip()
  assert(len(s) == n)
  def length():
    lengths = {}
    for i, c in enumerate(s):
      try:
        prev = s[i-1]
        if prev < c:
          lengths[i] = lengths[i-1] + 1
        else:
          lengths[i] = 1
      except LookupError:
        lengths[i] = 1
      yield lengths[i]
  return ' '.join(str(n) for n in length())

t = int(input())

for c in range(1, t+1):
  print(f'Case #{c}: {solve()}')