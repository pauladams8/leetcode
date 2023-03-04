def solution(h, q):
  ans = []
  for n in q:
    left, right, parent = 1, 2 ** h - 1, -1
    while left <= right:
      if right == n:
        ans.append(parent)
        break
      mid, parent = (left + right) // 2, right
      if n < mid:
        right = mid - 1
      else:
        left = mid
  return ans
