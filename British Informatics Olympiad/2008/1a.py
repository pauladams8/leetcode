def solve():
  l = int(input())
  if l%2 != 0 or l < 4 or l > 10000:
    return str(-1)
  def pairs():
      ms = set([0, 1])
      for n in range(2, l+1):
        if n not in ms:
          if l-n <= n and l-n not in ms:
            yield (n, l-n)
          for m in range(n**2, l+1, n):
              ms.add(m)
  return str(sum(1 for p in pairs())) 

c = 1
while True:
  try:
    print(f'Case #{c}: {solve()}')
    c += 1
  except KeyboardInterrupt:
    break