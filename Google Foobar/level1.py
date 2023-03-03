import collections

def solution(data, n):
  freq = collections.Counter(data)
  ans = []
  for d in data:
    if freq[d] <= n:
      ans.append(d)
  return ans
