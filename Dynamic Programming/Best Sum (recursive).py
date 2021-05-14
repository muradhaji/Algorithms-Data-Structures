def bestSum(sum, nums):
  if sum < 0: return None
  if sum == 0: return []
  shortest = None
  for num in nums:
    combination = bestSum(sum - num, nums)
    if combination != None:
      combination.append(num)
      if shortest == None or len(combination) < len(shortest):
        shortest = combination
  return shortest

print(bestSum(7, [5,3,4,7])) #[7]
print(bestSum(8, [2,3,5])) #[5,3]
print(bestSum(8, [1,4,5])) #[4,4]
print(bestSum(100, [1,2,5,25])) #Takes too long
