def xor_first(n):
  if n % 4 == 0:
    return n
  if n % 4 == 1:
    return 1
  if n % 4 == 2:
    return n + 1
  return 0

def solution(start, length):
  ans = 0
  for i in range(length):
    ans ^= xor_first(start + length - i - 1) ^ xor_first(start - 1)
    start += length
  return ans
