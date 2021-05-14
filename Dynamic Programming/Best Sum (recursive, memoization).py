def bestSum(sum, nums, memo = None):
  if memo is None: memo = {}
  if sum < 0: return None
  if sum == 0: return []
  if sum in memo:
    if memo[sum] != None: return memo[sum].copy()
    else: return None

  shortest = None

  for num in nums:
    combination = bestSum(sum - num, nums, memo)
    if combination != None:
      combination.append(num)
      if shortest == None or len(combination) < len(shortest):
        shortest = combination.copy()
  
  if shortest != None:
    memo[sum] = shortest.copy()
    return memo[sum].copy()
  else:
    memo[sum] = None
    return memo[sum]

print(bestSum(7, [5,3,4,7])) #[7]
print(bestSum(8, [2,3,5])) #[5,3]
print(bestSum(8, [1,4,5])) #[4,4]
print(bestSum(100, [2,5,25])) #[25,25,25,25]
